#pragma once
#include "wtfpch.h"

#include <memory>

#include "Tests/Test.h"
#include "Shader.h"
#include "Textures/Texture.h"
#include "Shaders/Shader.h"
#include "Renderer/SpriteRenderer.h"



class GameWindow : public Test::Test
{
public:
	GameWindow();
	~GameWindow();

	void OnUpdate(float deltaTime) override;
	void OnRender() override;
	void OnImGuiRender() override;

private:
	unsigned int m_Width;
	unsigned int m_Height;
	std::unique_ptr<Shader> m_Shader;
	std::unique_ptr<Texture> m_Texture;
	//std::unique_ptr<SpriteRenderer> m_SpriteRenderer;
};