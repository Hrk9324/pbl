#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <stdio.h>
#include <conio.h>
using namespace std;
class MonAn {
	int maMon;
	string tenMon;
	int gia;
public:
	MonAn(int = 0, const string& = "", int = 0);
	void setMaMon(int);
	int getMaMon() const;

	void setTenMon(const string&);
	string getTenMon() const;

	void setGia(int);
	int getGia() const;

	void hienThiThongTin() const;
	bool operator<(const MonAn& other) const;
};
