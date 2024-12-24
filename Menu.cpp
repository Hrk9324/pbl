#include "Menu.h"

Menu::Menu() {
    danhSachMonAn.clear();
    maMonCounter = 0;
}

void Menu::docMenuFromFile() {
    ifstream file("Menu.txt");
    if (!file.is_open()) {
        cerr << "Khong the mo file Menu.txt!" << endl;
        return;
    }

    string line;
    int maxMaMon = 0;
    while(getline(file, line)) {
        istringstream buffer(line);
        string maMon_str;
        string tenMon;
        string giaTien_str;
        getline(buffer, maMon_str, ',');
        getline(buffer, tenMon, ',');
        getline(buffer, giaTien_str, '\n');
        int maMon = stoi(maMon_str);
        int giaTien = stoi(giaTien_str);
        MonAn monAn;
        monAn.setMaMon(maMon);
        monAn.setTenMon(tenMon);
        monAn.setGia(giaTien);
        danhSachMonAn.push_back(monAn);
        maxMaMon = max(maxMaMon, monAn.getMaMon());
    }
    maMonCounter = maxMaMon + 1;
    file.close();
}

void Menu::ghiMenuToFile() {
    ofstream file("Menu.txt", ios::trunc);
    if (!file.is_open()) {
        cerr << "Khong the mo file Menu.txt de ghi!" << endl;
        return;
    }
    for (const auto& monAn : danhSachMonAn) {
        file << monAn.getMaMon() << ","
            << monAn.getTenMon() << ","
            << monAn.getGia() << " VND\n";
    }
    file.close();
}

bool Menu::timMonAn(int maMon) const {
	for (const auto& monAn : danhSachMonAn) {
		if (monAn.getMaMon() == maMon) {
			return true;
		}
	}
	return false;
}

bool Menu::themMonAn(const string& tenMon, int giaTien) {
    // Kiem tra dau vao
    if (tenMon.empty() || giaTien <= 0) {
        cerr << "Thong tin mon an khong hop le. Vui long kiem tra lai!" << endl;
        return false;
    }

    // Kiem tra trung lap ten mon an
    for (const auto& monAn : danhSachMonAn) {
        if (monAn.getTenMon() == tenMon) {
            cerr << "Mon an da ton tai trong menu!" << endl;
            return false;
        }
    }


    // Tao mon an moi va them vao danh sach
    MonAn monAn(maMonCounter, tenMon, giaTien);
    danhSachMonAn.push_back(monAn);
    maMonCounter++;

    // Chi ghi them mon an moi vao file, khong can ghi lai toan bo danh sach
    ofstream file("Menu.txt", ios::app); // Mo file o che do ghi them
    if (file.is_open()) {
        file << monAn.getMaMon() << "," << monAn.getTenMon() << "," << monAn.getGia() << "\n";
        file.close();
    }
    else {
        cerr << "Khong the ghi du lieu vao file Menu.txt!" << endl;
        return false;
    }

    cout << "Them mon an '" << tenMon << "' vao menu thanh cong!" << endl;
    return true;
}

bool Menu::xoaMonAn(int maMon) {
    for (int i = 0; i < danhSachMonAn.size(); ++i) {
        if (danhSachMonAn[i].getMaMon() == maMon) {
            danhSachMonAn.erase(danhSachMonAn.begin() + i, danhSachMonAn.begin() + i + 1);
            ghiMenuToFile();
            cout << "Da xoa mon an voi ma " << maMon << ".\n";
            return true;
        }
    }
    cout << "Khong tim thay mon an voi ma " << maMon << ".\n";
    return false;
}

bool Menu::suaMonAn(int maMon, const string& tenMonMoi, int giaTienMoi) {
    for (auto& monAn : danhSachMonAn) {
        if (monAn.getMaMon() == maMon) {
            if (tenMonMoi.empty() || giaTienMoi <= 0) {
                cerr << "Thong tin mon an khong hop le." << endl;
                return false;
            }
            monAn.setTenMon(tenMonMoi);
            monAn.setGia(giaTienMoi);
            ghiMenuToFile();
            cout << "Da sua mon an voi ma " << maMon << ".\n";
            return true;
        }
    }
    cout << "Khong tim thay mon an voi ma " << maMon << ".\n";
    return false;
}

void Menu::hienThiMenu() const {
    cout << "Danh sach mon an trong menu:\n";
	cout << left << setw(8) << "Ma Mon" << "|"
		<< setw(30) << "Ten Mon" << "|"
		<< "Gia\n";
	cout << string(8, '-') << "|" << string(30, '-') << "|" << string(20, '-') << endl;
    for (const auto& monAn : danhSachMonAn) {
        monAn.hienThiThongTin();
    }
}

void Menu::goiMon(HoaDon &hoaDon) {
    hienThiMenu();
    string maMon_str, soLuong_str;
    int maMon, soLuong;
    cout << "Nhap ma mon muon goi: ";
    cin >> maMon_str;
    while (!kiemTraSo(maMon_str)) {
        cout << "Vui long nhap mot so hop le!\n";
        cout << "Nhap ma mon muon goi: ";
        cin >> maMon_str;
    }
	cin.ignore();
    maMon = stoi(maMon_str);

    bool monTimThay = false;
    for (const auto& monAn : danhSachMonAn) {
        if (monAn.getMaMon() == maMon) {
            cout << "Nhap so luong: ";
            cin >> soLuong_str;
            while (!kiemTraSo(soLuong_str)) {
                cout << "Vui long nhap mot so hop le!\n";
                cout << "Nhap so luong: ";
                cin >> soLuong_str;
            }
            cin.ignore();
            soLuong = stoi(soLuong_str);
            int tongTien = monAn.getGia() * soLuong;
            cout << "Tong tien cho " << monAn.getTenMon()
                << " la: " << tongTien << " VND\n";
			hoaDon.themMonAn(monAn, soLuong);
            monTimThay = true;
            hoaDon.ghiDoanhThu(tongTien);
            break;
        }
    }
    if (!monTimThay) {
        cout << "Khong tim thay ma mon!\n";
    }   
}

void Menu::Gioithieu() {
	cout << "\t\t\t";
	for (int i = 0; i <= 50; ++i){
		cout << "-";
	}
	cout << endl;
	cout << "\t\t\t|            DO AN CO SO LAP TRINH PBL2           |\n";
	cout << "\t\t\t|THUC HIEN BOI: NGUYEN THANH BINH - NGUYEN DUY HAN|\n";
	cout << "\t\t\t";
	for (int i = 0; i <= 50; ++i){
		cout << "-";
	}
	cout << endl;
	cout << endl;
	cout <<"\t+-------------------------+ 			 +===================================+\n";
	cout <<"\t|   D                     | 			 ||                                 ||\n";
	cout <<"\t| B A C H K H O A         | 			 ||    TRUONG DAI HOC BACH KHOA     ||\n";
	cout <<"\t|   N -----**-------      |  			 ||        DAI HOC DA NANG          ||\n";
	cout <<"\t|   A ------***-----      | 			 ||                                 ||\n";
	cout <<"\t|   N -------****---      |  			 ||     KHOA CONG NGHE THONG TIN    ||\n";
	cout <<"\t|   G -------*****--      | 			 ||                                 ||\n";
	cout <<"\t|     ------******--      | 			 ||     UNG DUNG DAT MON AN VA      ||\n";
	cout <<"\t|     -----******---      | 			 ||       THANH TOAN DON HANG       ||\n";
	cout <<"\t|                         | 			 ||                                 ||\n";
	cout <<"\t+-------------------------+ 			 +===================================+\n";
	for (int j = 0; j <= 100; ++j){
		cout << "=";
	}
	cout << endl;
}