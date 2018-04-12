#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(39);
	ofSetWindowTitle("Insta");

	ofSetLineWidth(5);

}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	int span = 72;
	ofColor line_color;
	for (int x = span / 2; x < ofGetWidth() + span / 2; x += span) {

		for (int y = span / 2; y < ofGetHeight() + span / 2; y += span) {

			ofPoint point = ofPoint(x, y);

			ofPushMatrix();
			ofTranslate(point);
			ofRotate(ofNoise(x * 0.005, y * 0.005, ofGetFrameNum() * 0.03) * 360);

			line_color.setHsb((x + y) % 255, 239, 239);
			ofSetColor(line_color);

			ofDrawLine(ofPoint(0, -span / 2), ofPoint(0, span / 2));
			ofDrawLine(ofPoint(-span / 2, 0), ofPoint(span / 2, 0));
			
			ofPopMatrix();
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}