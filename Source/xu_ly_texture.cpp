#pragma once
#include "Header.h"

template<class T>
void xuLyTexture(T& a, const sf::Texture& texture, const int& maxDem, const int& t1, const int& t2)
{
	sf::Vector2u b = texture.getSize();
	int n = int(b.x) / int(b.y);
	int k = (a.dem.first / maxDem) % n;
	a.dem.first = a.dem.first % (maxDem * n);
	a.sprite.setTexture(texture);
	a.sprite.setTextureRect(sf::IntRect(t1 + int(b.y) * k, t2, a.chieuRong, a.chieuCao));
}