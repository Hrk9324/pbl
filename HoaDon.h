#pragma once
#include "MonAn.h"
#include "DSTaiKhoan.h"
class HoaDon {
	vector<pair<MonAn, int >> danhSachMonAn;
public:
	double tinhTongTien();
	void clearHoaDon();
	void themMonAn(MonAn, int);
	void ghiDoanhThu(string, int);
	void inHoaDon(string);
	void inHoaDonConsole();
};
