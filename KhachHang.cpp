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

// void DangKyKhachHang(const std::string& filePath) {
//     std::string tenKhachHang, username, password;
//     std::ofstream fileOut(filePath, std::ios::app);
    
//     cout << "Nhap ten khach hang: ";
//     std::cin.ignore();
//     getline(std::cin, tenKhachHang);

//     cout << "Nhap ten dang nhap: ";
//     std::cin >> username;
//     cout << "Nhap mat khau: ";
//     std::cin >> password;
    
//     if (fileOut.is_open()) {
//         std::string maKhachHang = TaiKhoan::TaoMaKhachHang();  // Tạo mã khách hàng tự động
//         fileOut << maKhachHang << ", " << tenKhachHang << ", " << username << ", " << password << endl;
//         cout << "Dang ky thanh cong voi ma khach hang: " << maKhachHang << endl;
//     } else {
//         cout << "Khong the mo file de dang ky." << endl;
//     }
// }

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

                    int SoThuTuMon, SoLuong;
                    cout << "Chon so thu tu mon an muon dat: ";
                    std::cin >> SoThuTuMon;

                    if (SoThuTuMon > 0 && SoThuTuMon <= menu.GetDsMonAn().size()) {
                        MonAn monAn = menu.GetDsMonAn()[SoThuTuMon - 1];
                        cout << "Nhap so luong muon dat: ";
                        std::cin >> SoLuong;

                        // Kiểm tra số lượng hợp lệ
                        if (SoLuong > 0) {
                            donHang.ThemMonAn(monAn, SoLuong);
                            cout << "Da them " << SoLuong << " mon '" << monAn.getTenMon() << "' vao don hang." << endl;
                            donHang.HienThiDonHang();  // Hiển thị chi tiết đơn hàng
                        } else {
                            cout << "So luong khong hop le!" << endl;
                        }
                    } else {
                        cout << "So thu tu khong hop le!" << endl;
                    }
                } else {
                    cout << "Dang nhap that bai!" << endl;
                }
                break;
            }
            case 2: {
                // DangKyKhachHang("KhachHang.txt");
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
