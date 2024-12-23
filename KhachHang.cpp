#include "KhachHang.h"

void KhachHang::hienThiChucNang() {
	Menu menu;
	menu.Gioithieu();
	cout << "---- CHUC NANG KHACH HANG----" << endl;	
	cout << "1. Goi mon" << endl;
	cout << "2. In hoa don" << endl;
	cout << "0. Dang xuat" << endl;
}

void KhachHang::xuLyChucNang(int choice, Menu &menu, int &result) {
	switch (choice) {
	case 1:
		menu.goiMon(hoaDon);
		break;
	case 2:
		hoaDon.inHoaDon();
		break;
	case 0:
		result = 0;
		break;
	default:
		cout << "Chuc nang khong ton tai" << endl;
		break;
	}
}