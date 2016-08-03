#include "TestPlat.h"

//
// Created by Allen Chen on 8/3/16.
//
// Leetcode 20: check if is valid parenthese
class isValid : public SlnBase{
    string s;
    bool result;
    void InputLocal(){
        s  = "[{([])}]";
    };
    void InputFromFile(ifstream& fh){
        getline(fh,s);
    }
    void PrintInput(){
        cout << s << endl;
    }
    void PrintResult(){
        cout << boolalpha << result << endl;
    }
    void Algo(){
        result = test(s);
    }
    bool test(string &s) {
        int n = s.length();
        if (n < 2 || (n % 2) == 1) {
            return false;
        }
        int i = 0;
        vector<char> cnt;
        int cnt_id = 0;
        char cur;
        for (i = 0; i < n; i++) {
            if (s[i] == '[' || s[i] == '{' || s[i] == '(') {
                cnt.push_back(s[i]);
            } else {
                if (cnt.empty() == true) {
                    return false;
                }
                cur = cnt.back();
                cnt.pop_back();
                if (cur == '[') {
                    if (s[i] == ']') {
                        continue;
                    }
                }
                if (cur == '{') {
                    if (s[i] == '}') {
                        continue;
                    }
                }
                if (cur == '(') {
                    if (s[i] == ')') {
                        continue;
                    }
                }
                return false;
            }
        }
        if (cnt.empty()) {
            return true;
        } else {
            return false;
        }
    };
};
const bool reg1 = TestPlat::reg<isValid>("Leetcode 20: valid parenthese");
