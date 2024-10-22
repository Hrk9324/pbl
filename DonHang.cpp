//DonHang.cpp

#include "DonHang.h"

DonHang::DonHang() : TongTien(0) {}

void DonHang::ThemMonAn(const MonAn& mon) {
	DsMonDaChon.push_back(mon);
	TongTien += mon.GetGia();
}

double DonHang::TinhTongTien() const {
	return TongTien;
}

void DonHang::ResetDonHang() {
    DsMonDaChon.clear();
    TongTien = 0;
}


void DonHang::HienThiDonHang() {
	for (const auto& mon : DsMonDaChon) {
		mon.HienThiMonAn();
	}
	cout << "Tong tien: " << TongTien << " VND " << endl;
}


