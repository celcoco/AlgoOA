//
// Created by Allen Chen on 8/29/16.
//

//
// Created by Allen Chen on 8/3/16.
//

#include "TestPlat.h"

class StringIntersection : public SlnBase {
    string str1 = "abbcdaf",str2 = "bcdxf",re;
    void PrintDesc() {
        cout << "find the intersection of two strings" << endl;
    }

    void InputLocal() {
    }

    void InputFromFile(ifstream &fh) {
        fh >> str1;
        fh >> str2;
    }

    void PrintInput() {
        cout << str1 << " " << str2 << endl;
    }

    void PrintResult() {
        cout << re << endl;
    }

    void Algo(){
        re = test(str1,str2);
    }

    string test(string str1,string str2) {
        //see if d is the multiple of other three numbers
        int T[str1.size()][str2.size()];
        int maxlen = 0;
        string ret;
        for(int i = 0;i < str1.size(); i++){
            for(int j = 0;j < str2.size(); j++){
                if(str1[i] == str2[j]){
                    if(i == 0 || j == 0){
                        T[i][j] = 1;
                    }else{
                        T[i][j] = T[i-1][j-1] + 1;
                    }
                    if( T[i][j] > maxlen){
                        maxlen = T[i][j];
                        ret = str1.substr(i-maxlen+1,maxlen);
                    }else{
                        if (T[i][j] == maxlen){
                            //cout << ret << " ";
                            ret = str1.substr(i-maxlen+1,maxlen);
                            //cout << ret << endl;
                        }
                    }
                }else{
                    T[i][j] = 0;
                }
            }
        }
        //cout << maxsubstr << endl;
        return ret;
    };
};
const bool reg1 = TestPlat::reg<StringIntersection>("StringIntersection found the intersection of two string");