#pragma once

#include "ofMain.h"
#include "Cell.h"

#include <vector>
#include <stack>

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		int cols, rows;
		int w = 20;

		vector<Cell> grid;
		vector<Cell> solGrid;

		int current;

		int startCell = 0;
		int endCell;
		int perimsLeft;
		int cellsLeft;

		stack<int> s;
		stack<int> sol;

		bool endFound = false;
		bool solution = false;
		bool allFilled = false;

};
