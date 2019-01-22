#include "wtfpch.h"

#include "SpriteRenderer.h"


SpriteRenderer::SpriteRenderer(const Texture & texture, Shader & shader)
	: m_Texture(texture), m_Shader(shader)
{
	float vertices[] =
	{
		-50.0f, -50.0f, 0.0f, 0.0f, 0.0f,		//0
		 50.0f, -50.0f, 0.0f, 1.0f, 0.0f,		//1
		 50.0f,  50.0f, 0.0f, 1.0f, 1.0f,		//2
		-50.0f,  50.0f, 0.0f, 0.0f, 1.0f 		//3
	};

	unsigned int indices[] =
	{
		0,1,2,
		2,3,0
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

	m_Shader.Bind();
	m_Shader.SetUniform4f("u_Color", 1.0f, 1.0f, 0.0f, 1.0f);
	m_Shader.SetUniform1i("u_Texture", 0);


	m_Proj = std::make_unique<glm::mat4>(glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -0.0f, 100.0f));
	m_View = std::make_unique<glm::mat4>(glm::mat4(1.0f));
	glm::vec3 modelPos(100.0f, 100.0f, 0.0f);
	m_Model = std::make_unique<glm::mat4>(glm::translate(glm::mat4(1.0f), modelPos));
}

SpriteRenderer::~SpriteRenderer()
{
}

void SpriteRenderer::Draw()
{
	glm::mat4 mvp = *m_Proj * *m_View * *m_Model;

	m_Texture.Bind();
	m_Shader.Bind();
	m_Shader.SetUniformMat4f("u_MVP", mvp);
	
	Renderer::Draw(*m_VAO, *m_IndexBuffer, m_Shader);
}

void SpriteRenderer::Clear() const
{
	Renderer::Clear();
}
