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
// Created by Allen Chen on 8/29/16.
//

//
// Created by Allen Chen on 8/3/16.
//

#include "TestPlat.h"

class TwoSum : public SlnBase {
    vector<int> vector1;
    vector<int> re;
    long long target = 8;
    void PrintDesc() {
        cout << "find two numbers whose sum equals to target" << endl;
    }

    void InputLocal() {
        int a[] = {3,4,5,6};

        vector1.insert(vector1.begin(),a,a+sizeof(a)/sizeof(int));

    }

    void InputFromFile(ifstream &fh) {
        fh >> target;
        int tmp;
        while (fh >> tmp){
            vector1.push_back(tmp);
        }
    }

    void PrintInput() {
        cout << target << endl;
        PrintAll(vector1);
    }

    void PrintResult() {
        //cout << re << endl;
        PrintAll(re);
    }

    void Algo(){
        re = test(vector1,target);
    }

    vector<int> test(vector<int> v, long long target) {
        vector<int> tmp;
        if(v.size() < 2)
            return tmp;
        map<int,int> map1;
        for(int i = 0;i < v.size(); i ++){
            if(map1.find((int)target-v[i]) != map1.end()){
                tmp.push_back(map1[target-v[i]]);
                tmp.push_back(i);
                return tmp;
            }
            map1[v[i]] = i;
        }
        tmp.push_back(-1);
        tmp.push_back(-1);
        return tmp;
    };
};
const bool reg1 = TestPlat::reg<TwoSum>("TwoSum : two numbers sum equal to target");