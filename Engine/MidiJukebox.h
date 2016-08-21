#pragma once
#include "Midi.h"
#include <string>
#include <map>
#include <memory>

class MidiJukebox
{
public:
	void AddSong( const std::wstring& name,float start,float end,bool looping = true )
	{
		songPtrs.emplace( name,std::make_unique<MidiSong>( name,start,end,looping ) );
	}
	MidiSong& GetSong( const std::wstring& name )
	{
		return *songPtrs[name];
	}
private:
	std::map<std::wstring,std::unique_ptr<MidiSong>> songPtrs;
};