//monan.cpp

#include "MonAn.h"

MonAn::MonAn() : MaMon(0), TenMon(""), Gia(0.0) {}

MonAn::MonAn(int ma, string ten, double gia) : MaMon(ma), TenMon(ten), Gia(gia) {}

int MonAn::GetMaMon() const {
	return MaMon;
}

string MonAn::GetTenMon() const {
	return TenMon;
}

double MonAn::GetGia() const {
	return Gia;
}

void MonAn::SetTen(string tenMoi) {
	ten = tenMoi;
}

void MonAn::SetGia(double GiaMoi) {
	Gia = GiaMoi;
}

void MonAn::HienThiMonAn() const {
	cout << "Ma mon: " << MaMon << " | Ten mon: " << TenMon << " | Gia: " << Gia << "VND" << endl;
}
