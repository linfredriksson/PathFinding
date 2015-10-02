#include "pathfinding.h"

namespace PathFinding
{
	namespace
	{
		struct Node
		{
			int x, y;
			float costH, costG, costF;
			int parent;
		};

		void updateCost(Node &node, Node &parent)
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