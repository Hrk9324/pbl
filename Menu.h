#ifndef MENU_H
#define MENU_H

#include <vector>
#include <unordered_set>
#include "MonAn.h"

class Menu {
private:
    std::vector<MonAn> danhSachMonAn;
    std::unordered_set<std::string> danhSachMaMon;

public:
    Menu();
    std::string TaoMaMonAn4KyTu();
    void ThemMonAnVaoMenu(MonAn &monan);
    void ThemMonAn();
    void XoaMonAnKhoiMenu(string &maMon);
    void XoaMonAn();
    void SuaMonAnTrongMenu(string &maMon);
    void SuaMonAn();
    void HienThiMenu() ;
    bool DocMenuTuFile(const string& fileName)  ;
    void GhiMenuVaoFile(const string &tenFile) const;
    void GoiMon();
    void ThemMonAnTuFile();
    std::vector<MonAn> GetDsMonAn() const;
};

#endif
