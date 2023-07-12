#pragma once
#include "doi_tuong.h"
#include "vat_pham.h"
#include "vu_no.h"
#include "sung.h"
#include "nhan_vat.h"
#include "gach.h"
#include "dan.h"
#include "khi_cau.h"
#include "xu_ly_gach.h"
#include "xu_ly_dan.h"
#include "xu_ly_vat_pham.h"
#include "xu_ly_vu_no.h"


void kiemTraDiemTrongHopGioiHan(bool& kiemTra, const sf::Vector2f& diem,
	const std::vector<sf::FloatRect>& khongGianHopGioiHan);

void kiemTraHaiDiemTrongBaHopGioiHan(bool& kiemTra, const sf::Vector2f& diem1, const sf::Vector2f& diem2,
	const std::vector<sf::FloatRect>& khongGianHopGioiHanBanDau,
	const std::vector<sf::FloatRect>& khongGianHopGioiHanGach,
	const std::vector<sf::FloatRect>& khongGianHopGioiHanSung);

void kiemTra(std::pair<int, int>& a, const int& i);

void xuLyPhim(int& i1, int& i2);

void gioiThieu();

void reset(bool& a, int& b, int& c, int& d, int& e, int& f);

void capNhat(std::vector<Gach>& khongGianGach1, std::vector<sf::FloatRect>& khongGianHopGioiHanGach1, int& gach1,
	         std::vector<Gach>& khongGianGach2, std::vector<sf::FloatRect>& khongGianHopGioiHanGach2, int& gach2,
	         std::vector<VatPham>& khongGianVatPham, std::vector<sf::FloatRect>& khongGianHopGioiHanVatPham, int& vatPham,
	         std::vector<Dan>& khongGianDan, int& dan,
	         std::vector<VuNo>& khongGianNo, int& no);

void xuLyGiaoDienMini(sf::Window& window, std::vector<DoiTuong>& khongGian, bool& thoat, int& manChoi);

void taoHinhLinhTinh(sf::Window& window, DoiTuong& win1, DoiTuong& win2, DoiTuong& nen,
	                 DoiTuong& anhNen, KhiCau& khiCau, std::vector<DoiTuong>& nutPlay);


void taiNhac(sf::Music& music);