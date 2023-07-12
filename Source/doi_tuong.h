#pragma once
#include "Header.h"

class DoiTuong
{
public:
	int k1 = 0;
	bool phongTo = false;
	double Ox, Oy;
	int chieuRong, chieuCao;
	sf::Texture texture;
	sf::Sprite sprite;

	DoiTuong(double _Ox, double _Oy, int _chieuRong, int _chieuCao);
};
