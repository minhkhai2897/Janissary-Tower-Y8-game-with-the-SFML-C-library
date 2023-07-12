#include "xu_ly_khi_cau.h"

void taoHinhKhiCau(KhiCau& khiCau)
{
	khiCau.texture.loadFromFile("anh/khi_cau.png");
	khiCau.sprite.setTexture(khiCau.texture);
	khiCau.sprite.setPosition(khiCau.Ox, khiCau.Oy);
}

void hanhDongKhiCau(KhiCau& a, std::vector<VatPham>& khongGianVatPham)
{
	if (int(khongGianVatPham.size()) < 20)
	{
		sf::Vector2f position = a.sprite.getPosition();
		if ((RONG / 2 <= position.x) && (position.x < RONG / 2 + a.tocDoDiChuyen)) {
			srand(time(NULL));
			a.loaiQua = rand() % 4 + 1;
			int m = (RONG - 2 * kichCoVienGach - a.chieuRong) / 2;
			a.thaQua = kichCoVienGach + (rand() % 2) * m + rand() % m + 1;
		}

		if ((a.thaQua <= position.x) && (position.x < a.thaQua + a.tocDoDiChuyen) && (a.k == -1)) {
			a.k = 0;
		}

		if (a.k == -1)
		{
			a.diChuyen();
		}
		else if (a.k == 0)
		{
			if (a.loaiQua == 1) {
				VatPham b(position.x + 51, int(position.y) / 4 * 4 + 10, 22, 20, a.loaiQua);
				khongGianVatPham.push_back(b);
			}
			else {
				VatPham b(position.x + 48, int(position.y) / 4 * 4 + 10, kichCoVienGach, kichCoVienGach, a.loaiQua);
				khongGianVatPham.push_back(b);
			}
			a.sprite.scale(1, 1.1);
			a.thaQua = -1;
			a.k++;
		}
		else if (a.k == 15)
		{
			a.sprite.scale(1, 1.0 * 10 / 11);
			a.k = -1;
		}
		else {
			a.k++;
		}
	}
	else {
		a.diChuyen();
	}
}