#pragma once

#include "ofMain.h"
#include "Slider.h"
#include "Drawable.h"

namespace ofxMiniGui {
	class Slider;
	class Gui : public Drawable {
	public:
		Gui();
		void setup();
		
		void add(Slider slider);
		Slider& get(int i);
		Slider& get(string name);
		bool exists(string name);
		void set(string name, float value);
		void set(int i, float value);
		int size();
		
		using Drawable::draw;
		void draw();
		
		void setVisible(bool visible);
		bool getVisible();
		
		ofTrueTypeFont& getFont();
		
		void mouseMoved(ofMouseEventArgs& args);
		void mouseDragged(ofMouseEventArgs& args);
		void mousePressed(ofMouseEventArgs& args);
		void mouseReleased(ofMouseEventArgs& args);
		void keyPressed(ofKeyEventArgs& args);
		void keyReleased(ofKeyEventArgs& args);
		void draw(ofEventArgs& args);
		
	protected:
		vector<Slider> sliders;
		ofTrueTypeFont font;
		ofVec2f padding;
		bool visible;
	};
}