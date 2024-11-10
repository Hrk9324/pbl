#include "TaiKhoan.h"
#include "Menu.h"
#include "DonHang.h"
#include "HoaDon.h"
#include <iostream>
#include <string>

void hienThiMenuChinhNhanVien() {
    cout << "----- DANG NHAP NHAN VIEN -----" << endl;
    cout << "1. Dang nhap" << endl;
    cout << "0. Thoat" << endl;
}

void hienThiMenuChucNangNhanVien() {
    cout << "----- CHUC NANG NHAN VIEN -----" << endl;
    cout << "1. Dat hang" << endl;
    cout << "2. In hoa don" << endl;
    cout << "3. Xem thuc don" << endl;
    cout << "0. Dang xuat" << endl;
}

void chucNangNhanVien() {
    Menu menu;
    DonHang donHang;
    HoaDon hoaDon;
    int luaChon;

    do {
        hienThiMenuChucNangNhanVien();
        cout << "Nhap lua chon: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1: {
                // Chức năng đặt hàng
                menu.HienThiMenu();
                menu.GoiMon;
                break;
            }
            case 2: {
                // In hóa đơn
                std::string maSoKhachHang = "MSKH1234"; // Ví dụ mã khách hàng
                hoaDon.InHoaDon(donHang, maSoKhachHang, "HoaDon.txt");
                break;
            }
            case 3: {
                // Hiển thị thực đơn
                menu.HienThiMenu();
                break;
            }
            case 0: {
                cout << "Dang xuat." << endl;
                break;
            }
            default: {
                cout << "Lua chon khong hop le!" << endl;
            }
        }
    } while (luaChon != 0);
}

void MENU(){
    int LuaChon;
    std::string TenDangNhap, MatKhau;

    do {
        hienThiMenuChinhNhanVien();
        cout << "Nhap lua chon: ";
        cin >> LuaChon;
        TaiKhoan Tai_Khoan;

        switch (LuaChon) {
            case 1: {
                if (Tai_Khoan.DangNhap("NhanVien.txt", TenDangNhap, MatKhau)) { //đang còn lỗi đăng nhập m coi thử fix đc ko
                    chucNangNhanVien();  // Gọi menu chức năng cho nhân viên
                }
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
