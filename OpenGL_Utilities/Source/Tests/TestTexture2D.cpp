#pragma once

#include "TestTexture2D.h"
#include "TestTexture2D.h"
#include "TestClearColor.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <string>

#include "imgui/imgui.h"

#include "OpenGLDebug.h"


namespace Test
{
	TestTexture2D::TestTexture2D() 
		: m_TranslationA(200, 200, 0), m_TranslationB(400, 200, 0),
		m_Proj(glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f)),
		m_View(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0)))
	{
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

		std::string shaderPath = "Source/Shaders/BasicShader.shader";
		m_Shader = std::make_unique<Shader>(shaderPath);
		m_VAO = std::make_unique<VertexArray>();
		m_IndexBuffer = std::make_unique<IndexBuffer>(indices, 6);
		
		m_VertexBuffer = std::make_unique<VertexBuffer>(vertices, 4 * 4 * sizeof(float));
		VertexBufferLayout layout;
		layout.Push<float>(2);
		layout.Push<float>(2);
		m_VAO->AddBuffer(*m_VertexBuffer, layout);

		m_Shader->Bind();
		m_Shader->SetUniform4f("u_Color", 1.0f, 1.0f, 0, 1.0f);

		m_Texture = std::make_unique<Texture>("Source/Graphics/Textures/Linux.png");
		m_Texture->Bind();
		m_Shader->Bind();
		m_Shader->SetUniform1i("u_Texture", 0);

		m_VAO->Unbind();
		m_Shader->Unbind();
		m_VertexBuffer->Unbind();
		m_IndexBuffer->Unbind();
	}

	TestTexture2D::~TestTexture2D()
	{
	}

	void TestTexture2D::OnUpdate(float deltaTime)
	{
		
	}

	void TestTexture2D::OnRender()
	{
		GLCall(glClearColor(0, 0, 0, 0));
		GLCall(glClear(GL_COLOR_BUFFER_BIT));
		Renderer renderer;

		m_Texture->Bind();
		{	
			glm::mat4 model = glm::translate(glm::mat4(1.0f), m_TranslationA);
			glm::mat4 mvp = m_Proj * m_View * model;
			m_Shader->Bind();
			m_Shader->SetUniformMat4f("u_MVP", mvp);
			renderer.Draw(*m_VAO, *m_IndexBuffer, *m_Shader);
		}
		{
			glm::mat4 model = glm::translate(glm::mat4(1.0f), m_TranslationB);
			glm::mat4 mvp = m_Proj * m_View * model;
			m_Shader->Bind();
			m_Shader->SetUniformMat4f("u_MVP", mvp);
			renderer.Draw(*m_VAO, *m_IndexBuffer, *m_Shader);
		}
	}

	void TestTexture2D::OnImGuiRender()
	{
		ImGui::SliderFloat3("Translation A", &m_TranslationA.x, 0.0f, 960.0f);
		ImGui::SliderFloat3("Translation B", &m_TranslationB.x, 0.0f, 960.0f);
//		ImGui::Text("Application average %/3f ms/frame (%.1f FPS"), 1000.0f / ImGui::GetIO().Framerate));
	}
}