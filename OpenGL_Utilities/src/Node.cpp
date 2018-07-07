#include "Node.h"
#include <iostream>


Node::Node(bool isWalkable, Vec2 worldPosition, Vei2 gridPosition) : isWalkable(isWalkable), worldPosition(worldPosition), gridPosition(gridPosition)
{}

Node::Node(const Node &source) : isWalkable(source.isWalkable), worldPosition(source.worldPosition), gridPosition(source.gridPosition)
{}

Node::Node(Node && donor) : isWalkable(donor.isWalkable), worldPosition(donor.worldPosition), gridPosition(donor.gridPosition)
{}

Node::~Node()
{
	std::cout << "Node destructor" << std::endl;
}

Node & Node::operator=(const Node & rhs)
{
	isWalkable = rhs.isWalkable;
	gridPosition = rhs.gridPosition;
	worldPosition = rhs.worldPosition;
	return *this;
}

Node & Node::operator=(Node && rhs)
{
	if (this != &rhs)
	{
		isWalkable = rhs.isWalkable;
		gridPosition = rhs.gridPosition;
		worldPosition = rhs.worldPosition;
		return *this;
	}
	return *this;
}

Vec2 Node::GetWorldPosition() const
{
	return worldPosition;
}

Vei2 Node::GetGridPosition() const
{
	return gridPosition;
}

void Node::SetWalkable(bool isWalkable)
{
	this->isWalkable = isWalkable;
}
