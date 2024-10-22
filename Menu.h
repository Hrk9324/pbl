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
		void ThemMonAn(const MonAn& mon);
		void XoaMonAn(int maMon);
		void CapNhatMonAn(int maMon, string tenMoi, double giaMoi);
		void HienThiMenu() const;
		void DocMenuTuFile(const string& tenFile);
		void GhiMenuVaoFile(const string& tenFile);
};
