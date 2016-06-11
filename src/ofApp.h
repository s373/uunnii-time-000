#pragma once
#include "MiniChronos.h"
#include "ofMain.h"

class ofApp : public ofBaseApp{
public:
	void setup(){
		ofSetWindowTitle("x/net.s373.UunniiTtiimmee.Now");
		ofSetFrameRate(1);
		ofBackground(10);
		chronos.setup();
	}
	void update(){
		ofSetWindowTitle("x/net.s373.UunniiTtiimmee.Now "+ofToString(ofGetFrameRate()));
		chronos.update();
	}
	void draw(){
		chronos.draw();
	}
	MiniChronos chronos;
};
