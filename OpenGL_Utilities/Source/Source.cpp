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
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw_gl3.h"

#include "Tests/TestClearColor.h"
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
	window = glfwCreateWindow(960, 540, "Mea Kupa", NULL, NULL);
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
		
		float vertices[] =
		{
			-50.0f, -50.0f, 0.0f, 0.0f,		//0
			 50.0f, -50.0f, 1.0f, 0.0f,		//1
			 50.0f,  50.0f, 1.0f, 1.0f,		//2
			-50.0f,  50.0f, 0.0f, 1.0f 		//3
		};

		unsigned int indices[] =
		{
			0,1,2,
			2,3,0,
		};
		
		GLCall(glEnable(GL_BLEND));
		GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

		VertexArray va;
		VertexBuffer vb(vertices, 4 * 4 * sizeof(float));
		VertexBufferLayout layout;
		layout.Push<float>(2);
		layout.Push<float>(2);
		va.AddBuffer(vb, layout);

		IndexBuffer ib(indices, 6);
		unsigned int ibo;

		std::string shaderName = "Source/Shaders/BasicShader.shader";
		Shader shader(shaderName);		
		shader.Bind();
		shader.SetUniform4f("u_Color", 1.0f, 1.0f, 0, 1.0f);	

		Texture texture("Source/Graphics/Textures/Linux.png");
		texture.Bind();
		shader.SetUniform1i("u_Texture", 0);

		va.Unbind();
		shader.Unbind();
		vb.Unbind();
		ib.Unbind();

		Renderer renderer;

		#pragma endregion
		
		#pragma region ImGUI Initialization

		ImGui::CreateContext();
		ImGui_ImplGlfwGL3_Init(window, true);
		ImGui::StyleColorsDark();

		bool show_demo_window = true;
		bool show_another_window = false;
		ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

		#pragma endregion

		Test::TestClearColor test;

		#pragma region Main Loop
		/* Loop until the user closes the window */
		while (!glfwWindowShouldClose(window))
		{
			renderer.Clear();
			
			test.OnUpdate(0.0f);
			test.OnRender();

			ImGui_ImplGlfwGL3_NewFrame();
			test.OnImGuiRender();
			ImGui::Render();


			//glm::vec3 translation = glm::vec3(0.0f, 0.0f, 0.0f);
			//ImGui::SliderFloat3("Translation", &translation.x, 0.0f, 960.0f);
			//
			//glm::mat4 proj = glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f);
			//glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));
			//glm::mat4 model = glm::translate(glm::mat4(1.0f), translation);
			//
			//float rad = glm::radians(35.0f);
			////model = glm::rotate(model, rad, glm::vec3(0.0f, 0.0f, 1.0f));
			//
			//glm::mat4 mvp = proj * view * model;
			//
			//shader.Bind();
			//shader.SetUniformMat4f("u_MVP", mvp);

			#pragma region ImGUI Example
			//static float f = 0.0f;
			//static int counter = 0;
			//ImGui::Text("Hello, world!");                           // Display some text (you can use a format string too)
			//ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f    
			//ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color
			//
			//ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our windows open/close state
			//ImGui::Checkbox("Another Window", &show_another_window);
			//
			//if (ImGui::Button("Button"))                            // Buttons return true when clicked (NB: most widgets return true when edited/activated)
			//	counter++;
			//ImGui::SameLine();
			//ImGui::Text("counter = %d", counter);
			//
			//ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
			#pragma endregion

			ImGui::Render();
			ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());

			vb.Bind();
			renderer.Draw(va, ib, shader);

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