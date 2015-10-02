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
		};

		void initiateNode(Node &node, int newX, int newY, int parent)
		{
			node.x = newX;
			node.y = newY;
			node.parent = parent;
			node.costG = node.costF = node.costH = 0.0f;
		}

		void updateCostGFH(Node &node, const Node &parent, const Node &goal)
		{
			node.costH = abs(node.x - goal.x) + abs(node.y - goal.y);
			updateCostGF(node, parent);
		}

		void updateCostGF(Node &node, const Node &parent)
		{
			node.costG = parent.costG != 0 ? parent.costG + 10.0f : 0.0f;
			node.costF = node.costH + node.costG;
		}

		void AstarStep()
		{

		}
	}

	void AStar()
	{

	}
};