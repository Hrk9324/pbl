#include "TaiKhoan.h"
#include "Menu.h"
#include "DonHang.h"
#include <iostream>
#include <fstream>
#include <string>

void hienThiMenuChinhKhachHang() {
    cout << "----- CHAO MUNG DEN UNG DUNG DAT MON -----" << endl;
    cout << "1. Dang nhap" << endl;
    cout << "2. Dang ky tai khoan" << endl;
    cout << "0. Thoat" << endl;
}

void MENU(){
    int LuaChon;
    std::string TenDangNhap, MatKhau;
    Menu menu;
    DonHang donHang;
    TaiKhoan taiKhoan;

    do {
        hienThiMenuChinhKhachHang();
        cout << "Nhap lua chon: ";
        std::cin >> LuaChon;

        switch (LuaChon) {
            case 1: {
                if (taiKhoan.DangNhap("KhachHang.txt", TenDangNhap, MatKhau)) { //không đăng nhập được
                    menu.HienThiMenu();
                    menu.GoiMon(); 
                }
                break;
            }
            case 2: {
                taiKhoan.TaoTaiKhoanKhachHang("KhachHang.txt");
                break;
            }
            case 0: {
                cout << "Thoat chuong trinh." << endl;
                break;
            }
            default: {
                cout << "Lua chon khong hop le!" << endl;
            }
        }
    } while (LuaChon != 0);
}

int main() {
    MENU();
    return 0;
}
