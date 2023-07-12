#pragma once
#include "doi_tuong.h"

class Gach : public DoiTuong
{
public:
	int hp = 15;
	bool daTaoHinh = false;

	sf::Texture texture1;
	sf::Texture texture2;
	sf::Texture texture3;
	sf::Sprite sprite1;
	sf::Sprite sprite2;
	sf::Sprite sprite3;

	Gach(int _Ox, int _Oy, int _chieuRong = kichCoVienGach, int _chieuCao = kichCoVienGach);
};