#include "wtfpch.h"



class Action
{
public:
	Action();
	
	void AddAction(std::function<void()> action)
	{
		m_ActionsSet.emplace_back(action);
	}

	void RemoveAciton(std::function<void()> action)
	{
		for (auto it = m_ActionsSet.begin(); it != m_ActionsSet.end(); it++)
		{
			std::function<void()> a = *it;
			if(a == action)
		}
	}

private:
	std::vector <std::function<void()>> m_ActionsSet;
	
};





