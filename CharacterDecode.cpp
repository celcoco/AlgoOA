//
// Created by Allen Chen on 8/29/16.
//

#include "TestPlat.h"

class CharacterDecode : public SlnBase {
    string input,key;
    string re;
    void PrintDesc() {
        cout << "CharacterDecode" << endl;
    }

    void InputLocal() {
        input = "amhbcdeplklsczo";
        key = "00001002336469700000000369";
        cout << key.size() <<endl;

    }

    void InputFromFile(ifstream &fh) {
        fh >> input >> key;
    }

    void PrintInput() {
        cout << input << endl << key << endl;
    }

    void PrintResult() {
        cout << re << endl;
    }

    void Algo(){
        re = test(input,key);
    }

    string test(string in, string k) {
        string tmp;
        if(k.size() == 26){
            for(int i = 0; i < in.size(); i++){
                char c = in[i];
                int cid = c-'a';
                int value = k[cid] - '0';
                if(value%3 != 0){
                    tmp += c;
                }
            }
        }
        return tmp;
    };
};
const bool reg1 = TestPlat::reg<CharacterDecode>("CharacterDecode: ");