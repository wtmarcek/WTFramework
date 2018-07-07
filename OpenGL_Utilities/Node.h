#pragma once

#include "Vec2.h"
#include <memory>

class Node
{
public:
private:
	Vec2 worldPosition;
	Vei2 gridPosition;
	int hCost;
	int gCost;
	int fCost;
	bool isWalkable;


public:
	//IMPLEMENT RULE OF 5 !!!!!!!! CONSIDER RULE OF 0
	Node() = default;
	Node(bool isWalkable, Vec2 worldPosition, Vei2 gridPosition);
	Node(const Node&);
	Node(Node&&);
	~Node();
	Node& operator = (const Node& rhs);
	Node& operator = (Node&& rhs);

	Vec2 GetWorldPosition() const;
	Vei2 GetGridPosition() const;

	void SetWalkable(bool isWalkable);
};
