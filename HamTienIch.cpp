#include "HamTienIch.h"
bool kiemTraSo(string s) {
    for(char c : s) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}