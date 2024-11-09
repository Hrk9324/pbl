#include "TaiKhoan.h"
#include "Menu.h"
#include "DonHang.h"
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

void hienThiMenuQuanLy() {
    cout << "----- QUAN LY -----" << endl;
    cout << "1. Tao tai khoan nhan vien" << endl;
    cout << "2. Quan ly menu" << endl;
    cout << "0. Thoat" << endl;
}

void hienThiMenuChucNang() {
    cout << "----- CHUC NANG QUAN LY MENU -----" << endl;
    cout << "1. Them mon an vao menu" << endl;
    cout << "2. Xoa mon an khoi menu" << endl;
    cout << "3. Sua mon an trong menu" << endl;
    cout << "4. Hien thi menu" << endl;
    cout << "0. Quay lai" << endl;
}

void ChucNangQuanLi() {
    Menu menu;
    menu.DocMenuTuFile();
    TaiKhoan taiKhoan;
    int LuaChonQuanLi;
    do {
        hienThiMenuQuanLy();
        cout << "Nhap lua chon: ";
        cin >> LuaChonQuanLi;

        switch (LuaChonQuanLi) {
            case 1:
                taiKhoan.TaoTaiKhoanNhanVien("NhanVien.txt");
                break;

            case 2: {
                int LuaChonChucNang;
                do {
                    hienThiMenuChucNang();
                    cout << "Nhap lua chon: ";
                    cin >> LuaChonChucNang;

                    switch (LuaChonChucNang) {
                        case 1: {
                            MonAn monAn;
                            monAn.setMaMon(menu.TaoMaMonAn4KyTu());
                            cout << "Nhap ten mon: ";
                            cin.ignore();  // Xóa ký tự newline còn lại trong bộ đệm
                            string tenMon;  // Tạo biến tạm để lưu tên món
                            getline(cin, tenMon);  // Đọc tên món vào biến tạm
                            monAn.setTenMon(tenMon);  // Gán tên món vào đối tượng

                            cout << "Nhap gia: ";
                            double gia;  // Tạo biến tạm để lưu giá món ăn
                            cin >> gia;  // Đọc giá vào biến gia
                            monAn.setGia(gia);  // Gán giá trị vào đối tượng monAn thông qua setter

                            menu.ThemMonAnVaoMenu(monAn);
                            break;
                        }
                        case 2: {
                            menu.HienThiMenu();
                            string maMon;
                            cout << "Nhap ma mon can xoa: ";
                            cin >> maMon;
                            menu.XoaMonAnKhoiMenu(maMon);
                            break;
                        }
                        case 3: {
                            menu.HienThiMenu();
                            string maMon;
                            cout << "Nhap ma mon can sua: ";
                            cin >> maMon;
                            menu.SuaMonAnTrongMenu(maMon);
                            break;
                        }
                        case 4:
                            menu.HienThiMenu();
                            break;
                    }
                } while (LuaChonChucNang != 0);
                break;
            }
        }
    } while (LuaChonQuanLi != 0);
}

bool DangNhapQuanLy() {
    string user, pass;
    string u = "admin", p = "123";
    cout << "Nhap username: ";
    getline(cin, user);
    cout << "Nhap password: ";
    getline(cin, pass);
    while (user != u || pass != p)
    {
        return 0;
    }
    return 1;
}

void MENU(){
    cout << "Chao mung den he thong Quan Ly!" << endl;
    int luaChon;
    do {
        cout << "----- MENU CHINH -----" << endl;
        cout << "1. Dang nhap Quan Ly" << endl;
        cout << "0. Thoat" << endl;
        cout << "Nhap lua chon: ";
        cin >> luaChon;
        switch (luaChon) {
            case 1:
                DangNhapQuanLy();
                if (DangNhapQuanLy() == 1)
                {
                    cout << "Dang nhap thanh cong, chao mung Quan Ly!" << endl;
                    ChucNangQuanLi();
                    cout << "Dang nhap thanh cong, chao mung Quan Ly!" << endl;
                    ChucNangQuanLi();
                }
                break;
            case 0:
                cout << "Cam on ban da su dung he thong!" << endl;
                break;
            default:
                cout << "Lua chon khong hop le, vui long chon lai." << endl;
                break;
        }
    } while (luaChon != 0);
}

int main() {
    MENU();
    return 0;
}