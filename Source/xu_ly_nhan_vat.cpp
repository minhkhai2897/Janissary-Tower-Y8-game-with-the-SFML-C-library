#include "xu_ly_nhan_vat.h"

void nhapTexture(std::vector<sf::Texture>& a, const int& phanLoai)
{
	std::fstream file;
	if (phanLoai == 1) {
		file.open("du_lieu/duLieu1.txt");
	}
	else {
		file.open("du_lieu/duLieu2.txt");
	}
	if (file.is_open()) {
		while (!file.eof()) {
			std::string s;
			file >> s;
			if (file) {
				sf::Texture texture;
				texture.loadFromFile(s);
				a.push_back(texture);
			}
		}
		file.close();
	}
	else {
		std::cout << "Khong mo duoc file du lieu " << phanLoai << std::endl;
	}
}

void xuLyHinhAnhNhanVat(NhanVat& a, const std::vector<sf::Texture>& textureNV)
{
	sf::Vector2f position = a.sprite.getPosition();
	if (a.biRoi) {
		if (a.huong) {
			kiemTra(a.dem, 1);
			xuLyTexture(a, textureNV[1]);
		}
		else {
			kiemTra(a.dem, 2);
			xuLyTexture(a, textureNV[0]);
		}
	}
	else {
		if ((a.a1 > 0) && (a.duocSangTrai) && (position.x > a.hanCheDiChuyenTrai)) {
			kiemTra(a.dem, 3);
			xuLyTexture(a, textureNV[2]);
		}
		else if ((a.d1 > 0) && (a.duocSangPhai) && (position.x < a.hanCheDiChuyenPhai)) {
			kiemTra(a.dem, 4);
			xuLyTexture(a, textureNV[3]);
		}
		else {
			if (a.huong) {
				kiemTra(a.dem, 5);
				xuLyTexture(a, textureNV[5]);
			}
			else {
				kiemTra(a.dem, 6);
				xuLyTexture(a, textureNV[4]);
			}
		}
	}
}

void kiemTraDieuKienDiChuyen(NhanVat& a, const std::vector<sf::FloatRect>& khongGianHopGioiHanBanDau,
	const std::vector<sf::FloatRect>& khongGianHopGioiHanGach,
	const std::vector<sf::FloatRect>& khongGianHopGioiHanSung)
{
	sf::Vector2f diemTren1 = sf::Vector2f(a.position.x + 0.01 + a.tocDoDiChuyen, a.position.y + (1.8 * a.chieuCao - kichCoVienGach) + 0.01);
	sf::Vector2f diemTren2 = sf::Vector2f(a.position.x + 1.8 * a.chieuRong - 0.01 - a.tocDoDiChuyen, a.position.y + (1.8 * a.chieuCao - kichCoVienGach) + 0.01);
	sf::Vector2f diemDuoi1 = sf::Vector2f(a.position.x + 0.01 + a.tocDoDiChuyen, a.position.y + 1.8 * a.chieuCao);
	sf::Vector2f diemDuoi2 = sf::Vector2f(a.position.x + 1.8 * a.chieuRong - 0.01 - a.tocDoDiChuyen, a.position.y + 1.8 * a.chieuCao);
	sf::Vector2f diemTrai1 = sf::Vector2f(a.position.x, a.position.y + 0.01 + (1.8 * a.chieuCao - kichCoVienGach));
	sf::Vector2f diemTrai2 = sf::Vector2f(a.position.x, a.position.y + 1.8 * a.chieuCao - 0.01);
	sf::Vector2f diemPhai1 = sf::Vector2f(a.position.x + 1.8 * a.chieuRong, a.position.y + 0.01 + (1.8 * a.chieuCao - kichCoVienGach));
	sf::Vector2f diemPhai2 = sf::Vector2f(a.position.x + 1.8 * a.chieuRong, a.position.y + 1.8 * a.chieuCao - 0.01);

	kiemTraHaiDiemTrongBaHopGioiHan(a.duocNhay, diemTren1, diemTren2, khongGianHopGioiHanBanDau,
		khongGianHopGioiHanGach, khongGianHopGioiHanSung);
	kiemTraHaiDiemTrongBaHopGioiHan(a.biRoi, diemDuoi1, diemDuoi2, khongGianHopGioiHanBanDau,
		khongGianHopGioiHanGach, khongGianHopGioiHanSung);
	kiemTraHaiDiemTrongBaHopGioiHan(a.duocSangTrai, diemTrai1, diemTrai2, khongGianHopGioiHanBanDau,
		khongGianHopGioiHanGach, khongGianHopGioiHanSung);
	kiemTraHaiDiemTrongBaHopGioiHan(a.duocSangPhai, diemPhai1, diemPhai2, khongGianHopGioiHanBanDau,
		khongGianHopGioiHanGach, khongGianHopGioiHanSung);
}

void taoGachBoiNhanVat(NhanVat& a, std::vector<Gach>& khongGianGach,
	                   const std::vector<sf::FloatRect>& khongGianHopGioiHanBanDau,
                       const std::vector<sf::FloatRect>& khongGianHopGioiHanGach,
	                   const std::vector<sf::FloatRect>& khongGianHopGioiHanSung)
{
	a.position = a.sprite.getPosition();
	sf::Vector2f point;
	point.x = floor((a.position.x + 1.8 * a.chieuRong / 2) / 28) * 28 + 1 + a.boSung;
	point.y = CAO - 101 - floor((CAO - 101 - a.position.y - 1.8 * a.chieuCao) / 28) * 28 + 1;

	bool duocTaoGach = true;

	kiemTraDiemTrongHopGioiHan(duocTaoGach, point, khongGianHopGioiHanSung);
	kiemTraDiemTrongHopGioiHan(duocTaoGach, point, khongGianHopGioiHanGach);
	kiemTraDiemTrongHopGioiHan(duocTaoGach, point, khongGianHopGioiHanBanDau);

	if (a.dan > 0) {
		if (duocTaoGach) {
			Gach b(point.x - 1, point.y - 1);
			khongGianGach.push_back(b);
		}
		a.dan -= 5;
	}
}

int kiemTraNhanVatCoGanSungHayKhong(NhanVat& a, bool& oGanSung, const std::vector<sf::FloatRect>& khongGianHopGioiHanSung)
{
	int k = 0;
	sf::FloatRect boundingBox = a.sprite.getGlobalBounds();
	for (int i = 0; i < int(khongGianHopGioiHanSung.size()); i++) {
		if (khongGianHopGioiHanSung[i].intersects(boundingBox)) {
			k = i;
			oGanSung = true;
			break;
		}
	}

	return k;
}

void xuLyDauVaoNhanVat1(NhanVat& a)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		a.a1++;
		a.huong = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		a.d1++;
		a.huong = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		a.w1++;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		a.s1++;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		a.sp1++;
	}
	xuLyPhim(a.a1, a.a2);
	xuLyPhim(a.d1, a.d2);
	xuLyPhim(a.w1, a.w2);
	xuLyPhim(a.s1, a.s2);
	xuLyPhim(a.sp1, a.sp2);

	a.hanCheDiChuyenPhai = 20 * kichCoVienGach - 1.8 * a.chieuRong;
}

void xuLyDauVaoNhanVat2(NhanVat& a)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		a.a1++;
		a.huong = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		a.d1++;
		a.huong = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		a.w1++;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		a.s1++;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		a.sp1++;
	}
	xuLyPhim(a.a1, a.a2);
	xuLyPhim(a.d1, a.d2);
	xuLyPhim(a.w1, a.w2);
	xuLyPhim(a.s1, a.s2);
	xuLyPhim(a.sp1, a.sp2);

	a.boSung = 7;
	a.hanCheDiChuyenTrai = RONG - 20 * kichCoVienGach;
}

void hanhDongNhanVat(NhanVat& a, std::vector<Gach>& khongGianGach,
	                 const std::vector<sf::FloatRect>& khongGianHopGioiHanBanDau,
	                 const std::vector<sf::FloatRect>& khongGianHopGioiHanGach,
	                 const std::vector<sf::FloatRect>& khongGianHopGioiHanSung,
	                 std::vector<Sung>& khongGianSung, std::vector<Dan>& khongGianDan,
	                 std::vector<VuNo>& khongGianNo)
{
	a.position = a.sprite.getPosition();
	a.duocSangTrai = true, a.duocSangPhai = true, a.biRoi = true, a.duocNhay = true;
	kiemTraDieuKienDiChuyen(a, khongGianHopGioiHanBanDau, khongGianHopGioiHanGach, khongGianHopGioiHanSung);

	bool oCanhSung = false;
	int p = kiemTraNhanVatCoGanSungHayKhong(a, oCanhSung, khongGianHopGioiHanSung);

	if (a.a1 > 0) {
		if ((a.duocSangTrai) && (a.position.x > a.hanCheDiChuyenTrai)) {
			a.diSangTrai();
		}
	}
	else if (a.d1 > 0) {
		if ((a.duocSangPhai) && (a.position.x < a.hanCheDiChuyenPhai)) {
			a.diSangPhai();
		}
	}

	if ((oCanhSung) && (a.w1 > 0)) {
		if (a.boSung != 7) {
			khongGianSung[p].sprite1.rotate(-1);
		}
		else {
			khongGianSung[p].sprite1.rotate(1);
		}
	}
	else {
		a.nhay();
	}

	// Cho du khi dang nhay thi nhan vat van luon duoc tinh la dang roi
	if (a.biRoi) {
		a.roi();

		if (a.s1 == 1) {
			taoGachBoiNhanVat(a, khongGianGach, khongGianHopGioiHanBanDau,
				khongGianHopGioiHanGach, khongGianHopGioiHanSung);
		}
	}
	else {
		if (a.s1 > 0) {
			if (oCanhSung) {
				if (a.boSung != 7) {
					khongGianSung[p].sprite1.rotate(1);
				}
				else {
					khongGianSung[p].sprite1.rotate(-1);
				}
			}
		}
	}

	if ((a.sp1 == 1) && (oCanhSung) && (a.dan > 0))
	{
		if (khongGianSung[p].phanLoai == 1) {
			a.dan--;
		}
		else if (khongGianSung[p].phanLoai == 2) {
			a.dan -= 5;
			a.dan = (a.dan < 0) ? 0 : a.dan;
		}
		else {
			a.dan -= 15;
			a.dan = (a.dan < 0) ? 0 : a.dan;
		}

		sf::Vector2f position = khongGianSung[p].sprite1.getPosition();
		double goc = khongGianSung[p].sprite1.getRotation();
		int k = (khongGianSung[p].phanLoai == 1) ? 41 : ((khongGianSung[p].phanLoai == 2) ? 52 : 46);
		if ((goc == 0) || (goc == 90) || (goc == 180) || (goc == 270)) {
			Dan dan(position.x, position.y, khongGianSung[p].phanLoai, 1 + (a.boSung == 7));
			dan.goc = goc;
			khongGianDan.push_back(dan);

			int c[4] = { 0, 1, 0, -1 };
			int d[4] = { -1, 0, 1, 0 };
			VuNo no(position.x + k * c[int(goc) / 90], position.y + k * d[int(goc) / 90]);
			khongGianNo.push_back(no);
		}
		else {
			int c[4] = { -1, 1, -1, 1 };
			int d[4] = { 1, -1, 1, -1 };
			double t = c[int(goc) / 90] * tan(d[int(goc) / 90] * (90 - goc) * PI / 180);
			Dan dan(position.x, position.y, khongGianSung[p].phanLoai, 1 + (a.hanCheDiChuyenPhai == RONG));
			dan.goc = goc;
			dan.a = t;
			khongGianDan.push_back(dan);

			int e[2] = { 1, -1 };
			double x = position.x + e[goc > 180] * sqrt(k * k / (1 + t * t));
			double y = t * x + position.y - t * position.x;
			VuNo no(x, y);
			khongGianNo.push_back(no);
		}
	}
}

void taoHinhNhanVat(std::vector<NhanVat>& khongGian)
{
	for (int i = 0; i < int(khongGian.size()); i++) {
		khongGian[i].sprite.setPosition(khongGian[i].Ox, khongGian[i].Oy);
		khongGian[i].inHp.setFillColor(sf::Color(214, 61, 69));
		khongGian[i].font.loadFromFile("Font/font.ttf");
		khongGian[i].text.setFont(khongGian[i].font);
		khongGian[i].text.setCharacterSize(17);
	}

	khongGian[0].sprite.setScale(1.8, 1.8);
	khongGian[1].sprite.setScale(1.8, 1.8);

	khongGian[0].inHp.setPosition(59, CAO - 64);
	khongGian[1].inHp.setPosition(RONG - 183, CAO - 64);

	khongGian[0].text.setPosition(59, CAO - 51);
	khongGian[1].text.setPosition(RONG - 78, CAO - 51);
}

void nhanVatVaChamVoiVatPham(std::vector<NhanVat>& khongGianNhanVat, std::vector<VatPham>& khongGianVatPham,
	                         std::vector<sf::FloatRect>& khongGianHopGioiHanVatPham)
{
	for (NhanVat& a : khongGianNhanVat) {
		sf::FloatRect boundingBox = a.sprite.getGlobalBounds();
		for (int i = 0; i < khongGianHopGioiHanVatPham.size(); i++) {
			if (boundingBox.intersects(khongGianHopGioiHanVatPham[i])) {
				khongGianVatPham[i].hp--;
				if (khongGianVatPham[i].phanLoai == 1) {
					a.dan = (a.dan + 100 > 495) ? 495 : (a.dan + 100);
				}
				else if (khongGianVatPham[i].phanLoai == 2) {
					a.dan = (a.dan + 50 > 495) ? 495 : (a.dan + 50);
					a.hp = (a.hp + 5 > 25) ? 25 : (a.hp + 5);
				}
				else if (khongGianVatPham[i].phanLoai == 3) {
					a.hp = (a.hp > 5) ? (a.hp - 5) : 0;
				}
				else {
					a.hp = (a.hp + 10 > 25) ? 25 : (a.hp + 10);
				}
			}
		}
	}
}

void capNhatNhanVat(std::vector<NhanVat>& khongGianNhanVat)
{
	khongGianNhanVat[0].inHp.setSize(sf::Vector2f(khongGianNhanVat[0].hp * 5, 10));
	khongGianNhanVat[0].text.setString(std::to_string(int(ceil(khongGianNhanVat[0].dan) / 5.0)));
	khongGianNhanVat[1].inHp.setSize(sf::Vector2f(khongGianNhanVat[1].hp * 5, 10));
	khongGianNhanVat[1].text.setString(std::to_string(int(ceil(khongGianNhanVat[1].dan) / 5.0)));
}
