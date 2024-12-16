#include "TaiKhoan.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <conio.h>  // Để ẩn mật khẩu khi nhập

using namespace std;

// Khởi tạo các biến tĩnh
vector<TaiKhoan::TaiKhoanNhanVien> TaiKhoan::danhSachNhanVien;
vector<TaiKhoan::TaiKhoanKhachHang> TaiKhoan::danhSachKhachHang;
int TaiKhoan::maNhanVienCounter = 1;  // Mã nhân viên bắt đầu từ 1
int TaiKhoan::maKhachHangCounter = 1; // Mã khách hàng bắt đầu từ 1

// Đọc tài khoản nhân viên từ file
void TaiKhoan::docTaiKhoanNhanVienFromFile() {
    ifstream file("NhanVien.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            TaiKhoanNhanVien nv;
            string password;
            getline(ss, line, ',');
            nv.maNhanVien = stoi(line);
            getline(ss, nv.tenNhanVien, ',');
            getline(ss, nv.username, ',');
            getline(ss, password, ',');
            nv.password = password;
            danhSachNhanVien.push_back(nv);
        }
        file.close();
    }
}

// Đọc tài khoản khách hàng từ file
void TaiKhoan::docTaiKhoanKhachHangFromFile() {
    ifstream file("KhachHang.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            TaiKhoanKhachHang kh;
            string password;
            getline(ss, line, ',');
            kh.maKhachHang = stoi(line);
            getline(ss, kh.tenKhachHang, ',');
            getline(ss, kh.username, ',');
            getline(ss, password, ',');
            kh.password = password;
            danhSachKhachHang.push_back(kh);
        }
        file.close();
    }
}

// Lưu tài khoản nhân viên vào file
void TaiKhoan::ghiTaiKhoanNhanVienToFile() {
    ofstream file("NhanVien.txt");
    if (file.is_open()) {
        for (const auto& nv : danhSachNhanVien) {
            file << nv.maNhanVien << ", "
                 << nv.tenNhanVien << ", "
                 << nv.username << ", "
                 << nv.password << endl;
        }
        file.close();
    }
}

// Lưu tài khoản khách hàng vào file
void TaiKhoan::ghiTaiKhoanKhachHangToFile() {
    ofstream file("KhachHang.txt");
    if (file.is_open()) {
        for (const auto& kh : danhSachKhachHang) {
            file << kh.maKhachHang << ", "
                 << kh.tenKhachHang << ", "
                 << kh.username << ", "
                 << kh.password << endl;
        }
        file.close();
    }
}

std::string TaiKhoan::getPassword() {
    std::string password = "";
    char ch;
    while ((ch = _getch()) != 13) { // 13 là mã ASCII của phím Enter
        if (ch == 8) { // 8 là mã ASCII của phím Backspace
            if (password.length() > 0) {
                password.pop_back();
                std::cout << "\b \b"; // Xóa dấu *
            }
        } else {
            password += ch;
            std::cout << "*"; // Hiển thị dấu *
        }
    }
    std::cout << std::endl;
    return password;
}


// Hàm tạo tài khoản nhân viên
//void TaiKhoan::taoTaiKhoanNhanVien() {
//    string tenNhanVien, username, password;
//
//    cout << "Nhap ten nhan vien: ";
//    cin.ignore();
//    getline(cin, tenNhanVien);
//
//    cout << "Nhap username: ";
//    getline(cin, username);
//
//    cout << "Nhap password: ";
//    password = getPassword(); // Dùng hàm để ẩn mật khẩu
//
//    TaiKhoanNhanVien nv;
//    nv.maNhanVien = maNhanVienCounter++;
//    nv.tenNhanVien = tenNhanVien;
//    nv.username = username;
//    nv.password = password;
//
//    danhSachNhanVien.push_back(nv);
//    ghiTaiKhoanNhanVienToFile();
//    cout << "Tao tai khoan nhan vien thanh cong!" << endl;
//}

void TaiKhoan::taoTaiKhoanNhanVien(const std::string& tenNhanVien, const std::string& username, const std::string& password) {
    std::ofstream file("NhanVien.txt", std::ios::app);  // Mở file với chế độ append để ghi thêm dữ liệu
    if (file.is_open()) {
        // Tạo mã nhân viên tự động (dựa trên số dòng trong file)
        int maNhanVien = 1;
        std::ifstream fileCheck("NhanVien.txt");
        std::string line;
        while (std::getline(fileCheck, line)) {
            maNhanVien++;  // Đếm số lượng nhân viên hiện có trong file để tạo mã mới
        }
        fileCheck.close();

        // Ghi thông tin tài khoản nhân viên vào file
        file << maNhanVien << ", " << tenNhanVien << ", " << username << ", " << password << std::endl;
        file.close();
        std::cout << "Tao tai khoan thanh cong cho " << tenNhanVien << std::endl;
    } else {
        std::cerr << "Khong the mo file!" << std::endl;
    }
}


// Hàm xóa tài khoản nhân viên
void TaiKhoan::xoaTaiKhoanNhanVien() {
    int maNhanVien;
    cout << "Nhap ma nhan vien can xoa: ";
    cin >> maNhanVien;
    cin.ignore();

    for (auto it = danhSachNhanVien.begin(); it != danhSachNhanVien.end(); ++it) {
        if (it->maNhanVien == maNhanVien) {
            danhSachNhanVien.erase(it);
            ghiTaiKhoanNhanVienToFile();
            cout << "Xoa tai khoan nhan vien thanh cong!" << endl;
            return;
        }
    }
    cout << "Khong tim thay nhan vien!" << endl;
}

// Hàm tạo tài khoản khách hàng
void TaiKhoan::taoTaiKhoanKhachHang() {
    string tenKhachHang, username, password;

    cout << "Nhap ten khach hang: ";
    getline(cin, tenKhachHang);

    cout << "Nhap username: ";
    getline(cin, username);

    cout << "Nhap password: ";
    password = getPassword(); // Dùng hàm để ẩn mật khẩu

    TaiKhoanKhachHang kh;
    kh.maKhachHang = maKhachHangCounter++;
    kh.tenKhachHang = tenKhachHang;
    kh.username = username;
    kh.password = password;

    danhSachKhachHang.push_back(kh);
    ghiTaiKhoanKhachHangToFile();
    cout << "Tao tai khoan khach hang thanh cong!" << endl;
}

// Hàm xóa tài khoản khách hàng
void TaiKhoan::xoaTaiKhoanKhachHang() {
    int maKhachHang;
    cout << "Nhap ma khach hang can xoa: ";
    cin >> maKhachHang;
    cin.ignore();

    for (auto it = danhSachKhachHang.begin(); it != danhSachKhachHang.end(); ++it) {
        if (it->maKhachHang == maKhachHang) {
            danhSachKhachHang.erase(it);
            ghiTaiKhoanKhachHangToFile();
            cout << "Xoa tai khoan khach hang thanh cong!" << endl;
            return;
        }
    }
    cout << "Khong tim thay khach hang!" << endl;
}

// Hàm đăng nhập
bool TaiKhoan::dangNhap() {
    string username, password;
    cout << "Nhap username: ";
    getline(cin, username);

    cout << "Nhap password: ";
    password = getPassword(); // Dùng hàm để ẩn mật khẩu

    // Kiểm tra trong tài khoản nhân viên
    for (const auto& nv : danhSachNhanVien) {
        if (nv.username == username && nv.password == password) {
            cout << "Dang nhap thanh cong voi tai khoan nhan vien!" << endl;
            return true;
        }
    }

    // Kiểm tra trong tài khoản khách hàng
    for (const auto& kh : danhSachKhachHang) {
        if (kh.username == username && kh.password == password) {
            cout << "Dang nhap thanh cong voi tai khoan khach hang!" << endl;
            return true;
        }
    }

    cout << "Username hoac password khong dung!" << endl;
    return false;
}

