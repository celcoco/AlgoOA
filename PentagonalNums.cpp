//
// Created by Allen Chen on 8/29/16.
//

#include "TestPlat.h"

class PentagonalNums : public SlnBase {
    vector<int> re;
    void PrintDesc() {
        cout << "PentagonalNums" << endl;
    }

    void InputLocal() {

    }

    void InputFromFile(ifstream &fh) {
    }

    void PrintInput() {
    }

    void PrintResult() {
        //cout << re << endl;
        PrintAll(re);
    }

    void Algo(){
        re = test();
    }

    vector<int> test() {
        vector<int> tmp;
        int i = 1;
        bool FindTwo = false;
        while(!FindTwo){
            i++;
            int n = i*(3*i-1)/2;
            for(int j = i-1; j > 0; j--){
                int m = j*(3*j-1)/2;
                if(isPentagonal(n-m) && isPentagonal(n+m)){
                    tmp.push_back(j);
                    tmp.push_back(i);
                    FindTwo = true;
                    break;
                }
            }
        }
        return tmp;
    };
    bool isPentagonal(int n){
        double test = (sqrt(24*n+1)+1.0)/6.0;
        return test == (int)(test);

    }
};
const bool reg1 = TestPlat::reg<PentagonalNums>("PentagonalNums");