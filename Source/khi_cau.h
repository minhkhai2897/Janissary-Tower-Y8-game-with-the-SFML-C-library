#pragma once
#include "doi_tuong.h"
#include <ctime>
#include <cstdlib>

class KhiCau : public DoiTuong
{
public:
	double tocDoDiChuyen = 2.5;
	bool x = false, y = false;
	int thaQua = -1;
	int loaiQua;
	int k = -1;

	KhiCau(double _Ox, double _Oy, int _chieuRong, int _chieuCao);
	void diChuyen();
};
