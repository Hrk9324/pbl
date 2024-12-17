#pragma once
#include "TaiKhoan.h"
#include "Menu.h"
class NhanVien : public TaiKhoan {
	HoaDon hoaDon;
public:
	void hienThiChucNang();
	void xuLyChucNang(int, Menu&, int&);
};
