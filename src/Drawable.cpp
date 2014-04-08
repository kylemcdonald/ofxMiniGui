#include "Drawable.h"

#include "ofMain.h"

namespace ofxMiniGui {
	Drawable::Drawable()
	:x(0), y(0), width(0), height(0) {
	}

	void Drawable::draw(int x, int y) {
		this->x = x;
		this->y = y;
		ofPushMatrix();
		ofTranslate(x, y);
		draw();
		ofPopMatrix();
	}
	
	int Drawable::getX() {return x;}
	int Drawable::getY() {return y;}
	int Drawable::getWidth() {return width;}
	int Drawable::getHeight() {return height;}
	void Drawable::setWidth(int width) {this->width = width;}
	void Drawable::setHeight(int height) {this->height = height;}
	
	ofMouseEventArgs Drawable::applyOffset(ofMouseEventArgs& args) {
		ofMouseEventArgs cur = args;
		cur.x -= x;
		cur.y -= y;
		return cur;
	}
	
	bool Drawable::isInside(ofMouseEventArgs& args) {
		return args.x > x && args.x < x + getWidth() &&
			args.y > y && args.y < y + getHeight();
	}
}