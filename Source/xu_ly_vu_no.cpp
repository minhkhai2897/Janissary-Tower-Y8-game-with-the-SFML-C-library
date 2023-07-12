#include "xu_ly_vu_no.h"

void taoHinhVuNo(std::vector<VuNo>& khongGianNo)
{
	for (int i = int(khongGianNo.size()) - 1; i >= 0; i--) {
		if (khongGianNo[i].daTaoHinh) {
			break;
		}
		else {
			khongGianNo[i].sprite.setOrigin(14, 14);
			khongGianNo[i].sprite.setPosition(khongGianNo[i].Ox, khongGianNo[i].Oy);
			khongGianNo[i].texture.loadFromFile("anh/vu_no.png");
			khongGianNo[i].daTaoHinh = true;
		}
	}
}

void xuLyHinhAnhVuNo(std::vector<VuNo>& khongGianNo)
{
	const int maxDem = 4;
	std::vector<VuNo> khongGianNoTamThoi;
	for (int i = 0; i < int(khongGianNo.size()); i++) {
		khongGianNo[i].dem.first++;
		if (khongGianNo[i].dem.first != 4 * maxDem) {
			khongGianNoTamThoi.push_back(khongGianNo[i]);
		}
	}
	khongGianNo = khongGianNoTamThoi;
	for (int i = 0; i < int(khongGianNo.size()); i++) {
		xuLyTexture(khongGianNo[i], khongGianNo[i].texture, maxDem, 0, 0);
	}
}