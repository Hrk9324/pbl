#include "TaiKhoan.h"
#include "MonAn.h"
#include "Menu.h"

void hienThiMenuQuanLy() {
    cout << "----- QUAN LY -----" << endl;
    cout << "1. Tao tai khoan nhan vien" << endl;
    cout << "2. Dang nhap" << endl;
    cout << "0. Thoat" << endl;
}



int main() {
    int LuaChon;
    string TenDangNhap;
    string monan;

    do {
        hienThiMenuQuanLy();
        cout << "Nhap lua chon: ";
        cin >> LuaChon;
        Menu menu;
        TaiKhoan Tai_Khoan;
        switch (LuaChon) {
            case 1: {
                //TaoTaiKhoanNhanVien("NhanVien.txt");
                break;
            }
            case 2: {
                if (Tai_Khoan.DangNhap("QuanLy.txt", TenDangNhap)) {
                    // chuc nang quan li
                }
                break;
            }
            case 3: {
                menu.ThemMonAnVaoMenu(monan);
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

    return 0;
}

