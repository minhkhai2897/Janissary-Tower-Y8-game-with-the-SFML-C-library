#include "xu_ly_chung.h"

void kiemTraDiemTrongHopGioiHan(bool& kiemTra, const sf::Vector2f& diem,
	const std::vector<sf::FloatRect>& khongGianHopGioiHan)
{
	if (kiemTra) {
		for (const sf::FloatRect& boundingBox : khongGianHopGioiHan) {
			if (boundingBox.contains(diem)) {
				kiemTra = false;
				break;
			}
		}
	}
}

void kiemTraHaiDiemTrongBaHopGioiHan(bool& kiemTra, const sf::Vector2f& diem1, const sf::Vector2f& diem2,
	                                 const std::vector<sf::FloatRect>& khongGianHopGioiHanBanDau,
	                                 const std::vector<sf::FloatRect>& khongGianHopGioiHanGach,
	                                 const std::vector<sf::FloatRect>& khongGianHopGioiHanSung)
{
	if (kiemTra)
		kiemTraDiemTrongHopGioiHan(kiemTra, diem1, khongGianHopGioiHanSung);
	if (kiemTra)
		kiemTraDiemTrongHopGioiHan(kiemTra, diem2, khongGianHopGioiHanSung);

	if (kiemTra)
		kiemTraDiemTrongHopGioiHan(kiemTra, diem1, khongGianHopGioiHanBanDau);
	if (kiemTra)
		kiemTraDiemTrongHopGioiHan(kiemTra, diem2, khongGianHopGioiHanBanDau);

	if (kiemTra)
		kiemTraDiemTrongHopGioiHan(kiemTra, diem1, khongGianHopGioiHanGach);
	if (kiemTra)
		kiemTraDiemTrongHopGioiHan(kiemTra, diem2, khongGianHopGioiHanGach);
}

void kiemTra(std::pair<int, int>& a, const int& i)
{
	if (a.second == i) {
		a.first++;
	}
	else {
		a.first = 0;
		a.second = i;
	}
}

void xuLyPhim(int& i1, int& i2)
{
	if (i1 == i2) {
		i1 = 0;
		i2 = 0;
	}
	else {
		if (i1 > 1000000) {
			i1 = 2;
		}
		i2 = i1;
	}
}

void gioiThieu()
{
	std::fstream file("du_lieu/gioi_thieu.txt");
	if (file.is_open()) {
		std::string line;
		while (!file.eof()) {
			std::getline(file, line);
			if (file) {
				std::cout << line << std::endl;
			}
		}
		file.close();
	}
}

void reset(bool& a, int& b, int& c, int& d, int& e, int& f)
{
	a = 0; b = 0; c = 0; d = 0; e = 0; f = 0;
}

void capNhat(std::vector<Gach>& khongGianGach1, std::vector<sf::FloatRect>& khongGianHopGioiHanGach1, int& gach1,
	std::vector<Gach>& khongGianGach2, std::vector<sf::FloatRect>& khongGianHopGioiHanGach2, int& gach2,
	std::vector<VatPham>& khongGianVatPham, std::vector<sf::FloatRect>& khongGianHopGioiHanVatPham, int& vatPham,
	std::vector<Dan>& khongGianDan, int& dan,
	std::vector<VuNo>& khongGianNo, int& no)
{
	if (!khongGianGach1.empty()) {
		if ((!khongGianGach1.back().daTaoHinh) || (int(khongGianGach1.size()) != gach1)) {
			taoHinhGach(khongGianGach1, khongGianHopGioiHanGach1);
			gach1 = khongGianGach1.size();
		}
	}

	if (!khongGianGach2.empty()) {
		if ((!khongGianGach2.back().daTaoHinh) || (int(khongGianGach2.size()) != gach2)) {
			taoHinhGach(khongGianGach2, khongGianHopGioiHanGach2);
			gach2 = khongGianGach2.size();
		}
	}

	if (!khongGianVatPham.empty()) {
		if ((!khongGianVatPham.back().daTaoHinh) || (khongGianVatPham.size() != vatPham)) {
			taoHinhVatPham(khongGianVatPham, khongGianHopGioiHanVatPham);
			vatPham = khongGianVatPham.size();
		}
	}

	if (!khongGianDan.empty()) {
		if ((!khongGianDan.back().daTaoHinh) || (khongGianDan.size() != dan)) {
			taoHinhDan(khongGianDan);
			dan = khongGianDan.size();
		}
	}

	if (!khongGianNo.empty()) {
		if ((!khongGianNo.back().daTaoHinh) || (khongGianNo.size() != no)) {
			taoHinhVuNo(khongGianNo);
			no = khongGianNo.size();
		}
	}
}

void xuLyGiaoDienMini(sf::Window& window, std::vector<DoiTuong>& khongGian, bool& thoat, int& manChoi)
{
	sf::Vector2i position = sf::Mouse::getPosition(window);
	for (int i = 0; i < int(khongGian.size()); i++)
	{
		if ((khongGian[i].Ox - khongGian[i].chieuRong / 2.0 < position.x) &&
			(position.x < khongGian[i].Ox + khongGian[i].chieuRong / 2.0) &&
			(khongGian[i].Oy - khongGian[i].chieuCao / 2.0 < position.y) &&
			(position.y < khongGian[i].Oy + khongGian[i].chieuCao / 2.0))
		{
			khongGian[i].k1 = (khongGian[i].k1 < 1000) ? (khongGian[i].k1 + 1) : 2;
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				manChoi = i + 1;
				thoat = true;
				break;
			}
		}
		else {
			khongGian[i].k1 = 0;
		}

		if ((khongGian[i].k1 > 0) && (!khongGian[i].phongTo)) {
			khongGian[i].sprite.scale(sf::Vector2f(1.1, 1.1));
			khongGian[i].phongTo = true;
		}
		if ((khongGian[i].k1 == 0) && (khongGian[i].phongTo)) {
			khongGian[i].sprite.scale(sf::Vector2f(1.0 * 10 / 11, 1.0 * 10 / 11));
			khongGian[i].phongTo = false;
		}
	}
}

void taoHinhLinhTinh(sf::Window& window, DoiTuong& win1, DoiTuong& win2, DoiTuong& nen,
	DoiTuong& anhNen, KhiCau& khiCau, std::vector<DoiTuong>& nutPlay)
{
	taoHinh(win1, "anh/win1.png");
	taoHinh(win2, "anh/win2.png");
	taoHinh(nen, "anh/nen.png");
	DoiTuong nut_play(563, 375, 187, 54);
	nutPlay.push_back(nut_play);
	taoHinh(nutPlay[0], "anh/play.png");
	nutPlay[0].sprite.setOrigin(94, 27);
	taoHinh(anhNen, "anh/anh_nen.png");
	taoHinh(khiCau, "anh/khi_cau.png");
}

void taiNhac(sf::Music& music)
{
	if (!music.openFromFile("am_thanh/Oakland_Dream.ogg")) {
		std::cout << "Khong tai duoc nhac";
	}
	music.setLoop(true);
}