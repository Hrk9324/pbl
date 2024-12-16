#include "Menu2.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
// Khởi tạo static maMonCounter
int Menu::maMonCounter = 1;
// Constructor: Đọc menu từ file khi khởi tạo
Menu::Menu() {
    docMenuFromFile();
}

void Menu::docMenuFromFile() {
    std::ifstream file("Menu.txt");
    if (!file.is_open()) {
        std::cerr << "Không thể mở file Menu.txt!" << std::endl;
        return;
    }

    std::string line;
    int maxMaMon = 0;

    while (std::getline(file, line)) {
        std::istringstream stream(line);
        int maMon;
        std::string tenMon;
        int giaTien;

        char comma1, comma2;  // Để xử lý dấu phẩy giữa các trường
        if (stream >> maMon >> comma1 && comma1 == ',' && std::getline(stream, tenMon, ',') && stream >> giaTien) {
            // Xóa khoảng trắng đầu và cuối của tên món ăn
            tenMon.erase(tenMon.begin(), std::find_if(tenMon.begin(), tenMon.end(), [](unsigned char c) { return !std::isspace(c); }));
            tenMon.erase(std::find_if(tenMon.rbegin(), tenMon.rend(), [](unsigned char c) { return !std::isspace(c); }).base(), tenMon.end());

            if (!tenMon.empty() && !stream.fail()) {
                MonAn monAn(maMon, tenMon, giaTien);
                danhSachMonAn.push_back(monAn);
                maxMaMon = std::max(maxMaMon, maMon);
            }
        } else {
            std::cerr << "Dòng không hợp lệ: " << line << std::endl;
        }
    }

    maMonCounter = maxMaMon + 1;  // Đặt mã món tiếp theo
    file.close();
}

void Menu::ghiMenuToFile() {
    std::ofstream file("Menu.txt", std::ios::trunc);
    if (!file.is_open()) {
        std::cerr << "Không thể mở file Menu.txt để ghi!" << std::endl;
        return; // Exit the function early
    }
    for (const auto& monAn : danhSachMonAn) {
        file << monAn.getMaMon() << ","
             << monAn.getTenMon() << ","
             << monAn.getGiaTien() << " VND\n";
    }
    file.close();
}

bool Menu::themMonAn(const std::string& tenMon, int giaTien) {
    // Kiểm tra đầu vào
    if (tenMon.empty() || giaTien <= 0) {
        std::cerr << "Thông tin món ăn không hợp lệ. Vui lòng kiểm tra lại!" << std::endl;
        return false;
    }

    // Kiểm tra trùng lặp tên món ăn
    for (const auto& monAn : danhSachMonAn) {
        if (monAn.getTenMon() == tenMon) {
            std::cerr << "Món ăn đã tồn tại trong menu!" << std::endl;
            return false;
        }
    }

    // Tạo món ăn mới và thêm vào danh sách
    MonAn monAn(maMonCounter, tenMon, giaTien);
    danhSachMonAn.push_back(monAn);
    maMonCounter++;

    // Chỉ ghi thêm món ăn mới vào file, không cần ghi lại toàn bộ danh sách
    std::ofstream file("Menu.txt", std::ios::app); // Mở file ở chế độ ghi thêm
    if (file.is_open()) {
        file << monAn.getMaMon() << ", " << monAn.getTenMon() << ", " << monAn.getGiaTien() << "\n";
        file.close();
    } else {
        std::cerr << "Không thể ghi dữ liệu vào file Menu.txt!" << std::endl;
        return false;
    }

    std::cout << "Thêm món ăn '" << tenMon << "' vào menu thành công!" << std::endl;
    return true;
}


bool Menu::xoaMonAn(int maMon) {
    auto it = std::find_if(danhSachMonAn.begin(), danhSachMonAn.end(),
        [maMon](const MonAn& monAn) {
            return monAn.getMaMon() == maMon;
        });
    if (it != danhSachMonAn.end()) {
        danhSachMonAn.erase(it);
        ghiMenuToFile();
        std::cout << "Đã xóa món ăn với mã " << maMon << ".\n";
        return true;
    }
    std::cout << "Không tìm thấy món ăn với mã " << maMon << ".\n";
    return false;
}

bool Menu::suaMonAn(int maMon, const std::string& tenMonMoi, int giaTienMoi) {
    for (auto& monAn : danhSachMonAn) {
        if (monAn.getMaMon() == maMon) {
            if (tenMonMoi.empty() || giaTienMoi < 0) {
                std::cerr << "Thông tin món ăn không hợp lệ." << std::endl;
                return false;
            }
            monAn.setTenMon(tenMonMoi);
            monAn.setGiaTien(giaTienMoi);
            ghiMenuToFile();
            std::cout << "Đã sửa món ăn với mã " << maMon << ".\n";
            return true;
        }
    }
    std::cout << "Không tìm thấy món ăn với mã " << maMon << ".\n";
    return false;
}

void Menu::hienThiMenu() const {
    std::cout << "Danh sách món ăn trong menu:\n";
    for (const auto& monAn : danhSachMonAn) {
        monAn.hienThiThongTin();
    }
}

void Menu::goiMon() {
    hienThiMenu();
    int maMon, soLuong;
    std::cout << "Nhập mã món muốn gọi: ";
    while (!(std::cin >> maMon)) {
        std::cout << "Vui lòng nhập một số hợp lệ!\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    bool monTimThay = false;
    for (const auto& monAn : danhSachMonAn) {
        if (monAn.getMaMon() == maMon) {
            std::cout << "Nhập số lượng: ";
            while (!(std::cin >> soLuong) || soLuong <= 0) {
                std::cout << "Vui lòng nhập số lượng hợp lệ (lớn hơn 0)!\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            double tongTien = monAn.getGiaTien() * soLuong;
            std::cout << "Tổng tiền cho " << monAn.getTenMon() << " là: "
                      << tongTien << " VND\n";
            monTimThay = true;
            break;
        }
    }
    if (!monTimThay) {
        std::cout << "Mã món không hợp lệ!\n";
    }
}
