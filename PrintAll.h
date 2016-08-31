//
// Created by Allen Chen on 8/3/16.
//

#ifndef ALGOOA_PRINTALL_H
#define ALGOOA_PRINTALL_H
#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
#include <set>
#include <list>
#include <queue>
#include <deque>
#include <string>

// Template for 1D array
template <typename T> void PrintAllT(T a [], int n);

// Template for 2D array
template <typename T> void PrintAllT(T** a, int n, int m);

// Template for vector
template <typename T> void PrintAllT(std::vector<T> a);

// Template for 2D vector
template <typename T> void PrintAllT(std::vector< std::vector <T> > a);

// Template for map
template <typename T1, typename T2> void PrintAllT(std::map<T1,T2> a);
// Template for set
template <typename T> void PrintAllT(std::set<T> a);
// Template for list
template <typename T> void PrintAllT(std::list<T> a);
// Template for deque
template <typename T> void PrintAllT(std::deque<T> a);

// print 1D array
void PrintAll(int a [], int n);
void PrintAll(float a [], int n);
void PrintAll(double a [],int n);
void PrintAll(std::string a [], int n);

// print 2D array
void PrintAll(int** a,int n,int m);
void PrintAll(float** a,int n,int m);
void PrintAll(double** a,int n,int m);
void PrintAll(std::string** a,int n, int m);

// print 1D vector
void PrintAll(std::vector<int> a);
void PrintAll(std::vector<float> a);
void PrintAll(std::vector<double> a);
void PrintAll(std::vector<std::string> a);

// print 2D vector
void PrintAll(std::vector<std::vector<int>> a);
void PrintAll(std::vector<std::vector<float>> a);
void PrintAll(std::vector<std::vector<double>> a);
void PrintAll(std::vector<std::vector<std::string>> a);

// map
void PrintAll(std::map<char,int> m1);
void PrintAll(std::map<std::string,int> m1);


// set
void PrintAll(std::set<int> set1);
void PrintAll(std::set<float> set1);
void PrintAll(std::set<double> set1);
void PrintAll(std::set<std::string> set1);

// list
void PrintAll(std::list<int> list1);

#endif //ALGOOA_PRINTALL_H
