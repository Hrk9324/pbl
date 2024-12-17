#pragma once
#include "MonAn.h"
#include "HoaDon.h"
class Menu {
    vector<MonAn> danhSachMonAn;  // Danh sách các món ăn trong menu
    int maMonCounter;
public:
    Menu();
	bool timMonAn(int) const;
    // Thêm món ăn vào menu (cập nhật mã món tự động)
    bool themMonAn(const string&, int);
    // Xóa món ăn khỏi menu theo mã món
    bool xoaMonAn(int);
    // Sửa món ăn trong menu theo mã món
    bool suaMonAn(int, const string&, int);
    // Hiển thị danh sách món ăn trong menu
    void hienThiMenu() const;
    // Gọi món: Hiển thị menu, nhập mã món và số lượng, tính tổng tiền
    void goiMon(HoaDon &);
    // Hàm đọc menu từ file Menu.txt
    void docMenuFromFile();
    // Hàm ghi menu vào file Menu.txt
    void ghiMenuToFile();
};