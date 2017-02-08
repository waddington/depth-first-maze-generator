/*
 * Cell.h
 *
 *  Created on: 19 Dec 2016
 *      Author: kai-w
 */

#ifndef SRC_CELL_H_
#define SRC_CELL_H_

#include <vector>

class Cell {
public:
	Cell(int ii, int jj, int ww, bool faked, int indexx);
	Cell(int ii, int jj, int ww, bool faked, int indexx, bool visd);
	virtual ~Cell();

	void show();
	Cell checkNeighbors(vector<Cell> grid, int cols, int rows);
	int getIndex(int iii, int jjj, int cols, int rows);
	vector<Cell> removeWalls(int a, int b, vector<Cell>);

	bool lineTop = true;
	bool lineBottom = true;
	bool lineLeft = true;
	bool lineRight = true;
	bool visited = false;
	bool fake = false;
	int index;
	bool current;
	bool counted = false;
	bool solutionCell = false;
	bool startCell = false;
	bool endCell = false;
	int i;
	int j;

private:

	int w;
};

#endif /* SRC_CELL_H_ */
