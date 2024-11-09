#include "HoaDon.h"
#include <iostream>
#include <fstream>

void HoaDon::InHoaDon(const DonHang& donHang, const std::string& MSKH, const std::string& TenFile) {
    std::ofstream outFile(TenFile);
    if (!outFile) {
        std::cerr << "Khong the mo tep de ghi hoa don!" << endl;
        return;
    }

    outFile << "Ma so khach hang: " << MSKH << endl;
    outFile << "Chi tiet don hang:" << endl;

    // Duyệt qua danh sách món ăn trong đơn hàng và ghi từng món vào file
    for (const auto& mon : donHang.getDanhSachMonAn()) {
        outFile << "- " << mon.getTenMon() << ": " << mon.getGia() << " VND" << endl;
    }
    outFile << "Tong tien: " << donHang.TinhTongTien() << " VND" << endl;

    outFile.close();
    cout << "Hoa don da duoc in ra tep: " << TenFile << endl;
}
