#ifdef __AREA_H__

template<class T>
Area<T>::Area(T length, T width)
: length_(length), width_(width)
{
}

template<class T>
Area<T>::~Area()
{
}

template<class T>
T Area<T>::area()
{
	return length_ * width_;
}

#endif