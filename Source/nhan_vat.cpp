#include "nhan_vat.h"

NhanVat::NhanVat(bool _huong, double _Ox, double _Oy, int _chieuRong, int _chieuCao)
	: DoiTuong(_Ox, _Oy, _chieuRong, _chieuCao), huong{ _huong }
{
	dem.first = -1;
	dem.second = -1;
}

void NhanVat::diSangTrai()
{
	sprite.move(-1 * tocDoDiChuyen, 0);
}

void NhanVat::diSangPhai()
{
	sprite.move(tocDoDiChuyen, 0);
}

void NhanVat::roi()
{
	sprite.move(0, tocDoRoi);
}

void NhanVat::nhay()
{
	if ((quangDuongDaNhay == 0) && (!biRoi) && (duocNhay)) {
		if (w1 == 1)
		{
			sprite.move(0, tocDoNhay);
			quangDuongDaNhay += -1 * tocDoNhay - tocDoRoi;
			tocDoNhay = tocDoNhay + giamToc;
			if (tocDoNhay + tocDoRoi >= 0) {
				tocDoNhay = -1 * tocDoRoi - 6;
			}
		}
	}
	else if ((0 < quangDuongDaNhay) && (quangDuongDaNhay < quangDuongNhay)) {
		if (duocNhay)
		{
			if (quangDuongDaNhay - tocDoNhay - tocDoRoi > quangDuongNhay) {
				tocDoNhay = quangDuongDaNhay - quangDuongNhay - tocDoRoi;
			}
			sprite.move(0, tocDoNhay);
			quangDuongDaNhay += -1 * tocDoNhay - tocDoRoi;
			tocDoNhay = tocDoNhay + giamToc;
			if (tocDoNhay + tocDoRoi >= 0) {
				tocDoNhay = -1 * tocDoRoi - 6;
			}
		}
		else {
			double m = quangDuongDaNhay - int(quangDuongDaNhay) / 4 * 4;
			sprite.move(0, m);
			quangDuongDaNhay = 0;
			tocDoNhay = -1 * tocDoRoi - 6;
		}
	}
	else {
		quangDuongDaNhay = 0;
		tocDoNhay = -1 * tocDoRoi - 6;
	}
}