#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <cassert>
#include <sstream>"
#include "Triangle.h"
#include "Vec2.h"
#include "OpenGLDebug.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shaders/Shader.h"
#include "Renderer/Renderer.h"
#include "Textures/Texture.h"


int main(void)
{
	GLFWwindow* window;
	
	/* Initialize the library */
	if (!glfwInit())
		return -1;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Mea Kupa", NULL, NULL);
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

	{
		float positions[] =
		{
			-0.5f, -0.5f, 0.0f, 0.0f,	//0
			 0.5f, -0.5f, 1.0f, 0.0f,	//1
			 0.5f,  0.5f, 1.0f, 1.0f,	//2
			-0.5f,	0.5f, 0.0f, 1.0f 	//3
		};
		unsigned int indices[] =
		{
			0,1,2,
			2,3,0,
		};
		
		VertexArray va;
		VertexBuffer vb(positions, 4 * 4 * sizeof(float));
		VertexBufferLayout layout;
		layout.Push<float>(2);
		va.AddBuffer(vb, layout);

		IndexBuffer ib(indices, 6);
		unsigned int ibo;

		std::string shaderName = "Source/Shaders/BasicShader.shader";
		Shader shader(shaderName);
		shader.Bind();
		shader.SetUniform4f("u_Color", 1.0f, 1.0f, 0, 1.0f);			

		//TODO: nie wczytuje siê texa
		Texture texture("Graphics/Textures/FallusTemple.png");
		texture.Bind();
		shader.SetUniform1i("u_Texture", 0);

		va.Unbind();
		shader.Unbind();
		vb.Unbind();
		ib.Unbind();

		Renderer renderer;

		/* Loop until the user closes the window */
		while (!glfwWindowShouldClose(window))
		{
			/* Render here */
			renderer.Clear();
			
			vb.Bind();
			renderer.Draw(va, ib, shader);

			/* Swap front and back buffers */
			glfwSwapBuffers(window);

			/* Poll for and process events */
			glfwPollEvents();
		}
	}

	glfwTerminate();
	return 0;
}