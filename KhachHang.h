#pragma once
#include "TaiKhoan.h"
#include "HoaDon.h"
class KhachHang : public TaiKhoan {
	HoaDon hoaDon;
public:
	void hienThiChucNang();
	void xuLyChucNang(int, Menu &, int &);
};

