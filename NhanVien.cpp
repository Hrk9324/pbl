#include "TaiKhoan.h"

void hienThiMenuChinhNhanVien() {
    cout << "----- DANG NHAP NHAN VIEN -----" << endl;
    cout << "1. Dang nhap" << endl;
    cout << "0. Thoat" << endl;
}

int main() {
    int LuaChon;
    string TenDangNhap;

    do {
        hienThiMenuChinhNhanVien();
        cout << "Nhap lua chon: ";
        cin >> LuaChon;
        TaiKhoan Tai_Khoan;
        switch (LuaChon) {
            case 1: {
                if (Tai_Khoan.DangNhap("NhanVien.txt", TenDangNhap)) {
                    // chuc nang nhan vien
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

    return 0;
}

