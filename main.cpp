#include <iostream>
#include "Menu.h"
#include "DSTaiKhoan.h"
using namespace std;
TaiKhoan* taiKhoanHienTai = nullptr;
bool working(DSTaiKhoan &DSTK, Menu &menu) {
	if (taiKhoanHienTai == nullptr) {
		system("cls");
		cout << "---- DANH SACH CHUC NANG ----\n";
		cout << "1. Dang nhap\n";
		cout << "2. Dang ky\n";
		cout << "0. Thoat\n";
		cout << "Nhap lua chon: ";
		string choice_str;
		cin >> choice_str;
		while (!kiemTraSo(choice_str)) {
			cout << "Vui long nhap mot so hop le!\n";
			cin >> choice_str;
		}
		cin.ignore();
		int choice = stoi(choice_str);
		switch (choice) {
		case 1:
			taiKhoanHienTai = DSTK.dangNhap();
			break;
		case 2:
			DSTK.taoTaiKhoanKhachHang();
			break;
		case 0:
			return false;
		default:
			cout << "Lua chon khong hop le!\n";
			break;
		}
		system("pause");
	}
	else {
		system("cls");
		int result = -1;	
		string choice_str;
		taiKhoanHienTai->hienThiChucNang();

		cout << "Nhap lua chon: ";
		cin >> choice_str;
		while (!kiemTraSo(choice_str)) {
			cout << "Vui long nhap mot so hop le!\n";
			cout << "Nhap lua chon: ";
			cin >> choice_str;
		}
		cin.ignore();
		int choice = stoi(choice_str);

		taiKhoanHienTai->xuLyChucNang(choice, menu, result);
		switch (result) {
		case 0:
			taiKhoanHienTai = nullptr;
			break;
		case 1:
			DSTK.taoTaiKhoanNhanVien();
			break;
		case 2:
			DSTK.xoaTaiKhoanNhanVien();
			break;
		case 3:
			DSTK.suaTaiKhoanNhanVien();
			break;
		case 4:
			DSTK.hienThiDSTaiKhoanNhanVien();
			break;
		default:
			break;
		}
		system("pause");
	}
	return true;
}

int main() {
	// g++ .\DSTaiKhoan.cpp .\HamTienIch.cpp .\KhachHang.cpp .\Menu.cpp .\MonAn.cpp .\NhanVien.cpp .\QuanLy.cpp .\TaiKhoan.cpp .\HoaDon.cpp .\main.cpp
	// Khởi tạo menu và danh sách tài khoản
	Menu menu;
	menu.docMenuFromFile();
	DSTaiKhoan DSTK;
	DSTK.docDSTaiKhoanFromFile();
	// Bắt đầu chương trình
	while (working(DSTK, menu));
	// Lưu dữ liệu
	menu.ghiMenuToFile();
	DSTK.ghiDSTaiKhoanToFile();
	return 0;
}