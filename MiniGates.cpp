//
// Created by Allen Chen on 8/3/16.
//
#include "TestPlat.h"

class MiniGates : public SlnBase{
public:
    int NumOfFlights;
    vector<int> arr;
    vector<int> dep;
    int NumOfGates;
    void PrintDesc(){
        cout << "Input file format 3 lines arr dep and NumOfFlights" << endl;
        cout << "Find the min num of gates that needs" << endl;
    }
    void InputLocal(){
        vector<int> tmp1 = {900,930,950};
        vector<int> tmp2  = {930,940,1200};
        NumOfFlights = tmp1.size();;
        arr = tmp1;
        dep = tmp2;
    };
    void InputFromFile(ifstream &fh){
        string str1;
        getline(fh,str1);
        stringstream ss1(str1);
        int tmp = 0;
        while(ss1 >> tmp){
            arr.push_back(tmp);
        }
        str1 = "";
        tmp = 0;
        getline(fh,str1);
        stringstream ss2(str1);
        while(ss2 >> tmp){
            dep.push_back(tmp);
        }
        str1 = "";
        tmp = 0;
        getline(fh,str1);
        stringstream ss3(str1);
        ss3 >> NumOfFlights;

    }
    void PrintInput(){
        cout << "NumOfFlights" << NumOfFlights << endl;
        cout << "Arr:" << endl;
        PrintAll(arr);
        cout << "Dep:" << endl;
        PrintAll(dep);
    }
    void PrintResult(){
        cout << "Num of Gates: " << NumOfGates << endl;
    }
    void Algo(){
        if(NumOfFlights != arr.size() || NumOfFlights != dep.size()){
            cout << "ERROR: input file is incorrect! size not matches!" << endl;
            cout << "arr:" << endl;
            PrintAll(arr);
            cout << "dep:" << endl;
            PrintAll(dep);
            cout << "NumOfFlights : " << NumOfFlights << endl;
            cout << "SET ALL TO ERROR" << endl;
            vector<int> tmp;
            arr = tmp;
            dep = tmp;
            NumOfFlights = 0;
        }
        if(NumOfFlights <= 0){
            return;
        }
        NumOfGates = test(&arr[0],&dep[0],NumOfFlights);
    }
    int test(int *arr, int *dep, int flights) {
        int i = 0;
        int j = 0;
        int NumOfGates = 0;
        vector<int> deplist;
        if(flights <=1 ){
            return flights;
        }
        deplist.push_back(dep[0]);
        bool FindGate = false;
        for(i=1;i<flights;i++){
            FindGate = false;
            for(j=0;j<deplist.size();j++){
                if(arr[i]>deplist[j]){//have available gates
                    deplist[j] = dep[i];//use the available gate and update the dep
                    FindGate = true;
                    break;
                }
            }
            if(!FindGate){
                deplist.push_back(dep[i]);
            }
        }
        NumOfGates = deplist.size();
        return NumOfGates;
    };
};
const bool reg1 = TestPlat::reg<MiniGates>("MiniGates");