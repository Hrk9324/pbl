#ifndef QUANLY_H
#define QUANLY_H

#include <string>
#include "Menu.h"
#include "TaiKhoan.h"

using namespace std;

// Lớp Quản lý
class QuanLy {
public:
    // Hàm đăng nhập cho quản lý
    static bool dangNhapQuanLy();

    // Hàm tạo tài khoản cho nhân viên
    static void taoTaiKhoanNhanVien();

    // Hàm xóa tài khoản nhân viên
    static void xoaTaiKhoanNhanVien();

    // Hàm thêm món ăn vào menu
    static void themMonAnVaoMenu(Menu& menu);

    // Hàm xóa món ăn khỏi menu
    static void xoaMonAnKhoiMenu(Menu& menu);

    // Hàm sửa món ăn trong menu
    static void suaMonAnTrongMenu(Menu& menu);

    // Hàm hiển thị menu quản lý
    static void hienThiMenuQuanLy();
};

#endif // QUANLY_H
