#pragma once
#include <SFML/Graphics.hpp>

template<class T>
void xuLyDoHong(std::vector<T>& khongGian, std::vector<sf::FloatRect>& khongGianHopGioiHan)
{
	std::vector<int> a;
	for (int i = 0; i < int(khongGian.size()); i++) {
		if (khongGian[i].hp < 1) {
			a.push_back(i);
		}
	}
	if (a.size() > 0) {
		for (int i = int(a.size()) - 1; i >= 0; i--) {
			khongGian.erase(khongGian.begin() + a[i]);
			khongGianHopGioiHan.erase(khongGianHopGioiHan.begin() + a[i]);
		}
	}
}