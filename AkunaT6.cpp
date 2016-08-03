//
// Created by Allen Chen on 8/3/16.
//

//
// Created by Allen Chen on 8/3/16.
//

#include "TestPlat.h"
class AkunaT6 : public SlnBase{
    string str1;
    string strout;
    void PrintDesc() {
        cout << "Change experssion from postfix to infix" << endl;
    }

    void InputLocal() {
        str1 = "23+21-/341-*+a+bc+/";
    }

    void InputFromFile(ifstream &fh) {
        getline(fh,str1);
    }

    void PrintInput() {
        cout << str1 << endl;
    }

    void PrintResult() {
        cout << strout << endl;
    }

    void Algo(){
        strout = test(str1);
    }

    string test(string str) {
        int PriorLevel = 0;
        int i = 0;
        int n = str.length();
        if(n<3){
            return str;
        }
        string NewExpr;
        vector<string> lists;
        int PrePriorLevel = 0;
        int PrePrePriorLevel = 0;
        for(i=0;i<n;i++){
            char tmp = str[i];
            bool isOp = true;
            switch(tmp){
                case('-'):
                    PriorLevel = 1;
                    break;
                case('+'):
                    PriorLevel = 1;
                    break;
                case('*'):
                    PriorLevel = 2;
                    break;
                case('/'):
                    PriorLevel = 2;
                    break;
                default:
                    isOp = false;
                    break;
            }
            if(isOp == false){
                string newvar = string(1,tmp);
                lists.push_back(newvar);
            }else{
                if(lists.size()<2){
                    cout<<"Err:Vector size:"<<lists.size()<<endl;
                    return NULL;
                }
                string prestr = lists.back();
                lists.pop_back();
                string preprestr = lists.back();
                lists.pop_back();
                if(PriorLevel>PrePriorLevel && PrePriorLevel!=0){
                    prestr = '('+prestr+')';
                }
                if(PriorLevel>PrePrePriorLevel && PrePrePriorLevel!=0){
                    preprestr = '('+preprestr+')';
                }

                string form1 = preprestr+tmp+prestr;
                lists.push_back(form1);
            }
            PrePrePriorLevel = PrePriorLevel;
            PrePriorLevel = PriorLevel;
        }
        if(lists.size()>1 || lists.empty()){
            cout<<"Err: final Vector size:"<<lists.size()<<endl;
            return NULL;
        }
        NewExpr = lists.back();
        lists.pop_back();
        return NewExpr;
    }
};
const bool reg1 = TestPlat::reg<AkunaT6>("AkunaT6 expression transformed forward to middle");