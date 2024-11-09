#include "DonHang.h"
#include <iostream>

void DonHang::ThemMonAn(const MonAn& mon, int soLuong) {
    for (int i = 0; i < soLuong; ++i) {
        dsMonDaChon.push_back(mon);  // Thêm từng món vào danh sách món đã chọn
    }
    tongTien += mon.getGia() * soLuong;
}

double DonHang::TinhTongTien() const {
    return tongTien;
}

void DonHang::HienThiDonHang() const {
    cout << "----- Chi tiet don hang -----" << endl;
    for (const auto& mon : dsMonDaChon) {
        cout << "Mon: " << mon.getTenMon() << " - Gia: " << mon.getGia() << " VND" << endl;
    }
    cout << "Tong tien: " << tongTien << " VND" << endl;
}
