#include "DSTaiKhoan.h"

DSTaiKhoan::DSTaiKhoan() {
	DSTK.clear();
}

DSTaiKhoan::~DSTaiKhoan() {
	for (int i = 0; i < DSTK.size(); i++) {
		delete DSTK[i];
	}
	DSTK.clear();
}

string DSTaiKhoan::getPassword() {
    string password = "";
    char ch;
    while ((ch = _getch()) != 13) {     // 13 là mã ASCII của phím Enter
        if (ch == 8) {                  // 8 là mã ASCII của phím Backspace
            if (password.length() > 0) {
                password.pop_back();
                cout << "\b \b"; 
            }
        }
        else {
            password += ch;
            cout << "*";  // Hiển thị dấu *
        }
    }
    cout << endl;
    return password;
}

bool DSTaiKhoan::KiemTraUsernam(const std::vector<TaiKhoan*>& DSTK, const std::string& username){
    for (int i = 0; i < DSTK.size(); i++){
        if (DSTK[i]->getUsername() == username)
        {      
		    return true;
        }
    }
    return false;
}

void DSTaiKhoan::docDSTaiKhoanFromFile() {
    ifstream file("TaiKhoan.txt");
    if (!file.is_open()) {
		cerr << "Khong the mo file de doc du lieu" << endl;
		return;
    }
    string line;
	int role = 0;
	string maTaiKhoan, tenTaiKhoan, username, password;
    string role_str;
    while (getline(file, line)) {
        stringstream ss(line);
		getline(ss, role_str, ','); 
		getline(ss, maTaiKhoan, ',');
		getline(ss, tenTaiKhoan, ',');
		getline(ss, username, ',');
		getline(ss, password, '\n');
        TaiKhoan* kh;
		// USA -> U(user), S(staff), A(admin)
        if (role_str == "U") {
			kh = new KhachHang();
            kh->setRole(0);
        }
        else if (role_str == "S") { 
			kh = new NhanVien();
            kh->setRole(1); 
        }
        else if (role_str == "A") { 
			kh = new QuanLy();
            kh->setRole(2); 
        }
        else {
			kh = new TaiKhoan();
        }
		kh->setMaTaiKhoan(stoi(maTaiKhoan));
		kh->setTenNguoiDung(tenTaiKhoan);
		kh->setUsername(username);
		kh->setPassword(password);
		DSTK.push_back(kh);
    }
    file.close();
}

void DSTaiKhoan::ghiDSTaiKhoanToFile() {
    ofstream file("TaiKhoan.txt");
    if (file.is_open()) {
        for (const auto& kh : DSTK) {
			if (kh->getRole() == 0) file << "U,";
			else if (kh->getRole() == 1) file << "S,";
			else if (kh->getRole() == 2) file << "A,";
            file << kh->getMaTaiKhoan() << ","
                << kh->getTenNguoiDung() << ","
                << kh->getUsername() << ","
                << kh->getPassword() << endl;
        }
        file.close();
    }
}

void DSTaiKhoan::taoTaiKhoanKhachHang() {
    string tenTaiKhoan, username, password;
    cout << "Nhap ten khach hang: ";
    getline(cin, tenTaiKhoan);
    
    bool UsernameHopLe = false;
    while (!UsernameHopLe)
    {
        cout << "Nhap username: ";
        getline(cin, username);

        if (KiemTraUsernam(DSTK, username))
        {
            cout << "username da ton tai!" << endl;
            cout << "nhap username khac" << endl;
        }
        else
        {
            UsernameHopLe = true;
            cout << "Username hop le" << endl;
        }
    }
    
    // cout << "Nhap username: ";
    // getline(cin, username);

    cout << "Nhap password: ";
    password = getPassword();  // Dùng hàm để ẩn mật khẩu

    TaiKhoan* kh = new KhachHang();
	kh->setRole(0);
	kh->setMaTaiKhoan(DSTK.size() + 1);
	kh->setTenNguoiDung(tenTaiKhoan);
	kh->setUsername(username);
	kh->setPassword(password);

    DSTK.push_back(kh);
	ghiDSTaiKhoanToFile();
    cout << "Tao tai khoan khach hang thanh cong!" << endl;
}

void DSTaiKhoan::taoTaiKhoanNhanVien() {
    string tenTaiKhoan, username, password;
    cout << "Nhap ten nhan vien: ";
    getline(cin, tenTaiKhoan);
    cout << tenTaiKhoan << endl;

    cout << "Nhap username: ";
    getline(cin, username);
    cout << username << endl;

    cout << "Nhap password: ";
    password = getPassword();  // Dùng hàm để ẩn mật khẩu

    TaiKhoan* kh = new NhanVien();
    kh->setRole(1);
    kh->setMaTaiKhoan(DSTK.size() + 1);
    kh->setTenNguoiDung(tenTaiKhoan);
    kh->setUsername(username);
    kh->setPassword(password);

    DSTK.push_back(kh);
    ghiDSTaiKhoanToFile();
    cout << "Tao tai khoan nhan vien thanh cong!" << endl;

}

void DSTaiKhoan::xoaTaiKhoan(int ma) {
	for (int i = 0; i < DSTK.size(); i++) {
		if (DSTK[i]->getMaTaiKhoan() == ma) {
			delete DSTK[i];
			DSTK.erase(DSTK.begin() + i, DSTK.begin() + i + 1);
			cout << "Xoa tai khoan thanh cong!" << endl;
			ghiDSTaiKhoanToFile();
			return;
		}
	}
}

void DSTaiKhoan::xoaTaiKhoanNhanVien() {
    hienThiDSTaiKhoanNhanVien();
	string ma_str;
	cout << "Nhap ma tai khoan nhan vien can xoa: ";
    cin >> ma_str;
    while (!kiemTraSo(ma_str)) {
        cout << "Vui long nhap mot so hop le!\n";
        cout << "Nhap ma tai khoan nhan vien can xoa: ";
        cin >> ma_str;
    }
	cin.ignore();
	int ma = stoi(ma_str);
	xoaTaiKhoan(ma);
}

void DSTaiKhoan::suaTaiKhoan(int ma, string ten, string username, string password) {
	for (int i = 0; i < DSTK.size(); i++) {
		if (DSTK[i]->getMaTaiKhoan() == ma) {
			DSTK[i]->setTenNguoiDung(ten);
			DSTK[i]->setUsername(username);
			DSTK[i]->setPassword(password);
			cout << "Sua tai khoan thanh cong!" << endl;
			ghiDSTaiKhoanToFile();
			return;
		}
	}
	cout << "Khong tim thay tai khoan voi ma tai khoan " << ma << endl;
}

void DSTaiKhoan::suaTaiKhoanNhanVien() {
    hienThiDSTaiKhoanNhanVien();
    string ma_str;
    cout << "Nhap ma tai khoan nhan vien can sua: ";
    cin >> ma_str;
    while (!kiemTraSo(ma_str)) {
        cout << "Vui long nhap mot so hop le!\n";
        cout << "Nhap ma tai khoan nhan vien can sua: ";
        cin >> ma_str;
    }
    int ma = stoi(ma_str);
    cin.ignore();
    string ten, username, password;
    cout << "Nhap ten nhan vien: ";
    getline(cin, ten);
    cout << "Nhap username: ";
    getline(cin, username);
    cout << "Nhap password: ";
    password = getPassword();
    suaTaiKhoan(ma, ten, username, password);
}


TaiKhoan* DSTaiKhoan::dangNhap() {
    string username, password;
    cout << "Nhap username: ";
    getline(cin, username);

    cout << "Nhap password: ";
    password = getPassword();  // Dùng hàm để ẩn mật khẩu

    for (auto& kh : DSTK) {
        if (kh->getUsername() == username && kh->getPassword() == password) {

            

            cout << "Dang nhap thanh cong cho khach hang: " << kh->getTenNguoiDung() << endl;
            return kh;  // Trả về con trỏ đến khách hàng
        }
    }



    cout << "Username hoac password sai!" << endl;
    return nullptr;  // Trả về nullptr nếu đăng nhập không thành công

}

void DSTaiKhoan::hienThiDSTaiKhoanKhachHang() {
    cout << "Danh sach khach hang: \n";
    cout << left << setw(8) << "Ma KH" << '|'
        << setw(30) << "Ten KH" << '|'
        << setw(30) << "Username" << endl;
	cout << string(8, '-') << '|' 
        << string(30, '-') << '|' 
        << string(30, '-') << endl;
	for (int i = 0; i < DSTK.size(); i++) {
		cout << left << setw(8) << DSTK[i]->getMaTaiKhoan() << '|' 
            << setw(30) << DSTK[i]->getTenNguoiDung() << '|'
			<< setw(30) << DSTK[i]->getUsername() << endl;
	}
}

void DSTaiKhoan::hienThiDSTaiKhoanNhanVien() {
    cout << "Danh sach tai khoan Nhan Vien: \n";
    cout << left << setw(8) << "Ma NV" << '|'
        << setw(30) << "Ten nhan vien" << '|'
		<< setw(30) << "Username" << '|'
		<< "Password" << endl;

    cout << string(8, '-') << '|'
        << string(30, '-') << '|'
        << string(30, '-') << '|'
		<< string(30, '-') << endl;

    for (int i = 0; i < DSTK.size(); i++) {
		if (DSTK[i]->getRole() == 1)
        cout << left << setw(8) << DSTK[i]->getMaTaiKhoan() << '|'
            << setw(30) << DSTK[i]->getTenNguoiDung() << '|'
			<< setw(30) << DSTK[i]->getUsername() << '|'
			<< setw(30) << DSTK[i]->getPassword() << endl;
    }

}