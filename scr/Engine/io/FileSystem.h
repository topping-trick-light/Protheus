/*************************************************************************
Protheus Source File.
Copyright (C), Protheus Studios, 2013-2014.
-------------------------------------------------------------------------

Description:
	Handles all File Operations for platform independance,
	All path's are relative to the set RootDir which is relative
	to the executable unless defined as an absolute path.
-------------------------------------------------------------------------
History:
- 27:05:2014: Waring J.
*************************************************************************/

#pragma once

#include "CFile.h" 
#include <string>

namespace Pro{
	namespace Util{
		class FileSystem
		{
			std::string rootDir; 
		public:
			FileSystem();
			~FileSystem();

			/*  Opens a file relative to the root directory */
			CFile openFile(const std::string& path);
			/*  Sets the root directory */
			void setRootDir(const std::string& dir);
			/*  Returns a reference to the root directory */
			std::string& getRootDir();
		};
	}
}