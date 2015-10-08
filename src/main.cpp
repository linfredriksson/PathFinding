#include <iostream>
#include <time.h>
#include "pathfinding.h"
#include "maze.h"

int main()
{
	int size[2] = {51, 11};
	int start[2] = {1, 1};
	int goal[2] = {size[0] - 2, size[1] - 2};
	int maxPathLength = 1000;
	int *path = new int[maxPathLength];
	unsigned char *map = new unsigned char[size[0] * size[1]];
	Maze::PrimsAlgorithm(size[0], size[1], map);
	//Maze::Random(size[0], size[1], 0.1, map);

	int time0 = clock();
	int pathLength = PathFinding::AStar(start[0], start[1], goal[0], goal[1], *map,
		size[0], size[1], path, maxPathLength);
	int time1 = clock();
	printf("time: %f seconds\n", (time1 * 0.001 - time0 * 0.001));

	if (pathLength != -1)
	{
		printf("Path length: %d\n", pathLength);
		for (int i = 0; i < pathLength; ++i)
			printf("%d, ", path[i]);
		printf("\n");

		for (int i = 0; i < size[0] * size[1]; ++i)
		{
			bool isPath = false;
			for (int j = 0; j < pathLength; ++j)
				if (i == path[j])
					isPath = true;

			map[i] ? printf("#") : isPath ? printf(".") : printf(" ");
			(i + 1) % size[0] == 0 ? printf("\n") : printf("");
		}
	}
	else
	{
		printf("No path found\n");
		Maze::printToConsole(size[0], size[1], map);
	}

	int a; std::cin >> a; // pause program

	return 0;
}