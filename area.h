#ifndef __AREA_H__
#define __AREA_H__

template<class T>
class Area
{
public:
	Area(T length, T width);
	~Area();
	T area();
private:
	T length_;
	T width_;
};

#include "area.cpp"

#endif