#include "Menu.h"
#include "MonAn.h"
#include "DonHang.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

Menu menu;

std::vector<MonAn> Menu::GetDsMonAn() const {
    return danhSachMonAn;
}

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

void Menu::DocMenuTuFile(const string& fileName) {
    ifstream file(fileName);
    if (!file.is_open())
    {
        cerr << "Khong the mo file: " << fileName << endl;
    }
    string maMon, tenMon;
    double Gia;
    while (file >> maMon >> tenMon >> Gia)
    {
        MonAn monan(maMon, tenMon, Gia);
        danhSachMonAn.push_back(monan);
    }
    file.close();
    
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

void Menu::ThemMonAn() {
    MonAn monan;
    monan.setMaMon(TaoMaMonAn4KyTu());
    cout << "Nhap ten mon: ";
    cin.ignore();                 // Xóa ký tự newline còn lại trong bộ đệm
    string tenMon;              // Tạo biến tạm để lưu tên món
    cin >> tenMon;              // Đọc tên món vào biến tạm
    monan.setTenMon(tenMon);    // Gán tên món vào đối tượng
    cout << "Nhap gia: ";
    double giaMon;              // Tạo biến tạm để lưu giá món ăn
    cin >> giaMon;
    monan.setGia(giaMon);       // Gán giá trị vào đối tượng monAn thông qua setter
    ThemMonAnVaoMenu(monan);
}

void Menu::XoaMonAnKhoiMenu(std::string &maMon) {
    for (auto it = danhSachMonAn.begin(); it != danhSachMonAn.end(); ++it) {
        if (it->getMaMon() == maMon) {
            danhSachMonAn.erase(it);
            danhSachMaMon.erase(maMon); // Xóa mã khỏi danh sách mã
            break;
        }
    }
    GhiMenuVaoFile("Menu.txt");
}

void Menu::XoaMonAn() {
    string mamon;
    cout << "nhap ma mon can xoa: ";
    cin >> mamon;
    menu.XoaMonAnKhoiMenu(mamon);
}

void Menu::SuaMonAnTrongMenu(std::string &maMon) {
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

void Menu::SuaMonAn() {
    string mamon;
    cout << "Nhap ma mon can sua: ";
    cin >> mamon;
    menu.SuaMonAnTrongMenu(mamon);
}

void Menu::HienThiMenu() const {
    DocMenuTuFile("Menu.txt");
    for (const auto &mon : danhSachMonAn) {
        cout << "Ma Mon: " << mon.getMaMon() << ", Ten Mon: " << mon.getTenMon()
                  << ", Gia: " << mon.getGia() << endl;
    }
}

void Menu::GoiMon() {
    int SoThuTuMon, SoLuong;
    DonHang donHang;
    cout << "Nhap ma mon an muon dat: ";
    cin >> SoThuTuMon;
    if (SoThuTuMon > 0 && SoThuTuMon <= menu.GetDsMonAn().size()) {
        MonAn monAn = menu.GetDsMonAn()[SoThuTuMon - 1];
        cout << "Nhap so luong muon dat: ";
        cin >> SoLuong;
        // Kiểm tra số lượng hợp lệ
        if (SoLuong > 0) {
        donHang.ThemMonAn(monAn, SoLuong);
        cout << "Da them " << SoLuong << " mon '" << monAn.getTenMon() << "' vao don hang." << endl;
        donHang.HienThiDonHang();  // Hiển thị chi tiết đơn hàng
        }
        else {
            cout << "So luong khong hop le!" << endl;
        }
    }
    else {
        cout << "So thu tu khong hop le!" << endl;
    }
}

