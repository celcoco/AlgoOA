//
// Created by Allen Chen on 8/29/16.
//

#include "TestPlat.h"

class CheapestTransform : public SlnBase {
    char sc,ec;
    vector<vector<int>> mat;
    int re;
    void PrintDesc() {
        cout << "CheapestTransform" << endl;
    }

    void InputLocal() {
        sc = 'c';
        ec = 'b';
        int a[3][3] = { {0,3,2}, {5,0,2}, {1,6,0}};
        for(int i = 0; i < 3; i ++){
            vector<int> tmp;
            for(int j = 0; j < 3; j++){
                tmp.push_back(a[i][j]);
            }
            mat.push_back(tmp);
        }

    }

    void InputFromFile(ifstream &fh) {
        fh >> sc >> ec;
        int n;
        fh >> n;
        for(int i = 0; i < n; i ++){
            vector<int> tmp;
            for(int j = 0;j <3; j++){
                int t;
                fh >> t;
                tmp.push_back(t);
            }
            mat.push_back(tmp);
        }
    }

    void PrintInput() {
        cout << sc << " " << ec << endl;
        PrintAll(mat);
    }

    void PrintResult() {
        cout << re << endl;
    }

    void Algo(){
        re = test(sc,ec,mat);
    }

    int test(char s, char e, vector<vector<int>> m) {
        int si = s - 'a', ei = e - 'a';
        string debug;
        debug += s;
        debug += "->";
        string str1;
        int tmp = m[si][ei];
        // 2 transfer
        for(int i = 0; i  < m.size(); i++){
            if(i != ei){
                int tran2 = m[si][i] + m[i][ei];
                if(tran2 < tmp){
                    str1 = "";
                    tmp = tran2;
                    str1 += (char)(i+'a');
                    str1 += "->";
                }
                // 3 transfer
                for(int j = 0; j < m.size(); j++){
                    if(j != ei){
                        int tran3 = m[si][i] + m[i][j] + m[j][ei];
                        if(tran3 < tmp){
                            str1 = "";
                            tmp = tran3;
                            str1 += (char)(i+'a');
                            str1 += "->";
                            str1 += (char)(j+'a');
                            str1 += "->";

                        }
                    }
                }
            }
        }
        cout << debug << str1 << e << endl;


        return tmp;
    };
};
const bool reg1 = TestPlat::reg<CheapestTransform>("CheapestTransform: ");