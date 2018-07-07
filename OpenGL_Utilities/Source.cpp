#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "ShaderUtilities.h"
#include "Triangle.h"
#include "Vec2.h"

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;


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

	Vec2 vers[3] = { Vec2(-1.0f, -1.0f), Vec2(0.0f, -1.0f), Vec2(0.0f, 0.0f) };
	Triangle tris({ 1,1 }, vers);
	tris.Draw();

	Vec2 vers1[3] = { Vec2(-0.5f, 1.0f), Vec2(0.0f, -1.0f), Vec2(0.0f, 0.0f) };
	Triangle tris1({ 1,1 }, vers1);
	tris1.Draw();

	ShaderProgramSource source = ParseShader("src/Shaders/Basic.shader");
	unsigned int shader = CreateShader(source.VertexSource, source.FragmentSource);
	glUseProgram(shader);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);
				
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glDeleteProgram(shader);
	glfwTerminate();
	return 0;
}