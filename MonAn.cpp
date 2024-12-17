#include "MonAn.h"

MonAn::MonAn(int maMon, const std::string& tenMon, int gia)
:maMon(maMon), tenMon(tenMon), gia(gia) {}

int MonAn::getMaMon() const {
    return maMon;
}

void MonAn::setMaMon(int maMon) {
    this->maMon = maMon;
}

string MonAn::getTenMon() const {
    return tenMon;
}

void MonAn::setTenMon(const std::string& tenMon) {
    this->tenMon = tenMon;
}

int MonAn::getGia() const {
    return gia;
}

void MonAn::setGia(int gia) {
    this->gia = gia;
}

void MonAn::hienThiThongTin() const {
    cout << left << setw(8) << maMon << "|"
        << setw(30) << tenMon << "|"
        << gia << " VND\n";
}

bool MonAn::operator<(const MonAn& other) const {
    return maMon < other.maMon;
}
