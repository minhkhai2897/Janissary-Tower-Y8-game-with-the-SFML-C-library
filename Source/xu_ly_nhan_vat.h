#pragma once
#include "Header.h"
#include "xu_ly_texture.h"
#include "xu_ly_chung.h"

void nhapTexture(std::vector<sf::Texture>& a, const int& phanLoai);

void xuLyHinhAnhNhanVat(NhanVat& a, const std::vector<sf::Texture>& textureNV);

void kiemTraDieuKienDiChuyen(NhanVat& a, const std::vector<sf::FloatRect>& khongGianHopGioiHanBanDau,
						     const std::vector<sf::FloatRect>& khongGianHopGioiHanGach,
							 const std::vector<sf::FloatRect>& khongGianHopGioiHanSung);

void taoGachBoiNhanVat(NhanVat& a, std::vector<Gach>& khongGianGach,
	                   const std::vector<sf::FloatRect>& khongGianHopGioiHanBanDau,
	                   const std::vector<sf::FloatRect>& khongGianHopGioiHanGach,
	                   const std::vector<sf::FloatRect>& khongGianHopGioiHanSung);

int kiemTraNhanVatCoGanSungHayKhong(NhanVat& a, bool& oGanSung, const std::vector<sf::FloatRect>& khongGianHopGioiHanSung);

void xuLyDauVaoNhanVat1(NhanVat& a);

void xuLyDauVaoNhanVat2(NhanVat& a);

void hanhDongNhanVat(NhanVat& a, std::vector<Gach>& khongGianGach,
	                 const std::vector<sf::FloatRect>& khongGianHopGioiHanBanDau,
	                 const std::vector<sf::FloatRect>& khongGianHopGioiHanGach,
	                 const std::vector<sf::FloatRect>& khongGianHopGioiHanSung,
	                 std::vector<Sung>& khongGianSung, std::vector<Dan>& khongGianDan,
	                 std::vector<VuNo>& khongGianNo);

void taoHinhNhanVat(std::vector<NhanVat>& khongGian);

void nhanVatVaChamVoiVatPham(std::vector<NhanVat>& khongGianNhanVat, std::vector<VatPham>& khongGianVatPham,
	                         std::vector<sf::FloatRect>& khongGianHopGioiHanVatPham);

void capNhatNhanVat(std::vector<NhanVat>& khongGianNhanVat);