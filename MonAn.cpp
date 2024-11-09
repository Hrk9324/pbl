#include "MonAn.h"
#include <iostream>

// Hàm dựng với tham số mặc định
MonAn::MonAn(const std::string &ma, const std::string &ten, double g) : maMon(ma), tenMon(ten), gia(g) {}

// Định nghĩa các setter và getter
void MonAn::setMaMon(const std::string &ma) {
    maMon = ma;
}

std::string MonAn::getMaMon() const {
    return maMon;
}

void MonAn::setTenMon(const std::string &ten) {
    tenMon = ten;
}

std::string MonAn::getTenMon() const {
    return tenMon;
}

void MonAn::setGia(double g) {
    gia = g;
}

double MonAn::getGia() const {
    return gia;
}

// Hàm hiển thị thông tin món ăn
void MonAn::hienThiThongTin() const {
    std::cout << "Ma Mon: " << maMon << ", Ten Mon: " << tenMon << ", Gia: " << gia << " VND" << std::endl;
}
