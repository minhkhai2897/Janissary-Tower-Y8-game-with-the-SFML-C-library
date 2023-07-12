#include "khoi_tao_man_choi.h"

void khoiTaoManChoi(std::vector<DoiTuong>& khongGianBanDau, std::vector<Gach>& khongGianGach1,
	std::vector<Gach>& khongGianGach2, std::vector<NhanVat>& khongGianNhanVat,
	std::vector<Sung>& khongGianSung1, std::vector<Sung>& khongGianSung2,
	std::vector<VatPham>& khongGianVatPham, const int& STT)
{
	const int k = 6;

	std::fstream file;
	switch (STT)
	{
	case 1:
		file.open("du_lieu/man_choi1.txt");
		break;
	case 2:
		file.open("du_lieu/man_choi2.txt");
		break;
	case 3:
		file.open("du_lieu/man_choi3.txt");
		break;
	case 4:
		file.open("du_lieu/man_choi4.txt");
		break;
	case 5:
		file.open("du_lieu/man_choi5.txt");
		break;
	default:
		file.open("du_lieu/man_choi6.txt");
	}

	int n;
	double a, b, c, d, e;

	if (file.is_open())
	{
		khongGianBanDau.clear();
		add(khongGianBanDau, 0, 0, kichCoVienGach, CAO);
		add(khongGianBanDau, RONG - kichCoVienGach, 0, kichCoVienGach, CAO);
		add(khongGianBanDau, 0, CAO - 101, RONG, 101);

		khongGianNhanVat.clear();
		file >> n;
		for (int i = 0; i < n; i++) {
			file >> a >> b >> c >> d;
			NhanVat nhanVat1(1, a * kichCoVienGach + 1, b * kichCoVienGach - 1.8 * d, c, d);
			khongGianNhanVat.push_back(nhanVat1);
			NhanVat nhanVat2(0, RONG - a * kichCoVienGach - 1.8 * c - 1, b * kichCoVienGach - 1.8 * d, c, d);
			khongGianNhanVat.push_back(nhanVat2);
		}

		khongGianGach1.clear();
		khongGianGach2.clear();
		file >> n;
		for (int i = 0; i < n; i++) {
			file >> a >> b >> c >> d;
			add(khongGianGach1, a * kichCoVienGach, b * kichCoVienGach + k, c * kichCoVienGach, d * kichCoVienGach);
			add(khongGianGach2, RONG - khongGianGach1[i].Ox - khongGianGach1[i].chieuRong, khongGianGach1[i].Oy,
				khongGianGach1[i].chieuRong, khongGianGach1[i].chieuCao);
		}

		khongGianSung1.clear();
		khongGianSung2.clear();
		file >> n;
		for (int i = 0; i < n; i++) {
			file >> a >> b >> c;
			add(khongGianSung1, a, b * kichCoVienGach, c * kichCoVienGach + k, kichCoVienGach, kichCoVienGach);
			add(khongGianSung2, khongGianSung1[i].phanLoai, RONG - khongGianSung1[i].Ox - khongGianSung1[i].chieuRong,
				khongGianSung1[i].Oy, kichCoVienGach, kichCoVienGach);
		}

		khongGianVatPham.clear();
		file >> n;
		for (int i = 0; i < n; i++) {
			file >> a >> b >> c >> d >> e;
			add(khongGianVatPham, a, b * kichCoVienGach, c * kichCoVienGach, d, e);
			add(khongGianVatPham, a, RONG - b * kichCoVienGach - d, c * kichCoVienGach, d, e);
		}

		file.close();
	}
	else {
		std::cout << "Khong mo duoc file du lieu man choi";
	}
}

void khoiTaoKhongGianMini(std::vector<DoiTuong>& khongGianMini)
{
	add(khongGianMini, 205, 216, RONG, CAO);
	add(khongGianMini, 564, 216, RONG, CAO);
	add(khongGianMini, 923, 216, RONG, CAO);
	add(khongGianMini, 205, 535, RONG, CAO);
	add(khongGianMini, 564, 535, RONG, CAO);
	add(khongGianMini, 923, 535, RONG, CAO);
}

void taoHinhBanDau(std::vector<DoiTuong>& khongGian, std::vector<sf::FloatRect>& khongGianHopGioiHan)
{
	taoHinh(khongGian[0], "anh/thanh_doc_trai.png");
	taoHinh(khongGian[1], "anh/thanh_doc_phai.png");
	taoHinh(khongGian[2], "anh/thanh_ngang.png");

	khongGianHopGioiHan.clear();
	for (const DoiTuong& i : khongGian) {
		sf::FloatRect boundingBox = i.sprite.getGlobalBounds();
		khongGianHopGioiHan.push_back(boundingBox);
	}
}

void taoHinhKhongGianMini(std::vector<DoiTuong>& khongGianMini)
{
	taoHinh(khongGianMini[0], "anh/man_choi1.png");
	taoHinh(khongGianMini[1], "anh/man_choi2.png");
	taoHinh(khongGianMini[2], "anh/man_choi3.png");
	taoHinh(khongGianMini[3], "anh/man_choi4.png");
	taoHinh(khongGianMini[4], "anh/man_choi5.png");
	taoHinh(khongGianMini[5], "anh/man_choi6.png");

	for (int i = 0; i < int(khongGianMini.size()); i++) {
		khongGianMini[i].sprite.setOrigin(564, 376);
		khongGianMini[i].sprite.setScale(1.0 * 309 / 1127, 1.0 * 309 / 1127);
		khongGianMini[i].chieuCao *= 1.0 * 309 / 1127;
		khongGianMini[i].chieuRong *= 1.0 * 309 / 1127;
	}
}