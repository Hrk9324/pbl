#include "NhanVien.h"
#include <conio.h>  // Dùng cho _getch() để ẩn mật khẩu

using namespace std;

// Hàm tĩnh để ẩn mật khẩu khi nhập
string NhanVien::getPasswordInput() {
    string password;
    char ch;
    while (true) {
        ch = _getch();  // Dùng _getch() để nhập ký tự mà không hiển thị ra màn hình
        if (ch == 13) {  // Kiểm tra phím Enter
            break;
        } else if (ch == 8) {  // Kiểm tra phím Backspace
            if (password.length() > 0) {
                password.pop_back();
                cout << "\b \b";  // Xóa ký tự đã nhập
            }
        } else {
            password.push_back(ch);
            cout << "*";  // In dấu * cho mật khẩu
        }
    }
    cout << endl;
    return password;
}

// Hàm đăng nhập cho nhân viên
bool NhanVien::dangNhap() {
    string username, password;

    cout << "Nhap username: ";
    getline(cin, username);

    cout << "Nhap password: ";
    password = getPasswordInput();  // Lấy mật khẩu từ phương thức getPasswordInput

    ifstream file("NhanVien.txt");
    string line;
    while (getline(file, line)) {
        size_t pos = line.find(",");
        string storedUsername = line.substr(pos + 1, line.find(",", pos + 1) - pos - 1);
        string storedPassword = line.substr(line.rfind(",") + 1);

        if (username == storedUsername && password == storedPassword) {
            cout << "Dang nhap thanh cong!" << endl;
            return true;
        }
    }

    cout << "Username hoac password sai!" << endl;
    return false;
}

// Chức năng gọi món cho nhân viên chạy bàn
void NhanVien::goiMon(Menu& menu) {
    menu.hienThiMenu();  // Hiển thị menu món ăn

    int maMon, soLuong;
    cout << "Nhap ma mon muon goi: ";
    cin >> maMon;

    cout << "Nhap so luong: ";
    cin >> soLuong;

    // Lấy thông tin món ăn từ menu và tính tổng tiền
    int giaTien = menu.getMenu()[maMon - 1].getGiaTien();  // Giả sử maMon bắt đầu từ 1
    int tongTien = giaTien * soLuong;

    // Hiển thị thông tin món đã gọi và tổng tiền
    cout << "Món gọi: " << menu.getMenu()[maMon - 1].getTenMon() << endl;
    cout << "Số lượng: " << soLuong << endl;
    cout << "Tổng tiền: " << tongTien << " VND" << endl;

    cout << "Giao dịch đã được ghi nhận. Chạy bàn tiếp theo..." << endl;
}
