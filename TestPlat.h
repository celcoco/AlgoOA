//
// Created by Allen Chen on 8/3/16.
//

#ifndef ALGOOA_TESTPLAT_H
#define ALGOOA_TESTPLAT_H

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "SlnBase.h"
#include "PrintAll.h"
// class SlnBase used to apply the test
using namespace std;

typedef std::map<std::string, SlnBase*(*)()> SlnListType;
typedef SlnListType::iterator SlnListItType;
typedef SlnListType::value_type SlnListValueType;
class TestPlat{
public:
    TestPlat(){};
    virtual ~ TestPlat(){};

    // start algorithm test
    void Start(SlnBase* pSB);

    // store the registered class and create function
    // string and function pointer(which returns SlnBase *)
    // use the function pointer to dynamically create the derivec class objects
    // static, because it is shared everywhere.
    static SlnListType SlnList;

    void SelectMenu();

    // register the derived class
    template <typename T> static bool reg(std::string str){
        TestPlat::SlnList[str] = &TestPlat::CreateObj<T>;
        return true;
    };
    // create the object of derived class
    template <typename T> static SlnBase* CreateObj(){
        return new T();
    };

    // for static test
    static int t;
    static void sett(int i){
        TestPlat::t = i;
    }

};


#endif //ALGOOA_TESTPLAT_H
