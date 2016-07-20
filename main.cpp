#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#include "solution.h"

using namespace std;
void moveZeroes(vector<int>& nums);
int main() {
    Solution sln;
    vector<int> nums;

    /* 169 Majority Element */
    /* assume majority Element always exist in non-empty array */
    int inarr[3] = {1,2,2};
    cout<<"input array: [ ";
    for(int i=0;i<3;i++){
        nums.push_back(inarr[i]);
        cout<<inarr[i]<<" ";
    }
    cout<<"]"<<endl;
    int majnum = sln.majorityElement(nums);
    cout<<"169. Majority Number is:"<<majnum<<endl;

    /* 20 Valid Parentheses */
    string t20in = "[{([])}]";
    bool t20out = sln.isValid(t20in);
    cout<<"20 Valid Parenthese"<<endl;
    cout<<"input string:"<<t20in<<endl;
    cout<<"result:"<<t20out<<endl;


    string t20in_2 = "ABAABbaaa";
    cout<<"20_2 input AB pair:"<<t20in_2<<endl;
    cout<<"result:"<<sln.isValid2(t20in_2)<<endl;
    int id = sln.MatchingPair(t20in_2);
    if(id <= 0){
        cout<<"last pair id:"<<id<<" "<<endl;
    }else{
        cout<<"last pair id:"<<id<<" "<<t20in_2[id]<<endl;
    }

    cout<<"Gate:"<<endl;
    int arr[6] = {900,910,920};
    int dep[6] = {930,940,1200};
    //    int arr[6] = {900,940,950,1100,1500,1800};
    //int dep[6] = {910,1200,1120,1130,1900,2000};
    int flights = 3;

    cout<<sln.miniGates(arr,dep,flights)<<endl;

    char a = sln.pairchar("abcba");
    string b(1,a);

    cout<<b<<endl;




    return 1;
}



