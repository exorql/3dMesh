#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(40);
    ofBackground(0); // 背景black
    ofSetColor(0,255,0);
     //板を生成
    ofPlanePrimitive plane;
    plane.set(600, 600, 30, 30);
     // 生成した板からメッシュを生成 メッシュの情報を抽出
    mesh = plane.getMesh();
}

//--------------------------------------------------------------
void ofApp::update(){
    ofColor color;
    for(int i=0; i < mesh.getVertices().size(); i++) {
        mesh.addColor(ofFloatColor(1.0, 1.0, 1.0, 1.0));  //色情報初期化
        float x = mesh.getVertices()[i].x;
        float y = mesh.getVertices()[i].y;
        //sin波を使って3Dの波を生成 ofGetElapsedTimef プログラム実行からの経過時間
        float z = sin(ofGetElapsedTimef() + x * 0.06) * 200.0;
        mesh.setVertex(i, glm::vec3(x,y,z));
        color.setHsb(ofMap(ofNoise(x * 0.005, y * 0.005, z * 0.005, ofGetFrameNum() * 0.008), 0, 1, 0, 150), 180, 230);
        mesh.setColor(i,color);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    ofRotateXDeg(-60);
    mesh.drawWireframe();
    cam.end();
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

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
