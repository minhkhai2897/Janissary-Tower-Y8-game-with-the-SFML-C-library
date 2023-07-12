#pragma once
#include "xu_ly_chung.h"
#include "tao_hinh.h"

void taoHinhVatPham(std::vector<VatPham>& khongGian, std::vector<sf::FloatRect>& khongGianHopGioiHan);

void roiVatPham(std::vector<VatPham>& khongGianVatPham, std::vector<sf::FloatRect>& khongGianHopGioiHanVatPham,
	            std::vector<sf::FloatRect>& khongGianHopGioiHanBanDau, std::vector<sf::FloatRect>& khongGianHopGioiHanGach1,
	            std::vector<sf::FloatRect>& khongGianHopGioiHanGach2, std::vector<sf::FloatRect>& khongGianHopGioiHanSung1,
	            std::vector<sf::FloatRect>& khongGianHopGioiHanSung2);
