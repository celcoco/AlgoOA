//
// Created by Allen Chen on 8/29/16.
//

#include "TestPlat.h"

class FindMedian : public SlnBase {
    vector<int> in;
    double median;
    int k;
    void PrintDesc() {
        cout << "Find median of subarray of sorted array including elements <=k" << endl;
    }

    void InputLocal() {
        int a[] = {2,3,4,6,7};
        k = 6;
        in.insert(in.begin(),a,a+sizeof(a)/sizeof(int));
    }

    void InputFromFile(ifstream &fh) {
        fh >> k;
        int tmp;
        while(fh >> tmp){
            in.push_back(tmp);
        }
    }

    void PrintInput() {
        PrintAll(in);
    }

    void PrintResult() {
        cout << median << endl;
    }

    void Algo(){
        median = test(in,k);
    }

    double test(vector<int> in, int k) {
        unsigned long arrsize = in.size();
        if(arrsize <= 1)
            return k;
        int subarrsize = 0;
        for(int i = 0;i < arrsize; i ++){
            if(in[i] <= k){
                subarrsize++;
            } else break;
        }
        if(subarrsize%2 == 1){
            return in[subarrsize/2-1];
        }else{
            return (in[subarrsize/2]+in[subarrsize/2-1])/2.0;
        }
    };
};
const bool reg1 = TestPlat::reg<FindMedian>("FindMedian: subarray <= k");