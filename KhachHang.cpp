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

void menuChucNang(){
    cout << "---- Moi chon chuc nang ----" << endl;
    cout << "1. Hien thi menu." << endl;
    cout << "2. Chon Mon." << endl;
    cout << "3. In Hoa Don" << endl;
    cout << "0. Tro Ve." << endl;
}

void ChucNang(){
    int LuaChon;
    Menu menu;    
    HoaDon hoaDon;
    DonHang donHang;
    
    menu.DocMenuTuFile("Menu.txt");
    do
    {
        menuChucNang();
        cout << "Nhap lua chon: ";
        cin >> LuaChon;
        switch (LuaChon)
        {
        case 1: {
            menu.HienThiMenu();
            break;
        }
            
        case 2:{
            menu.HienThiMenu();
            menu.GoiMon();
            break;
        }
            
        case 3:{
            std::string MaKH = hoaDon.DocMSKH("KhachHang.txt");
            hoaDon.InHoaDon(donHang, MaKH, "HoaDon.txt");
            break;
        }
            
        default:{
            break;
        }
            
        }
    } while (LuaChon != 0);
    
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
                    // cout << "Moi quy khach dat mon!" << endl;
                    // menu.HienThiMenu();
                    // menu.GoiMon(); 
                    // string MSKH = hoaDon.DocMSKH("khachHang.txt");
                    // hoaDon.InHoaDon(donHang, MSKH, "HoaDon.txt");
                    ChucNang();
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
                break;
            }
        }
    } while (LuaChon != 0);
}

int main() {
    MENU();
    return 0;
}
