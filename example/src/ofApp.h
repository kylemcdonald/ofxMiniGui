#pragma once

#include "ofMain.h"
#include "ofxMiniGui.h"

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
	
	ofxMiniGui::Gui gui;
};
