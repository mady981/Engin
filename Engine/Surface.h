#pragma once
#include "Colors.h"
#include "Rec.h"
#include <string>
#include <vector>

class Surface
{
public:
	Surface() = default;
	Surface( const std::wstring& filename );
	Surface( int width,int height );
	void PutPixel( int x,int y,Color c );
	Color GetPixel( int x,int y ) const;
	int getWidht() const;
	int getHeight() const;
	RecI GetRect() const;
	void Fill( Color c );
	const Color* Data() const;
private:
	std::vector<Color> pixels;
	int width = 0;
	int height = 0;
};
