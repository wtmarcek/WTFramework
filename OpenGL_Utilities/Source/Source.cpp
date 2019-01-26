#pragma once


#include "Tests/TestClearColor.h"
#include "Tests/TestTexture2D.h"
#include "Tests/TestPerspective.h"
#include "Game/GameWindow.h"

#include "Scene/Scene.h"
#include "SceneObjects\ThrowingObject.h"
#include "SceneObjects\PlayerObject.h"

#include "Physics/Physics.h"
#include "Physics\BoxCollider.h"




Physics* Physics::s_Instance = 0;


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
	window = glfwCreateWindow(720, 720, "Mea Kupa", NULL, NULL);
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
		Renderer renderer;
		Physics *physics = physics->GetInstance();
		#pragma endregion
		

		#pragma region ImGUI Initialization
		ImGui::CreateContext();
		ImGui_ImplGlfwGL3_Init(window, true);
		ImGui::StyleColorsDark();
		#pragma endregion
		
		#pragma region  Tests setup
		//Test::Test* currentTest = nullptr;
		//Test::TestMenu* testMenu = new Test::TestMenu(currentTest);
		//currentTest = testMenu;
		//
		//testMenu->RegisterTest<Test::TestClearColor>("Clear Color");
		//testMenu->RegisterTest<Test::TestTexture2D>("Texture 2D");
		//testMenu->RegisterTest<Test::TestPerspective>("Perspective");
		//testMenu->RegisterTest<GameWindow>("Game");
		#pragma endregion

#pragma region DebugCene
		std::unique_ptr<Scene> mainScene = std::make_unique<Scene>();
		
		std::unique_ptr<Shader> shader = std::make_unique<Shader>("Source/Shaders/BasicShader.shader");
		std::unique_ptr<Texture> texture = std::make_unique<Texture>("Source/Graphics/Textures/Linux.png");
		std::unique_ptr<Texture> fallus = std::make_unique<Texture>("Source/Graphics/Textures/FallusTemple.png");
		const Camera& mainCamera = *(mainScene->GetCamera());

		//SCENE_OBJECT
		std::unique_ptr<SceneObject> debugObject = 
			std::make_unique<SceneObject>(mainCamera, *fallus, *shader, CollisionLayer::PickUp);
		debugObject->GetTransform().SetPosition(glm::vec3(-10.0f, -10.0f, -10.0f));
		debugObject->GetTransform().SetScale(glm::vec3(30.0f, 30.0f, 30.0f));
		mainScene->AddSceneObject(debugObject.get());

		//THROWING_OBJECT
		//std::unique_ptr<ThrowingObject> throwingObj =
		//	std::make_unique<ThrowingObject>(mainCamera, *texture, *shader, CollisionLayer::Damage);
		//throwingObj->GetTransform().SetScale(glm::vec3(20.0f, 20.0f, 20.0f));
		//throwingObj->GetTransform().SetRotation(glm::vec3(0.0f, 50.0f, 0.0f));
		//mainScene->AddSceneObject(throwingObj.get());
		//throwingObj->SetForce(glm::vec3(1.0f, 0.0f, 0.0f));

		//PLAYER_OBJECT
		std::unique_ptr<PlayerObject> playerObj =
			std::make_unique<PlayerObject>(mainCamera, *texture, *shader, CollisionLayer::Player, window);
		playerObj->GetTransform().SetScale(glm::vec3(20.0f, 20.0f, 20.0f));
		playerObj->GetTransform().SetRotation(glm::vec3(0.0f, 0.0f, 0.0f));
		mainScene->AddSceneObject(playerObj.get());
#pragma endregion

		float timeSinceSceneStarted = 0;

#pragma region Main Loop
		while (!glfwWindowShouldClose(window))
		{
			renderer.Clear();			
			ImGui_ImplGlfwGL3_NewFrame();		

			if (mainScene != nullptr)
			{
				float deltaTime = (float)glfwGetTime() - timeSinceSceneStarted;
				mainScene->OnTick(deltaTime);				
				timeSinceSceneStarted = glfwGetTime();

				mainScene->OnRender();	

				std::cout << "dt: " << glfwGetTime() - timeSinceSceneStarted
					<< "|| started: " << timeSinceSceneStarted
					<< "glfw: " << glfwGetTime() << std::endl;
			}
			//if (currentTest)
			//{
			//	currentTest->OnUpdate(0.0f);
			//	currentTest->OnRender();
			//	ImGui::Begin("Test");
			//	if (currentTest != testMenu && ImGui::Button("<-"))
			//	{
			//		delete currentTest;
			//		currentTest = testMenu;
			//	}
			//	currentTest->OnImGuiRender();
			//	ImGui::End();
			//}
			ImGui::Render();
			ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());

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