#pragma once
#include "doi_tuong.h"

class NhanVat : public DoiTuong
{
public:
	std::pair<int, int> dem;
	const double giamToc = 0.13;   // Phai dieu chinh neu giam toc do roi...
	const double tocDoDiChuyen = 2.5;
	const double tocDoRoi = 4;
	int hp = 25;
	int dan = 250;
	double tocDoNhay = -1 * tocDoRoi - 6;
	int w1 = 0, w2 = 0, s1 = 0, s2 = 0, sp1 = 0, sp2 = 0, a1 = 0, a2 = 0, d1 = 0, d2 = 0;
	const double quangDuongNhay = 4 * kichCoVienGach + 16;
	double quangDuongDaNhay = 0;
	int boSung = 0;
	bool huong = false;
	bool duocSangTrai = true, duocSangPhai = true, biRoi = true, duocNhay = true;
	double hanCheDiChuyenTrai = 0, hanCheDiChuyenPhai = RONG;

	sf::Vector2f position;
	sf::Font font;
	sf::Text text;
	sf::RectangleShape inHp;

	NhanVat(bool _huong, double _Ox = 0, double _Oy = 0, int _chieuRong = 15, int _chieuCao = 17);
	void diSangTrai();
	void diSangPhai();
	void roi();
	void nhay();
};