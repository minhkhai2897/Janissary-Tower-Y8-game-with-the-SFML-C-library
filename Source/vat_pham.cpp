#include "vat_pham.h"

VatPham::VatPham(int _Ox, int _Oy, int _chieuRong, int _chieuCao, int _phanLoai)
	: DoiTuong(_Ox, _Oy, _chieuRong, _chieuCao), phanLoai{ _phanLoai }
{
}