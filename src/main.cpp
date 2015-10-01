#include <iostream>
#include "astar.h"
#include "maze.h"

int main()
{
	int width = 4;
	int height = 3;
	unsigned char *map = new unsigned char[width * height];
	Maze::PrimsAlgorithm(width, height, map);
	Maze::printToConsole(width, height, map);

	return 0;
}