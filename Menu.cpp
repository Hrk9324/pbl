#include "Menu.h"
#include "MonAn.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

Menu::Menu() {
    std::srand(std::time(0)); // Khởi tạo hạt giống cho số ngẫu nhiên
}

std::string Menu::TaoMaMonAn4KyTu() {
    std::string maMon;
    do {
        maMon = "MA";
        for (int i = 0; i < 4; ++i) {
            maMon += '0' + rand() % 10;
        }
    } while (danhSachMaMon.find(maMon) != danhSachMaMon.end()); // Kiểm tra trong danh sách mã

    danhSachMaMon.insert(maMon); // Thêm mã mới vào danh sách
    return maMon;
}

void Menu::DocMenuTuFile(){
    
}

void Menu::GhiMenuVaoFile(const std::string &tenFile) const {
    std::ofstream file(tenFile);
    if (file.is_open()) {
        for (const auto &mon : danhSachMonAn) {
            file << mon.getMaMon() << ", " << mon.getTenMon() << ", " << mon.getGia() << endl;
        }
        file.close();
    } else {
        std::cerr << "Khong the mo file de ghi!" << endl;
    }
}

void Menu::ThemMonAnVaoMenu(MonAn &monan) {
    danhSachMonAn.push_back(monan);
    std::ofstream file("Menu.txt", std::ios::app);
    if (file.is_open()) {
        file << monan.getMaMon() << ", " << monan.getTenMon() << ", " << monan.getGia() << endl;
        file.close();
    } else {
        std::cerr << "Khong the mo file de ghi!" << endl;
    }
}

void Menu::XoaMonAnKhoiMenu(const std::string &maMon) {
    for (auto it = danhSachMonAn.begin(); it != danhSachMonAn.end(); ++it) {
        if (it->getMaMon() == maMon) {
            danhSachMonAn.erase(it);
            danhSachMaMon.erase(maMon); // Xóa mã khỏi danh sách mã
            break;
        }
    }
    GhiMenuVaoFile("Menu.txt");
}

void Menu::SuaMonAnTrongMenu(const std::string &maMon) {
    for (auto &mon : danhSachMonAn) {
        if (mon.getMaMon() == maMon) {
            std::string tenMoi;
            double giaMoi;
            cout << "Nhap ten moi: ";
            std::cin.ignore();
            getline(std::cin, tenMoi);
            cout << "Nhap gia moi: ";
            std::cin >> giaMoi;
            mon.setTenMon(tenMoi);
            mon.setGia(giaMoi);
            break;
        }
    }
    GhiMenuVaoFile("Menu.txt");
}

void Menu::HienThiMenu() const {
    for (const auto &mon : danhSachMonAn) {
        cout << "Ma Mon: " << mon.getMaMon() << ", Ten Mon: " << mon.getTenMon()
                  << ", Gia: " << mon.getGia() << endl;
    }
}

std::vector<MonAn> Menu::GetDsMonAn() const {
    return danhSachMonAn;
}
