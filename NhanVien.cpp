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
                int soThuTuMon, soLuong;
                
                cout << "Nhap so thu tu mon an muon dat: ";
                cin >> soThuTuMon;
                
                if (soThuTuMon > 0 && soThuTuMon <= menu.GetDsMonAn().size()) {
                    MonAn monAn = menu.GetDsMonAn()[soThuTuMon - 1];
                    
                    cout << "Nhap so luong muon dat: ";
                    cin >> soLuong;

                    donHang.ThemMonAn(monAn, soLuong);

                    cout << "Da them " << soLuong << " mon '" << monAn.getTenMon() 
                              << "' vao don hang." << endl;
                } else {
                    cout << "So thu tu mon an khong hop le!" << endl;
                }
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
    std::string TenDangNhap;

    do {
        hienThiMenuChinhNhanVien();
        cout << "Nhap lua chon: ";
        cin >> LuaChon;
        TaiKhoan Tai_Khoan;

        switch (LuaChon) {
            case 1: {
                if (Tai_Khoan.DangNhap("NhanVien.txt", TenDangNhap)) {
                    cout << "Dang nhap thanh cong!" << endl;
                    chucNangNhanVien();  // Gọi menu chức năng cho nhân viên
                } else {
                    cout << "Dang nhap that bai! Ten dang nhap hoac mat khau khong dung." << endl;
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
