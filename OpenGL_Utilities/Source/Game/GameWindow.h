//#pragma once
//#include "Tests/Test.h"
//
//#include <GL/glew.h>
//
//
//enum GameState
//{
//	GAME_ACTIVE,
//	GAME_MENU,
//	GAME_WIN
//};
//
//class GameWindow : public Test::Test
//{
//public:
//	GameState State;
//	bool Keys[1024];
//
//	GameWindow(unsigned int width, unsigned int height);
//	~GameWindow();
//
//	void OnUpdate(float deltaTime) override;
//	void OnRender() override;
//	void OnImGuiRender() override;
//
//private:
//	unsigned int m_Width, m_Height;
//
//};