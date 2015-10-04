#include <iostream>
#include "pathfinding.h"
#include "maze.h"

int main()
{
	int width = 11;
	int height = 11;
	unsigned char *map = new unsigned char[width * height];
	Maze::PrimsAlgorithm(width, height, map);
	Maze::printToConsole(width, height, map);

	PathFinding::AStar(1, 1, 9, 9, *map, width, height);

	int a; std::cin >> a; // pause program

	return 0;
}