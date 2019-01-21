#pragma once

#pragma region Includes
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <cassert>
#include <sstream>

#include "Triangle.h"
#include "Vec2.h"
#include "OpenGLDebug.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shaders/Shader.h"
#include "Renderer/Renderer.h"
#include "Textures/Texture.h"

#include "Tests/Test.h"
#include "Tests/TestClearColor.h"
#include "Tests/TestTexture2D.h"
#include "Tests/TestPerspective.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw_gl3.h"

#pragma endregion


int main(void)
{

	#pragma region GLFW initialization

	GLFWwindow* window;
	
	/* Initialize the library */
	if (!glfwInit())
		return -1;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(800, 600, "Mea Kupa", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	if (glewInit() != GLEW_OK)
	{
		std::cout << "#ERROR: glewInit() != GLEW_OK" << std::endl;
	}
	std::cout << glGetString(GL_VERSION) << std::endl;

	glfwSwapInterval(1);

	#pragma endregion


	{	
		#pragma region Start			
		Renderer renderer;
		#pragma endregion
		

		#pragma region ImGUI Initialization
		ImGui::CreateContext();
		ImGui_ImplGlfwGL3_Init(window, true);
		ImGui::StyleColorsDark();
		#pragma endregion
		
		#pragma region  Tests setup
		Test::Test* currentTest = nullptr;
		Test::TestMenu* testMenu = new Test::TestMenu(currentTest);
		currentTest = testMenu;

		testMenu->RegisterTest<Test::TestClearColor>("Clear Color");
		testMenu->RegisterTest<Test::TestTexture2D>("Texture 2D");
		testMenu->RegisterTest<Test::TestPerspective>("Perspective");
		#pragma endregion


		#pragma region Main Loop
		while (!glfwWindowShouldClose(window))
		{
			renderer.Clear();
			
			ImGui_ImplGlfwGL3_NewFrame();
			if (currentTest)
			{
				currentTest->OnUpdate(0.0f);
				currentTest->OnRender();
				ImGui::Begin("Test");
				if (currentTest != testMenu && ImGui::Button("<-"))
				{
					delete currentTest;
					currentTest = testMenu;
				}
				currentTest->OnImGuiRender();
				ImGui::End();
			}
			ImGui::Render();
			ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());

			glfwSwapBuffers(window);
			glfwPollEvents();
		}
		#pragma endregion
	}

	ImGui_ImplGlfwGL3_Shutdown();
	ImGui::DestroyContext();
	glfwTerminate();
	return 0;
}