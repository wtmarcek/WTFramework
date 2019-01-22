#pragma once

#pragma region Includes
#include"wtfpch.h"

#include "Tests/TestClearColor.h"
#include "Tests/TestTexture2D.h"
#include "Tests/TestPerspective.h"
#include "Game/GameWindow.h"




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
		testMenu->RegisterTest<GameWindow>("Game");
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