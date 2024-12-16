#ifndef MENU_H
#define MENU_H

#include "MonAn.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class Menu {
private:
    std::vector<MonAn> danhSachMonAn;  // Danh sách các món ăn trong menu
    static int maMonCounter;           // Biến static theo dõi mã món cuối cùng

//    // Hàm đọc menu từ file Menu.txt
//    void docMenuFromFile();
//
//    // Hàm ghi menu vào file Menu.txt
//    void ghiMenuToFile() const;

public:
    // Constructor
    Menu();
    
    // Khai báo hàm trả về mã món tiếp theo
	int getMaMonTiepTheo() const;

    // Thêm món ăn vào menu (cập nhật mã món tự động)
    //void themMonAn();
	//    void themMonAn(const std::string& tenMon, double giaTien);
	//    void themMonAn(const std::string& tenMon, int giaTien);
	bool themMonAn(const std::string& tenMon, int giaTien);

    // Xóa món ăn khỏi menu theo mã món
    //bool xoaMonAn();
	bool xoaMonAn(int maMon);
    // Sửa món ăn trong menu theo mã món
    bool suaMonAn(int maMon, const std::string& tenMonMoi, int giaTienMoi);  // Cập nhật khai báo hàm sửa món ăn

    // Hiển thị danh sách món ăn trong menu
    void hienThiMenu() const;

    // Gọi món: Hiển thị menu, nhập mã món và số lượng, tính tổng tiền
    void goiMon();
    
    // Hàm đọc menu từ file Menu.txt
    void docMenuFromFile();

    // Hàm ghi menu vào file Menu.txt
    void ghiMenuToFile();
};

#endif // MENU_H
