#include "khi_cau.h"

KhiCau::KhiCau(double _Ox, double _Oy, int _chieuRong, int _chieuCao)
	: DoiTuong(_Ox, _Oy, _chieuRong, _chieuCao)
{
}

void KhiCau::diChuyen()
{
	sf::Vector2f position = sprite.getPosition();

	if ((position.x <= kichCoVienGach) || (position.x >= RONG - kichCoVienGach - chieuRong)) {
		x = !x;
	}
	if ((position.y <= kichCoVienGach / 2) || (position.y >= 1.5 * kichCoVienGach)) {
		y = !y;
	}

	if (x == true) {
		if (y == true) {
			sprite.move(tocDoDiChuyen, tocDoDiChuyen / 5);
		}
		else {
			sprite.move(tocDoDiChuyen, -1 * tocDoDiChuyen / 5);
		}
	}
	else {
		if (y == true) {
			sprite.move(-1 * tocDoDiChuyen, tocDoDiChuyen / 5);
		}
		else {
			sprite.move(-1 * tocDoDiChuyen, -1 * tocDoDiChuyen / 5);
		}
	}
}