/*************************************************************************
Protheus Source File.
Copyright (C), Protheus Studios, 2013-2014.
-------------------------------------------------------------------------

Description:
A class with the functionality of compining multiple tracks and their
effects to produce the output stream for the audio device

-------------------------------------------------------------------------
History:
- 09:06:2014 Waring J.
*************************************************************************/
#pragma once

#include <atomic>
#include <thread>
#include "CAudioBuffer.h"
#include "CAudioSignal.h"

namespace Pro{
	namespace Audio{
		using namespace std;

		class CAudioMixer
		{
			CAudioBuffer* m_output_stream;
			atomic<bool> m_stream_ready;
			atomic<bool> m_stream_refill;
			vector<CAudioSignal> m_signals;
			void process_stream(CAudioBuffer* stream, vector<CAudioSignal>* signals);
			thread m_stream_processor;
		public:
			CAudioMixer();
			~CAudioMixer();
			CAudioBuffer* getStream();
			bool isStreamReady();
			void refillStream();
			void playTrack(CAudioSignal);
			// Will create a signal from the track
			void playTrack(CAudioTrack);
			void pause();
			void resume();
			void stop();

			// LUA Functions

			static inline string lGetMetatable(){
				return "audio_mixer_metatable";
			}

			template<typename T>
			static inline void lGetFunctions(std::vector<luaL_Reg>& fields){
				//fields.push_back({ "update", &T::lUpdate });
			}
		};
	}
}
