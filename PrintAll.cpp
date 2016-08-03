//
// Created by Allen Chen on 8/3/16.
//
#include "PrintAll.h"
using namespace std;

// print 1D arrary
void PrintAll(int a [], int n){
    cout << "[ ";
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << "]" << endl;
}
void PrintAll(float a [], int n){
    cout << "[ ";
    for(int i = 0; i < n; i++){
        cout << fixed << setprecision(2) << a[i] << " ";
    }
    cout << "]" << endl;
}
// print 2D array
void PrintAll(int** a,int n,int m){
    cout << "[" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "]" << endl;
}
void PrintAll(float** a,int n,int m){
    cout << "[" << endl;
    for(int i = 0;i < n; i++){
        for(int j = 0; j < m; j++){
            cout << fixed << setprecision(2) << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "]" << endl;
}

// print vector
void PrintAll(vector<int> a){
    cout << "[ ";
    for(int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
    cout << "]" << endl;
}
void PrintAll(vector<float> a){
    cout << "[ ";
    for(int i = 0; i < a.size(); i++){
        cout << fixed << setprecision(2) << a[i] << " ";
    }
    cout << "]" << endl;
}
void PrintAll(vector<string> a){
    cout << "[ ";
    for(int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
    cout << "]" << endl;
}
void PrintAll(map<string,int> m1){
    cout << "{ " << endl;
    for(map<string,int>::iterator it = m1.begin(); it != m1.end(); it ++){
        cout << it->first << " : " << it->second << endl;
    }
    cout<< " }" << endl;
}

// Template for array
template <typename T> void PrintAllT(T a [], int n){
    cout << "[" << endl;
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << "]" << endl;
}
// Template for array
template <typename T> void PrintAllT(T a [], int n, int m){
    cout << "[" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "]" << endl;
}
// Template for vector
template <typename T> void PrintAllT(vector<T> a){
    cout << "[" << endl;
    for (int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
    cout << "]" << endl;
}

// template for 2D vector
template <typename T> void PrintAllT(vector<vector<T> > a){
    cout << "[" << endl;
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < a[i].size(); j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "]" << endl;
}