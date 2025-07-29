#include <iostream>
#include <vector>
using namespace std;

struct Point3D {
    double x, y, z;
    
    Point3D(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
    
    bool operator<(const Point3D& other) const {
        if (x != other.x) return x < other.x;
        if (y != other.y) return y < other.y;
        return z < other.z;
    }
    
    bool operator==(const Point3D& other) const {
        return x == other.x && y == other.y && z == other.z;
    }
};

int binarySearch(const vector<Point3D>& arr, const Point3D& target) {
    int left = 0;
    int right = arr.size() - 1;
    int steps = 0;
    
    while (left <= right) {
        steps++;
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return steps;
        }
        
        if (arr[mid] < target) {
            left = mid + 1;
        } 
        else 
        {
            right = mid - 1;
        }
    }
    
    return -1; 
}

int main() {
    
    int n;
    cin >> n;
    
    vector<Point3D> points(n);
    
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y >> points[i].z;
    }
    
    int m;
    cin >> m;
    
    for (int i = 0; i < m; i++) {
        Point3D query;
        cin >> query.x >> query.y >> query.z;
        
        int result = binarySearch(points, query);
        
        if (result == -1) {
            cout << "KHONG" << endl;
        } else {
            cout << result << endl;
        }
    }
    
    return 0;
}