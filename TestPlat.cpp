//
// Created by Allen Chen on 8/3/16.
//

#include "TestPlat.h"
#include "SlnBase.h"
#include <sstream>

SlnListType TestPlat::SlnList = SlnListType();

int TestPlat::t = 0;

// Algorithm Choose Menu
void TestPlat::SelectMenu(){
    cout<<"Test Platform Algorithm List:"<<endl;
    map<string,SlnBase*(*)()>::iterator it;
    vector<SlnListItType> AlgoLists;
    int i = 0;
    for(it = TestPlat::SlnList.begin(); it != TestPlat::SlnList.end(); it++){
        cout << i << " : " << it->first <<endl;
        AlgoLists.push_back(it);
        i++;
    }
    while(1){
        cout << "Please input the algorithm number:" << endl;
        int j = 0;
        string str1;
        getline(cin,str1);
        if(str1 == "")
            break;
        stringstream sst(str1);
        sst >> j;
        if(!sst || !sst.eof()){
            cout << "Not Number or there's space ! Try Again!" <<endl;
            continue;
        }
        //j = stoi(str1.c_str());
        if(j >= AlgoLists.size() || j < 0){
            cout << "Invalid number! Please enter again!" << endl;
            continue;
        }
        SlnBase* p = AlgoLists[j]->second();
        cout << "---------------------------" << endl;
        cout << AlgoLists[j]->first << endl;
        cout << "---------------------------" << endl;
        Start(p);
        delete p;
        cout << "------------DONE-----------" << endl;
        cout << "Enter to run a new test or 'q' to quit!" << endl;
        getline(cin,str1);
        if(str1 == "q")
            break;
        i = 0;
        for(it = TestPlat::SlnList.begin(); it != TestPlat::SlnList.end(); it++){
            cout << i << " : " << it->first << endl;
            i++;
        }
    }
}

// Start the test
void TestPlat::Start(SlnBase* p){
    p->run();
}


