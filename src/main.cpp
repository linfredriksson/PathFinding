#include <iostream>
#include "pathfinding.h"
#include "maze.h"

int main()
{
	int width = 7;
	int height = 5;
	unsigned char *map = new unsigned char[width * height];
	Maze::PrimsAlgorithm(width, height, map);
	Maze::printToConsole(width, height, map);

	int pathLength = 10;
	int *path = new int[pathLength];

	if (PathFinding::AStar(1, 1, width - 2, height - 2, *map, width, height, path, pathLength))
	{
		std::cout << "Path found : ";

		for (int i = 0; i < pathLength; ++i)
		{
			if (path[i] == -1) break;
			std::cout << path[i] << ", ";
		}
		std::cout << std::endl;
	}
	else
	{
		std::cout << "Path not found" << std::endl;
	}

	int a; std::cin >> a; // pause program

	return 0;
}