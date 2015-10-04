#include "pathfinding.h"
#include <math.h>
#include <vector>

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

		typedef std::vector<Node> list;

		void initiateNode(Node &node, int newX, int newY, int parent)
		{
			node.x = newX;
			node.y = newY;
			node.parent = parent;
			node.costG = node.costF = node.costH = 0.0f;
		}

		void updateCostGF(Node &node, float parentCostG)
		{
			node.costG = parentCostG != 0 ? parentCostG + 10.0f : 0.0f;
			node.costF = node.costH + node.costG;
		}

		void updateCostGFH(Node &node, float parentCostG, const Node &target)
		{
			node.costH = abs(node.x - target.x) + abs(node.y - target.y);
			updateCostGF(node, parentCostG);
		}

		void AStarStep(list &open, list &closed, list &path)
		{
			if (open.size() == 0)
				return;

			open.pop_back(); // tmp

			AStarStep(open, closed, path);
		}
	}

	void AStar(int startX, int startY, int targetX, int targetY, const unsigned char &map,
		int mapWidth, int mapHeight)
	{
		list open, closed, path;
		int mapSize = mapWidth * mapHeight;
		int n = 0;
		
		Node target;
		initiateNode(target, targetX, targetY, -1);

		Node start;
		initiateNode(start, startX, startY, -1);
		updateCostGFH(start, 0.0f, target);
		open.push_back(start);

		AStarStep(open, closed, path);
	}
};