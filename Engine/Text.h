#pragma once
#include "Graphics.h"
#include "Rec.h"
#include "Vec2.h"
#include "Surface.h"
#include <string>
#include <sstream>

class Text
{
public:
	Text( const int Rows,const int Collums,Surface& font,Color chroma = Colors::Black )
		:
		font( font ),
		chroma( chroma ),
		CharWidth( font.getWidht() / Rows ),
		CharHeight( font.getHeight() / Collums )
	{
	}
	void DrawText( const std::string& text,const Vec2i& pos,Graphics& gfx ) const
	{
		int currletter = 0;
		for ( auto c : text )
		{
			gfx.DrawSprite( pos.x + currletter * CharWidth,pos.y,CharMaping( c ),font,chroma );
			++currletter;
		}
	}
	void DrawNumber( const int num,const Vec2i& pos,Graphics& gfx ) const
	{
		std::stringstream s_;
		s_ << num;
		DrawText( s_.str(),pos,gfx );
	}
private:
	RecI CharMaping( char c ) const
	{
		const char y = c / ( font.getWidht() / CharWidth );
		const char x = c % ( font.getWidht() / CharWidth );
		return RecI( x * CharWidth,( x + 1 ) * CharWidth,y * CharHeight,( y + 1 ) * CharHeight );
	}
private:
	Surface font;
	const Color chroma;
	const char CharHeight;
	const char CharWidth;
};