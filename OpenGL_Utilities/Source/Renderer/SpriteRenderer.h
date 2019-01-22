#pragma once

class SpriteRenderer : Renderer
{
public:
	SpriteRenderer(const Texture& texture, Shader& shader);
	~SpriteRenderer();
	
	void Draw();
	void Clear() const override;

private:
	std::unique_ptr<VertexArray> m_VAO;
	std::unique_ptr<VertexBuffer> m_VertexBuffer;
	std::unique_ptr<IndexBuffer> m_IndexBuffer;
	
	std::unique_ptr<glm::mat4> m_Proj;
	std::unique_ptr<glm::mat4> m_View;
	std::unique_ptr<glm::mat4> m_Model;

	const Texture& m_Texture;
	Shader& m_Shader;
};