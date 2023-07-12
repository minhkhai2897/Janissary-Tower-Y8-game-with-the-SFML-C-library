#pragma once
#include <SFML/Graphics.hpp>
#include "dan.h"
#include "nhan_vat.h"
#include "gach.h"
#include "vu_no.h"
#include "vat_pham.h"
#include "tao_hinh.h"

void taoHinhDan(std::vector<Dan>& khongGian);

void hanhDongDan(std::vector<Dan>& khongGianDan, std::vector<NhanVat>& khongGianNhanVat,
	             std::vector<sf::FloatRect>& khongGianHopGioiHanBanDau, std::vector<sf::FloatRect>& khongGianHopGioiHanGach1,
	             std::vector<sf::FloatRect>& khongGianHopGioiHanGach2, std::vector<sf::FloatRect>& khongGianHopGioiHanVatPham,
	             std::vector<Gach>& khongGianGach1, std::vector<Gach>& khongGianGach2, std::vector<VatPham>& khongGianVatPham);

void xuLyDanHong(std::vector<Dan>& khongGian, std::vector<VuNo>& khongGianNo);
