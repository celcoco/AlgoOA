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
// Created by Allen Chen on 8/29/16.
//

//
// Created by Allen Chen on 8/3/16.
//

#include "TestPlat.h"

class RemoveDuplicate : public SlnBase {
    vector<int> vector1;
    vector<int> re;
    void PrintDesc() {
        cout << "remove the duplicate" << endl;
    }

    void InputLocal() {
        int a[] = {7,3,4,5,6,5};
        vector1.insert(vector1.begin(),a,a+sizeof(a)/sizeof(int));

    }

    void InputFromFile(ifstream &fh) {
        int tmp;
        while (fh >> tmp){
            vector1.push_back(tmp);
        }
    }

    void PrintInput() {
        PrintAll(vector1);
    }

    void PrintResult() {
        //cout << re << endl;
        PrintAll(re);
    }

    void Algo(){
        re = test(vector1);
    }

    vector<int> test(vector<int> v) {
        vector<int> tmp;
        if(v.size() < 2)
            return v;
        set<int> set1;
        for(int i = 0; i < v.size(); i ++){
            set1.insert(v[i]);
        }
        set<int>::reverse_iterator it;
        for(it = set1.rbegin(); it != set1.rend(); it ++){
            tmp.push_back(*it);
        }
        return tmp;
    };
};
const bool reg1 = TestPlat::reg<RemoveDuplicate>("RemoveDuplicate");