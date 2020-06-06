#pragma once
#include "Vec2.h"

template<typename T>
class Rec_
{
public:
	Rec_() = default;
	Rec_( T left_in,T right_in,T top_in,T bottem_in )
		:
		left( left_in ),
		right( right_in ),
		top( top_in ),
		bottem( bottem_in )
	{
	}
	Rec_( const Vec2_<T>& topleft,const Vec2_<T>& bottemright )
		:
		Rec_( topleft.x,bottemright.x,topleft.y,bottemright.y )
	{
	}
	Rec_( const Vec2_<T>& topleft,T width,T height )
		:
		Rec_( topleft,topleft + Vec2f( width,height ) )
	{
	}
	template<typename I>
	Rec_( const Rec_<I>& rhs )
		:
		left( (T)left ),
		right( (T)right ),
		top( (T)top ),
		bottem( (T)bottem )
	{
	}
	bool isOverlappingWith( const Rec_& other ) const
	{
		return right > other.left && left < other.right
			&& bottem > other.top && top < other.bottem;
	}
	bool isOverlappingWith( const Vec2_<T>& other ) const
	{
		return right > other.x && left < other.x
			&& bottem > other.y && top < other.y;
	}
	Rec_ fromCenter( const Vec2_<T>& center,T width,T height )
	{
		const Vec2f half( width / 2.0f,height / 2.0f );
		return Rec_( center - half,center + half );
	}
	T getWidth() const
	{
		return right - left;
	}
	T getHeight() const
	{
		return bottem - top;
	}
public:
	T left;
	T right;
	T top;
	T bottem;
};

typedef Rec_<int> RecI;
typedef Rec_<float> RecF;
