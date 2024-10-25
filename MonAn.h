//thiet ke class monan
#pragma once
#include <iostream>
#include <string>

using namespace std;

class MonAn {
	private:
		string MaMon;
		string TenMon;
		double Gia;
	
	public:
		MonAn();
		MonAn(int ma, string ten, double gia);
		string GetMaMon() const;
		string GetTenMon() const;
		double GetGia() const;
		void SetTen(string tenMoi);
		void SetGia(double giaMoi);
		void HienThiMonAn() const;
};


