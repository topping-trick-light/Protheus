/*************************************************************************
Protheus Source File.
Copyright (C), Protheus Studios, 2013-2014.
-------------------------------------------------------------------------

Description:
A extern class to provide writing functions to a buffer

-------------------------------------------------------------------------
History:
- 1:06:2014: Waring J.
*************************************************************************/
#pragma once

#include "BufferIO.h"

#include "classDefinition.h"

namespace Pro{
	namespace Util{
		using namespace Serializer;

		class BufferWriter :
			public BufferIO
		{
		public:
			BufferWriter(CBuffer* buffer);
			~BufferWriter();

			// writes a value to the buffer at the writer,
			// of the size specified
			void write(void* value, unsigned size);
			  
			template<typename T>
			void inline write(T& data){ 
				write(&data, sizeof(T));
			}

			template<typename T>
			void inline write(T&& data){
				// Not sure about the behavior for r values
				// because this is a Universal Reference.
				write(&data, sizeof(T));
			}

			// Writes the array into the buffer, size in bytes
			template<typename T>
			void inline write_array(T* data, unsigned size){
				write((void*)data, size);
			}

			// writes the amount of elements in an array
			template<typename T>
			void inline write_elements(T* data, unsigned elements){
				write((void*) data, elements * sizeof(T));
			}

			template<typename T>
			void serialized_write(classDefinition def, T* data){
				const auto members = def.getMembers();

				// Write the amount of members in the extern class
				write<unsigned short>(members.size());

				// Write each member
				for each(const auto member in members){
					write_array<char>(member.name, 32);

					// Pointer to the data member we want
					const auto member_pointer =
						static_cast<char*>(data)+
						member.offset;

					// Write the size of the member
					write<unsigned>(member.size);
					// Write the data of the member
					write(member_pointer, member.size);
				}
			}
			 
		};
	}
}
