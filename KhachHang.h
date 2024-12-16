#ifndef KHACHHANG_H
#define KHACHHANG_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "MonAn.h"
#include "Menu.h"

using namespace std;

// Lớp Khách Hàng
class KhachHang {
public:
    int maKhachHang;
    string tenKhachHang;
    string username;
    string password;

    // Hàm nhập mật khẩu với dấu *
    static string getPassword();

    // Đọc tài khoản khách hàng từ file
    static void docTaiKhoanKhachHangFromFile(vector<KhachHang>& danhSachKhachHang);

    // Ghi tài khoản khách hàng vào file
    static void ghiTaiKhoanKhachHangToFile(const vector<KhachHang>& danhSachKhachHang);

    // Tạo tài khoản khách hàng
    static void taoTaiKhoanKhachHang(vector<KhachHang>& danhSachKhachHang);

    // Đăng nhập
    static KhachHang* dangNhap(vector<KhachHang>& danhSachKhachHang);

    // Hàm gọi món và in hóa đơn
    static void goiMon(Menu& menu, KhachHang* kh);
};

#endif
