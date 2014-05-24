#include "Renderer.h"

namespace Pro{
	namespace Graphics{  
		 
		Renderer::Renderer(){

		}

		Renderer::Renderer(lua_State* lua_state){
			SDL_Window* w = Util::luaP_registerget<SDL_Window>(lua_state, "SDL_WINDOW");
			renderer = SDL_CreateRenderer(w, -1,
				SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (renderer == nullptr)
				return;
			Util::luaP_registerstore(lua_state, "SDL_RENDERER", renderer);
			sprite_batcher = new SpriteBatcher(lua_state); 
		}

		Renderer::~Renderer()
		{
			delete sprite_batcher;
		} 

		SDL_Renderer* Renderer::getRenderer(){
			return renderer;
		}

		void Renderer::renderScene(Scene::Scene* scene, SpriteManager* spriteMng){
			// Get data 
			Scene::Map* map = scene->getMap(); 
			//SDL_Point* cameraPos = scene->getActiveCamera()->getPosition();

			//std::unordered_map<GUID, GameObject::Entity*>* entities = scene->getEntities();

			// Render the Map, only sections visible to the camera

			auto sections = map->getVisibleSections(scene->getActiveCamera());

			// render the tiles

			int x(0), y(0);

			for each(const auto& section in sections){
				for each(const auto& col in section->getData()){
					if (col[0] == '\r')
						continue;
					for each(const auto& row in col){
						Scene::TileType* tile = map->getTileType(row - 48);
						// check if textured
						if (!tile->isTextured)
							continue;
						// populate the sprite pointer
						if (static_cast<Asset::Sprite*>(tile->spriteCache) == nullptr)
							tile->spriteCache = spriteMng->getSprite(tile->spriteName);

						Math::Vector4 spriteRect = static_cast<Asset::Sprite*>(tile->spriteCache)->getRect();
						spriteRect.x *= spriteRect.z;
						spriteRect.y *= spriteRect.w;
						sprite_batcher->push(static_cast<Asset::Sprite*>(tile->spriteCache), spriteRect);
						y++;
					}
					x++;
					y = 0;
				}
				x = 0;
			}

			// render entities 
			//GameObject::AnimatedEntity* aeCache;
			//GameObject::SpriteEntity* seCache;
			//for each(auto kv in *entities){
			//	// check if animated
			//	aeCache = dynamic_cast<GameObject::AnimatedEntity*>(kv.second);
			//	if (aeCache != nullptr){ 
			//		sprite_batcher->push(aeCache->activeAnimation->getFrame(), aeCache->getPositionRect());
			//		aeCache->activeAnimation->nextFrame();
			//		continue;
			//	}
			//	// check if has sprite
			//	seCache = dynamic_cast<GameObject::SpriteEntity*>(kv.second);
			//	if (seCache != nullptr){
			//		sprite_batcher->push(spriteMng->getSprite(seCache->getSpriteName()), seCache->getPositionRect());
			//		continue;
			//	}
			//	continue;
			//}
			// calls the batcher to render all sprites

			sprite_batcher->flush();
		}

		
	}
}