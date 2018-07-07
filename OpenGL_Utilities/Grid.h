#pragma once

#include <utility>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <memory>
#include "Collider2D.h"
#include "Vec2.h"
#include "Node.h"

class Grid
{
public:
	struct UnwalkableArea
	{
	private:
		Vec2 center;
		float width;
		float height;
	public:
		UnwalkableArea(Vec2 center, float width, float height) : center(center), width(width), height(height)
		{}
	};

private:
	const Vec2 worldCenterPosition;
	const Vec2 worldGridSize;
	const Vec2 worldNodeSize;
	const std::unordered_set<Vei2>& unwalkableNodes;
	const std::unordered_map<Vec2, Vei2> worldToGridPos;
	std::vector<std::vector<std::unique_ptr<Node>>>nodes;
public:
	Grid(const Vec2 worldCenterPosition, const Vec2 worldGridSize, const Vec2 worldNodeSize, const std::vector<Collider2D> unwalkable);
	~Grid();

	void UpdateGrid(Vec2 unwalkable);
	std::vector<Node&> GetNeighbours(Node& target) const;
	Vei2 GetWorldToGridPosition(Vec2 worldPosition) const;
};