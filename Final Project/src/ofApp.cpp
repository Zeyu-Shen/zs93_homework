#include "ofApp.h"
#include <cmath>

//--------------------------------------------------------------
void ofApp::setup(){
    sphere = ofSpherePrimitive(1000, 50);
    z.reserve(6);
    sphere.setPosition(0, 0, 0);
    ofBackground(ofColor::black);
    font.load("Iron.ttf", 90);
    font2.load("Iron.ttf", 60);
    font3.load("NerkoOne-Regular.ttf", 30);
    fftsmooth = new float [8192];
    for (int i=0; i<8192; i++){
        fftsmooth[i] = 0;
    }
    
    bands = 64;
    
    beat.setLoop(true);
    beat.setVolume(0.2);
    
    Line l = Line();
    l.peak = ofRandom(l.particles.size()/3, l.particles.size()*2/3);
    lines.push_back(l);
}

bool ofApp::checkCollision(){
    for (int i=0; i<lines.size(); i++){
        vector<Particle> v = lines[i].particles;
        for (int j=0; j<v.size(); j++){
            Particle p = v[j];
            double d = length(p.pos-glm::vec3(ball.x, ball.y+50, ball.z));
            //cout<<d<<" "<<p.ypos<<endl;
            if (d<ball.radius+p.mass*2-10 && p.ypos>585 && p.ypos<590){
                return true;
            }
        }
    }
    return false;
}

//--------------------------------------------------------------
void ofApp::update(){
    if (!loaded && canload){
        if (z[0]) beat.loadSound("beat.mp3");
        if (z[1]) beat.loadSound("autumn.wav");
        if (z[2]) beat.loadSound("Cristal.mp3");
        if (z[3]) beat.loadSound("Earth.wav");
        if (z[4]) beat.loadSound("Waterfall.wav");
        if (z[5]) beat.loadSound("Chaos.wav");
        loaded = true;
    }
    sphere.rotateDeg(0.05, glm::vec3(-1, 1, 0));
    if (finish){
        return;
    }
    if (begin){
        for (int i=0; i<lines.size(); i++){
            lines[i].update();
        }
        if (lines.back().Z > -200){
            Line l = Line();
            l.peak = ofRandom(l.particles.size()/3, l.particles.size()*2/3);
            lines.push_back(l);
        }
        if (lines.size() && (lines[0].Z >= 0 || lines[0].Y>=700)){
            lines.erase(lines.begin());
        }
        if (checkCollision()){
            finish = true;
        }
        for (int i=0; i<lines.size(); i++){
            if (lines[i].Y >= ball.y+50 && !lines[i].added){
                cnt++;
                lines[i].added = true;
            }
        }
        ball.update();
        
        ofSoundUpdate();
        
        for (int i=0; i<lines.size(); i++){
            Line l = lines[i];
            vector<Particle> v = l.particles;
            if (v[0].ypos-50>=ball.y){
                if (ball.x<v[l.peak-v.size()/6].pos.x || ball.x>v[l.peak+v.size()/6].pos.x){
                    finish = true;
                }
            }
        }
        
        float * value = ofSoundGetSpectrum(bands);
        for (int i=0; i<lines.size(); i++){
            Line l = lines[i];
            if (!l.updated){
                vector<Particle> a = l.particles;
                for (int j=0; j<a.size(); j++){
                    a[j].update2(a[0].pos.y);
                    a[j].applyElasticForce(0.5);
                }
                int peak = l.peak;
                for (int j=peak-a.size()/6; j<peak+a.size()/6; j++){
                    //cout<<((a.size()/6-abs(peak-j))*fftsmooth[0])/(a.size()/6)<<endl;
                    float t = ofGetElapsedTimef();
                    float force = -(150*pow((a.size()/6-abs(peak-j)+ofSignedNoise(j, t)), 0.5)*pow(fftsmooth[0], 0.5))/(a.size()/6);
                    //cout<<force<<endl;
                    a[j].applyForce(glm::vec3(0, force, 0));
                }
                l.particles = a;
                l.updated = true;
                lines[i] = l;
            }
            vector<Particle> a = l.particles;
            for (int j=0; j<a.size(); j++){
                a[j].update2(a[0].pos.y);
                a[j].applyElasticForce(0.1);
            }
            l.particles = a;
            l.updated = true;
            lines[i] = l;
        }
        for (int i=0; i<bands; i++){
            fftsmooth[i] *= 0.3f;
            if (fftsmooth[i]<1){
                fftsmooth[i] = value[i];
            }
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (!start){
        font.drawString("Music Mover", ofGetWidth()/2-310, ofGetHeight()/2+30);
        ofDrawBitmapString("Click Anywhere to Start the Game", ofGetWidth()/2-130, ofGetHeight()/2+80);
    }
    if (start && !begin){
        font2.drawString("Choose Your Song", ofGetWidth()/2-310, 100);
        font3.drawString("Beat", 180, 250);
        font3.drawString("Earth", 650, 250);
        font3.drawString("Cristal", 180, 400);
        font3.drawString("All About Us", 650, 400);
        font3.drawString("Waterfall", 180, 550);
        font3.drawString("Chaos", 650, 550);
    }
    cam.begin();
    ofEnableDepthTest();
    ofSetColor(ofColor::purple);
    sphere.drawWireframe();
    ofDisableDepthTest();
    cam.end();
    ofSetColor(255);
    if (begin){
        ball.draw();
        for (int i=0; i<lines.size(); i++){
            lines[i].draw();
        }
        string str = "Your Score: "+to_string(cnt);
        ofDrawBitmapString(str, 50, 50);
        if (finish){
            gameOver();
        }
    }
}

void ofApp::gameOver(){
    font.drawString("Game Over!", ofGetWidth()/2-270, ofGetHeight()/2+30);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'a'){
        ball.update_left = true;
    }
    if (key == 'd'){
        ball.update_right = true;
    }
    if (key == 'w'){
        ball.click_update();
    }
    switch(key){
        case '1':
            beat.play();
            break;
        case '2':
            beat.stop();
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == 'a'){
        ball.update_left = false;
    }
    if (key == 'd'){
        ball.update_right = false;
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if (!begin && start){
        begin = true;
        if (x<=500 && y<=350){
            z[0] = true;
        }
        if (x>=500 && y<=350){
            z[1] = true;
        }
        if (x<=500 && y>=350 && y<=450){
            z[2] = true;
        }
        if (x>=500 && y>=350 && y<=450){
            z[3] = true;
        }
        if (x<=5000 && y>=450){
            z[4] = true;
        }
        if (x>=500 && y>=450){
            z[5] = true;
        }
        canload = true;
    }
    if (!start){
        start = true;
        //cout<<x<<" "<<y<<endl;
    }
    ball.click_update();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
