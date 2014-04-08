#include "Slider.h"

namespace ofxMiniGui {
	static ofColor cyan(0, 174, 239), magenta(236, 0, 140), yellow(255, 242, 0);

	void smartRect(int x, int y, int width, int height) {
		//ofRect(x, y, width, height);
		if(ofGetFill()) {
			ofRect(x, y, width, height);
		} else {
			ofRect(x + .5, y + .5, width - 1, height - 1);
		}
	}
	
	void smartLine(int x1, int y1, int x2, int y2) {
		//ofLine(x1, y1, x2, y2);
		ofLine(x1 + .5, y1 + .5, x2 + .5, y2 + .5);
	} 
		
	Slider::Slider(string name, float min, float max, float value)
	:name(name)
	,min(min), max(max), value(value), original(value)
	,hover(false), selected(false)
	,lastSelected(0) {
		width = 64, height = 11;
	}
	
	void Slider::draw() {
		ofColor background(0), foreground(64), outline(128), text(255);
		if(selected) {
			outline = magenta;
			foreground.set(128);
		} else if(hover) {
			outline = cyan;
		} else if(lastSelected > 0) {
			float elapsed = ofGetElapsedTimef() - lastSelected;
			float fadeOut = 6;
			outline.lerp(magenta, ofMap(elapsed, fadeOut, 0, 0, 1, true));
		}
		ofFill();
		ofSetColor(background);
		smartRect(0, 0, width, height);
		ofSetColor(foreground);
		float valueWidth = 0;
		if(min != max) {
			valueWidth = ofMap(value, min, max, 0, width);
		}
		smartRect(0, 0, valueWidth, height); 
		ofNoFill();
		ofSetColor(outline);
		smartRect(0, 0, width, height);
		smartLine(valueWidth, 0, valueWidth, height);
		ofSetColor(text);
		ofFont& font = parent->getFont();
		string label = (hover || selected) ? ofToString(value) : name;
		font.drawString(label, 2, font.getSize() + 1);
	}
	
	string Slider::getName() {return name;}
	float Slider::getMin() {return min;}
	float Slider::getMax() {return max;}
	float& Slider::getValue() {return value;}
	Gui* Slider::getParent() {return parent;}
	
	void Slider::setName(string name) {this->name = name;}
	void Slider::setMin(float min) {this->min = min;}
	void Slider::setMax(float max) {this->max = max;}
	void Slider::setValue(float value) {this->value = ofClamp(value, min, max);}
	void Slider::setParent(Gui* parent) {this->parent = parent;}
	
	void Slider::mouseMoved(ofMouseEventArgs& args) {
		hover = isInside(args);
	}
	
	void Slider::mouseDragged(ofMouseEventArgs& args) {
		if(selected) {
			ofMouseEventArgs local = applyOffset(args);
			float value = min;
			if(min != max) {
				value = ofMap(local.x, 0, width, min, max, true);
			}
			setValue(value);
		}		
	}
	
	void Slider::mousePressed(ofMouseEventArgs& args) {
		selected = isInside(args);
		mouseDragged(args);
		if(selected && args.button == 2) {
			value = original;
			selected = false;
		}
	}
	
	void Slider::mouseReleased(ofMouseEventArgs& args) {
		if(selected) {
			lastSelected = ofGetElapsedTimef();
		}
		selected = false;
	}
	
	Slider::operator float&() {
		return getValue();
	}
}