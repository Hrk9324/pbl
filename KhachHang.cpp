#include "KhachHang.h"
#include <conio.h>  // Để sử dụng _getch() cho việc nhập mật khẩu ẩn

// Hàm nhập mật khẩu với dấu *
string KhachHang::getPassword() {
    string password = "";
    char ch;
    while ((ch = _getch()) != 13) {  // 13 là mã ASCII của phím Enter
        if (ch == 8) {  // 8 là mã ASCII của phím Backspace
            if (password.length() > 0) {
                password.pop_back();
                cout << "\b \b";  // Xóa dấu *
            }
        } else {
            password += ch;
            cout << "*";  // Hiển thị dấu *
        }
    }
    cout << endl;
    return password;
}

// Đọc tài khoản khách hàng từ file
void KhachHang::docTaiKhoanKhachHangFromFile(vector<KhachHang>& danhSachKhachHang) {
    ifstream file("KhachHang.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            KhachHang kh;
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

// Ghi tài khoản khách hàng vào file
void KhachHang::ghiTaiKhoanKhachHangToFile(const vector<KhachHang>& danhSachKhachHang) {
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

// Tạo tài khoản khách hàng
void KhachHang::taoTaiKhoanKhachHang(vector<KhachHang>& danhSachKhachHang) {
    string tenKhachHang, username, password;

    cout << "Nhap ten khach hang: ";
    cin.ignore();
    getline(cin, tenKhachHang);

    cout << "Nhap username: ";
    getline(cin, username);

    cout << "Nhap password: ";
    password = getPassword();  // Dùng hàm để ẩn mật khẩu

    KhachHang kh;
    kh.maKhachHang = danhSachKhachHang.size() + 1;  // Mã khách hàng tự động tăng
    kh.tenKhachHang = tenKhachHang;
    kh.username = username;
    kh.password = password;

    danhSachKhachHang.push_back(kh);
    ghiTaiKhoanKhachHangToFile(danhSachKhachHang);
    cout << "Tao tai khoan khach hang thanh cong!" << endl;
}

// Đăng nhập
KhachHang* KhachHang::dangNhap(vector<KhachHang>& danhSachKhachHang) {
    string username, password;
    cout << "Nhap username: ";
    getline(cin, username);

    cout << "Nhap password: ";
    password = getPassword();  // Dùng hàm để ẩn mật khẩu

    for (auto& kh : danhSachKhachHang) {
        if (kh.username == username && kh.password == password) {
            cout << "Dang nhap thanh cong cho khach hang: " << kh.tenKhachHang << endl;
            return &kh;  // Trả về con trỏ đến khách hàng
        }
    }
    cout << "Username hoac password sai!" << endl;
    return nullptr;  // Trả về nullptr nếu đăng nhập không thành công
}

// Hàm gọi món và in hóa đơn
void KhachHang::goiMon(Menu& menu, KhachHang* kh) {
    if (kh == nullptr) {
        cout << "Khach hang chua dang nhap!" << endl;
        return;
    }

    vector<MonAn> menuList = menu.getMenu();
    int maMon, soLuong;
    double tongTien = 0;

    cout << "\n===== MENU =====" << endl;
    menu.inMenu();  // In menu

    cout << "Nhap ma mon an muon goi: ";
    cin >> maMon;

    cout << "Nhap so luong: ";
    cin >> soLuong;

    for (const auto& mon : menuList) {
        if (mon.getMaMon() == maMon) {
            tongTien += mon.getGiaTien() * soLuong;
            break;
        }
    }

    cout << "\n===== HOA DON =====" << endl;
    cout << "Khach hang: " << kh->tenKhachHang << endl;
    cout << "Tong tien: " << tongTien << endl;
    cout << "Xac nhan thanh toan (y/n): ";
    char xacNhan;
    cin >> xacNhan;
    if (xacNhan == 'y' || xacNhan == 'Y') {
        cout << "Thanh toan thanh cong!" << endl;
        // Lưu hóa đơn vào file
        ofstream hoaDonFile("HoaDon.txt", ios::app);
        if (hoaDonFile.is_open()) {
            hoaDonFile << kh->maKhachHang << ", " << kh->tenKhachHang << ", " << tongTien << endl;
            hoaDonFile.close();
        }
    } else {
        cout << "Huy thanh toan!" << endl;
    }
}
