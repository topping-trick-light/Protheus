#pragma once
#include "Scene.h"
#include "Renderer.h"
#include "Timer.h" 
#include "Network.h"
#include "GUIDLookup.h"
#include "Window.h"
#include "SpriteManager.h" 
#include "EventHandeler.h"

namespace Pro{ 
	class Core
	{
		Scene::Scene* scene;
		Networking::Network* network;
		Graphics::Renderer* renderer;
		Window* window;
		Timer* timer;
		Graphics::SpriteManager* sprite_manager;
		EventHandeler* event_handeler;

		bool running = false;

		bool update();
		bool render();
	public: 
		// Core functions 
		Core::Core();
		  
		bool loadSpriteSheet(const std::string &path, const std::string &data);
		bool loadSpriteAnimations(const std::string& path);
		bool loadScene(const std::string &path, const std::string& data);

		// x : position X, y : position Y
		// w : width, h : height
		void setWindowDimensions(SDL_Rect rect);
		// Sets the name of the window
		void setWindowTitle(const std::string& name);
		/* Runs the loop once and stops,
		   for user modification of the map */
		void run();

		// Change window details before Starting the engine
		bool start();
		bool cleanup();

		// Game Functions

		void addEntity(GameObject::Entity* entity);
		void removeEntity(GameObject::Entity entity);
		std::unordered_map<GUID, GameObject::Entity*>* getEntities();
		GameObject::Entity* getEntity(uint32 _id);

		// Network Functions

		Networking::TCPConnection* netStartServer();
		Networking::TCPConnection* netConnectToServer(const std::string &IP);

		// returns the amount of bytes recieved
		unsigned int netRecv(Networking::TCPConnection*, void *buffer);
		// returns the amount of bytes recieved without clearing the buffer
		unsigned int netPeek(Networking::TCPConnection*);
		// sends the buffer through the connection
		void netSend(Networking::TCPConnection* connection, void* buffer, unsigned int bufferSize);
		/* sends the buffer through the connection and deletes the buffer  */
		void netSendd(Networking::TCPConnection* connection, void* buffer, unsigned int bufferSize);

		// Resource Functions
		 
		Asset::AnimatedSprite*	getSpriteAnimations(const std::string& name);

		// Event Functions

		std::vector<SDL_Event>* pollKeyEvents();
		std::vector<SDL_Event>* pollMouseEvents();
		std::vector<SDL_Event>* pollSystemEvents();
		std::vector<SDL_Event>* pollUserEvents();

		// Map Functions

		
		Scene::TileType* getMapTile(unsigned int x, unsigned int y);
		std::vector<GameObject::Entity*> pollMapTile(unsigned int x, unsigned int y);
		std::vector<GameObject::Entity*> pollMapTile(SDL_Rect pos);
		void setActiveCamera(const std::string& name);
		Scene::Camera* getActiveCamera();
		Scene::Camera* getCamera(const std::string& name);
		void addCamera(Scene::Camera*);
		 
		static int lUpdate(lua_State*);
	}; 
}