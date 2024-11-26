#include "Menu.h"
#include "MonAn.h"
#include "DonHang.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <limits>

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
        maMon = "";
        for (int i = 0; i < 4; ++i) {
            maMon += '0' + rand() % 10;
        }
    } while (danhSachMaMon.find(maMon) != danhSachMaMon.end()); // Kiểm tra trong danh sách mã

    danhSachMaMon.insert(maMon); // Thêm mã mới vào danh sách
    return maMon;
}

void Menu::GhiMenuVaoFile(const std::string &tenFile) const {
    std::ofstream file(tenFile);
    if (file.is_open()) {
        for (const auto &mon : danhSachMonAn) {
            file << mon.getMaMon() << " " << mon.getTenMon() << " " << mon.getGia() << endl;
        }
        file.close();
    } else {
        cerr << "Khong the mo file de ghi!" << endl;
    }
}

void Menu::ThemMonAnVaoMenu(MonAn &monan) {
    danhSachMonAn.push_back(monan);
    std::ofstream file("Menu.txt", std::ios::app);
    if (file.is_open()) {
        file << monan.getMaMon() << " " << monan.getTenMon() << " " << monan.getGia() << endl;
        cout << "da them mon an vao file" << endl;
        file.close();
    } else {
        std::cerr << "Khong the mo file de ghi!" << endl;
    }

    
}

void Menu::ThemMonAnTuFile() {
    ifstream file("Menu.txt");
    string line;
    if(file.is_open()) {
        while(!file.eof()) {
            getline(file, line);
            cout << line << endl;
            MonAn newMonAn;
            string maMon, tenMon, gia;
            int index = 0;
            for(int i = index; i < line.size(); ++i) {
                if(line[i] == ',') {
                    maMon = line.substr(index, i - index);
                    cout << maMon << endl;
                    index = i + 1;
                    break;
                }
            }
            for(int i = index; i < line.size(); ++i) {
                if(line[i] == ',') {
                    tenMon = line.substr(index, i - index);
                    cout << tenMon << endl;
                    index = i + 1;
                    break;
                }
            }
            gia = line.substr(index, line.size() - index);
            cout << gia << endl;
            newMonAn.setMaMon(maMon);
            newMonAn.setTenMon(tenMon);
            newMonAn.setGia(0);
            this->ThemMonAnVaoMenu(newMonAn);
        }
    }
}

void Menu::ThemMonAn() {
    MonAn monan;
    monan.setMaMon(TaoMaMonAn4KyTu());
    cout << "Nhap ten mon: ";
    cin.ignore();                 // Xóa ký tự newline còn lại trong bộ đệm
    string tenMon;              // Tạo biến tạm để lưu tên món
    getline(cin, tenMon);             // Đọc tên món vào biến tạm
    monan.setTenMon(tenMon);    // Gán tên món vào đối tượng
    cout << "Nhap gia: ";
    double giaMon;              // Tạo biến tạm để lưu giá món ăn
    cin >> giaMon;
    monan.setGia(giaMon);       // Gán giá trị vào đối tượng monAn thông qua setgia
    ThemMonAnVaoMenu(monan);
}

void Menu::XoaMonAnKhoiMenu(std::string &maMon) {

    for (auto it = danhSachMonAn.begin(); it != danhSachMonAn.end(); ) {
        if (it->getMaMon() == maMon) {
            it = danhSachMonAn.erase(it);
            danhSachMaMon.erase(maMon); // Xóa mã khỏi danh sách mã
            cout << "Da xoa mon an co ma " << maMon << " ra khoi menu" << endl;
            break;
        }
        else it++;
    }
    GhiMenuVaoFile("Menu.txt");
}

void Menu::XoaMonAn(){
    string maMon;
    cout << "Nhap ma mon can xoa:";
    cin >> maMon;
    XoaMonAnKhoiMenu(maMon);
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
    SuaMonAnTrongMenu(mamon);
}

bool Menu::DocMenuTuFile(const string& fileName) {
    ifstream file(fileName);
    if (!file.is_open())
    {
        cerr << "Khong the mo file: " << fileName << endl;
        return false;
    }
    danhSachMonAn.clear();
    string maMon, tenMon;
    double Gia;
    while (file >> maMon >> tenMon >> Gia)
    {
        MonAn monan(maMon, tenMon, Gia);
        danhSachMonAn.push_back(monan);
    }
    file.close();
    return true;
}

void Menu::HienThiMenu() {
    if (!DocMenuTuFile("Menu.txt")) {
        cout << "Khong the doc file Menu.txt!" << endl;
        return;
    }
    if (danhSachMonAn.empty()) {
        cout << "Danh sach mon an rong!" << endl;
        return;
    }
    for (const auto &mon : danhSachMonAn) {
        cout << "Ma Mon: " << mon.getMaMon() << " " << "Ten Mon: " << mon.getTenMon()
                << " "  << "Gia: " << mon.getGia() << "VND" << endl;
    }
}

void Menu::GoiMon() {
    ifstream file("Menu.txt");
    if (!file.is_open()) {
        cout << "Khong the mo file." << endl;
        return;
    }
    string maMon;
    int SoLuong;
    DonHang donHang;
    MonAn monAn;
    cout << "Nhap ma mon an muon dat: ";
    cin >> maMon;
    cout << menu.GetDsMonAn().size() << endl;
    for (auto mon : danhSachMonAn ) {
        if (mon.getMaMon() == maMon) {
            monAn = mon;
            cout << "Nhap so luong muon dat: ";
            cin >> SoLuong;
            if (SoLuong > 0) {  // Kiểm tra số lượng hợp lệ
                donHang.ThemMonAn(monAn, SoLuong);
                cout << "Da them " << SoLuong << " mon " << monAn.getTenMon() << " vao don hang." << endl;
                donHang.HienThiDonHang();  // Hiển thị chi tiết đơn hàng
                return;
            }
            else {
                cout << "So luong khong hop le!" << endl;
            }
        }
        else {
            cout << "Khong the dat mon!" << endl;
        }
        file.close();
    }



    // cout << menu.GetDsMonAn().size() << endl;
    // if (maMon > 0 && maMon <= menu.GetDsMonAn().size()) {
    //     MonAn monAn = menu.GetDsMonAn()[maMon ];
    //     cout << "Nhap so luong muon dat: ";
    //     cin >> SoLuong;
    //     // Kiểm tra số lượng hợp lệ
    //     if (SoLuong > 0) {
    //     donHang.ThemMonAn(monAn, SoLuong);
    //     cout << "Da them " << SoLuong << " mon " << monAn.getTenMon() << " vao don hang." << endl;
    //     donHang.HienThiDonHang();  // Hiển thị chi tiết đơn hàng
    //     }
        
}

