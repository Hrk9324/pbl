#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

class TaiKhoan {
private:
    string TenDangNhap;
    string MatKhau;

public:
    TaiKhoan() {}

    TaiKhoan(string tenDangNhap, string matKhau) {
        this->TenDangNhap = tenDangNhap;
        this->MatKhau = matKhau;
    }

    string GetTenDangNhap() const {
        return TenDangNhap;
    }

    bool XacThuc(string mk) const {
        return MatKhau == mk;
    }
    bool DangNhap(string, string) {
        return true;
    }
    
};

