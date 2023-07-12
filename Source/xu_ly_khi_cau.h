#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "khi_cau.h"
#include "vat_pham.h"


void taoHinhKhiCau(KhiCau& khiCau);

void hanhDongKhiCau(KhiCau& a, std::vector<VatPham>& khongGianVatPham);
