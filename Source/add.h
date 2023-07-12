#pragma once
#include "Header.h"

template<class T>
void add(std::vector<T>& khongGian, const int& Ox, const int& Oy,
	const int& chieuRong = kichCoVienGach, const int& chieuCao = kichCoVienGach);

template<class T>
void add(std::vector<T>& khongGian, const int& phanLoai, const int& Ox, const int& Oy,
	const int& chieuRong, const int& chieuCao);

#include "add.cpp"
