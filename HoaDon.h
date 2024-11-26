#pragma once
#include "DonHang.h"
#include <fstream>
#include <string>

class HoaDon {
public:
    void InHoaDon(const DonHang& donHang, const std::string& MSKH, const std::string& TenFile);
    string DocMSKH(const std::string& TenFile);
};
