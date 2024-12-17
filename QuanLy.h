#pragma once
#include "TaiKhoan.h"

class QuanLy : public TaiKhoan {
public:
	void themMonAnVaoMenu(Menu& menu);
	void xoaMonAnKhoiMenu(Menu& menu);
	void suaMonAnTrongMenu(Menu& menu);

	void hienThiChucNang();
	void xuLyChucNang(int, Menu&, int&);
};
