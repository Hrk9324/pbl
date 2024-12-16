#ifndef TAIKHOAN_H
#define TAIKHOAN_H

#include <string>
#include <vector>
#include <conio.h>

// Lớp Tài Khoản
class TaiKhoan {
public:
    // Tạo tài khoản cho nhân viên
	// static void taoTaiKhoanNhanVien();
	// static void taoTaiKhoanNhanVien(const std::string& tenNhanVien, const std::string& username, const std::string& password);
	void taoTaiKhoanNhanVien(const std::string& tenNhanVien, const std::string& username, const std::string& password);
    
    // Xóa tài khoản nhân viên
    static void xoaTaiKhoanNhanVien();
    
    // Tạo tài khoản cho khách hàng
    static void taoTaiKhoanKhachHang();
    
    // Xóa tài khoản khách hàng
    static void xoaTaiKhoanKhachHang();
    
    // Đăng nhập vào hệ thống
    static bool dangNhap();
    
    //Hàm ẩn mật khẩu
    static std::string getPassword();
    
private:
    // Lưu thông tin tài khoản (username, password) cho nhân viên và khách hàng
    static void ghiTaiKhoanNhanVienToFile();
    static void ghiTaiKhoanKhachHangToFile();
    
    // Đọc thông tin tài khoản từ file
    static void docTaiKhoanNhanVienFromFile();
    static void docTaiKhoanKhachHangFromFile();
    
    // Lưu thông tin vào mảng để dễ dàng xử lý
    struct TaiKhoanNhanVien {
        int maNhanVien;
        std::string tenNhanVien;
        std::string username;
        std::string password;
    };

    struct TaiKhoanKhachHang {
        int maKhachHang;
        std::string tenKhachHang;
        std::string username;
        std::string password;
    };

    // Mảng lưu các tài khoản nhân viên và khách hàng
    static std::vector<TaiKhoanNhanVien> danhSachNhanVien;
    static std::vector<TaiKhoanKhachHang> danhSachKhachHang;

    // Tạo mã tự động cho nhân viên và khách hàng
    static int maNhanVienCounter;
    static int maKhachHangCounter;
};

#endif // TAIKHOAN_H
