#ifndef MONAN_H
#define MONAN_H

#include <string>
using namespace std;
class MonAn {
private:
    std::string maMon;
    std::string tenMon;
    double gia;

public:
    // Hàm dựng
    MonAn(const std::string &ma = "", const std::string &ten = "", double g = 0.0);

    // Setter và Getter
    void setMaMon(const std::string &ma);
    std::string getMaMon() const;

    void setTenMon(const std::string &ten);
    std::string getTenMon() const;

    void setGia(double g);
    double getGia() const;

    // Hiển thị thông tin
    void hienThiThongTin() const;
};

#endif
