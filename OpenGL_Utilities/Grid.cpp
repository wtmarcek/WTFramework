#include <iostream>
#include "Grid.h"

//std::Grid::Grid(const Vei2 resolution, const unordered_set<Vei2>& unwalkableNodes) : resolution(resolution)
//{
//	int debug = 0;
//
//	int width = resolution.x;
//	int height = resolution.y;
//	nodes.reserve(width);
//	for (int x = 0; x < width; x++)
//	{	
//		nodes.emplace_back();
//		nodes[x].reserve(height);
//		for (int y = 0; y < height; y++)
//		{
//			Vei2 gridPos = Vei2(x, y);
//			auto iter = unwalkableNodes.find(v);
//			if (iter != unwalkableNodes.end())
//			{
//				nodes[x].emplace_back(make_unique<Node>(true, v));
//			}
//			else
//			{
//				nodes[x].emplace_back(make_unique<Node>(false, v));
//			}
//			debug++;
//		}
//	}	
//	cout << "Nodes created: " << debug << endl;
//}
//
//Grid::Grid(const Vec2 worldCenterPosition, const Vec2 worldGridSize, const Vec2 worldNodeSize, const std::vector<Collider2D> unwalkable)
//	: worldCenterPosition(worldCenterPosition), worldGridSize(worldGridSize), worldNodeSize(worldNodeSize), unwalkableNodes(std::move(unwalkableNodes))
//{
//	Vec2 leftUpperNodePos = Vec2(
//		worldCenterPosition.x - (worldGridSize.x / 2.0f) + (worldNodeSize.x/2.0f), 
//		worldCenterPosition.y + (worldGridSize.y / 2.0f) - (worldNodeSize.y/2.0f));
//	int width = (int)(worldGridSize.x / worldNodeSize.x);
//	int height = (int)(worldGridSize.y / worldNodeSize.y);
//	nodes.reserve(width);
//	for (int x = 0; x < width; x++)
//	{
//		nodes.emplace_back();
//		nodes[x].reserve(height);
//		for (int y = 0; y < height; y++)
//		{
//			//IMPLEMENT UNWALKABLE NODES
//		}
//	}
//
//
//
//	//int width = resolution.x;
//	//int height = resolution.y;
//	nodes.reserve(width);
//	for (int x = 0; x < width; x++)
//	{	
//		nodes.emplace_back();
//		nodes[x].reserve(height);
//		for (int y = 0; y < height; y++)
//		{
//			Vei2 gridPos = Vei2(x, y);
//			auto iter = unwalkableNodes.find(v);
//			if (iter != unwalkableNodes.end())
//			{
//				nodes[x].emplace_back(make_unique<Node>(true, v));
//			}
//			else
//			{
//				nodes[x].emplace_back(make_unique<Node>(false, v));
//			}
//			debug++;
//		}
//	}	
//}

Grid::~Grid()
{
	for (auto& w : nodes)
	{
		for (auto h = w.begin(); h != w.end(); h++)
		{
			h->reset();
		}
	}
}


//std::vector<Node&> std::Grid::GetNeighbours(Node& target)
//{
//	Vei2 targetPos = target.GetGridPosition();
//
//	nodes[targetPos.x][targetPos.y]
//
//
//	return vector<Node&>();
//}


