//
// Created by Allen Chen on 8/3/16.
//

#include "TestPlat.h"

class AkunaT1 : public SlnBase {
    int num;
    bool re;

    void PrintDesc() {
        cout << "See if the num could be multiple of 3 numbers" << endl;
    }

    void InputLocal() {
        num = 15;
    }

    void InputFromFile(ifstream &fh) {
        fh >> num;
    }

    void PrintInput() {
        cout << num << endl;
    }

    void PrintResult() {
        cout << re << endl;
    }

    void Algo(){
        re = test(num);
    }

    bool test(int d) {
        //see if d is the multiple of other three numbers
        int i = 0;
        if (d < 8) {
            //2*2*2 = 8
            return false;
        }
        int PrimeNums = 0;
        i = 2;
        while (i <= d) {
            int reminder = d % i;
            if (reminder == 0) {
                PrimeNums++;
                if (PrimeNums >= 3) {
                    //already have three prime numbers
                    return true;
                } else {
                    d = d / i;
                }
                i = 1;
            }
            i++;
        }
        return false;
    };
};
const bool reg1 = TestPlat::reg<AkunaT1>("AkunaT1 if a num could be divided by 3 nums");