//
// Created by Allen Chen on 8/3/16.
//

#include "TestPlat.h"
class MajorityElement:public SlnBase{
public:
    vector<int> nums;
    int maxnum = 0;
    virtual void PrintDesc(){
        cout << "Calculation the max num of majority number in vector" << endl;
        cout << "assume majority Element always exist in non-empty array" << endl;
    }
    virtual void InputLocal(){
        int inarr[3] = {1,2,2};
        for(int i = 0; i < 3; i++){
            nums.push_back(inarr[i]);
        }
    }
    virtual void InputFromFile(fstream& fh){};
    virtual void PrintInput(){
        PrintAll(nums);
    }
    virtual void PrintResult(){
        cout << maxnum << endl;
    }
    virtual void Algo(){
        maxnum = test(nums);
    }
    int test(vector<int>& nums){
        int len = nums.size();
        std::map<int,int>cnt;
        int i = 0;
        int freq = len/2;
        if(len<3){
            return nums[0];
        }
        for(i=0;i<len;i++){
            if(cnt.find(nums[i]) != cnt.end()){
                cnt[nums[i]]++;
                int n = cnt[nums[i]];
                if(n > freq){
                    maxnum = nums[i];
                    break;
                }
            }else{
                cnt[nums[i]] = 1;
            }
        }
        return maxnum;
    }
};
const bool reg1 = TestPlat::reg<MajorityElement>("MajorityElement");