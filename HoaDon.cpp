//HoaDon.cpp

#include "HoaDon.h"

void HoaDon::InHoaDon(const DonHang& donHang, const string& MSKH, const string& tenFile){
	ofstream file(tenFile, ios::app);
	if (file.is_open()) {
		file << "Ma so khach hang: " << MSKH << endl;
		DonHang donhang;
		donhang.HienThiDonHang();
		file << "Tong tien: " << donHang.TinhTongTien() << " VND " << endl;
		file.close(); 
	}
}


