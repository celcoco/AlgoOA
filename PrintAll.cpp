//
// Created by Allen Chen on 8/3/16.
//
#include "PrintAll.h"

using namespace std;

// Template for 1D array
template <typename T> void PrintAllT(T a [], int n){
    cout << "[" << endl;
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << "]" << endl;
}

// Template for 2D array
template <typename T> void PrintAllT(T** a, int n, int m){
    cout << "[" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "]" << endl;
}
// Template for 1D vector
template <typename T> void PrintAllT(vector<T> a){
    cout << "[" << endl;
    for (int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
    cout << "]" << endl;
}

// template for 2D vector
template <typename T> void PrintAllT(vector< vector<T> > a) {
    cout << "[" << endl;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "]" << endl;
}

// template for map
template <typename T1, typename T2> void PrintAllT(map<T1,T2> m1){
    cout << "{ " << endl;
    for(auto& it : m1){
        cout << it.first << " : " << it.second << endl;
    }
    cout<< " }" << endl;
}
// template for set
template <typename T> void PrintAllT(set<T> set1){
    cout << "{ ";
    for(auto& it : set1){
        cout << it << " ";
    }
    cout<< " }" << endl;
}
// template for list
template <typename T> void PrintAllT(list<T> list1){
    cout << "{ ";
    for(auto& it : list1){
        cout << it << " ";
    }
    cout<< " }" << endl;
}
// template for deque
template <typename T> void PrintAllT(deque<T> deque1){
    cout << "{ ";
    for(auto& it : deque1){
        cout << it << " ";
    }
    cout<< " }" << endl;
}

// print 1D arrary
void PrintAll(int a [], int n){
    PrintAllT<int>(a,n);
};
void PrintAll(float a [], int n){
    cout << fixed << setprecision(2);
    PrintAllT<float>(a,n);
}
void PrintAll(double a [], int n){
    cout << fixed << setprecision(2);
    PrintAllT<double>(a,n);
}
void PrintAll(string a [], int n){
    PrintAllT<string>(a,n);
};

// print 2D array
void PrintAll(int** a,int n,int m){
    PrintAllT<int>(a,n,m);
}
void PrintAll(float** a,int n,int m){
    cout << fixed << setprecision(2);
    PrintAllT<float>(a,n,m);
}
void PrintAll(double ** a,int n,int m){
    cout << fixed << setprecision(2);
    PrintAllT<double>(a,n,m);
};
void PrintAll(string** a,int n, int m){
    PrintAllT<string>(a,n,m);
}



// print vector
void PrintAll(vector<int> a){
    PrintAllT<int>(a);
}
void PrintAll(vector<float> a){
    cout << fixed << setprecision(2);
    PrintAllT<float>(a);
}
void PrintAll(vector<double> a){
    cout << fixed << setprecision(2);
    PrintAllT<double>(a);
}
void PrintAll(vector<string> a){
    PrintAllT<string>(a);
}



// 2D vector
void PrintAll(vector< vector<int> > a){
    PrintAllT<int>(a);
}
void PrintAll(vector< vector<float> > a){
    cout << fixed << setprecision(2);
    PrintAllT<float>(a);
}
void PrintAll(vector< vector<double> > a){
    cout << fixed << setprecision(2);
    PrintAllT<double>(a);
}
void PrintAll(vector< vector<string> > a){
    PrintAllT<string>(a);
}

// map
void PrintAll(map<char,int> m1){
    PrintAllT<char,int>(m1);
}
void PrintAll(map<string,int> m1){
    PrintAllT<string,int>(m1);
}

// set
void PrintAll(set<int> set1){
    PrintAllT<int>(set1);
}
void PrintAll(set<float> set1){
    PrintAllT<float>(set1);
}
void PrintAll(set<double> set1){
    PrintAllT<double>(set1);
}
void PrintAll(set<string> set1){
    PrintAllT<string>(set1);
}

// list
void PrintAll(list<int> list1){
    PrintAllT<int>(list1);
}