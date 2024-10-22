#include "TaiKhoan.h"
#include "Menu.h"
#include "DonHang.h"

void hienThiMenuChinhKhachHang() {
    cout << "----- CHAO MUNG DEN UNG DUNG DAT MON -----" << endl;
    cout << "1. Dang nhap" << endl;
    cout << "2. Dang ky tai khoan" << endl;
    cout << "0. Thoat" << endl;
}

int main() {
    int LuaChon;
    string TenDangNhap;
    Menu menu;
    DonHang Don_Hang;

    do {
        hienThiMenuChinhKhachHang();
        cout << "Nhap lua chon: ";
        cin >> LuaChon;
        TaiKhoan Tai_Khoan;
        switch (LuaChon) {
            case 1: {
                if (Tai_Khoan.DangNhap("KhachHang.txt", TenDangNhap)) {
                    menu.HienThiMenu();
                
                int SoThuTuMon, SoLuong;
                cout << "Chon so thu tu mon an muon dat: ";
                cin >> SoThuTuMon;

                if (SoThuTuMon > 0 && SoThuTuMon <= menu.GetDsMonAn.size()) {
                    MonAn monAn = menu.GetDsMonAn[SoThuTuMon - 1];
                    cout << "Nhap so luong muon dat: ";
                    cin >> SoLuong;

                    for (int i = 0; i < SoLuong; ++i) {
                        Don_Hang.ThemMonAn(monAn);
                    }

                    cout << "Da them " << SoLuong << " mon '" << monAn.GetTenMon() << "' vao don hang." << endl;
                } else {
                    cout << "So thu tu khong hop le!" << endl;
                }
                }
                break;
            }
            case 2: {
                //DangKyKhachHang("KhachHang.txt");  thiếu hàm đăng kí mẹ r, m bảo t fix kiểu éo j.
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

