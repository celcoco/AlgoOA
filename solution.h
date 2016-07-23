//
// Created by Allen Chen on 6/21/16.
//

// Solution Class.

#ifndef ALGORITHMC_SOLUTION_H
#define ALGORITHMC_SOLUTION_H

#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <math.h>
#include <sstream>
using namespace std;
class Solution{
public:
    // test method
    void test(int i);

    //169. Majority Element
    int majorityElement(vector<int>& nums);

    //283. Move Zeros
    void moveZeroes(vector<int>& nums);

    //20. Valid Parentheses
    bool isValid(string s);

    //20. transformed fidessa OA 7 FT
    bool isValid2(string s);
    int MatchingPair(string s);

    // meeting room II transformed for flights
    int miniGates(int arr[],int dep[],int flights);

    // Fidessa find pair char
    char pairchar(string s);

    // Akuna Quant Dev OA
    bool Akuna_t1(int d);

    float Akuna_t2(float data[],int n);

    int** Akuna_t3(int** mat,int n,int m);
    vector<vector<int>> Akuna_t3_2(vector<vector<int>> mat,int n,int m);

    int Akuna_t4(string str);

    float Akuna_t5(int n);

    string Akuna_t6(string str);

    int PilNum(int year);
    void UniWordCnt(void);
    void LowestDist(void);

};


#endif //ALGORITHMC_SOLUTION_H
