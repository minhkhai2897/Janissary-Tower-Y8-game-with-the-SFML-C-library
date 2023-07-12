#include "khoi_tao_man_choi.h"
#include "xu_ly_chung.h"
#include "xu_ly_nhan_vat.h"
#include "xu_ly_gach.h"
#include "xu_ly_dan.h"
#include "xu_ly_sung.h"
#include "xu_ly_khi_cau.h"
#include "xu_ly_vat_pham.h"
#include "xu_ly_vu_no.h"
#include "xu_ly_do_hong.h"

int main()
{
	std::vector<NhanVat> khongGianNhanVat;
	std::vector<DoiTuong> khongGianBanDau;
	std::vector<Gach> khongGianGach1;
	std::vector<Gach> khongGianGach2;
	std::vector<Sung> khongGianSung1;
	std::vector<Sung> khongGianSung2;
	std::vector<VatPham> khongGianVatPham;
	std::vector<DoiTuong> khongGianMini;
	sf::RenderWindow window(sf::VideoMode(RONG, CAO), "con_ga_con", sf::Style::Close);
	window.setFramerateLimit(60);

	gioiThieu();

	khoiTaoKhongGianMini(khongGianMini);
	taoHinhKhongGianMini(khongGianMini);

	while (window.isOpen()) 
	{
		int manChoi = 0;
		DoiTuong win1(0, 0, RONG, CAO);
		DoiTuong win2(0, 0, RONG, CAO);
		DoiTuong nen(0, 0, RONG, CAO);
		DoiTuong anhNen(0, 0, RONG, CAO);
		KhiCau khiCau(kichCoVienGach, kichCoVienGach, 125, 59);

		std::vector<Dan> khongGianDan;
		std::vector<VuNo> khongGianNo;
		std::vector<sf::Texture> textureNV1;
		std::vector<sf::Texture> textureNV2;
		std::vector<sf::FloatRect> khongGianHopGioiHanBanDau;
		std::vector<sf::FloatRect> khongGianHopGioiHanGach1;
		std::vector<sf::FloatRect> khongGianHopGioiHanGach2;
		std::vector<sf::FloatRect> khongGianHopGioiHanSung1;
		std::vector<sf::FloatRect> khongGianHopGioiHanSung2;
		std::vector<sf::FloatRect> khongGianHopGioiHanVatPham;

		std::vector<DoiTuong> nutPlay;
		taoHinhLinhTinh(window, win1, win2, nen, anhNen, khiCau, nutPlay);

		bool chuyenMan = true;
		while (true) 
		{
			if (!khongGianNhanVat.empty()) {
				if (khongGianNhanVat[1].hp < 1) {
					window.draw(win1.sprite);
					if (chuyenMan) {
						std::cout << std::endl << "PINK WIN";
						chuyenMan = false;
					}
				}
				else {
					window.draw(win2.sprite);
					if (chuyenMan) {
						std::cout << std::endl << "BLUE WIN";
						chuyenMan = false;
					}
				}
			}
			else {
				window.draw(nen.sprite);
			}
			window.draw(nutPlay[0].sprite);

			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed) {
					window.close();
				}
			}

			window.display();
			bool thoat = false;
			xuLyGiaoDienMini(window, nutPlay, thoat, manChoi);

			
			if (thoat) {
				break;
			}
		}

		while (true) 
		{
			window.draw(nen.sprite);
			for (int i = 0; i < int(khongGianMini.size()); i++) {
				window.draw(khongGianMini[i].sprite);
			}

			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed) {
					window.close();
				}
			}

			window.display();

			bool thoat = false;
			xuLyGiaoDienMini(window, khongGianMini, thoat, manChoi);
			if (thoat) {
				break;
			}
		}
		khoiTaoManChoi(khongGianBanDau, khongGianGach1, khongGianGach2, khongGianNhanVat, khongGianSung1, khongGianSung2, khongGianVatPham, manChoi);
		
		nhapTexture(textureNV1, 1);
		nhapTexture(textureNV2, 2);

		taoHinhNhanVat(khongGianNhanVat);
		taoHinhBanDau(khongGianBanDau, khongGianHopGioiHanBanDau);
		taoHinhSung(khongGianSung1, khongGianHopGioiHanSung1);
		for (Sung& i : khongGianSung1) {
			i.sprite1.setRotation(90);
		}
		taoHinhSung(khongGianSung2, khongGianHopGioiHanSung2);
		for (Sung& i : khongGianSung2) {
			i.sprite1.setRotation(-90);
		}

		sf::Music music;
		taiNhac(music);
		music.play();

		chuyenMan = true;
		while (true)
		{
			static int gach1 = 0, gach2 = 0, vatPham = 0, dan = 0, no = 0;
			if (chuyenMan) {
				reset(chuyenMan, gach1, gach2, vatPham, dan, no);
			}

			capNhat(khongGianGach1, khongGianHopGioiHanGach1, gach1,
				    khongGianGach2, khongGianHopGioiHanGach2, gach2,
				    khongGianVatPham, khongGianHopGioiHanVatPham, vatPham,
			     	khongGianDan, dan, khongGianNo, no);
			
			xuLyHinhAnhNhanVat(khongGianNhanVat[0], textureNV1);
			xuLyHinhAnhNhanVat(khongGianNhanVat[1], textureNV2);
			xuLyHinhAnhVuNo(khongGianNo);

			window.clear();

			window.draw(anhNen.sprite);
			for (const DoiTuong& i : khongGianBanDau) {
				window.draw(i.sprite);
			}
			for (const VatPham& i : khongGianVatPham) {
				window.draw(i.sprite);
			}
			for (const Gach& i : khongGianGach1) {
				if (i.hp <= 5) {
					window.draw(i.sprite1);
				}
				else if (i.hp <= 10) {
					window.draw(i.sprite2);
				}
				else {
					window.draw(i.sprite3);
				}
			}
			for (const Gach& i : khongGianGach2) {
				if (i.hp <= 5) {
					window.draw(i.sprite1);
				}
				else if (i.hp <= 10) {
					window.draw(i.sprite2);
				}
				else {
					window.draw(i.sprite3);
				}
			}
			for (const NhanVat& i : khongGianNhanVat) {
				window.draw(i.sprite);
				window.draw(i.text);
				window.draw(i.inHp);
			}
			for (const Dan& i : khongGianDan) {
				window.draw(i.sprite);
			}
			for (const Sung& i : khongGianSung1) {
				window.draw(i.sprite);
				window.draw(i.sprite1);
			}
			for (const Sung& i : khongGianSung2) {
				window.draw(i.sprite);
				window.draw(i.sprite1);
			}
			window.draw(khiCau.sprite);
			for (const VuNo& i : khongGianNo) {
				window.draw(i.sprite);
			}

			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed) {
					window.close();
				}
			}

			window.display();

			if ((khongGianNhanVat[0].hp < 1) || (khongGianNhanVat[1].hp < 1)) {
				break;
			}

			xuLyDoHong(khongGianGach1, khongGianHopGioiHanGach1);
			xuLyDoHong(khongGianGach2, khongGianHopGioiHanGach2);
			xuLyDoHong(khongGianVatPham, khongGianHopGioiHanVatPham);
			xuLyDanHong(khongGianDan, khongGianNo);

			xuLyDauVaoNhanVat1(khongGianNhanVat[0]);
			xuLyDauVaoNhanVat2(khongGianNhanVat[1]);

			hanhDongNhanVat(khongGianNhanVat[0], khongGianGach1,
		            		khongGianHopGioiHanBanDau, khongGianHopGioiHanGach1,
		            		khongGianHopGioiHanSung1, khongGianSung1, khongGianDan,
		            		khongGianNo);
			hanhDongNhanVat(khongGianNhanVat[1], khongGianGach2,
		             		khongGianHopGioiHanBanDau, khongGianHopGioiHanGach2,
		            		khongGianHopGioiHanSung2, khongGianSung2, khongGianDan,
		            		khongGianNo);
			hanhDongDan(khongGianDan, khongGianNhanVat, khongGianHopGioiHanBanDau,
						khongGianHopGioiHanGach1, khongGianHopGioiHanGach2, khongGianHopGioiHanVatPham, 
						khongGianGach1, khongGianGach2, khongGianVatPham);

			roiVatPham(khongGianVatPham, khongGianHopGioiHanVatPham, khongGianHopGioiHanBanDau,
				       khongGianHopGioiHanGach1, khongGianHopGioiHanGach2, khongGianHopGioiHanSung1,
				       khongGianHopGioiHanSung2);

			nhanVatVaChamVoiVatPham(khongGianNhanVat, khongGianVatPham, khongGianHopGioiHanVatPham);

			hanhDongKhiCau(khiCau, khongGianVatPham);

			capNhatNhanVat(khongGianNhanVat);
		}
	}

	return 0;
}

