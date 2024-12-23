#pragma once
#include "KhachHang.h"
#include "NhanVien.h"
#include "QuanLy.h"

class DSTaiKhoan {
    vector<TaiKhoan *> DSTK;
public:
    DSTaiKhoan();
	~DSTaiKhoan();
    string getPassword();
    // Đọc tài khoản khách hàng từ file
    void docDSTaiKhoanFromFile();
    // Ghi tài khoản khách hàng vào file
    void ghiDSTaiKhoanToFile();
    // Tạo tài khoản khách hàng
    void taoTaiKhoanKhachHang();
    //kiểm tra usernam có bị trùng hay không
    bool KiemTraUsernam(const std::vector<TaiKhoan*>& DSTK, const std::string& username);
	// Tạo tài khoản nhân viên
	void taoTaiKhoanNhanVien();
	// Xóa tài khoản với mã tài khoản
	void xoaTaiKhoan(int);
    void xoaTaiKhoanNhanVien(); // Nhập từ bàn phím
	// Sửa tài khoản
	void suaTaiKhoan(int, string, string, string);
	void suaTaiKhoanNhanVien(); // Nhập từ bàn phím
    // Đăng nhập
    TaiKhoan* dangNhap();
	// Hiển thị danh sách khách hàng
	void hienThiDSTaiKhoanKhachHang();
	void hienThiDSTaiKhoanNhanVien();
};