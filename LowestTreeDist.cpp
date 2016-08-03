//
// Created by Allen Chen on 8/3/16.
//

//
// Created by Allen Chen on 8/3/16.
//

//
// Created by Allen Chen on 8/3/16.
//

#include "TestPlat.h"
#include "Tree.h"
class LowestTreeDist : public SlnBase{
    TreeNode* node = NULL;
    int lowestdist;
    virtual ~LowestTreeDist(){
        if(node != NULL){
            delete node;
            node = NULL;
        }
    }
    void PrintDesc() {
        cout << "Cal the lowest dist for a mountain-like tree" << endl;
    }

    void InputLocal() {
        vector<int> a = {1,2,3,4,5,6,7,8,9,10};
        for(int i = 0; i < a.size(); i++){

            cout << i << endl;
            TreeInsert(node,a[i]);
        }
        //TreeInsert(node,10);
    }

    void InputFromFile(ifstream &fh) {
        string str;
        getline(fh,str);
        while(str!=""){
            stringstream sstr(str);
            int tmp;
            while(sstr>>tmp){
                TreeInsert(node,tmp);

            }
            getline(fh,str);
        }
    }

    void PrintInput() {
        TreePrint(node);
    }

    void PrintResult() {
        cout << lowestdist << endl;
    }

    void Algo(){
        lowestdist = test(node);
    }

    int test(TreeNode* node1) {
        if(node1 == NULL){
            return 0;
        }else{
            int LeftDist = TreeMiniDist(node1->left);
            int RigtDist = TreeMiniDist(node1->right);
            int MiniDist = LeftDist;
            if(RigtDist < MiniDist){
                MiniDist = RigtDist;
            }
            return MiniDist+node1->val;
        }
    }
};
const bool reg1 = TestPlat::reg<LowestTreeDist>("LowestTreeDist a mountain-like test not binomial tree!");