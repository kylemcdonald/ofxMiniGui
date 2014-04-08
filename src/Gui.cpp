#include "Gui.h"

namespace ofxMiniGui {
	Gui::Gui()
	:padding(1, 1) {
	}
	
	void Gui::setup() {
		font.loadFont("fonts/04B_03.ttf", 6, false);
		ofRegisterKeyEvents(this);
		setVisible(true);
	}
	
	void Gui::add(Slider slider) {
		slider.setParent(this);
		sliders.push_back(slider);
	}
	
	Slider& Gui::get(int i) {
		return sliders[i];
	}
	
	Slider& Gui::get(string name) {
		for(int i = 0; i < sliders.size(); i++) {
			if(sliders[i].getName() == name) {
				return sliders[i];
			}
		}
		ofLogError() << "'" << name << "' does not exist.";
	}
	
	bool Gui::exists(string name) {
		for(int i = 0; i < sliders.size(); i++) {
			if(sliders[i].getName() == name) {
				return true;
			}
		}
		return false;
	}
	
	void Gui::set(string name, float value) {
		(float&) get(name) = value;
	}
	
	void Gui::set(int i, float value) {
		(float&) get(i) = value;
	}
	
	int Gui::size() {
		return sliders.size();
	}
	
	void Gui::draw() {
		ofPushStyle();
		glPushAttrib(GL_ALL_ATTRIB_BITS);
		glDisable(GL_DEPTH_TEST);
		glDisable(GL_FOG);
		ofDisableSmoothing();
		ofDisableAlphaBlending();
		ofDisableLighting();
		ofDisableSeparateSpecularLight();
		ofSetLineWidth(1);
		
		width = ofGetWidth();
		height = ofGetHeight();
		int x = 0, y = 0;
		for(int i = 0; i < sliders.size(); i++) {
			if(y + sliders[i].getHeight() > getHeight()) {
				y = 0;
				x += sliders[i].getWidth();
				x += padding.x;
			}
			sliders[i].draw(x, y);
			y += sliders[i].getHeight();
			y += padding.y;
		}
		font.drawString(ofToString((int) ofGetFrameRate()), width - 20, height - 8);
		glPopAttrib();
		ofPopStyle();
	}
	
	void Gui::setVisible(bool visible) {
		this->visible = visible;
		if(visible) {
			ofAddListener(ofEvents().draw, this, &Gui::draw);
			ofRegisterMouseEvents(this);
		} else {
			ofRemoveListener(ofEvents().draw, this, &Gui::draw);
			ofUnregisterMouseEvents(this);
		}
	}
	
	bool Gui::getVisible() {return visible;}

	void Gui::mouseMoved(ofMouseEventArgs& args) {
		ofMouseEventArgs local = applyOffset(args);
		for(int i = 0; i < sliders.size(); i++) {
			sliders[i].mouseMoved(local);
		}
	}
	
	void Gui::mouseDragged(ofMouseEventArgs& args) {
		ofMouseEventArgs local = applyOffset(args);
		for(int i = 0; i < sliders.size(); i++) {
			sliders[i].mouseDragged(local);
		}
	}
	
	void Gui::mousePressed(ofMouseEventArgs& args) {
		ofMouseEventArgs local = applyOffset(args);
		for(int i = 0; i < sliders.size(); i++) {
			sliders[i].mousePressed(local);
		}
	}
	
	void Gui::mouseReleased(ofMouseEventArgs& args) {
		ofMouseEventArgs local = applyOffset(args);
		for(int i = 0; i < sliders.size(); i++) {
			sliders[i].mouseReleased(local);
		}
	}
	
	void Gui::keyPressed(ofKeyEventArgs& args) {
		if(args.key == 'f') {
			ofToggleFullscreen();
		}
		if(args.key == '\t') {
			setVisible(!getVisible());
		}
	}
	
	void Gui::keyReleased(ofKeyEventArgs& args) {
	}
	
	void Gui::draw(ofEventArgs& args) {
		draw(1, 1);
	}
	
	ofFont& Gui::getFont() {
		return font;
	}
	
}
