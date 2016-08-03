//
// Created by Allen Chen on 8/3/16.
//

#include "TestPlat.h"

class MatchingPair : public SlnBase{
public:
    string s;
    int index = -1;
    void PrintDesc(){
        cout << "Find the index of last matching pair, -1 if no pairs match" << endl;
    }
    void InputLocal(){
        s = "ABBbba";
    }
    void InputFromFile(ifstream &fh){
        getline(fh,s);
    }
    void PrintInput(){
        cout << s << endl;
    }
    void PrintResult(){
        cout << "s[" << index << "]: " << s[index] << endl;
    }
    void Algo(){
        index = test(s);
    }
    int test(string & s){
        int n = s.length();
        if(n<2){
            return -1;
        }
        int i = 0;
        vector<char> cnt;
        int cnt_id = 0;
        char cur;
        int id = 0;
        for(i=0;i<n;i++) {
            // start with capital or followed by captial
            if(s[i]>='A' && s[i]<= 'Z'){
                cnt.push_back(s[i]);
            }else {
                // if upcase followed by lowercase, must match or return -1
                if (cnt.empty() == true) {
                    return -1;
                }
                cur = cnt.back();
                cnt.pop_back();
                //have no match pair right. must have one!
                if((int)(cur-'A') == (int)(s[i]-'a')){
                    id = i;
                    continue;
                }else {
                    // if the first letter comes not pair, return -1
                    if (id == 0) {
                        return -1;
                    }
                }
            }
        }
        return id;
    }
};
const bool reg1 = TestPlat::reg<MatchingPair>("MatchingPair(transformed LC20 valid parenthese)");