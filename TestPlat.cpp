//
// Created by Allen Chen on 8/3/16.
//

#include "TestPlat.h"
//#include "SlnBase.h"
//#include <sstream>

SlnListType TestPlat::SlnList = SlnListType();

//int TestPlat::t = 0;

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
    cout << "Please input the algorithm number (q to quit):" << endl;
}
void TestPlat::run() {
    SelectMenu();
    string str1;
    getline(cin,str1);
    while(str1 != "q"){
        int j = 0;
        stringstream sst(str1);
        sst >> j;
        if(!sst || !sst.eof()){
            cerr << "Not Number or there's space ! Try Again!" <<endl;
            getline(cin,str1);
            continue;
        }
        if(j >= TestPlat::SlnList.size() || j < 0){
            cerr << "Invalid number(should < " << TestPlat::SlnList.size() << ")! Try again!" << endl;
            getline(cin,str1);
            continue;
        }
        int i = 0;

        for(auto& it : TestPlat::SlnList){
            if(i == j){
                SlnBase* p = it.second();
                cout << "---------------------------" << endl;
                cout << it.first << endl;
                cout << "---------------------------" << endl;
                Start(p);
                delete p;
                cout << "------------DONE-----------" << endl;
                break;
            }
            i++;
        }
        cout << " 'r or enter'(re-run) 'm' (menu) 'q' (quit) or Alogorithm id!" << endl;
        string tmp;
        getline(cin,tmp);
        //cout << "your enter: " << tmp << endl;
        if(tmp == "" || tmp == "r") continue;
        if(tmp == "q") {
            cout<< "Quit the TestPlat" << endl;
            return;
        }
        if(tmp == "m"){
            SelectMenu();
            getline(cin,str1);
            continue;
        }
        str1 = tmp;
    }
}
// Start the test
void TestPlat::Start(SlnBase* p){
    p->run();
}


