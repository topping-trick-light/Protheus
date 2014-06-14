/*************************************************************************
Protheus Source File.
Copyright (C), Protheus Studios, 2013-2014.
-------------------------------------------------------------------------

Description:

-------------------------------------------------------------------------
History:
- 21:05:2014: Waring J.
*************************************************************************/

#pragma once

#include <unordered_map>
#include "..\gameobject\Scene.h" 
#include "..\util\LuaUtils.h"

namespace Pro{
	using namespace GameObject;
	class SceneContainer
	{
	protected:
		std::unordered_map<uint32, Scene*> stored_scenes;
		Scene* active_scene = nullptr;
	public:
		SceneContainer(){}
		~SceneContainer(){}

		void addScene(Scene*); 
		Scene* getScene(uint32);
		Scene* getActiveScene(); 
		void setActiveScene(uint32);
		void destoryScene(uint32); 
		 
		static int lAddScene(lua_State*);
		static int lSetActiveScene(lua_State*);
		static int lGetActiveScene(lua_State*);
		static int lGetScene(lua_State*);
		static int lDestoryScene(lua_State*);
	}; 
}

