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

class MarketEquilibrium : public SlnBase {
    vector<vector<double>> TransferMat;
    vector<double> init_share;
    vector<double> eq_share;
    void PrintDesc() {
        cout << "get the stable market share " << endl;
    }

    void InputLocal() {
        double a[] = {0.4, 0.6};
        double t[2][2] = { {0.8,0.2}, {0.1,0.9} };
        int n = 2;
        init_share.insert(init_share.begin(),a,a+ sizeof(a)/ sizeof(double));
        for(int i = 0;i < n; i++){
            vector<double> tmp;
            for(int j = 0;j < n; j++){
                tmp.push_back(t[i][j]);
            }
            TransferMat.push_back(tmp);
        }
    }

    void InputFromFile(ifstream &fh) {
        int n;
        fh >> n;
        for(int i = 0;i < n; i ++){
            int tmp;
            fh >> tmp;
            init_share.push_back(tmp);
        }
        for(int i = 0;i < n; i++){
            vector<double> tmpv;
            for(int j = 0; j < n; j++){
                int tmp;
                fh >> tmp;
                tmpv.push_back(tmp);
            }
            TransferMat.push_back(tmpv);
        }
    }

    void PrintInput() {
        PrintAll(init_share);
        PrintAll(TransferMat);

    }

    void PrintResult() {
        PrintAll(eq_share);
    }

    void Algo(){
        eq_share = test(init_share,TransferMat);
    }

    vector<double> test(vector<double> init,vector<vector<double>> mat) {
        vector<double> preshare = init, curshare = init;
        int n = (int) init.size();
        int i = 0, j = 0;
        bool isStable = false;
        double dif;
        //cout << n << endl;
        while(!isStable){
            dif = 0;
            for(i = 0; i < n; i ++){
                double cur = 0;
                for(j = 0; j < n; j ++){
                    double tmp = preshare[j];
                    double TransProb = mat[j][i];
                    cur += tmp*TransProb;
                }
                cur = floor(cur*1000)/1000;
                curshare[i] = cur;
                dif += abs(cur-preshare[i]);
            }
            preshare = curshare;
            //PrintAll(curshare);
            if(dif == 0){
                isStable = true;
            }
        }
        return curshare;
    };
};
const bool reg1 = TestPlat::reg<MarketEquilibrium>("MarketEquilibrium ");