#include "maze.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

namespace Maze
{
	// Helpter functions.
	namespace
	{
		// Recursively generate the maze.
		void PrimsAlgorithmStep(int x, int y, int directionX, int directionY, int sizeX, int sizeY, unsigned char *maze)
		{
			x = x + directionX * 2;
			y = y + directionY * 2;

			if (x < 1 || x > sizeX - 2 || y < 1 || y > sizeY - 2 || maze[x + y * sizeX] == 0)
				return;

			maze[x + y * sizeX] = 0;
			maze[x - directionX + (y - directionY) * sizeX] = 0;

			int randomDirection = rand() % 4;

			for (int i = 0; i < 4; ++i)
			{
				++randomDirection;
				randomDirection %= 4;

				int newDirectionX = 0;
				int newDirectionY = 0;
				newDirectionY = (randomDirection == 0) ? -1 : newDirectionY;
				newDirectionY = (randomDirection == 1) ? 1 : newDirectionY;
				newDirectionX = (randomDirection == 2) ? 1 : newDirectionX;
				newDirectionX = (randomDirection == 3) ? -1 : newDirectionX;

				PrimsAlgorithmStep(x, y, newDirectionX, newDirectionY, sizeX, sizeY, maze);
			}
		}

		// Fill maze with one value
		void Fill(int sizeX, int sizeY, int value, unsigned char *maze)
		{
			for (int i = 0; i < sizeX * sizeY; ++i)
				maze[i] = value;
		}
	}

	void PrimsAlgorithm(int sizeX, int sizeY, unsigned char *maze)
	{
		srand(time(NULL));
		Fill(sizeX, sizeY, 1, maze);
		PrimsAlgorithmStep(1, 1, 0, 0, sizeX, sizeY, maze);
	}

	void Random(int sizeX, int sizeY, float fillRate, unsigned char *maze)
	{
		for (int i = 0; i < sizeX * sizeY; ++i)
			maze[i] = (rand() % 1000 * 0.001 < fillRate) ? 1 : 0;
	}

	void printToConsole(int sizeX, int sizeY, unsigned char *maze)
	{
		for (int y = 0; y < sizeY; ++y)
		{
			for (int x = 0; x < sizeX; ++x)
				maze[x + y * sizeX] ? printf("#") : printf(" ");
			printf("\n");
		}
	}
};