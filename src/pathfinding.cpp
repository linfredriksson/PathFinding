#include "pathfinding.h"
#include <math.h>
#include <vector>
#include <algorithm>

namespace PathFinding
{
	namespace
	{
		struct Node
		{
			int x, y;
			float costG, costF, costH;
			int parent;

			inline bool operator < (const Node &rhs) { return costF > rhs.costF; }
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

		bool AStarStep(const unsigned char &	map, int mapWidth, int mapHeight,
			const Node &target, list &open, list &closed, list &path)
		{
			if (open.size() == 0)
				return false;

			std::sort(open.begin(), open.end());

			closed.push_back(open.back());
			open.pop_back();
			Node *currentNode = &closed.back();
			
			int neighbour[4][2] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
			for (int i = 0; i < 4; ++i)
			{
				int posX = (*currentNode).x + neighbour[i][0];
				int posY = (*currentNode).y + neighbour[i][1];

				// check if neighbour is out of bounds
				if (posX < 0 || posY < 0 || posX > mapWidth || posY > mapHeight)
					continue;

				// check if neighbour is a wall
				if ((&map)[posX + posY * mapWidth])
					continue;

				Node temp;
				initiateNode(temp, posX, posY, closed.size() - 1);

				// check if neighbour already is in the closed list
				if (std::find(closed.begin(), closed.end(), temp) != closed.end())
					continue;

				// check if neighbour already is in the open list
				auto it = std::find(open.begin(), open.end(), temp);

				if (it != open.end())
				{
					if (currentNode->costG + 10 < it->costG)
					{
						(*it).parent = closed.size() - 1;
						updateCostGF((*it), currentNode->costG);
					}
					continue;
				}

				open.push_back(temp);

				if (temp == target)
				{
					auto tmp = temp;
					while (tmp.parent != -1)
					{
						path.push_back(tmp);
						tmp = closed[tmp.parent];
					}

					return true;
				}
			}

			return AStarStep(map, mapWidth, mapHeight, target, open, closed, path);
		}
	}

	bool AStar(int startX, int startY, int targetX, int targetY, const unsigned char &map,
		int mapWidth, int mapHeight, int *path, int pathLength)
	{
		list open, closed, finalPath;
		int mapSize = mapWidth * mapHeight;
		int n = 0;
		
		Node target;
		initiateNode(target, targetX, targetY, -1);

		Node start;
		initiateNode(start, startX, startY, -1);
		updateCostGFH(start, 0.0f, target);
		open.push_back(start);

		bool result = AStarStep(map, mapWidth, mapHeight, target, open, closed, finalPath);

		if (result)
		{
			for (int i = 0; i < pathLength; ++i)
				path[i] = -1;

			if (pathLength < finalPath.size())
				return false;

			for (int i = 0; i < finalPath.size(); ++i)
				path[i] = finalPath[i].x + finalPath[i].y * mapWidth;

			return true;
		}
		else
		{
			return false;
		}
	}
};