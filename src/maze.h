#pragma once

namespace Maze
{
	// Maze based on Prim's algorithm. For more information please follow the link.
	// https://en.wikipedia.org/wiki/Maze_generation_algorithm
	void PrimsAlgorithm(int sizeX, int sizeY, unsigned char *maze);

	// Random "maze" where wall elements are randomly placed. The larger the fillRate
	// the more walls will be placed.
	void Random(int sizeX, int sizeY, float fillRate, unsigned char *maze);

	void printToConsole(int sizeX, int sizeY, unsigned char *maze);
};