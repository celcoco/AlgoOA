//
// Created by Allen Chen on 8/3/16.
//

#ifndef ALGOOA_PRINTALL_H
#define ALGOOA_PRINTALL_H
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>

// print 1D arrary
void PrintAll(int a [], int n);
void PrintAll(float a [], int n);
// print 2D array
void PrintAll(int** a,int n,int m);
void PrintAll(float** a,int n,int m);
// print vector
void PrintAll(std::vector<int> a);
void PrintAll(std::vector<float> a);
void PrintAll(std::vector<std::string> a);
void PrintAll(std::map<std::string,int> m1);
// Template for array
template <typename T> void PrintAllT(T a [], int n);
// Template for array
template <typename T> void PrintAllT(T a [], int n, int m);
// Template for vector
template <typename T> void PrintAllT(std::vector<T> a);
// template for 2D vector
template <typename T> void PrintAllT(std::vector< std::vector <T> > a);
#endif //ALGOOA_PRINTALL_H
