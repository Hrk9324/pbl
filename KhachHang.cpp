#include "TaiKhoan.h"
#include "Menu.h"
#include "DonHang.h"
#include <iostream>
#include <fstream>
#include <string>
#include "HoaDon.h"

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
    HoaDon hoaDon;
    DonHang donHang;
    TaiKhoan taiKhoan;
    menu.DocMenuTuFile("Menu.txt");
    // menu.ThemMonAnTuFile();
    // system("pause");
    do {
        hienThiMenuChinhKhachHang();
        cout << "Nhap lua chon: ";
        std::cin >> LuaChon;

        switch (LuaChon) {
            case 1: {
                if (taiKhoan.DangNhap("KhachHang.txt", TenDangNhap, MatKhau)) {
                    cout << "Moi quy khach dat mon!" << endl;
                    menu.HienThiMenu();
                    menu.GoiMon(); 
                    string MSKH = hoaDon.DocMSKH("khachHang.txt");
                    hoaDon.InHoaDon(donHang, MSKH, "HoaDon.txt");
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
