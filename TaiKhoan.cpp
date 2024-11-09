// TaiKhoan.cpp
#include "TaiKhoan.h"
#include <fstream>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;
// Kiểm tra đăng nhập, xác thực dựa trên tên đăng nhập và mật khẩu

bool TaiKhoan::DangNhap(const string& fileName, string& tenDangNhap, string& matKhau) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Khong the mo file: " << fileName << endl;
        return false;
    }
    string tenDangNhapFile, matKhauFile, gmailFile;
    cout << "Nhap ten dang nhap: ";
    cin >> tenDangNhap;
    cout << "Nhap mat khau: ";
    cin >> matKhau;
    while (file >> gmailFile >> tenDangNhapFile >> matKhauFile) {
        if (tenDangNhap == tenDangNhapFile && matKhau == matKhauFile) {
            cout << "Dang nhap thanh cong." << endl;
            file.close();
            return true;
        }
    }
    cout << "Ten dang nhap hoac mat khau khong dung." << endl;
    file.close();
    return false;
}

// Tạo tài khoản nhân viên mới và lưu vào file
// void TaiKhoan::TaoTaiKhoanNhanVien(const string& fileName) {
//     ofstream outfile(fileName, ios::app);
//     if (!outfile) {
//         cerr << "Khong the mo file: " << fileName << endl;
//         return;
//     }
//     string tenDangNhap, matKhau;
//     cout << "Nhap ten dang nhap: ";
//     cin >> tenDangNhap;
//     cout << "Nhap mat khau moi: ";
//     cin >> matKhau;
//     outfile << tenDangNhap << " " << matKhau << endl;
//     outfile.close();
//     cout << "Da tao tai khoan nhan vien thanh cong!" << endl;
// }

void TaiKhoan::TaoTaiKhoanNhanVien(const std::string& filePath) {
    ifstream file("NhanVien.txt");
    if (!file.is_open()) {
        cerr << "Khong the mo file de doc tai khoan nhan vien!" << endl;
        return;
    }

    // Tìm mã nhân viên lớn nhất
    string line;
    int maxMaNhanVien = 0;
    while (getline(file, line)) {
        istringstream iss(line);
        int maNV;
        string hoTen, username, password;
        if (iss >> maNV) {
            iss.ignore();
            getline(iss, hoTen, ',');
            getline(iss, username, ',');
            getline(iss, password);
            maxMaNhanVien = max(maxMaNhanVien, maNV);
        }
    }

    file.close();

    // Mã nhân viên tiếp theo
    string maNV = to_string(maxMaNhanVien + 1);

    ofstream outFile("NhanVien.txt", ios::app);
    if (!outFile.is_open()) {
        cerr << "Khong the mo file de ghi tai khoan nhan vien!" << endl;
        return;
    }

    string hoTen, username, password;
    cout << "Nhap ho va ten nhan vien: ";
    cin.ignore();  // Xóa ký tự newline còn lại trong bộ đệm
    getline(cin, hoTen);  // Đọc tên nhân viên
    cout << "Nhap username: ";
    getline(cin, username); // Đọc username với khả năng chứa khoảng trắng
    cout << "Nhap password: ";
    getline(cin, password); // Đọc password với khả năng chứa khoảng trắng

    outFile << maNV << ", " << hoTen << ", " << username << ", " << password << endl;
    outFile.close();

    cout << "Da tao tai khoan nhan vien " << hoTen << " voi ma so: " << maNV << endl;
}

TaiKhoan::TaiKhoan() {
    std::srand(std::time(0));
}

std::string TaiKhoan::TaoMaKhachHang() {
    std::string maKH;
    do {
        for (int i = 0; i < 6; i++)
        {
            maKH += '0' + rand() % 10;
        }
        
    } while (danhSachMaKH.find(maKH) != danhSachMaKH.end());
    danhSachMaKH.insert(maKH);
    return maKH;
}


void TaiKhoan::TaoTaiKhoanKhachHang(const std::string& filePath){
    ifstream file("KhachHang.txt");
    if (!file.is_open())
    {
        cerr << "Khong the mo file de doc tai khoan khach hang!" << endl;
        return;
    }
    string maKH = TaoMaKhachHang();
    ofstream outFile("KhachHang.txt", ios::app);
    if (!outFile.is_open())
    {
        cerr << "khong the mo file de ghi tai khoan khach hang" << endl;
        return;
    }
    string gmail, user, pass;
    cout << "nhap gmail: ";
    cin.ignore();
    getline(cin, gmail);
    cout << "nhap username: ";
    getline(cin, user);
    cout << "nhap password: ";
    getline(cin, pass);

    outFile << maKH << ", " << gmail << ", " << user << ", " << pass << endl;
    outFile.close();

    cout << "da tao tai khoan thanh cong" << endl;
}