//
// Created by Allen Chen on 8/3/16.
//

#ifndef ALGOOA_SLNBASE_H_H
#define ALGOOA_SLNBASE_H_H

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include "PrintAll.h"

using namespace std;
class SlnBase{
public:
    SlnBase(){
        std::cout<<"Base construct"<<std::endl;
    };
    virtual ~SlnBase(){
        cout<<"Base destruct"<<endl;
    };

    virtual void InputFromFile(ifstream &fh){};
    virtual void InputLocal(){};
    virtual void CreateTestCase(){
        while(1){
            cout << "Please enter TestCase Filename or use default local testcase : " << endl;
            string str1;
            getline(cin,str1);
            if(str1 == ""){
                InputLocal();
                break;
            }else{
                str1 = "/Users/Allen/Dropbox/AlgoOA/" + str1;
                cout << str1;

                ifstream fh(str1);
                if( !fh.is_open() ){
                    cout << "File:\"" << str1 << "\" can't be opened, please try again!" << endl;
                    continue;
                }else{
                    cout << " Open succesfully!" << endl;
                }
                InputFromFile(fh);
                fh.close();
                break;
            }
        }
    }
    virtual void run(){
        PrintDesc();
        CreateTestCase();
        cout << "Input: " << endl;
        PrintInput();
        Algo();
        cout << "Result: " << endl;
        PrintResult();
    };
    virtual void PrintDesc(){};
    virtual void Algo(){};
    virtual void PrintInput(){};
    virtual void PrintResult(){};



};

#endif //ALGOOA_SLNBASE_H_H
