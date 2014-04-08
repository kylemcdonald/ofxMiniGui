#pragma once

#include "Gui.h"
#include "Drawable.h"

namespace ofxMiniGui {
	class Gui;
	class Slider : public Drawable {
	public:
		Slider(string name, float min, float max, float value);
		
		using Drawable::draw;
		void draw();
		
		string getName();
		float getMin();
		float getMax();
		float& getValue();
		Gui* getParent();
		
		void setName(string name);
		void setMin(float min);
		void setMax(float max);
		void setValue(float value);
		void setParent(Gui* parent);
		
		void mouseMoved(ofMouseEventArgs& args);
		void mouseDragged(ofMouseEventArgs& args);
		void mousePressed(ofMouseEventArgs& args);
		void mouseReleased(ofMouseEventArgs& args);
		
		operator float&();
	
	protected:
		string name;
		float min, max;
		float original, value;
		Gui* parent;
		bool hover, selected;
		float lastSelected;
	};
}