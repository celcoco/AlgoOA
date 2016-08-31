//
// Created by Allen Chen on 8/29/16.
//

//
// Created by Allen Chen on 8/3/16.
//

#include "TestPlat.h"

class StringIntersection2 : public SlnBase {
    string str1 = "zzfffaabbcedf",str2 = "zaebdjf",re;
    void PrintDesc() {
        cout << "find intersection(common characters) of two strings in alphabeta order" << endl;
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
        string ret;
        int list1[52], list2[52];
        for(int i = 0;i < 52; i++){
            list1[i] = 0;
            list2[i] = 0;
        }
        for(int i = 0;i < str1.size(); i ++){
            if(str1[i] >= 'a' && str1[i] <= 'z'){
                list1[(str1[i]-'a')]++;
            }
            if(str1[i] >= 'A' && str1[i] <= 'Z'){
                list1[str1[i]-'A'+26]++;
            }
        }
        for(int i = 0;i < str2.size(); i ++){
            if(str2[i] >= 'a' && str2[i] <= 'z'){
                list2[str2[i]-'a']++;
            }
            if(str2[i] >= 'A' && str2[i] <= 'Z'){
                list2[str2[i]-'A'+26]++;
            }
        }
        for(int i = 0;i < 52; i ++){
            if(list1[i] > 0 && list2[i] > 0){
                char c;
                if(i < 26){
                    c = (char)(i + 'a');
                }else{
                    c = (char)(i + 'A');
                }
                //cout << c << endl;
                ret += c;
            }
        }
        return ret;
    };
};
const bool reg1 = TestPlat::reg<StringIntersection2>("StringIntersection2 found the common characters of two string");
