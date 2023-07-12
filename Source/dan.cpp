#include "dan.h"

Dan::Dan(double _Ox, double _Oy, int _phanLoai, int _nhanVat)
	: DoiTuong(_Ox, _Oy, 0, 0), phanLoai{ _phanLoai }, nhanVat{ _nhanVat }
{
	if (phanLoai == 1) {
		chieuRong = 9;
		chieuCao = 11;
	}
	else if (phanLoai == 2) {
		chieuRong = 12;
		chieuCao = 17;
	}
	else {
		chieuRong = 19;
		chieuCao = 18;
	}
}

void Dan::diChuyen()
{
	int k = 1 + (phanLoai == 3);
	if ((goc == 0) || (goc == 90) || (goc == 180) || (goc == 270)) {
		int c[4] = { 0, 1, 0 , -1 };
		int d[4] = { -1, 0, 1, 0 };
		sprite.move(c[int(goc) / 90] * tocDoDiChuyen / k, d[int(goc) / 90] * tocDoDiChuyen / k);
	}
	else {
		int e[2] = { 1 , -1 };
		double x = e[goc > 180] * tocDoDiChuyen / sqrt(a * a + 1) / k;
		double y = a * x;
		sprite.move(x, y);
	}
}