//
// Created by Allen Chen on 8/3/16.
//

#include "TestPlat.h"
#include <cmath>
class AkunaT2 : public SlnBase {

    vector<float> nums;
    int len;
    float re;

    void PrintDesc() {
        cout << "Calculate the standard deviation" << endl;
    }

    void InputLocal() {
        vector<float> tmp = {2.1, 2.0, 2.1};
        nums = tmp;
    }

    void InputFromFile(ifstream &fh) {
        int tmp;
        while(fh >> tmp){
            nums.push_back(tmp);
        };
        len = nums.size();
    }

    void PrintInput() {
        PrintAll(nums);
    }

    void PrintResult() {
        cout << re << endl;
    }

    void Algo(){
        re = test(&nums[0],len);
    }

    float test(float *data, int n) {
        int i = 0;
        if(n<2){
            return data[0];
        }
        double sum = 0;
        float avg = 0;
        for(i=0;i<n;i++){
            sum += data[i];
        }
        avg = sum/n;
        double sqrtsum = 0;
        for(i=0;i<n;i++){
            float dif = data[i] - avg;
            sqrtsum += (dif*dif);
        }
        float StdDev = sqrt(sqrtsum/(n-1));
        return StdDev;
    }
};
const bool reg1 = TestPlat::reg<AkunaT2>("AkunaT2 standard deviation");