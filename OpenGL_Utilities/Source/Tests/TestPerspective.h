#pragma once
#include <memory>

#include "Tests/Test.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "VertexArray.h"
#include "Textures/Texture.h"


namespace Test
{
	class TestPerspective : public Test
	{
	public:
		TestPerspective();
		~TestPerspective();

		void OnUpdate(float deltaTime) override;
		void OnRender() override;
		void OnImGuiRender() override;

	private:
		std::unique_ptr<VertexArray> m_VAO;
		std::unique_ptr<VertexBuffer> m_VertexBuffer;
		std::unique_ptr<IndexBuffer> m_IndexBuffer;
		std::unique_ptr<Shader> m_Shader;
		std::unique_ptr<Texture> m_Texture;

		glm::mat4 m_Proj;
		glm::mat4 m_View;

		glm::vec3 m_Translation;
		float m_RotationAngle;
		glm::vec3 m_RotationAxis;
		glm::vec3 m_Scale;		
	};
}