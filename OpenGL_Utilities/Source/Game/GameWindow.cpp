#include "GameWindow.h"


GameWindow::GameWindow()
{
	m_Shader = std::make_unique<Shader>("Source/Shaders/BasicShader.shader");
	m_Texture = std::make_unique<Texture>("Source/Graphics/Textures/Linux.png");

	m_SpriteRenderer = std::make_unique<SpriteRenderer>(*m_Texture, *m_Shader);
}

GameWindow::~GameWindow()
{

}

void GameWindow::OnUpdate(float deltaTime)
{
}

void GameWindow::OnRender()
{
	m_SpriteRenderer->Draw();
}

void GameWindow::OnImGuiRender()
{
}


