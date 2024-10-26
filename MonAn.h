//thiet ke class monan
#pragma once
#include <iostream>
#include <string>

using namespace std;

class MonAn {
	private:
		std::string MaMon;
		std::string TenMon;
		double Gia;
	
	public:
		MonAn();
		MonAn(const std::string& ma,const std::string& ten, double gia);
		string GetMaMon() const;
		string GetTenMon() const;
		double GetGia() const;
		void SetTen(string tenMoi);
		void SetGia(double giaMoi);
		void HienThiMonAn() const;
};


