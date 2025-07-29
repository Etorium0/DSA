    /*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
    define
    include
    ###End banned keyword*/
    #include <iostream>
    #include <string>

    using namespace std;

    struct Hocsinh {
        int Maso;
        string Hoten;
        int Namsinh;
        bool Gioitinh;
        double TBK;
    };
    void Input(Hocsinh &x) {
        cin >> x.Maso;
        getline(cin>>ws, x.Hoten);
        cin >> x.Namsinh;
        cin >> x.Gioitinh;
        cin >> x.TBK;
    }
    void Output(Hocsinh hs) {
        cout << '[' << hs.Maso << "\t" << hs.Hoten << "\t" << hs.Gioitinh << "\t" << hs.Namsinh << "\t" << hs.TBK << "]\n";
    }


    int QuickSort(Hocsinh [] , int, int);

    int main()
    {
        Hocsinh *ls = NULL;
        int n;
        cin >> n;
        ls = new Hocsinh[n];
        for (int i = 0; i < n; i++) {
            Input(ls[i]);
        }
        cout << QuickSort(ls, 0, n-1) << endl;
        for (int i = 0; i < n; i++) {
            Output(ls[i]);
        }
        delete [] ls;
        return 0;
    }

    int QuickSort(Hocsinh ls[], int b, int e) 
    {
        int count = 0;

        if (b < e) 
        {
            string pivot = ls[e].Hoten;
            int i = b - 1;
            for (int j = b; j < e; j++) {
                if (ls[j].Hoten <= pivot) {
                    i++;
                    swap(ls[i], ls[j]);
                }
            }
            swap(ls[i + 1], ls[e]);
            count++;
            int pi = i + 1;
            count += QuickSort(ls, b, pi - 1);
            count += QuickSort(ls, pi + 1, e);
        }

        return count;
    }
