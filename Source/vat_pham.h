#pragma once
#include "doi_tuong.h"

class VatPham : public DoiTuong
{
public:
	bool daTaoHinh = false;
	int phanLoai;
	int hp = 1;
	double tocDoRoi = 4;

	VatPham(int _Ox, int _Oy, int _chieuRong, int _chieuCao, int _phanLoai);
};