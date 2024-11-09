#ifndef DONHANG_H
#define DONHANG_H

#include "MonAn.h"
#include "Menu.h"
#include <iostream>
#include <vector>
#include <string>

class DonHang {
private:
    std::vector<MonAn> dsMonDaChon;
    double tongTien;

public:
    DonHang() : tongTien(0) {}

    void ThemMonAn(const MonAn& mon, int soLuong);
    double TinhTongTien() const;
    void HienThiDonHang() const;
    const std::vector<MonAn>& getDanhSachMonAn() const {
        return dsMonDaChon;
    }
};

#endif
