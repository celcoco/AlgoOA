#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <iomanip>

#include "solution.h"
template <typename T>
void printarrary(T a[],int n);

template <typename T>
void printarrary2d(T** a,int n,int m);

template<typename T>
void printvector(vector<T> a);

template<typename T>
void printvector2d(vector<vector<T>> a);

using namespace std;
int main() {
    cout<<"------START------"<<endl;
    Solution sln;
    int i=0;
    int j=0;

//    /* 169 Majority Element */
//    /* assume majority Element always exist in non-empty array */
//    cout<<"\n169. Majority Number"<<endl;
//    int inarr[3] = {1,2,2};
//    cout<<"input:";
//    printarrary(inarr,3);
//    vector<int> nums;
//    for(i=0;i<3;i++){
//        nums.push_back(inarr[i]);
//    }
//    int majnum = sln.majorityElement(nums);
//    cout<<"Result:"<<majnum<<endl;
//
//    /* 20 Valid Parentheses */
//    cout<<"\n20. Valid Parenthese"<<endl;
//    string t20in = "[{([])}]";
//    bool t20out = sln.isValid(t20in);
//    cout<<"input string:"<<t20in<<endl;
//    cout<<"result:"<<t20out<<endl;

//    /* 20 transformed */
//    cout<<"\nMatching Pair"<<endl;
//    string t20in_2 = "ABBbbc";
//    cout<<"input:"<<t20in_2<<endl;
//    cout<<"result:"<<sln.isValid2(t20in_2)<<endl;
//    int id = sln.MatchingPair(t20in_2);
//    if(id <= 0){
//        cout<<"last pair id:"<<id<<" "<<endl;
//    }else{
//        cout<<"last pair id:"<<id<<" "<<t20in_2[id]<<endl;
//    }
//
//
//    cout<<"\nFinding Mini Gates"<<endl;
//    int arr[6] = {900,930,950};
//    int dep[6] = {930,940,1200};
//    int flights = 3;
//    cout<<"arr:";
//    printarrary(arr,flights);
//    cout<<"dep:";
//    printarrary(dep,flights);
//    cout<<"MiniGate:"<<sln.miniGates(arr,dep,flights)<<endl;
//
//    cout<<"\nPair Char"<<endl;
//    string PairCharIn = "abcba";
//    cout<<"Input:"<<PairCharIn;
//    char PairCharOut = sln.pairchar(PairCharIn);
//    cout<<"Result:"<<PairCharOut<<endl;


//    cout<<"\nAkuna t1"<<endl;
//    int d = 2*2*2;
//    //cin>>d;
//    cout<<"input:"<<d<<endl;
//    bool akuna_t1 = sln.Akuna_t1(d);
//    cout<<"result:"<<akuna_t1<<endl;
//
//    cout<<"\nAkuna t2"<<endl;
//    float akuna_t2_in[3] = {2.1, 2.0, 2.1};
//    cout<<"Input:"<<endl;
//    printarrary(akuna_t2_in,3);
//    float stddev = sln.Akuna_t2(akuna_t2_in,3);
//    cout<<"Result:"<<stddev<<endl;


//    cout<<"\nAkuna t3"<<endl;
//    int arrh = 3;
//    int arrw = 4;
//    int **pmat = new int*[arrh];
//    for(i=0;i<arrh;i++){
//        pmat[i] = new int[arrw];
//    }
//    for(i=0;i<arrh;i++){
//        for(j=0;j<arrw;j++){
//            pmat[i][j] = i*arrw+j;
//        }
//    }
//    cout<<"Input:"<<endl;
//    printarrary2d(pmat,arrh,arrw);
//    int **newmat = sln.Akuna_t3(pmat,arrh,arrw);
//    cout<<"Result:"<<endl;
//    printarrary2d(newmat,arrw,arrh);
//    for(i=0;i<arrh;i++){
//        delete [] pmat[i];
//    }
//    delete [] pmat;
//    for(i=0;i<arrw;i++){
//        delete [] newmat[i];
//    }
//    delete [] newmat;

//    cout<<"\nAkuna t3_2 using 2d vector"<<endl;
//    int arrh = 3;
//    int arrw = 4;
//    vector<vector<int>> mat;
//    for(i=0;i<arrh;i++){
//        vector<int> tmp;
//        for(j=0;j<arrw;j++){
//            tmp.push_back(i*arrw+j);
//        }
//        mat.push_back(tmp);
//    }
//    cout<<"Input:"<<endl;
//    printvector2d(mat);
//    vector<vector<int>> newmat = sln.Akuna_t3_2(mat,arrh,arrw);
//    cout<<"Result:"<<endl;
//    printvector2d(newmat);

//    cout<<"\nAkuna t4"<<endl;
//    cout<<"Input:"<<endl;
//    string line;
//    string word;
//    vector<string> words;
//    getline(cin,line);
//    vector<string> abbrs;
//    int UniWordCnt = 0;
//    while(line != "q"){
//        cout<<"input:"<<line<<endl;
//        UniWordCnt += sln.Akuna_t4(line);
//        getline(cin,line);
//    }
//    cout<<"Result:"<<UniWordCnt<<endl;

//    cout<<"\nAkuna t5"<<endl;
//    int RollNum = 3;
//    cout<<"Input:"<<RollNum<<endl;
//    double FinalExpvalue = sln.Akuna_t5(RollNum);
//    cout<<"Result:"<<FinalExpvalue<<endl;
//    printf("Result2:%.2f\n",FinalExpvalue);
//    cout<<"Result3:";
//    cout<<setiosflags(ios::fixed)<<setprecision(2)<<floor(FinalExpvalue*100)/100<<endl;


//    cout<<"\nAkuna t6"<<endl;
//    string Postfixstr = "23+21-/341-*+a+bc+/";
//    cout<<"Input:"<<Postfixstr<<endl;
//    string Infixstr = sln.Akuna_t6(Postfixstr);
//    cout<<"Result:"<<Infixstr<<endl;

//    cout<<"\nPilNum"<<endl;
//    int year = 2016;
//    cout<<"Input:"<<year<<endl;
//    int pilnum = sln.PilNum(year);
//    cout<<"Resutl:"<<pilnum<<endl;
//    int monthlen[12]={31,28,30,31,30,31,31,30,31,30,31};

//    cout<<"\nUniWordCnt"<<endl;
//    sln.UniWordCnt();

    cout<<endl<<"LowestDist"<<endl;
    sln.LowestDist();

    cout<<"-------END-------"<<endl;
    return 1;
}

template <typename T>
void printarrary(T a[],int n){
    cout<<"[ ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"]"<<endl;
}

template <typename T>
void printarrary2d(T** a,int n,int m){
    cout<<"["<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"]"<<endl;
}

template <typename T>
void printvector(vector<T> a){
    cout<<"[ ";
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<"]"<<endl;
}

template <typename T>
void printvector2d(vector<vector<T>> a){
    cout<<"["<<endl;
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[i].size();j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"]"<<endl;
}