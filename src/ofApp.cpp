#include "ofApp.h"
#include "Cell.h"

#include <vector>
#include <iostream>
#include <stack>
#include <string>

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(false);
	ofSetFrameRate(2000);

	cols = 600/w;
	rows = 600/w;

	perimsLeft = (cols * 2) + ((rows - 2) * 2);
	cellsLeft = cols * rows;

	// Looping through rows/cols and generating cell objects
	for (int y=0; y<rows; y++)
	{
		for (int x=0; x<cols; x++)
		{
			Cell cell(x,y,w,false,(x + (y*cols)));
			grid.push_back(cell);
		}
	}

	current = startCell;
	grid[current].startCell = true;
	s.push(current);
}

//--------------------------------------------------------------
void ofApp::update(){
	grid[current].visited = true;

	cellsLeft--;

	if (cellsLeft == 0)
	{
		allFilled = true;
	}

	if (grid[current].counted == false)
	{
		if (grid[current].i == 0 || grid[current].j == 0 || grid[current].i == cols-1 || grid[current].j == rows-1)
		{
			perimsLeft--;
			grid[current].counted = true;
		}
	}

	if (perimsLeft == 0)
	{
		endCell = current;
		grid[current].endCell = true;
		endFound = true;
		sol = s;
	}

	Cell next = grid[current].checkNeighbors(grid, cols, rows);

	if (next.index >= 0 && next.visited != true)
	{
		s.push(next.index);
		grid[current].current = false;
		grid = grid[current].removeWalls(grid[current].index, next.index, grid);
		current = next.index;
		grid[current].current = true;
		grid[current].visited = true;
	} else {
		if (!s.empty())
		{
			s.pop();
			grid[current].current = false;
			current = s.top();
			grid[current].current = true;
		}
	}

	while (!solution && allFilled && endFound)
	{
		if (!sol.empty())
		{
			if (endFound && allFilled)
			{
				solGrid.push_back(grid[sol.top()]);
				sol.pop();
			}
		} else {
			solution = true;
		}
	}

	if (solution && allFilled)
	{
		ofSleepMillis(1000);
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetBackgroundColor(253, 250, 240);

	for (float i=0; i<grid.size(); i++)
	{
		grid[i].show();
	}

	if (solution)
	{
		for (float j=0; j<solGrid.size(); j++)
		{
			solGrid[j].solutionCell = true;
			solGrid[j].show();
		}
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
