#include <iostream>
#include <unordered_set>
#include <memory>
#include "Vec2.h"
#include "Grid.h"

void tololo(std::unordered_set<Vei2>&& a, std::unordered_set<Vei2>& b)
{
	b = std::move(a);
}

int main()
{

	Vei2 veis[6]{ Vei2(1,1), Vei2(2,2), Vei2(3,3), Vei2(4,4), Vei2(5,5), Vei2(6,6) };
	std::unordered_set<Vei2> unwalkable;
	for (auto& v : veis)
	{
		unwalkable.emplace(v);
	}
	//
	//{
	//	auto grid = std::make_unique<std::Grid>(Vei2(10, 10), unwalkable);
	//}
	std::unordered_set<Vei2> kupakabra;
	tololo(std::move(unwalkable), kupakabra);



	while (true);
	return 0;
}
