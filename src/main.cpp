#include <iostream>
#include "pathfinding.h"
#include "maze.h"

int main()
{
	int width = 51;
	int height = 11;
	unsigned char *map = new unsigned char[width * height];
	Maze::PrimsAlgorithm(width, height, map);

	int maxPathLength = 1000;
	int *path = new int[maxPathLength];
	int pathLength = PathFinding::AStar(1, 1, width - 2, height - 2, *map, width, height, path, maxPathLength);
	if (pathLength != -1)
	{
		for (int i = 0; i < width * height; ++i)
		{
			bool isPath = false;
			for (int j = 0; j < pathLength; ++j)
				if (i == path[j])
					isPath = true;

			map[i] ? printf("#") : isPath ? printf(".") : printf(" ");
			(i + 1) % width == 0 ? printf("\n") : printf("");
		}
	}
	else
	{
		Maze::printToConsole(width, height, map);
	}

	int a; std::cin >> a; // pause program

	return 0;
}