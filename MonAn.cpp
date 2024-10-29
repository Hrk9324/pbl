//monan.cpp

#include "MonAn.h"

MonAn::MonAn() : MaMon(0), TenMon(""), Gia(0.0) {}

MonAn::MonAn(const std::string& ma, const std::string& ten, double gia) : MaMon(ma), TenMon(ten), Gia(gia) {}

string MonAn::GetMaMon() const {
	return MaMon;
}

string MonAn::GetTenMon() const {
	return TenMon;
}

double MonAn::GetGia() const {
	return Gia;
}

void MonAn::SetTen(string tenMoi) {
	string ten = tenMoi;
}

void MonAn::SetGia(double GiaMoi) {
	double Gia = GiaMoi;
}

void MonAn::HienThiMonAn() const {
	cout << "Ma mon: " << MaMon << " | Ten mon: " << TenMon << " | Gia: " << Gia << "VND" << endl;
}


