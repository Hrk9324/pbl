#pragma once
#include "MonAn.h"
class HoaDon {
	vector<pair<MonAn, int >> danhSachMonAn;
public:
	double tinhTongTien();
	void clearHoaDon();
	void themMonAn(MonAn, int);
	void ghiDoanhThu(int);
	void inHoaDon();
	void inHoaDonConsole();
};
