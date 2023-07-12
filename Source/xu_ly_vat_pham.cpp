#include "xu_ly_vat_pham.h"

void taoHinhVatPham(std::vector<VatPham>& khongGian, std::vector<sf::FloatRect>& khongGianHopGioiHan)
{
	for (int i = int(khongGianHopGioiHan.size()); i < int(khongGian.size()); i++)
	{
		switch (khongGian[i].phanLoai) {
		case 1:
			taoHinh(khongGian[i], "anh/vat_pham1.png");
			break;
		case 2:
			taoHinh(khongGian[i], "anh/vat_pham2.png");
			break;
		case 3:
			taoHinh(khongGian[i], "anh/vat_pham3.png");
			break;
		default:
			taoHinh(khongGian[i], "anh/vat_pham4.png");
		}
		sf::FloatRect boundingBox = khongGian[i].sprite.getGlobalBounds();
		khongGianHopGioiHan.push_back(boundingBox);

		khongGian[i].daTaoHinh = true;
	}
	for (VatPham& i : khongGian) {
		i.sprite.setTexture(i.texture);
	}
}

void roiVatPham(std::vector<VatPham>& khongGianVatPham, std::vector<sf::FloatRect>& khongGianHopGioiHanVatPham,
	            std::vector<sf::FloatRect>& khongGianHopGioiHanBanDau, std::vector<sf::FloatRect>& khongGianHopGioiHanGach1,
	            std::vector<sf::FloatRect>& khongGianHopGioiHanGach2, std::vector<sf::FloatRect>& khongGianHopGioiHanSung1,
	            std::vector<sf::FloatRect>& khongGianHopGioiHanSung2)
{
	std::vector<sf::FloatRect> khongGianHopGioiHanVatPhamTamThoi;

	for (VatPham& vatPham : khongGianVatPham) {
		sf::Vector2f position = vatPham.sprite.getPosition();
		sf::Vector2f diem1 = sf::Vector2f(position.x + 1, position.y + vatPham.chieuCao + 0.0001);
		sf::Vector2f diem2 = sf::Vector2f(position.x + vatPham.chieuRong - 1, position.y + vatPham.chieuCao + 0.0001);

		bool roi = true;
		if (roi)
			kiemTraDiemTrongHopGioiHan(roi, diem1, khongGianHopGioiHanVatPham);
		if (roi)
			kiemTraDiemTrongHopGioiHan(roi, diem1, khongGianHopGioiHanBanDau);
		if (roi)
			kiemTraDiemTrongHopGioiHan(roi, diem1, khongGianHopGioiHanGach1);
		if (roi)
			kiemTraDiemTrongHopGioiHan(roi, diem1, khongGianHopGioiHanGach2);
		if (roi)
			kiemTraDiemTrongHopGioiHan(roi, diem1, khongGianHopGioiHanSung1);
		if (roi)
			kiemTraDiemTrongHopGioiHan(roi, diem1, khongGianHopGioiHanSung2);

		if (roi)
			kiemTraDiemTrongHopGioiHan(roi, diem2, khongGianHopGioiHanVatPham);
		if (roi)
			kiemTraDiemTrongHopGioiHan(roi, diem2, khongGianHopGioiHanBanDau);
		if (roi)
			kiemTraDiemTrongHopGioiHan(roi, diem2, khongGianHopGioiHanGach1);
		if (roi)
			kiemTraDiemTrongHopGioiHan(roi, diem2, khongGianHopGioiHanGach2);
		if (roi)
			kiemTraDiemTrongHopGioiHan(roi, diem2, khongGianHopGioiHanSung1);
		if (roi)
			kiemTraDiemTrongHopGioiHan(roi, diem2, khongGianHopGioiHanSung2);

		if (roi) {
			vatPham.sprite.move(0, vatPham.tocDoRoi);
		}

		sf::FloatRect boundingBox = vatPham.sprite.getGlobalBounds();
		khongGianHopGioiHanVatPhamTamThoi.push_back(boundingBox);
	}
	khongGianHopGioiHanVatPham = khongGianHopGioiHanVatPhamTamThoi;
}

