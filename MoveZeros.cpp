//
// Created by Allen Chen on 8/3/16.
//


#include "TestPlat.h"
class MoveZeros: public SlnBase{
public:
    vector<int> nums;
    virtual void PrintInput(){
        PrintAll(nums);
    }
    virtual void PrintResult(){
        PrintAll(nums);
    }
    virtual void InputLocal(){
        vector<int> tmp = {1,0,2,0,3,5};
        nums = tmp;
    }
    void Algo()
    {
        test(nums);
    }
    void test(vector<int>& nums) {
        int len = nums.size();
        int i = 0; // global iterator
        int j = -1;// iterator of zeros
        int k = -1; // iterator of non-zeros
        for(i = 0;i < len; i ++){
            if (nums[i] == 0){
                if(j == -1)
                    j = i;
            }else{
                if(j != -1){
                    k = i;
                    nums[j] = nums[k];
                    nums[k] = 0;
                    //cout<< "j=" << j << ",k=" << k <<endl;
                    j++;
                }

            }
        }
    }
};
const bool reg1 = TestPlat::reg<MoveZeros>("Leetcode 283: Moving zeros");