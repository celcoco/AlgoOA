//
// Created by Allen Chen on 8/29/16.
//

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

class CountBits : public SlnBase {
    int int1;
    int re;
    void PrintDesc() {
        cout << "1's in the binary format of the number" << endl;
    }

    void InputLocal() {
        int1 = 11;
    }

    void InputFromFile(ifstream &fh) {
        fh >> int1;
    }

    void PrintInput() {
        cout << int1 << endl;
    }

    void PrintResult() {
        cout << re << endl;
    }

    void Algo(){
        re = test(int1);
    }

    int test(int in1) {
        int ret = 0;
        unsigned int tmp = (unsigned int)in1;
        while(tmp != 0){
            if(tmp%2 == 1){
                ret ++;
            }
            tmp = tmp/2;
        }
        return ret;
    };
};
const bool reg1 = TestPlat::reg<CountBits>("CountBits : 1's in the binary format of the number");