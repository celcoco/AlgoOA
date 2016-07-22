#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#include "solution.h"
void printarrary(int a[],int n){
    cout<<"[ ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"]"<<endl;
}

using namespace std;
int main() {
    cout<<"------START------"<<endl;
    Solution sln;
    int i=0;

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



    cout<<"-------END-------"<<endl;
    return 1;
}



