#pragma once
#include "Menu.h"
class TaiKhoan {
protected:
	// -1: Khong xac dinh, 0: Khach hang, 1: Nhan vien, 2: Quan ly
    int role;
    int maTaiKhoan;
    string tenNguoiDung;
    string username;
    string password;
public:
    TaiKhoan();
    TaiKhoan(int, int, const string&, const string&, const string&);

	int getRole() const;
    int getMaTaiKhoan() const;
    string getTenNguoiDung() const;
    string getUsername() const;
    string getPassword() const;

    void setRole(int);
    void setMaTaiKhoan(int);
    void setTenNguoiDung(const string&);
    void setUsername(const string&);
    void setPassword(const string&);

    virtual void hienThiChucNang();
    virtual void xuLyChucNang(int, Menu&, int&);
};

