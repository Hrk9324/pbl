#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "TaiKhoan2.h"
#include "MonAn.h"
#include "Menu2.h"

using namespace std;

// Hàm đăng nhập quản lý
bool dangNhapQuanLy() {
    string username, password;

    cout << "Nhap username: ";
    getline(cin, username);

    cout << "Nhap password: ";
    password = TaiKhoan::getPassword();  // Dùng hàm getPassword để ẩn mật khẩu

    if (username == "administrator" && password == "adminn123") {
        cout << "Dang nhap thanh cong!" << endl;
        return true;
    } else {
        cout << "Username hoac password sai!" << endl;
        return false;
    }
}

// Hàm tạo tài khoản nhân viên
//void taoTaiKhoanNhanVien() {
//    TaiKhoan::taoTaiKhoanNhanVien();
//}
void taoTaiKhoanNhanVien() {
    string tenNhanVien, username, password;

    cout << "Nhap ten nhan vien: ";
    cin.ignore();  // Bỏ qua ký tự newline còn lại trong bộ đệm
    getline(cin, tenNhanVien);  // Đọc tên nhân viên

    cout << "Nhap username: ";
    getline(cin, username);  // Đọc username

    cout << "Nhap password: ";
    getline(cin, password);  // Đọc password

    // Tạo đối tượng TaiKhoan và gọi hàm tạo tài khoản
    TaiKhoan taiKhoan;
    taiKhoan.taoTaiKhoanNhanVien(tenNhanVien, username, password);
}


// Hàm xóa tài khoản nhân viên
void xoaTaiKhoanNhanVien() {
    TaiKhoan::xoaTaiKhoanNhanVien();
}

// Hàm thêm món ăn vào menu
void themMonAnVaoMenu(Menu& menu) {
    string tenMon;
    int giaTien;

    cout << "Nhap ten mon an: ";
    cin.ignore();
    getline(cin, tenMon);

    cout << "Nhap gia tien: ";
    cin >> giaTien;

    menu.themMonAn(tenMon, giaTien);  // Gọi hàm thêm món ăn vào menu
}

// Hàm xóa món ăn khỏi menu
void xoaMonAnKhoiMenu(Menu& menu) {
	int maMon;
	std::cout << "Nhap ma mon an muon xoa: ";
	std::cin >> maMon;
	menu.xoaMonAn(maMon);  // Gọi hàm xóa món ăn với mã đã nhập

}

void suaMonAnTrongMenu(Menu& menu) {
    int maMon;
    string tenMonMoi;
    int giaTienMoi;

    cout << "Nhap ma mon an can sua: ";
    cin >> maMon;

    cout << "Nhap ten mon an moi: ";
    cin.ignore();
    getline(cin, tenMonMoi);

    cout << "Nhap gia tien moi: ";
    cin >> giaTienMoi;

    // Gọi phương thức suaMonAn với các tham số
    menu.suaMonAn(maMon, tenMonMoi, giaTienMoi);
}


// Hàm menu quản lý
void hienThiMenuQuanLy() {
    Menu menu;
    menu.docMenuFromFile();  // Đọc dữ liệu menu từ file khi khởi động chương trình
    int luaChon;

    while (true) {
        cout << "\n===== MENU QUAN LY =====" << endl;
        cout << "1. Tao tai khoan nhan vien" << endl;
        cout << "2. Xoa tai khoan nhan vien" << endl;
        cout << "3. Them mon an vao menu" << endl;
        cout << "4. Xoa mon an khoi menu" << endl;
        cout << "5. Sua mon an trong menu" << endl;
        cout << "6. Thoat" << endl;

        cout << "Nhap lua chon: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1:
                taoTaiKhoanNhanVien();
                break;
            case 2:
                xoaTaiKhoanNhanVien();
                break;
            case 3:
                themMonAnVaoMenu(menu);
                break;
            case 4:
                xoaMonAnKhoiMenu(menu);
                break;
            case 5:
                suaMonAnTrongMenu(menu);
                break;
            case 6:
                menu.ghiMenuToFile();  // Ghi lại menu vào file trước khi thoát
                cout << "Thoat chuong trinh!" << endl;
                return;
            default:
                cout << "Lua chon khong hop le!" << endl;
        }
    }
}

// Hàm main
int main() {
    if (dangNhapQuanLy()) {
        hienThiMenuQuanLy();  // Sau khi đăng nhập thành công, hiển thị menu quản lý
    } else {
        cout << "Dang nhap khong thanh cong. Thoat chuong trinh!" << endl;
    }

    return 0;
}
