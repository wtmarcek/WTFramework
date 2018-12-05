#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "imgui/imgui.h"
#include "Renderer/OpenGLDebug.h"
#include "TestClearColor.h"

namespace Test
{
	TestClearColor::TestClearColor()
		: m_Color{1.0f, 1.0f, 0.0f, 1.0f}
	{
	}


	TestClearColor::~TestClearColor()
	{
	}

	void TestClearColor::OnUpdate(float deltaTime)
	{
	}

	void TestClearColor::OnRender()
	{
		GLCall(glClearColor(m_Color[0], m_Color[1], m_Color[2], m_Color[3]));
		GLCall(glClear(GL_COLOR_BUFFER_BIT));
	}

	void TestClearColor::OnImGuiRender()
	{
		ImGui::ColorEdit4("Clear Color", m_Color);
	}
}