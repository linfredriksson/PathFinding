#include "pathfinding.h"
#include <math.h>

namespace PathFinding
{
	namespace
	{
		struct Node
		{
			int x, y;
			float costG, costF, costH;
			int parent;

			inline bool operator < (const Node &rhs) { return costF < rhs.costF; }
			inline bool operator == (const Node &rhs) { return x == rhs.x && y == rhs.y; }
		};

		void initiateNode(Node &node, int newX, int newY, int parent)
		{
			node.x = newX;
			node.y = newY;
			node.parent = parent;
			node.costG = node.costF = node.costH = 0.0f;
		}

		void updateCostGF(Node &node, const Node &parent)
		{
			node.costG = parent.costG != 0 ? parent.costG + 10.0f : 0.0f;
			node.costF = node.costH + node.costG;
		}

		void updateCostGFH(Node &node, const Node &parent, const Node &target)
		{
			node.costH = abs(node.x - target.x) + abs(node.y - target.y);
			updateCostGF(node, parent);
		}

		void AstarStep()
		{

		}
	}

	void AStar(int startX, int startY, int targetX, int targetY, const unsigned char &map,
		int mapWidth, int mapHeight)
	{
		int mapSize = mapWidth * mapHeight, n = 0;
		while (n < mapSize)
		{

		}
	}
};