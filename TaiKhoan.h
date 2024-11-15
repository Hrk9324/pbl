#ifndef TAIKHOAN_H
#define TAIKHOAN_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>
#include <unordered_set>
#include <vector>
using namespace std;

class TaiKhoan {
private:
    std::unordered_set<std::string> danhSachMaKH;
public:
    TaiKhoan();
    std::string TaoMaKhachHang();
    bool DangNhap(const string& file, string& tenDangNhap, string& matKhau);
    void TaoTaiKhoanNhanVien(const std::string& filePath);
    void TaoTaiKhoanKhachHang(const std::string& filePath);
    void XoaTaiKhoanNhanVien(const std::string& filePath);
};

#endif
