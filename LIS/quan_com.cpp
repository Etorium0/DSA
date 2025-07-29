#include <iostream>
using namespace std;

struct KhachHang {
    int soThuTu;
    int loaiCom; // 0: com_chien, 1: com_tam, 2: com_suon
    KhachHang* next;
    
    KhachHang() : soThuTu(0), loaiCom(0), next(NULL) {}
    KhachHang(int stt, int loai) : soThuTu(stt), loaiCom(loai), next(NULL) {}
};

class Queue {
private:
    KhachHang* front;
    KhachHang* rear;
    
public:
    Queue() : front(NULL), rear(NULL) {}
    
    void push(int soThuTu, int loaiCom) {
        KhachHang* newNode = new KhachHang(soThuTu, loaiCom);
        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }
    
    void pop() {
        if (front == NULL) return;
        KhachHang* temp = front;
        front = front->next;
        if (front == NULL) rear = NULL;
        delete temp;
    }
    
    bool empty() {
        return front == NULL;
    }
    
    void printAll() {
        if (empty()) {
            cout << "Tiem qua e, khong co khach nao" << endl;
            return;
        }
        
        KhachHang* current = front;
        while (current != NULL) {
            cout << current->soThuTu << " ";
            if (current->loaiCom == 0) cout << "com_chien";
            else if (current->loaiCom == 1) cout << "com_tam";
            else cout << "com_suon";
            cout << endl;
            current = current->next;
        }
    }
    
    ~Queue() {
        while (!empty()) {
            pop();
        }
    }
};

int main() {
    Queue hangDoi;
    int soThuTuHienTai = 1;
    int trangThai;
    
    while (cin >> trangThai && trangThai != -1) {
        if (trangThai == 0) {
            // Khách vào quán
            char c1, c2, c3, c4, c5, c6, c7, c8, c9;
            cin >> c1;
            if (c1 == 'c') {
                cin >> c2 >> c3 >> c4;
                if (c2 == 'o' && c3 == 'm' && c4 == '_') {
                    cin >> c5;
                    if (c5 == 'c') {
                        // Có thể là com_chien
                        cin >> c6 >> c7 >> c8 >> c9;
                        if (c6 == 'h' && c7 == 'i' && c8 == 'e' && c9 == 'n') {
                            hangDoi.push(soThuTuHienTai, 0); // com_chien
                            soThuTuHienTai++;
                        }
                    } else if (c5 == 't') {
                        // Có thể là com_tam
                        cin >> c6 >> c7;
                        if (c6 == 'a' && c7 == 'm') {
                            hangDoi.push(soThuTuHienTai, 1); // com_tam
                            soThuTuHienTai++;
                        }
                    } else if (c5 == 's') {
                        // Có thể là com_suon
                        cin >> c6 >> c7 >> c8;
                        if (c6 == 'u' && c7 == 'o' && c8 == 'n') {
                            hangDoi.push(soThuTuHienTai, 2); // com_suon
                            soThuTuHienTai++;
                        }
                    }
                }
            }
        } 
        else if (trangThai == 1) {
            // Khách ra về
            hangDoi.pop();
        }
    }
    
    // Xuất kết quả
    hangDoi.printAll();
    
    return 0;
}
