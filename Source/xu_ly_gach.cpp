#include "xu_ly_gach.h"

void nhapHinhAnhGach(Gach& a, const std::string& path1, const std::string& path2, const std::string& path3)
{
	a.texture1.loadFromFile(path1);
	a.sprite1.setTexture(a.texture1);
	a.sprite1.setTextureRect(sf::IntRect(0, 0, a.chieuRong, a.chieuCao));
	a.sprite1.setPosition(a.Ox, a.Oy);

	a.texture2.loadFromFile(path2);
	a.sprite2.setTexture(a.texture2);
	a.sprite2.setTextureRect(sf::IntRect(0, 0, a.chieuRong, a.chieuCao));
	a.sprite2.setPosition(a.Ox, a.Oy);

	a.texture3.loadFromFile(path3);
	a.sprite3.setTexture(a.texture3);
	a.sprite3.setTextureRect(sf::IntRect(0, 0, a.chieuRong, a.chieuCao));
	a.sprite3.setPosition(a.Ox, a.Oy);
}

void taoHinhGach(std::vector<Gach>& khongGian, std::vector<sf::FloatRect>& khongGianHopGioiHan)
{
	for (int i = int(khongGianHopGioiHan.size()); i < int(khongGian.size()); i++)
	{
		if (khongGian[i].chieuRong == kichCoVienGach && khongGian[i].chieuCao == kichCoVienGach) {
			nhapHinhAnhGach(khongGian[i], "anh/gach_1x1_5hp.png", "anh/gach_1x1_10hp.png", "anh/gach_1x1_15hp.png");
		}
		else if (khongGian[i].chieuRong == kichCoVienGach && khongGian[i].chieuCao == 4 * kichCoVienGach) {
			nhapHinhAnhGach(khongGian[i], "anh/gach_4x1_20hp.png", "anh/gach_4x1_40hp.png", "anh/gach_4x1_60hp.png");
		}
		else if (khongGian[i].chieuRong == 4 * kichCoVienGach && khongGian[i].chieuCao == kichCoVienGach) {
			nhapHinhAnhGach(khongGian[i], "anh/gach_1x4_20hp.png", "anh/gach_1x4_40hp.png", "anh/gach_1x4_60hp.png");
		}

		sf::FloatRect boundingBox = khongGian[i].sprite1.getGlobalBounds();
		khongGianHopGioiHan.push_back(boundingBox);

		khongGian[i].daTaoHinh = true;
	}
	for (Gach& i : khongGian) {
		i.sprite1.setTexture(i.texture1);
		i.sprite2.setTexture(i.texture2);
		i.sprite3.setTexture(i.texture3);
	}
}
