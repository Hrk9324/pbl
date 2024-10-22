//Donhang.h

#pragma once
#include "MonAn.h"
#include <vector>

class DonHang {
	private:
		vector<MonAn> DsMonDaChon;
		double TongTien;
	public:
		void ResetDonHang();
		DonHang();
		void ThemMonAn(const MonAn& mon);
		double TinhTongTien() const;
		void HienThiDonHang() ;
};
