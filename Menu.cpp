//Menu.cpp

#include "Menu.h"

void Menu::ThemMonAn(const MonAn& mon) {
	DsMonAn.push_back(mon);
}

void Menu::XoaMonAn( string maMon) {
	for (auto it = DsMonAn.begin(); it != DsMonAn.end(); ++it) {
		if (it->GetMaMon() == maMon) {
			DsMonAn.erase(it);
			break;
		}
	}
}

void Menu::CapNhatMonAn(string maMon, string tenMoi, double giaMoi) {
	for (auto& mon : DsMonAn) {
		if (mon.GetMaMon() == maMon) {
			mon.SetTen(tenMoi);
			mon.SetGia(giaMoi);
			break;
		}
	}
}

void Menu::HienThiMenu() const {
	for (const auto& mon : DsMonAn) {
		mon.HienThiMonAn();
	}
}

void Menu::DocMenuTuFile(const string& tenFile) {
	ifstream file(tenFile);
	if (file.is_open()) {
		int ma;
		string ten;
		double gia;
		while (file >> ma >> ten >> gia) {
			DsMonAn.push_back(MonAn(ma, ten , gia));
		}
		file.close();
	}
}

void Menu::GhiMenuVaoFile(const string& tenFile) {
	ofstream file(tenFile);
	if (file.is_open()) {
		for (const auto& mon : DsMonAn) {
			file << mon.GetMaMon() << " " << mon.GetTenMon() << " " << mon.GetGia() << endl;
		}
		file.close();	
	}
}

vector<MonAn> Menu::GetDsMonAn() const {
	return DsMonAn;
}


