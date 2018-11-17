#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <cassert>
#include "ShaderUtilities.h"
#include "Triangle.h"
#include "Vec2.h"
#include "OpenGLDebug.h"
#include <sstream>


//#define ASSERT(x) if (!(x)) std::cin.ignore();
//#define GLCall(x) GLClearError();\
//	x;\
//	ASSERT(GLLogCall(#x, __FILE__, __LINE__))
//
//static void GLClearError()
//{
//	while (glGetError() != GL_NO_ERROR);
//}
//
//static bool GLLogCall(const char* function, const char* file, int line)
//{
//	while (GLenum error = glGetError())
//	{
//		std::cout << "OpenGL Error: " << "(" << error << "): " << function << " " << file << ":" << line << std::endl;
//		return false;
//	}
//	return true;
//}


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
	
	float positions[] =
	{
		-0.5, -0.5f,
		0.5f, -0.5f,
		0.5f,  0.5f,
		-0.5f,	0.5f
	};
	unsigned int indices[] =
	{
		0,1,2,
		2,3,0,
	};

	unsigned int vao;
	GLCall(glGenVertexArrays(1, &vao));
	GLCall(glBindVertexArray(vao));

	unsigned int buffer;
	GLCall(glGenBuffers(1, &buffer));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, buffer));
	GLCall(glBufferData(GL_ARRAY_BUFFER, 4 * 2 * sizeof(float), positions, GL_STATIC_DRAW));

	GLCall(glEnableVertexAttribArray(0));
	GLCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0));

	unsigned int ibo;
	GLCall(glGenBuffers(1, &ibo));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo));
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW));
	

	ShaderProgramSource source = ParseShader("Source/Shaders/BasicShader.shader");
	unsigned int shader = CreateShader(source.VertexSource, source.FragmentSource);
	//glUseProgram(shader);
	//
	int location = glGetUniformLocation(shader, "u_Color");
	//ASSERT(location != -1);
	//GLCall(glUniform4f(location, 0.5f, 0.5f, 0.5f, 1.0f));

	GLCall(glBindVertexArray(0));
	GLCall(glUseProgram(0));
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo));

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);
				
		GLCall(glUseProgram(shader));
		GLCall(glUniform4f(location, 1.0f, 1.0f, 0, 1.0f));		

		GLCall(glBindVertexArray(vao));
		GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo));
		
		GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glDeleteProgram(shader);
	glfwTerminate();
	return 0;
}