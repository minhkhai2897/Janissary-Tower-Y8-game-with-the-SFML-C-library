#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "gach.h"

void nhapHinhAnhGach(Gach& a, const std::string& path1, const std::string& path2, const std::string& path3);

void taoHinhGach(std::vector<Gach>& khongGian, std::vector<sf::FloatRect>& khongGianHopGioiHan);

