#include "HoaDon.h"

double doanhThuTong = 0;

void HoaDon::themMonAn(MonAn monAn, int soLuong) {
	danhSachMonAn.push_back({monAn, soLuong});
}

void HoaDon::clearHoaDon() {
	danhSachMonAn.clear();
}

double HoaDon::tinhTongTien() {
	double tongTien = 0;
	for (const auto& monAn : danhSachMonAn) {
		tongTien += monAn.first.getGia() * monAn.second;
	}
	return tongTien;
}

void HoaDon::inHoaDon() {
	ofstream file("HoaDon.txt");
	if (file.is_open()) {
		file << "Thong tin hoa don:" << endl;
		file << left << setw(8) << "Ma Mon" << "|"
			<< setw(30) << "Ten Mon" << "|"
			<< setw(20) << "Gia" << "|"
			<< "So Luong" << endl;
		file << string(8, '-') << "|" << string(30, '-') << "|" << string(20, '-') << "|" << string(12, '-') << endl;
		for (const auto& monAn : danhSachMonAn) {
			file << left << setw(8) << monAn.first.getMaMon() << "|"
				<< setw(30) << monAn.first.getTenMon() << "|"
				<< setw(20) << to_string(monAn.first.getGia()) + " VND" << "|"
				<< setw(4) << monAn.second << endl;
		}

		file << string(8 + 30 + 20 + 12 + 3, '-') << endl;
		file << "Tong tien: " << tinhTongTien() << " VND" << endl;
		cout << "In hoa don thanh cong vao file: HoaDon.txt" << endl;
		file.close();
	}
}

void HoaDon::ghiDoanhThu(int doanhThu) {
    ofstream file("ThongKeDoanhThu.txt", ios::app);
	// Mở file ở chế độ append để không mất dự liệu ghi vào trước đó
    if (file.is_open()) {
        file << "Doanh thu : " << doanhThu << " VND" << endl;
        file.close();
    }
}