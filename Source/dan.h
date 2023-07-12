#pragma once
#include "doi_tuong.h"

class Dan : public DoiTuong
{
public:
	bool daTaoHinh = false;
	int phanLoai;
	int hp = 4;
	double a = 0, goc;
	int nhanVat;
	double tocDoDiChuyen = 16;

	Dan(double _Ox, double _Oy, int _phanLoai, int _nhanVat);
	void diChuyen();
};

