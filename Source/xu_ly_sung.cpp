#include "xu_ly_sung.h"

void taoHinhSung(std::vector<Sung>& khongGian, std::vector<sf::FloatRect>& khongGianHopGioiHan)
{
	for (Sung& i : khongGian) {
		taoHinh(i, "anh/o_sung.png");
		sf::FloatRect boundingBox = i.sprite.getGlobalBounds();
		khongGianHopGioiHan.push_back(boundingBox);
	}

	for (Sung& sung : khongGian) {
		if (sung.phanLoai == 1) {
			sung.texture1.loadFromFile("anh/sung1.png");
			sung.sprite1.setTexture(sung.texture1);
			sung.sprite1.setOrigin(8, 35);
		}
		else if (sung.phanLoai == 2) {
			sung.texture1.loadFromFile("anh/sung2.png");
			sung.sprite1.setTexture(sung.texture1);
			sung.sprite1.setOrigin(9, 43);
		}
		else {
			sung.texture1.loadFromFile("anh/sung3.png");
			sung.sprite1.setTexture(sung.texture1);
			sung.sprite1.setOrigin(10, 36);
		}

		sung.sprite1.setPosition(sung.Ox + kichCoVienGach / 2, sung.Oy + kichCoVienGach / 2);
	}
}