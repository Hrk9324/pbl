#include <iostream>
#include <fstream>
#include <string>
#include "QuanLy.h"
#include "KhachHang.h"
#include "NhanVien.h"

using namespace std;

// Hàm kiểm tra đăng nhập
bool dangNhap(string& username, string& password) {
    cout << "Nhap username: ";
    getline(cin, username);

    cout << "Nhap password: ";
    password = TaiKhoan::getPassword();  // Dùng hàm getPassword từ TaiKhoan để ẩn mật khẩu
    return true;
}

// Hàm xác định vai trò của người dùng
void kiemTraVaiTro(string username, string password) {
    // Kiểm tra xem người dùng là Quản lý
    if (username == "administrator" && password == "adminn123") {
        cout << "Dang nhap thanh cong voi vai tro QUAN LY!" << endl;
        QuanLy::hienThiMenuQuanLy();  // Chạy chức năng Quản lý
    } 
    // Kiểm tra xem người dùng là Nhân viên
    else {
        ifstream nhanVienFile("NhanVien.txt");
        string line;
        while (getline(nhanVienFile, line)) {
            size_t pos = line.find(",");
            string storedUsername = line.substr(pos + 1, line.find(",", pos + 1) - pos - 1);
            string storedPassword = line.substr(line.rfind(",") + 1);
            
            if (username == storedUsername && password == storedPassword) {
                cout << "Dang nhap thanh cong voi vai tro NHAN VIEN!" << endl;
                NhanVien nhanVien;
                nhanVien.dangNhap();
                nhanVien.goiMon();  // Nhân viên gọi món
                return;
            }
        }
    }

    // Kiểm tra xem người dùng là Khách hàng
    ifstream khachHangFile("KhachHang.txt");
    while (getline(khachHangFile, line)) {
        size_t pos = line.find(",");
        string storedUsername = line.substr(pos + 1, line.find(",", pos + 1) - pos - 1);
        string storedPassword = line.substr(line.rfind(",") + 1);
        
        if (username == storedUsername && password == storedPassword) {
            cout << "Dang nhap thanh cong voi vai tro KHACH HANG!" << endl;
            KhachHang khachHang;
            khachHang.dangNhap();
            khachHang.goiMon();  // Khách hàng gọi món
            return;
        }
    }

    cout << "Tai khoan hoac mat khau sai!" << endl;
}

int main() {
    string username, password;
    if (dangNhap(username, password)) {
        kiemTraVaiTro(username, password);  // Kiểm tra và xác định vai trò sau khi đăng nhập
    }
    return 0;
}
