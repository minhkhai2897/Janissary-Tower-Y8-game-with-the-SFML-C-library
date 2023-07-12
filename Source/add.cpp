#pragma once
#include "Header.h"

template<class T>
void add(std::vector<T>& khongGian, const int& Ox, const int& Oy,
	const int& chieuRong, const int& chieuCao)
{
	T a(Ox, Oy, chieuRong, chieuCao);
	khongGian.push_back(a);
}

template<class T>
void add(std::vector<T>& khongGian, const int& phanLoai, const int& Ox, const int& Oy,
	const int& chieuRong, const int& chieuCao)
{
	T a(Ox, Oy, chieuRong, chieuCao, phanLoai);
	khongGian.push_back(a);
}

