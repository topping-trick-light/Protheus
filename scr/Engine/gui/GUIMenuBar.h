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

#include <vector>
#include "GUIDropDownMenu.h"
namespace Pro{
	namespace GUI{
		class GUIMenuBar :
			public GUIEntity
		{
			std::vector<GUIDropDownMenu> elements;
		public:
			GUIMenuBar(const std::string& name);
			GUIMenuBar();
			~GUIMenuBar();

			void attachMenu(GUIDropDownMenu* component);
			void update(std::vector<SDL_Event> events);

			// returns the Metatable's name assosiated with this object
			static string lGetMetatable(){
				return "gui_menubar_metatable";
			}
		};
	}
}