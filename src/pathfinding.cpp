#include "pathfinding.h"

namespace PathFinding
{
	namespace
	{
		struct Node
		{
			int x, y, id;
			float costH, costG, costF;
			int parent;
		};
	}

	void AStar();
};