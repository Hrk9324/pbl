#include "NhanVien.h"

void NhanVien::hienThiChucNang() {
	Menu menu;
	menu.Gioithieu();
    cout << "----- CHUC NANG NHAN VIEN -----" << endl;
    cout << "1. Dat Mon" << endl;
    cout << "2. In hoa don" << endl;
	cout << "3. Dat lai hoa don" << endl;
    cout << "0. Dang xuat" << endl;
}

void NhanVien::xuLyChucNang(int choice, Menu& menu, int& result) {
	switch (choice) {
	case 1:
		menu.goiMon(hoaDon);
		break;
	case 2:
		hoaDon.inHoaDon();
		break;
	case 3:
		hoaDon.clearHoaDon();
		break;
	case 0:
		result = 0;
		break;
	default:
		cout << "Chuc nang khong ton tai" << endl;
		break;
	}
}