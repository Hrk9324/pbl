#include "MonAn.h"

// Constructor mặc định
MonAn::MonAn() : maMon(0), tenMon(""), giaTien(0.0) {}

// Constructor đầy đủ tham số
MonAn::MonAn(int maMon, const std::string& tenMon, double giaTien)
    : maMon(maMon), tenMon(tenMon), giaTien(giaTien) {}

// Getter và Setter
int MonAn::getMaMon() const {
    return maMon;
}

void MonAn::setMaMon(int maMon) {
    this->maMon = maMon;
}

std::string MonAn::getTenMon() const {
    return tenMon;
}

void MonAn::setTenMon(const std::string& tenMon) {
    this->tenMon = tenMon;
}

double MonAn::getGiaTien() const {
    return giaTien;
}

void MonAn::setGiaTien(double giaTien) {
    this->giaTien = giaTien;
}

// Hiển thị thông tin món ăn
void MonAn::hienThiThongTin() const {
    std::cout << std::setw(3) << std::setfill('0') << maMon << ", "
              << tenMon << ", "
              << giaTien << " VND\n";
}

// Toán tử so sánh
bool MonAn::operator<(const MonAn& other) const {
    return maMon < other.maMon;
}
