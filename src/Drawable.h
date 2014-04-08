#pragma once

#include "ofMain.h"

namespace ofxMiniGui {
	class Drawable {
	public:
		Drawable();
		
		virtual void draw() = 0;
		void draw(int x, int y);
		
		int getX();
		int getY();
		int getWidth();
		int getHeight();
		
		void setWidth(int width);
		void setHeight(int height);
		
	protected:
		int x, y, width, height;
		
		ofMouseEventArgs applyOffset(ofMouseEventArgs& args);
		bool isInside(ofMouseEventArgs& args);
	};
}