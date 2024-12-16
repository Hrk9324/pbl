#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <iostream>
#include <fstream>
#include <string>
#include "Menu.h"

class NhanVien {
private:
    int maNhanVien;              // Mã nhân viên
    std::string tenNhanVien;      // Tên nhân viên
    std::string username;         // Username của nhân viên
    std::string password;         // Mật khẩu của nhân viên

public:
    NhanVien(int maNhanVien = 0, const std::string& tenNhanVien = "", const std::string& username = "", const std::string& password = "")
        : maNhanVien(maNhanVien), tenNhanVien(tenNhanVien), username(username), password(password) {}

    static bool dangNhap();  // Phương thức đăng nhập cho nhân viên
    static void goiMon(Menu& menu);  // Chức năng gọi món cho nhân viên chạy bàn

    // Các phương thức getter để truy xuất thông tin của nhân viên
    int getMaNhanVien() const { return maNhanVien; }
    std::string getTenNhanVien() const { return tenNhanVien; }
    std::string getUsername() const { return username; }
    std::string getPassword() const { return password; }

    static std::string getPasswordInput();  // Hàm tĩnh để ẩn mật khẩu khi nhập
};

#endif // NHANVIEN_H
