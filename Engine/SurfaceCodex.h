#pragma once
#include "Surface.h"
#include <string>
#include <map>

class SurfaceCodex
{
public:
	static Surface* Retrive( const std::wstring& key )
	{
		return get_().Retrive_( key );
	}
	static void Purge()
	{
		get_().Purge_();
	}
	static void Delete( const std::wstring& key )
	{
		get_().Delete_( key );
	}
private:
	SurfaceCodex() = default;
	~SurfaceCodex()
	{
		for ( auto& e : Entrys )
		{
			delete e.second;
		}
	}
private:
	Surface* Retrive_( const std::wstring& key )
	{
		const auto i = Entrys.find( key );
		if ( i == Entrys.end() )
		{
			Surface* p = new Surface( key );
			Entrys.emplace( key,p );
			return p;
		}
		return i->second;
	}
	void Purge_()
	{
		for ( auto& e : Entrys )
		{
			delete e.second;
		}
		Entrys.clear();
	}
	void Delete_( const std::wstring& key )
	{
		delete Entrys.find( key )->second;
		Entrys.erase( key );
	}
public:
	static SurfaceCodex& get_()
	{
		static SurfaceCodex codex;
		return codex;
	}
private:
	std::map<std::wstring,Surface*> Entrys;
};