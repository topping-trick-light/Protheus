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
#include <fstream>
#include <vector>

#include "Camera.h"
#include "Tile.h"
#include "Area.h"
#include "StringConverter.h"
#include "MapSection.h"
#include "Math.h"

// Build to replace TileMap

// Theory
/**
*	The world map is broken down into sections
*	Each section is defined according to the datafile
*	each sections has a active variable and will only update
*	if the section is active
*/
namespace Pro{
	namespace Scene{
		class Map : 
			public Component::Area
		{
		private:  
			std::vector<MapSection*> mapSections;
			std::vector<TileType> tileData; 

			bool loadLevelData(const std::string& file);
			bool loadLevelTileData(const std::string&file);
		public:
			Map();
			~Map();

			std::vector<MapSection*> getVisibleSections(Camera* cam);
			bool loadLevel(const std::string& file, const std::string& data);
			TileType* getTile(Math::Vector2);
			TileType* getTileType(unsigned int);
		};
	} 
}