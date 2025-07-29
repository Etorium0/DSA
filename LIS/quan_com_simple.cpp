#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    queue<pair<int, string>> hangDoi; // pair<số thứ tự, loại cơm>
    int soThuTu = 1;
    int trangThai;
    
    while (cin >> trangThai && trangThai != -1) {
        if (trangThai == 0) {
            // Khách vào quán
            string loaiCom;
            cin >> loaiCom;
            hangDoi.push(make_pair(soThuTu, loaiCom));
            soThuTu++;
        } 
        else if (trangThai == 1) {
            // Khách ra về
            if (!hangDoi.empty()) {
                hangDoi.pop();
            }
        }
    }
    
    // Xuất kết quả
    if (hangDoi.empty()) {
        cout << "Tiem qua e, khong co khach nao" << endl;
    } else {
        while (!hangDoi.empty()) {
            pair<int, string> khach = hangDoi.front();
            hangDoi.pop();
            cout << khach.first << " " << khach.second << endl;
        }
    }
    
    return 0;
}
