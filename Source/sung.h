#pragma once
#include "doi_tuong.h"

class Sung : public DoiTuong
{
public:
	int phanLoai;
	sf::Texture texture1;
	sf::Sprite sprite1;

	Sung(int _Ox, int _Oy, int _chieuRong, int _chieuCao, int _phanLoai);
};