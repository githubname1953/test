#include "ofApp.h"
#include<vector>

float H;
float W;
float angle = 0;
//const float posy0 = (float) ofGetScreenHeight() - 100.0f;
ofVec2f pos;
float v = 0;
vector<ofVec2f> Box;
vector<int> count1;
int score = 0; int collided = 0;
//--------------------------------------------------------------
void ofApp::setup(){
	H = ofGetHeight();
	W = ofGetWidth();
	pos.x = 300;
	pos.y = 600;
	
	Box.push_back(ofVec2f(W, 600.0f)); count1.push_back(0);
	Box.push_back(ofVec2f(W+500, 560.0f)); count1.push_back(0);
	
}

//--------------------------------------------------------------
void ofApp::update(){
	ofSetBackgroundColor(ofColor(30, 30, 30));
	ofSetWindowTitle(to_string(ofGetFrameRate()));
	
	for (int i=0; i<Box.size();i++)
	{
		Box[i].x -= 5;

		if (fabs(Box[i].x - pos.x) <= 50 && fabs(Box[i].y - pos.y) <= 50) count1[i]++;

		if (Box[i].x - pos.x < -50)
		{
			if (count1[i] > 0) { collided++; count1[i] = -1; }

			else if (count1[i] == 0) { score++; count1[i] = -1; }
		}

		if (Box[i].x <= -50) { Box[i].x = W; count1[i] = 0; } 
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofSetColor(100, 100, 220);
	ofDrawRectangle(0, 650, ofGetScreenWidth(), 50);
    ofDrawBitmapString(to_string(collided), 100, 100);
	ofDrawBitmapString(to_string(score), 150, 100);

	if (pos.y <= 600)
	{
		v += 1;
		pos.y += v;
	}

	ofSetColor(100, 220, 100);
	for (auto& b : Box)
	{
		ofDrawRectangle(b, 50, 50);
	}

	ofSetColor(220,100,100);
	ofDrawRectangle(pos, 50, 50);
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == ' ')
	{
		if (pos.y >= 600) v = -20;
		if (pos.y >= 600) pos.y += v;
	}
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
