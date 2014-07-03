/*************************************************************************
Protheus Source File.
Copyright (C), Protheus Studios, 2013-2014.
-------------------------------------------------------------------------

Description:

-------------------------------------------------------------------------
History:
- 20:05:2014: Waring J.
*************************************************************************/

#pragma once

#include <SDL.h>
#include <string>
 
#include "..\Math.h"
#include "..\component\CGUID.h"
#include "..\component\Area.h"
#include <SDL_render.h>

namespace Pro{
	namespace Asset{
		using namespace std;
		using namespace Math;

		class Sprite : 
			public Component::CGUID,
			public Component::Area
		{
		private: 
			Vector2 rect; 
			SDL_Texture* texture;
		public:
			Sprite(const string& name, Vector2& dimensions, SDL_Texture* tex);
			Sprite();
			~Sprite();
			  
			SDL_Texture* getTexture();
			
			 
			// returns the Metatable's name assosiated with this object
			static string lGetMetatable(){
				return "asset_sprite_metatable";
			}

			template<typename T>
			static void lGetFunctions(std::vector<luaL_Reg>& fields){
				//fields.push_back({ "push", &T::lPush });
			}
		};
	}
}