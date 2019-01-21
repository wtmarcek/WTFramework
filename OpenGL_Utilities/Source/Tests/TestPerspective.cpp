#include "TestPerspective.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include "imgui/imgui.h"
#include "OpenGLDebug.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"


namespace Test
{
	TestPerspective::TestPerspective()		
		: m_Translation(200, 200, 0), m_Scale(1.0f, 1.0f, 1.0f),
		m_RotationAngle(45.0f), m_RotationAxis(0.0f, 0.0f, 1.0f),
		m_Proj(glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -960.0f, 1000.0f)),
		m_View(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, -3)))
	{
		//float vertices[] =
		//{
		//	-50.0f, -50.0f, 0.0f, 0.0f, 0.0f,		//0
		//	 50.0f, -50.0f, 0.0f, 1.0f, 0.0f,		//1
		//	 50.0f,  50.0f, 0.0f, 1.0f, 1.0f,		//2
		//	-50.0f,  50.0f, 0.0f, 0.0f, 1.0f 		//3
		//};

		//float vertices[] =
		//{
		//	-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,		//0
		//	 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,		//1
		//	 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,		//2
		//	-0.5f,  0.5f, 0.0f, 0.0f, 1.0f 		//3
		//};

		/*unsigned int indices[] =
		{
		0,1,2,
		2,3,0,
		};*/

		////////////////////////////////////////////////////////////////////////////
		float vertices[] =
		{
			// front
			-0.5, -0.5,  0.5, 0.0f, 0.0f,
			0.5, -0.5,  0.5, 1.0f, 0.0f,
			0.5,  0.5,  0.5, 1.0f, 1.0f,
			-0.5,  0.5,  0.5, 0.0f, 1.0f,
			// back
			-0.5, -0.5, -0.5, 0.0f, 0.0f,
			0.5, -0.5, -0.5,  1.0f, 0.0f,
			0.5,  0.5, -0.5,  1.0f, 1.0f,
			-0.5,  0.5, -0.5, 0.0f, 1.0f
		};
		unsigned int indices[] =
		{
			// front
			0, 1, 2,
			2, 3, 0,
			// right
			1, 5, 6,
			6, 2, 1,
			// back
			7, 6, 5,
			5, 4, 7,
			// left
			4, 0, 3,
			3, 7, 4,
			// bottom
			4, 5, 1,
			1, 0, 4,
			// top
			3, 2, 6,
			6, 7, 3,
		};


		GLCall(glEnable(GL_BLEND));
		GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

		m_IndexBuffer = std::make_unique<IndexBuffer>(indices, 6);

		m_VertexBuffer = std::make_unique<VertexBuffer>(vertices, 5 * 4 * sizeof(float));
		VertexBufferLayout layout;
		layout.Push<float>(3);
		layout.Push<float>(2);
		m_VAO = std::make_unique<VertexArray>();
		m_VAO->AddBuffer(*m_VertexBuffer, layout);

		std::string shaderPath = "Source/Shaders/BasicShader.shader";
		m_Shader = std::make_unique<Shader>(shaderPath);
		m_Shader->Bind();
		m_Shader->SetUniform4f("u_Color", 1.0f, 1.0f, 0, 1.0f);

		m_Texture = std::make_unique<Texture>("Source/Graphics/Textures/FallusTemple.png");
		m_Texture->Bind();
		m_Shader->Bind();
		m_Shader->SetUniform1i("u_Texture", 0);

		m_VAO->Unbind();
		m_Shader->Unbind();
		m_VertexBuffer->Unbind();
		m_IndexBuffer->Unbind();
	}
	
	TestPerspective::~TestPerspective()
	{
	}

	void TestPerspective::OnUpdate(float deltaTime)
	{
	}

	void TestPerspective::OnRender()
	{
		GLCall(glClearColor(0, 0, 0, 0));
		GLCall(glClear(GL_COLOR_BUFFER_BIT));
		Renderer renderer;

		m_Texture->Bind();
		{
			/*glm::mat4 translation = glm::translate(glm::mat4(1.0f), m_TranslationA);
			glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), glm::radians(m_RotationA), m_RotationAxisA);
			glm::mat4 scale = glm::scale(glm::mat4(1.0f), m_ScaleA);
			glm::mat4 model = translation * rotation * scale;
			glm::mat4 mvp = m_Proj * m_View * model;*/

			glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), glm::radians(-m_RotationAngle), glm::vec3(1.0f, 0.0f, 0.0f));
			glm::mat4 scale = glm::scale(glm::mat4(1.0f), m_Scale);
			glm::mat4 model = rotation * scale;
			//glm::mat4 projection = glm::ortho(-400.0f, 400.0f, -300.0f, 300.0f, -960.0f, 1000.0f);
			glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)800 / (float)600, 0.1f, 100.0f);

			glm::mat4 mvp = projection * m_View * model;


			//glm::mat4 model;
			//glm::mat4 view;
			//glm::mat4 projection;
			////model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
			//model = glm::translate(model, m_TranslationA);
			//view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
			////projection = glm::perspective(glm::radians(45.0f), (float)800 / (float)600, 0.1f, 100.0f);
			//projection = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f, -960.0f, 1000.0f);
			//
			//glm::mat4 mvp = projection * view * model;


			m_Shader->Bind();
			m_Shader->SetUniformMat4f("u_MVP", mvp);
			renderer.Draw(*m_VAO, *m_IndexBuffer, *m_Shader);
		}
		{
			//glm::mat4 model = glm::translate(glm::mat4(1.0f), m_TranslationB);
			//glm::mat4 mvp = m_Proj * m_View * model;
			//m_Shader->Bind();
			//m_Shader->SetUniformMat4f("u_MVP", mvp);
			//renderer.Draw(*m_VAO, *m_IndexBuffer, *m_Shader);
		}
	}

	void TestPerspective::OnImGuiRender()
	{
		//ImGui::SliderFloat3("Translation A", &m_TranslationA.x, -100.0f, 400.0f);
		ImGui::SliderFloat3("Scale A", &m_Scale.x, 0.1f, 10.0f);
		ImGui::SliderFloat("Rotation A", &m_RotationAngle, 0.0f, 360.0f);
		//ImGui::SliderFloat3("Axis A", &m_RotationAxisA.x, 0.0f, 1.0f);

		//ImGui::SliderFloat3("Translation B", &m_TranslationB.x, -100.0f, 400.0f);
		//ImGui::Text("Application average %/3f ms/frame (%.1f FPS"), 1000.0f / ImGui::GetIO().Framerate));
	}
}