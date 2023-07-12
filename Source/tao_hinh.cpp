#pragma once
#include <string>
#include <SFML/Graphics.hpp>

template<class T>
void taoHinh(T& a, const std::string& path)
{
	a.texture.loadFromFile(path);
	a.sprite.setTexture(a.texture);
	a.sprite.setTextureRect(sf::IntRect(0, 0, a.chieuRong, a.chieuCao));
	a.sprite.setPosition(a.Ox, a.Oy);
}