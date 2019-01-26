#pragma once
#include <GLFW\glfw3.h>

class GameManager {
public:
	static float s_DeltaTime;
	static GameManager *GetInstance()
	{
		if (!instance)
			instance = new GameManager;
		return instance;
	}
	
	void Tick() 
	{
		 
	}

private:
	static GameManager *instance;
	
	GameManager()
	{

	}
};


