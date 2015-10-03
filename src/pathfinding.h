#pragma once

namespace PathFinding
{
	void AStar(int startX, int startY, int targetX, int targetY, const unsigned char &map,
		int mapWidth, int mapHeight);
};