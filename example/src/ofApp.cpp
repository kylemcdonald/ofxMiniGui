#include "ofApp.h"

using namespace ofxMiniGui;

void ofApp::setup() {
	ofSetVerticalSync(true);
	vector<string> joints = ofSplitString("MasterFloor Root Hips UpLeg_L LoLeg_L Foot_L Toe_L UpLeg_R LoLeg_R Foot_R Toe_R Spine1 Spine2 Spine3 Neck Head Jaw TongueBase TongueMid TongueTip Eye_R Eye_L UpLid_R LoLid_R UpLid_L LoLid_L Clavicle_L UpArm_L LoArm_L Hand_L Wrist-1_L Palm-2_L Finger-2-1_L Finger-2-2_L Finger-2-3_L Palm-3_L Finger-3-1_L Finger-3-2_L Finger-3-3_L Wrist-2_L Palm-4_L Finger-4-1_L Finger-4-2_L Finger-4-3_L Palm-5_L Finger-5-1_L Finger-5-2_L Finger-5-3_L Palm-1_L Finger-1-1_L Finger-1-2_L Finger-1-3_L Clavicle_R UpArm_R LoArm_R Hand_R Wrist-1_R Palm-2_R Finger-2-1_R Finger-2-2_R Finger-2-3_R Palm-3_R Finger-3-1_R Finger-3-2_R Finger-3-3_R Wrist-2_R Palm-4_R Finger-4-1_R Finger-4-2_R Finger-4-3_R Palm-5_R Finger-5-1_R Finger-5-2_R Finger-5-3_R Palm-1_R Finger-1-1_R Finger-1-2_R Finger-1-3_R Wrist_L Wrist_R Ankle_L Ankle_R", " ");

	gui.setup();
	for(int i = 0; i < joints.size(); i++) {
		gui.add(Slider(joints[i]+".x", -1, +1, 0));
		gui.add(Slider(joints[i]+".y", -1, +1, 0));
		gui.add(Slider(joints[i]+".z", -1, +1, 0));
	}
}

void ofApp::update() {
}

void ofApp::draw() {
	ofBackground(0);
	ofTranslate(1, 1);
	gui.draw(0, 0);
}
