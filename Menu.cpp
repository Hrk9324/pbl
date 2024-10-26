//Menu.cpp

#include "Menu.h"

void Menu::ThemMonAnVaoMenu(const MonAn& monan) {
	string tenMon;
	double giaMon;
	cout << "Ten Mon";
	cin >> tenMon;
	cout << endl;
	cout << "Gia Mon";
	cin >> giaMon;
	monan.SetTen(tenMon);
	monan.SetGia(giaMon);
	DsMonAn.push_back(monan);
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
		std::string ten;
		double gia;
		while (file >> ma >> ten >> gia) {
			if (file.fail())
			{
				std::cerr << "khong the mo file " << tenFile << std::endl;
			}
			
		}
		DsMonAn.push_back(MonAn(static_cast<int>(ma), static_cast<const std::string&>(ten), static_cast<double>(gia)));
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


