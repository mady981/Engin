#pragma once

#include "Graphics.h"

namespace SpriteEffect
{
	class Copy
	{
	public:
		void operator()( Color cSrc,int xDest,int yDest,Graphics& gfx ) const
		{
			gfx.PutPixel( xDest,yDest,cSrc );
		}
	};

	class Chroma
	{
	public:
		Chroma( Color c = Colors::Magenta )
			:
			chroma( c )
		{}
		void operator()( Color cSrc,int xDest,int yDest,Graphics& gfx ) const
		{
			if ( cSrc != chroma )
			{
				gfx.PutPixel( xDest,yDest,cSrc );
			}
		}
	private:
		Color chroma;
	};

	class Alpha
	{
	public:
		Alpha( float a,Color c = Colors::Magenta )
			:
			chroma( c ),
			alpha( a )
		{}
		void operator()( Color cSrc,int xDest,int yDest,Graphics& gfx ) const
		{
			if ( cSrc != chroma )
			{
				Color origin = gfx.getPixel( xDest,yDest );
				gfx.PutPixel( xDest,yDest,
					Color(
						unsigned char( ( cSrc.GetR() * alpha + origin.GetR() * ( 1 - alpha ) ) ),
						unsigned char( ( cSrc.GetG() * alpha + origin.GetG() * ( 1 - alpha ) ) ),
						unsigned char( ( cSrc.GetB() * alpha + origin.GetB() * ( 1 - alpha ) ) )
					)
				);
			}
		}
	private:
		Color chroma;
		float alpha;
	};

	class Substitution
	{
	public:
		Substitution( Color s,Color c = Colors::Magenta )
			:
			sub( s ),
			chroma( c )
		{}
		void operator()( Color cSrc,int xDest,int yDest,Graphics& gfx ) const
		{
			if ( cSrc != chroma )
			{
				gfx.PutPixel( xDest,yDest,sub );
			}
		}
	private:
		Color chroma;
		Color sub;
	};
}