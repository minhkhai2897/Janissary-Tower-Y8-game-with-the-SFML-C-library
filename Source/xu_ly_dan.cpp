#include "xu_ly_dan.h"

void taoHinhDan(std::vector<Dan>& khongGian)
{
	for (int i = int(khongGian.size()) - 1; i >= 0; i--) {
		if (khongGian[i].daTaoHinh) {
			break;
		}
		else
		{
			if (khongGian[i].phanLoai == 1)
			{
				if (khongGian[i].nhanVat == 1) {
					taoHinh(khongGian[i], "anh/dan1_nv1.png");
				}
				else {
					taoHinh(khongGian[i], "anh/dan1_nv2.png");
				}
				khongGian[i].sprite.setOrigin(4, 5);
			}
			else if (khongGian[i].phanLoai == 2)
			{
				if (khongGian[i].nhanVat == 1) {
					taoHinh(khongGian[i], "anh/dan2_nv1.png");
				}
				else {
					taoHinh(khongGian[i], "anh/dan2_nv2.png");
				}
				khongGian[i].sprite.setOrigin(6, 8);
			}
			else
			{
				if (khongGian[i].nhanVat == 1) {
					taoHinh(khongGian[i], "anh/dan3_nv1.png");
				}
				else {
					taoHinh(khongGian[i], "anh/dan3_nv2.png");
				}
				khongGian[i].sprite.setOrigin(9, 8);
			}
			khongGian[i].sprite.setRotation(khongGian[i].goc);
			khongGian[i].daTaoHinh = true;
		}
	}
	for (Dan& i : khongGian) {
		i.sprite.setTexture(i.texture);
	}
}

void hanhDongDan(std::vector<Dan>& khongGianDan, std::vector<NhanVat>& khongGianNhanVat,
	             std::vector<sf::FloatRect>& khongGianHopGioiHanBanDau, std::vector<sf::FloatRect>& khongGianHopGioiHanGach1,
	             std::vector<sf::FloatRect>& khongGianHopGioiHanGach2, std::vector<sf::FloatRect>& khongGianHopGioiHanVatPham,
	             std::vector<Gach>& khongGianGach1, std::vector<Gach>& khongGianGach2, std::vector<VatPham>& khongGianVatPham)
{
	for (Dan& dan : khongGianDan) {
		dan.diChuyen();

		sf::FloatRect boundingBox = dan.sprite.getGlobalBounds();
		for (int i = 0; i < int(khongGianHopGioiHanBanDau.size()); i++) {
			if (boundingBox.intersects(khongGianHopGioiHanBanDau[i])) {
				dan.hp = 0;
				break;
			}
		}
		if (dan.nhanVat == 2) {
			for (int i = 0; i < int(khongGianHopGioiHanGach1.size()); i++) {
				if (boundingBox.intersects(khongGianHopGioiHanGach1[i]))
				{
					dan.hp = (dan.phanLoai == 3) ? (dan.hp - 1) : 0;
					khongGianGach1[i].hp = (dan.phanLoai == 1) ? khongGianGach1[i].hp - 1 : khongGianGach1[i].hp - 5;
					break;
				}
			}
		}
		else {
			for (int i = 0; i < int(khongGianHopGioiHanGach2.size()); i++) {
				if (boundingBox.intersects(khongGianHopGioiHanGach2[i]))
				{
					dan.hp = (dan.phanLoai == 3) ? (dan.hp - 1) : 0;
					khongGianGach2[i].hp = (dan.phanLoai == 1) ? khongGianGach2[i].hp - 1 : khongGianGach2[i].hp - 5;
					break;
				}
			}
		}
		for (int i = 0; i < int(khongGianHopGioiHanVatPham.size()); i++) {
			if (boundingBox.intersects(khongGianHopGioiHanVatPham[i]))
			{
				dan.hp = (dan.phanLoai == 3) ? (dan.hp - 1) : 0;
				khongGianVatPham[i].hp--;
				break;
			}
		}
		for (int i = 0; i < int(khongGianNhanVat.size()); i++) {
			if (dan.nhanVat != i + 1) {
				sf::FloatRect NV = khongGianNhanVat[i].sprite.getGlobalBounds();
				if (boundingBox.intersects(NV))
				{
					khongGianNhanVat[i].hp = (khongGianNhanVat[i].hp > 4) ? khongGianNhanVat[i].hp - 5 : 0;
					dan.hp = 0;
					break;
				}
			}
		}
	}
}

void xuLyDanHong(std::vector<Dan>& khongGian, std::vector<VuNo>& khongGianNo)
{
	std::vector<int> a;
	for (int i = 0; i < int(khongGian.size()); i++) {
		sf::Vector2f position = khongGian[i].sprite.getPosition();
		if (position.y < -1000) {
			khongGian[i].hp = 0;
		}
		if (khongGian[i].hp < 1) {
			a.push_back(i);
			sf::Vector2f position = khongGian[i].sprite.getPosition();
			VuNo no(position.x, position.y);
			khongGianNo.push_back(no);
		}
	}
	if (a.size() > 0) {
		for (int i = a.size() - 1; i >= 0; i--) {
			khongGian.erase(khongGian.begin() + a[i]);
		}
	}
}