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

    //20 transformed fidessa OA 7 FT
    bool isValid2(string s);
    int MatchingPair(string s);

    // meeting room II transformed for flights
    int miniGates(int arr[],int dep[],int flights);

    // fidessa find pair char
    char pairchar(string s);
};


#endif //ALGORITHMC_SOLUTION_H
