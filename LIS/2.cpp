#include <iostream>
#include <cmath>
using namespace std;

struct Point3D {
    double x, y, z;
    Point3D* next;
    
    Point3D() : x(0), y(0), z(0), next(NULL) {}
    Point3D(double _x, double _y, double _z) : x(_x), y(_y), z(_z), next(NULL) {}
};

class LinkedList {
private:
    Point3D* head;
    
public:
    LinkedList() : head(NULL) {}
    
    void addPoint(double x, double y, double z) {
        Point3D* newPoint = new Point3D(x, y, z);
        if (head == NULL) {
            head = newPoint;
        } else {
            Point3D* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newPoint;
        }
    }
    
    int findPoint(double x, double y, double z) {
        Point3D* current = head;
        int index = 0;
        const double EPS = 1e-9; // Độ chính xác cho so sánh số thực
        
        while (current != NULL) {
            // So sánh với độ chính xác epsilon để tránh lỗi do số thực
            if (abs(current->x - x) < EPS && 
                abs(current->y - y) < EPS && 
                abs(current->z - z) < EPS) {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1; // Không tìm thấy
    }
    
    ~LinkedList() {
        while (head != NULL) {
            Point3D* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList pointList;
    int n;
    
    // Nhập n điểm vào danh sách A
    cin >> n;
    for (int i = 0; i < n; i++) {
        double x, y, z;
        cin >> x >> y >> z;
        pointList.addPoint(x, y, z);
    }
    
    // Nhập m điểm để tìm kiếm
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        double x, y, z;
        cin >> x >> y >> z;
        
        int result = pointList.findPoint(x, y, z);
        if (result == -1) {
            cout << "KHONG" << endl;
        } else {
            cout << result << endl;
        }
    }
    
    return 0;
}
