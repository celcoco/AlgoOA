//
// Created by Allen Chen on 8/29/16.
//

//
// Created by Allen Chen on 8/29/16.
//

//
// Created by Allen Chen on 8/3/16.
//

#include "TestPlat.h"

class LargestProduct : public SlnBase {
    vector<int> inarr;
    long long maxprod;
    void PrintDesc() {
        cout << "Calculate the largest product of two numbers (small number comes first)" << endl;
    }

    void InputLocal() {
        int a[] = {6,4,5,3};
        inarr.insert(inarr.begin(),a,a+ sizeof(a)/ sizeof(int));
    }

    void InputFromFile(ifstream &fh) {
        int tmp;
        while(fh >> tmp){
            inarr.push_back(tmp);
        }
    }

    void PrintInput() {
        PrintAll(inarr);
    }

    void PrintResult() {
        cout << maxprod << endl;
    }

    void Algo(){
        maxprod = test(inarr);
    }

    long long test(vector<int> inarr) {
        int arrsize = (int)inarr.size();
        if(arrsize < 2)
            return false;
        long long ret = LLONG_MIN;
        int suf[arrsize-1];
        suf[arrsize-2] = inarr[arrsize-1];
        for(int i = arrsize-3;i >= 0; i--){
            if(inarr[i+1] > suf[i+1]){
                suf[i] = inarr[i+1];
            }else{
                suf[i] = suf[i+1];
            }
        }
        for(int i = 0;i < sizeof(suf)/ sizeof(int);i ++){
            if(inarr[i] < suf[i]){
                long long tmp = inarr[i]*suf[i];
                if(tmp > ret){
                    ret = tmp;
                }
            }
        }
        return ret;
    };
};
const bool reg1 = TestPlat::reg<LargestProduct>("LargestProduct : of two number");