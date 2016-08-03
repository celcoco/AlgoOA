//
// Created by Allen Chen on 8/3/16.
//

//
// Created by Allen Chen on 8/3/16.
//
#include "TestPlat.h"

class PairChar : public SlnBase{
public:
    string str1;
    char c;
    int NumOfGates;
    void PrintDesc(){
        cout << "Find 1st shown char that has a matching char" << endl;
    }
    void InputLocal(){
        str1 = "dabcba";
    };
    void InputFromFile(ifstream &fh){
        getline(fh,str1);

    }
    void PrintInput(){
        cout << str1 << endl;
    }
    void Algo(){
        c = test(str1);
    }
    void PrintResult(){
        cout << c << endl;
    }
    char test(string s) {

        int n = s.size();
        int i = 0;
        int asciitable[128];
        for(i=0;i<128;i++){
            asciitable[i] = 0;
        }
        for(i=0;i<n;i++){
            int id = s[i];
            asciitable[id]++;
        }
        for(i=0;i<128;i++){
            if(asciitable[i]>=2){
                return (char)i;
            }
        }
        return '\0';
    };
};
const bool reg1 = TestPlat::reg<PairChar>("1st shown PairChar");