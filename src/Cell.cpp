/*
 * Cell.cpp
 *
 *  Created on: 19 Dec 2016
 *      Author: kai-w
 */

#include "ofMain.h"
#include <Cell.h>
#include <iostream>

Cell::Cell(int ii, int jj, int ww, bool faked, int indexx) {
	i = ii;
	j = jj;
	w = ww;
	fake = faked;
	index = indexx;
	current = false;
}
Cell::Cell(int ii, int jj, int ww, bool faked, int indexx, bool visd) {
	i = ii;
	j = jj;
	w = ww;
	fake = faked;
	index = indexx;
	current = false;
	visited = true;
}

Cell::~Cell() {
}


void Cell::show() {
	int x = i * w;
	int y = j * w;

	if (visited)
	{
		ofSetColor(255,0,255);
		ofDrawRectangle(ofPoint(x,y),w,w);
	}

	if (current)
	{
		ofSetColor(255,0,0);
		ofDrawRectangle(ofPoint(x,y),w,w);
	}

	if (solutionCell)
	{
		ofSetColor(155,255,155);
		ofDrawRectangle(ofPoint(x,y),w,w);
	}

	if (startCell || endCell)
	{
		ofSetColor(100, 255, 100);
		ofDrawRectangle(ofPoint(x,y),w,w);
	}

	ofSetColor(0,0,0);
	ofSetLineWidth(2);
	if (lineTop)
	{
		ofDrawLine(x,y,x+w,y);
	}
	if (lineBottom)
	{
		ofDrawLine(x,y+w,x+w,y+w);
	}
	if (lineLeft)
	{
		ofDrawLine(x,y,x,y+w);
	}
	if (lineRight)
	{
		ofDrawLine(x+w,y,x+w,y+w);
	}
}

int Cell::getIndex(int iii, int jjj, int cols, int rows) {
	if (iii<0 || jjj<0 || iii>cols-1 || jjj>rows-1)
	{
		return -1;
	}

	return iii + (jjj * cols);
}

Cell Cell::checkNeighbors(vector<Cell> grid, int cols, int rows) {
	Cell top(0,0,0,true,-5,true), bottom(0,0,0,true,-5,true), left(0,0,0,true,-5,true), right(0,0,0,true,-5,true);

	if (getIndex(i, j-1, cols, rows) >= 0)
	{
		top = grid[getIndex(i, j-1, cols, rows)];
	}
	if (getIndex(i, j+1, cols, rows) >= 0)
	{
		bottom = grid[getIndex(i, j+1, cols, rows)];
	}
	if (getIndex(i-1, j, cols, rows) >= 0)
	{
		left = grid[getIndex(i-1, j, cols, rows)];
	}
	if (getIndex(i+1, j, cols, rows) >= 0)
	{
		right = grid[getIndex(i+1, j, cols, rows)];
	}

	vector<Cell> neighbors = {};

	if (top.index >= 0 && top.fake == false && top.visited == false)
	{
		neighbors.push_back(top);
	}
	if (bottom.index >= 0 && bottom.fake == false && bottom.visited == false)
	{
		neighbors.push_back(bottom);
	}
	if (left.index >= 0 && left.fake == false && left.visited == false)
	{
		neighbors.push_back(left);
	}
	if (right.index >= 0 && right.fake == false && right.visited == false)
	{
		neighbors.push_back(right);
	}
	if (neighbors.size() > 0)
	{
		int r = ofRandom(0, neighbors.size());
		Cell poss = neighbors[r];

		return poss;
	} else {
		return Cell(0,0,0,true,-5);
	}
}

vector<Cell> Cell::removeWalls(int a, int b, vector<Cell> g) {
	int x = g[a].i - g[b].i;
	int y = g[a].j - g[b].j;

	if (x == 1)
	{
		g[a].lineLeft = false;
		g[b].lineRight = false;
	} else {
		if (x == -1)
		{
			g[a].lineRight = false;
			g[b].lineLeft = false;
		}
	}

	if (y == 1)
	{
		g[a].lineTop = false;
		g[b].lineBottom = false;
	} else {
		if (y == -1)
		{
			g[a].lineBottom = false;
			g[b].lineTop = false;
		}
	}

	return g;
}
