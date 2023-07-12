#pragma once
#include "add.h"
#include "gach.h"
#include "nhan_vat.h"
#include "sung.h"
#include "vat_pham.h"
#include "tao_hinh.h"

void khoiTaoManChoi(std::vector<DoiTuong>& khongGianBanDau, std::vector<Gach>& khongGianGach1,
	std::vector<Gach>& khongGianGach2, std::vector<NhanVat>& khongGianNhanVat,
	std::vector<Sung>& khongGianSung1, std::vector<Sung>& khongGianSung2,
	std::vector<VatPham>& khongGianVatPham, const int& STT);

void khoiTaoKhongGianMini(std::vector<DoiTuong>& khongGianMini);

void taoHinhBanDau(std::vector<DoiTuong>& khongGian, std::vector<sf::FloatRect>& khongGianHopGioiHan);

void taoHinhKhongGianMini(std::vector<DoiTuong>& khongGianMini);
