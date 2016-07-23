//
// Created by Allen Chen on 7/14/16.
//
#include "solution.h"
struct TreeNode{
    int val = 0;
    TreeNode* left;
    TreeNode* right;
    TreeNode* ParalRigt;
    TreeNode(int x) : val(x),left(NULL),right(NULL),ParalRigt(NULL){};
};
int TreeLen(TreeNode* node){
    if(node == NULL){
        return 0;
    }else{
        int LeftLen = TreeLen(node->left);
        int RigtLen = TreeLen(node->right);

        if(LeftLen > RigtLen){
            return LeftLen+1;
        }else{
            return RigtLen+1;
        }
    }
}
int TreeLenMini(TreeNode* node){
    if(node == NULL){
        return 0;
    }else{
        int LeftLen = TreeLenMini(node->left);
        int RigtLen = TreeLenMini(node->right);

        if(LeftLen > RigtLen){
            return RigtLen+1;
        }else{
            return LeftLen+1;
        }
    }
}
void TreeInsert(TreeNode*& node,int data){
    if(node == NULL){
        TreeNode* tmp = new TreeNode(data);
        node = tmp;
        return;
    }else{
        int LeftLen = TreeLenMini(node->left);
        int RigtLen = TreeLenMini(node->right);
        if(LeftLen > RigtLen+1 || LeftLen < RigtLen){
            cout<<"ERROR: LeftLen="<<LeftLen<<",RigtLen="<<RigtLen<<endl;
            return;
        }else{
            if(LeftLen == RigtLen){
                TreeInsert(node->left,data);
                if(node->right != NULL && node->left->right != NULL) {
                    node->right->left = node->left->right;
                }
            }else{
                TreeInsert(node->right,data);
                node->left->ParalRigt = node->right;
            }
        };
        return;
    }
}
void TreeDele(TreeNode*& node){
    if(node == NULL){
        return;
    }else{
        TreeDele(node->left);
        TreeDele(node->right);
        delete(node);
        if(node->left!=NULL){
            node->left = NULL;
        }
        if(node->right!=NULL){
            node->right = NULL;
        }
        if(node->ParalRigt!=NULL)
        {
            node->ParalRigt->left = NULL;
            node->ParalRigt = NULL;
        }
        node = NULL;
    }
}
void RecPrint(TreeNode* node){
    cout<<node->val<<"   ";
    if(node->ParalRigt != NULL){
        RecPrint(node->ParalRigt);
    }
}
void RecPrint2(TreeNode* node){
    if(node->left != NULL){
        cout<<"/ ";
    }else{
        cout<<"  ";
    }
    if(node->right != NULL){
        cout<<"\\ ";
    }else{
        cout<<"  ";
    }
    if(node->ParalRigt != NULL){
        RecPrint2(node->ParalRigt);
    }
}
void TreePrint(TreeNode* node){
    if(node != NULL){
        int MaxLen = TreeLen(node);
        int i = 0;
        while(i<2*(MaxLen-1)){
            cout<<" ";
            i++;
        }
        RecPrint(node);
        cout<<endl;
        i=0;
        while(i<2*(MaxLen-1)-1){
            cout<<" ";
            i++;
        }
        RecPrint2(node);
        cout<<endl;
        TreePrint(node->left);
    }
}
void Print (TreeNode * x, int & id)
{
    if (!x) return;

    Print (x->left,id);

    id++;
    cout << id << ' ' << x->val << endl;

    Print (x->right,id);
}

int TreeMiniDist(TreeNode* node){
    if(node == NULL){
        return 0;
    }else{
        int LeftDist = TreeMiniDist(node->left);
        int RigtDist = TreeMiniDist(node->right);
        int MiniDist = LeftDist;
        if(RigtDist < MiniDist){
            MiniDist = RigtDist;
        }
        return MiniDist+node->val;
    }
}
void Solution::LowestDist() {
    string str;
    int a;
    getline(cin,str);
    TreeNode* node = NULL;
    while(str!=""){
        stringstream sstr(str);
        int tmp;
        while(sstr>>tmp){
            //cout<<tmp<<endl;
            //cout<<"Before:"<<hex<<node<<endl;
            TreeInsert(node,tmp);
            //cout<<"After:"<<hex<<node<<endl;
        }
        getline(cin,str);
    }
    TreePrint(node);
    //int id = 0;
    //Print(node,id);
    int MiniDist = TreeMiniDist(node);
    cout<<"Result:"<<MiniDist<<endl;
    TreeDele(node);
}
void Solution::UniWordCnt() {
    string str;
    string word;
    char letter;
    map<string,int> wordlist;
    int letterlist[26];
    map<string,int>::iterator wordit;
    for(int i=0;i<26;i++){
        letterlist[i] = 0;
    }
    getline(cin,str);
    int wordcnt = 0;
    while(str!=""){
        stringstream sstr(str);
        while(getline(sstr,word,' ')){
            wordit = wordlist.find(word);
            if(wordit==wordlist.end()) {
                wordlist.insert(pair<string, int>(word, 0));
            }
            wordlist[word]++;
            wordcnt ++;
            for(int i=0;i<word.length();i++){
                letter = word[i];
                int asc = letter-'a'-0;
                letterlist[asc]++;
            }
        }
        getline(cin,str);
    }
    cout<<wordcnt<<endl<<"words"<<endl;
    for(wordit = wordlist.begin();wordit!=wordlist.end();wordit++){
        cout<<wordit->first<<" "<<wordit->second<<endl;
    }
    cout<<"letters"<<endl;
    for(int i=0;i<26;i++){
        cout<<(char)(i+'a')<<" "<<letterlist[i]<<endl;
    }
}
int Solution::PilNum(int year) {
    int monthlen[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int styear = (year/100)*100;
    int edyear = styear + 99;
    int pilnum = 0;
    cout<<"st"<<styear<<"ed"<<edyear<<endl;
    for(int i=styear;i<=edyear;i++){
        int r1 = i%4;
        int r2 = i%100;
        int r3 = i%400;
        if(r2==0){
            if(r3==0){
                monthlen[1] = 29;
            }
        }else{
            if(r1==1){
                monthlen[1] = 29;
            }
        }
        int l1 = i%10;
        int l2 = (i/10)%10;
        int l3 = (i/100)%10;
        int l4 = (i/1000);
        int mon = 0;
        int day = 0;
        //7dig
        mon = l1;
        day = l2*10+l3;
        if(mon>=1 && mon<=12){
            if(day>=0 && day<=monthlen[mon-1]) {
                pilnum++;
                printf("[%2d]7:%2d%02d%4d\n",pilnum,mon,day,i);
            }
        }
        //8dig
        mon = l1*10+l2;
        day = l3*10+l4;
        if(mon>=1 && mon<=12){
            if(day>=0 && day<=monthlen[mon-1]) {
                pilnum++;
                printf("[%2d]8:%02d%02d%4d\n",pilnum,mon,day,i);
            }
        }
    }
    return pilnum;
}

bool Solution::Akuna_t1(int d) {
    //see if d is the multiple of other three numbers
    int i = 0;
    if(d<8){
        //2*2*2 = 8
        return false;
    }
    int PrimeNums = 0;
    i = 2;
    while(i<=d){
        int reminder = d%i;
        if(reminder==0){
            PrimeNums++;
            if(PrimeNums>=3){
                //already have three prime numbers
                return true;
            }else{
                d = d/i;
            }
            i = 1;
        }
        i++;
    }
    return false;

}
float Solution::Akuna_t2(float *data, int n) {
    int i = 0;
    if(n<2){
        return data[0];
    }
    double sum = 0;
    float avg = 0;
    for(i=0;i<n;i++){
        sum += data[i];
    }
    avg = sum/n;
    double sqrtsum = 0;
    for(i=0;i<n;i++){
        float dif = data[i] - avg;
        sqrtsum += (dif*dif);
    }
    float StdDev = sqrt(sqrtsum/(n-1));
    return StdDev;
}
int** Solution::Akuna_t3(int **mat, int n, int m) {
    if(n<=1 && m <=1){
        return mat;
    }
    int i = 0;
    int j = 0;
    int i2 = 0;
    int j2 = 0;
    int ** pnewmat = new int*[m];
    for(j=0;j<m;j++){
        pnewmat[j] = new int[n];
    }


    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            i2 = m - j - 1;
            j2 = i;
            pnewmat[i2][j2] = mat[i][j];
        }
    }
    return pnewmat;
}
vector<vector<int>> Solution::Akuna_t3_2(vector<vector<int>> mat,int n,int m){
    if(n<=1 && m <=1){
        return mat;
    }
    int i = 0;
    int j = 0;
//    int i2 = 0;
//    int j2 = 0;
    vector<vector<int>> newmat;
//    for(i2=0;i2<m;i2++){
//        vector<int> tmp;
//        for(j2=0;j2<n;j2++){
//            tmp.push_back(0);
//        }
//        newmat.push_back(tmp);
//    }
    for(i=0;i<m;i++){
        vector<int> tmp;
        for(j=0;j<n;j++){
            tmp.push_back(mat[j][m-i-1]);
        }
        newmat.push_back(tmp);
    }
    return newmat;
}
int Solution::Akuna_t4(string str) {
    string word;
    vector<string> abbrs;
    int UniWordCnt = 0;
    int i = 0;
    stringstream strs(str);
    while(getline(strs,word,' ')){
        if(word == ""){
            continue;
        }else{
            int wordlen = word.length();
            if(wordlen>2){
                string mid = to_string(wordlen-2);
                string abbr = word.at(0)+mid+word.at(wordlen-1);
                bool UniWord = true;
                for(i=0;i<abbrs.size();i++){
                    if(abbrs[i] == abbr){
                        UniWord = false;
                        break;
                    }
                }
                if(UniWord == true){
                    UniWordCnt++;
                    abbrs.push_back(abbr);
                    cout<<"UniAbbr:"<<abbr<<endl;

                }
            }
            cout<<"word:"<<word<<endl;
        }
    }
    return UniWordCnt;
}
float Solution::Akuna_t5(int n) {
    const float InitExpValue= 3.5;
    int i = 0;
    float CurExpValue = 0;
    float NexExpValue = 0;
    float FinalExpValue = 0;
    if(n==1){
        return InitExpValue;
    }
    if(n<1){
        return 0.0;
    }

    CurExpValue = InitExpValue;
    for(i=1;i<n;i++){
        NexExpValue = CurExpValue;
        double tmp = 0;
        for(int j=1;j<7;j++){
            if(j > NexExpValue){
                tmp += j;
            }else{
                tmp += NexExpValue;
            }
        }
        CurExpValue = tmp/6;
    }
    FinalExpValue = CurExpValue;
    return FinalExpValue;
}
string Solution::Akuna_t6(string str) {
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
    return '\0';
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
                return false;
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
void Solution::test(int i) { cout<<i<<endl;}
