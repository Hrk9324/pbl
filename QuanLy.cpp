#include "QuanLy.h"

void QuanLy::themMonAnVaoMenu(Menu& menu) {
	string tenMonAn;
	cout << "Nhap ten mon an: ";
	getline(cin, tenMonAn);
	string gia_str;
	cout << "Nhap gia mon an: ";
	cin >> gia_str;
	while (!kiemTraSo(gia_str)) {
		cout << "Vui long nhap mot so hop le!\n";
		cout << "Nhap ma mon an can xoa: ";
		cin >> gia_str;
	}
	int gia = stoi(gia_str);
	cin.ignore();
	menu.themMonAn(tenMonAn, gia);
}

void QuanLy::xoaMonAnKhoiMenu(Menu& menu) {
	menu.hienThiMenu();
	string maMonAn_str;
	cout << "Nhap ma mon an can xoa: ";
	cin >> maMonAn_str;
	while (!kiemTraSo(maMonAn_str)) {
		cout << "Vui long nhap mot so hop le!\n";
		cout << "Nhap ma mon an can xoa: ";
		cin >> maMonAn_str;
	}
	int maMonAn = stoi(maMonAn_str);
	menu.xoaMonAn(maMonAn);
}

void QuanLy::suaMonAnTrongMenu(Menu& menu) {
	menu.hienThiMenu();
	string maMonAn_str;
	cout << "Nhap ma mon an can sua: ";
	cin >> maMonAn_str;
	while (!kiemTraSo(maMonAn_str)) {
		cout << "Vui long nhap mot so hop le!\n";
		cout << "Nhap ma mon an can sua: ";
		cin >> maMonAn_str;
	}
	int maMonAn = stoi(maMonAn_str);
	cin.ignore();
	string tenMonAn;
	cout << "Nhap ten mon an: ";
	getline(cin, tenMonAn);
	string gia_str;
	cout << "Nhap gia mon an: ";
	cin >> gia_str;
	while (!kiemTraSo(gia_str)) {
		cout << "Vui long nhap mot so hop le!\n";
		cout << "Nhap ma mon an can xoa: ";
		cin >> gia_str;
	}
	int gia = stoi(gia_str);
	cin.ignore();
	menu.suaMonAn(maMonAn, tenMonAn, gia);
}

void QuanLy::hienThiChucNang() {
	cout << "---- CHUC NANG QUAN LY----" << endl;
	cout << "1. Hien thi danh sach mon an" << endl;
	cout << "2. Them mon an vao menu" << endl;
	cout << "3. Xoa mon an khoi menu" << endl;
	cout << "4. Sua mon an trong menu" << endl;
	cout << "5. Hien thi danh sach nhan vien" << endl;
	cout << "6. Them tai khoan nhan vien" << endl;
	cout << "7. Xoa tai khoan nhan vien" << endl;
	cout << "8. Sua tai khoan nhan vien" << endl;
	cout << "0. Dang xuat" << endl;
}

void QuanLy::xuLyChucNang(int choice, Menu& menu, int& result) {
	switch (choice) {
	case 1:
		menu.hienThiMenu();
		break;
	case 2:
		themMonAnVaoMenu(menu);
		break;
	case 3:
		xoaMonAnKhoiMenu(menu);
		break;
	case 4:
		suaMonAnTrongMenu(menu);
		break;
	case 5:
		result = 4;
		break;
	case 6:
		result = 1;
		break;
	case 7:
		result = 2;
		break;
	case 8:
		result = 3;
		break;
	case 0:
		result = 0;
		break;
	default:
		cout << "Chuc nang khong ton tai" << endl;
		break;
	}
}