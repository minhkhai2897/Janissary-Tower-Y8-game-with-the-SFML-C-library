#pragma once
#include "doi_tuong.h"

class VuNo : public DoiTuong
{
public:
	std::pair<int, int> dem;
	bool daTaoHinh = false;

	VuNo(double _Ox, double _Oy, int _chieuRong = 28, int _chieuCao = 28);
};