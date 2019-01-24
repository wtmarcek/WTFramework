#pragma once

#include "wtfpch.h"

class Quad
{
	Quad();
	~Quad();

private:
	std::vector<float> m_Vertices;
	std::vector<unsigned int> m_Indices;
};