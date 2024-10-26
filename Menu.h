//menu.h

#pragma once
#include "MonAn.h"
#include <vector>
#include <fstream>
#include <string>

class Menu {
	private:

	public:
		vector<MonAn> DsMonAn;
		vector<MonAn> GetDsMonAn;
//		void ThemMonAn(string maMon, string tenMon, double giaMon);
		void ThemMonAnVaoMenu(const MonAn& monan);
		void XoaMonAn(string maMon);
		void CapNhatMonAn(string maMon, string tenMoi, double giaMoi);
		void HienThiMenu() const;
		void DocMenuTuFile(const string& tenFile);
		void GhiMenuVaoFile(const string& tenFile);
};
