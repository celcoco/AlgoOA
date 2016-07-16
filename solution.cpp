//
// Created by Allen Chen on 7/14/16.
//
#include "solution.h"
char Solution::pairchar(string s) {
    int n = s.size();
    int i = 0;
    int asciitable[128];
    for(i=0;i<128;i++){
        asciitable[i] = 0;
    }
    for(i=0;i<n;i++){
        int id = s[i];
        asciitable[id]++;
    }
    for(i=0;i<128;i++){
        if(asciitable[i]>=2){
            return (char)i;
        }
    }
    return NULL;
}
int Solution::miniGates(int *arr, int *dep, int flights) {
    int i = 0;
    int j = 0;
    int NumOfGates = 0;
    vector<int> deplist;
    if(flights <=1 ){
        return flights;
    }
    deplist.push_back(dep[0]);
    bool FindGate = false;
    for(i=1;i<flights;i++){
        FindGate = false;
        for(j=0;j<deplist.size();j++){
            if(arr[i]>deplist[j]){//have available gates
                deplist[j] = dep[i];//use the available gate and update the dep
                FindGate = true;
                break;
            }
        }
        if(!FindGate){
            deplist.push_back(dep[i]);
        }
    }
    NumOfGates = deplist.size();
    return NumOfGates;

}
int Solution::MatchingPair(string s){
    int n = s.length();
    if(n<2 || (n%2) ==1 ){
        return -1;
    }
    int i = 0;
    vector<char> cnt;
    int cnt_id = 0;
    char cur;
    int id = 0;
    for(i=0;i<n;i++) {
        if(s[i]>='A' && s[i]<= 'Z'){
            cnt.push_back(s[i]);
        }else {
            if (cnt.empty() == true) {
                return false;
            }
            cur = cnt.back();
            cnt.pop_back();
            if((int)(cur-'A') == (int)(s[i]-'a')){
                if(id == 0){
                    id = i;
                }
                continue;
            }
            return -1;
        }
    }
    if(cnt.empty()){
        return id;
    }else{
        return -1;
    }
}
bool Solution::isValid2(string s) {
    int n = s.length();
    if(n<2 || (n%2) ==1 ){
        return false;
    }
    int i = 0;
    vector<char> cnt;
    int cnt_id = 0;
    char cur;
    for(i=0;i<n;i++) {
        if(s[i]>='A' && s[i]<= 'Z'){
            cnt.push_back(s[i]);
        }else {
            if (cnt.empty() == true) {
                return false;
            }
            cur = cnt.back();
            cnt.pop_back();
            if((int)(cur-'A') == (int)(s[i]-'a')){
                continue;
            }
            return false;
        }
    }
    if(cnt.empty()){
        return true;
    }else{
        return false;
    }
}
bool Solution::isValid(string s) {
    int n = s.length();
    if(n<2 || (n%2) ==1 ){
        return false;
    }
    int i = 0;
    vector<char> cnt;
    int cnt_id = 0;
    char cur;
    for(i=0;i<n;i++) {
        if(s[i]=='[' || s[i]=='{' || s[i]=='('){
            cnt.push_back(s[i]);
        }else {
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
    if(cnt.empty()){
        return true;
    }else{
        return false;
    }
}
int Solution::majorityElement(vector<int>& nums) {
    int len = nums.size();
    std::map<int,int>cnt;
    int i = 0;
    int maxnum = 0;
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
void Solution::moveZeroes(vector<int>& nums) {
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
void Solution::test(int i) { std::cout<<i<<std::endl;}
