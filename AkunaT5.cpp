//
// Created by Allen Chen on 8/3/16.
//

#include "TestPlat.h"
class AkunaT5 : public SlnBase{
    int num;
    float expval;
    void PrintDesc() {
        cout << "Calculate the expected value of mutiple tosses" << endl;
    }

    void InputLocal() {
        num = 5;
    }

    void InputFromFile(ifstream &fh) {
        fh >> num;
    }

    void PrintInput() {
        cout << num << endl;
    }

    void PrintResult() {
        cout << expval << endl;
    }

    void Algo(){
        expval = test(num);
    }

    float test(int n) {
        const float InitExpValue= 3.5;
        int i = 0;
        float CurExpValue = 0;
        float NexExpValue = 0;
        float FinalExpValue = 0;
        if(n==1){
            return InitExpValue;
        }
        if(n<1){
            return 0.0;
        }

        CurExpValue = InitExpValue;
        for(i=1;i<n;i++){
            NexExpValue = CurExpValue;
            double tmp = 0;
            for(int j=1;j<7;j++){
                if(j > NexExpValue){
                    tmp += j;
                }else{
                    tmp += NexExpValue;
                }
            }
            CurExpValue = tmp/6;
        }
        FinalExpValue = CurExpValue;
        return FinalExpValue;
    }
};
const bool reg1 = TestPlat::reg<AkunaT5>("AkunaT5 expected value");