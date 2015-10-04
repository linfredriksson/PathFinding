#pragma once

namespace PathFinding
{
	bool AStar(int startX, int startY, int targetX, int targetY, const unsigned char &map,
		int mapWidth, int mapHeight, int *path, int pathLength);
};