#include "vu_no.h"

VuNo::VuNo(double _Ox, double _Oy, int _chieuRong, int _chieuCao)
	: DoiTuong(_Ox, _Oy, _chieuRong, _chieuCao)
{
	dem.first = -1;
	dem.second = -1;
}