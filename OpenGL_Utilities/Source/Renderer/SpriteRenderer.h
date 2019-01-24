#pragma once
#include "Renderer.h"
#include "Camera.h"
#include "Textures/Texture.h"
#include "SceneObjects/Transform.h"

class SpriteRenderer : public Renderer
{
public:
	SpriteRenderer(const Camera& camera, Texture& texture, Shader& shader, const Transform& transform);
	~SpriteRenderer();
	
	void Draw();
	void Clear() const override;

private:
	std::unique_ptr<VertexArray> m_VAO;
	std::unique_ptr<VertexBuffer> m_VertexBuffer;
	std::unique_ptr<IndexBuffer> m_IndexBuffer;
	
	//std::unique_ptr<glm::mat4> m_Model;

	const Transform& m_Transform;
	const Texture& m_Texture;
	const Camera& m_Camera;
	Shader& m_Shader;
};