#include "TaiKhoan.h"

TaiKhoan::TaiKhoan()
	:role(-1), maTaiKhoan(0), tenNguoiDung(""), username(""), password("") {}

TaiKhoan::TaiKhoan(int role, int ma, const string& ten, const string& username, const string& password)
	:role(role), maTaiKhoan(ma), tenNguoiDung(ten), username(username), password(password) {}

void TaiKhoan::setRole(int role) {
	this->role = role;
}

void TaiKhoan::setMaTaiKhoan(int ma) {
	maTaiKhoan = ma;
}

void TaiKhoan::setTenNguoiDung(const string& ten) {
	tenNguoiDung = ten;
}

void TaiKhoan::setUsername(const string& user) {
	username = user;
}

void TaiKhoan::setPassword(const string& pass) {
	password = pass;
}

int TaiKhoan::getRole() const {
	return role;
}

int TaiKhoan::getMaTaiKhoan() const {
	return maTaiKhoan;
}

string TaiKhoan::getTenNguoiDung() const {
	return tenNguoiDung;
}

string TaiKhoan::getUsername() const {
	return username;
}

string TaiKhoan::getPassword() const {
	return password;
}

void TaiKhoan::hienThiChucNang() {
	cout << "Chuc nang cua tai khoan khong xac dinh" << endl;
}

void TaiKhoan::xuLyChucNang(int choice, Menu& menu, int& result) {
	cout << "Chuc nang cua tai khoan khong xac dinh" << endl;
}