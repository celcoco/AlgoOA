//
// Created by Allen Chen on 8/3/16.
//

//
// Created by Allen Chen on 8/3/16.
//
#include "TestPlat.h"

class UniWordCnt : public SlnBase{
public:
    vector<string> strlist;
    void PrintDesc(){
        cout << "Count the words and letters" << endl;
    }
    void InputLocal(){
        string str1 = "You tell me this is a test that such a simple test";
        strlist.push_back(str1);
    }
    void InputFromFile(ifstream &fh){
        string str1;
        while(getline(fh,str1)){
            strlist.push_back(str1);
        }
    }
    void PrintInput(){
        PrintAll(strlist);
    }
    void PrintResult(){
        cout << "See output ^ " << endl;
    }
    void Algo(){
        test();
    }
    void test() {
        string str1;
        map<string,int> wordcnt;
        map<char,int> lettercnt;
        for(int i = 0; i < 26; i++){
            char c = (char)(i+'a');
            lettercnt[c] = 0;
        }
        while(strlist.size() != 0){
            str1 = strlist.back();
            strlist.pop_back();
            //if(str1 == "") break;
            stringstream sstr1(str1);
            string word;
            while(getline(sstr1,word,' ')){
                bool isWord = false;
                for(auto& w : word){
                    if(w >= 'a' && w <= 'z'){
                        isWord = true;
                    }else{
                        if(w > 'z' || w < 'A' || (w < 'a' && w > 'Z')){
                            isWord = false;
                            break;
                        }
                    }
                }
                if(!isWord) continue;
                if(wordcnt.find(word) != wordcnt.end()){
                    wordcnt[word]++;
                }else{
                    wordcnt[word] = 1;
                }
                for(auto& l : word){
                    if(l > 'z' || l < 'a') continue;
                    lettercnt[l] ++;
                }
            }
        }
        cout << wordcnt.size() << endl << "words" << endl;
        for(auto& i : wordcnt){
            cout << i.first << " " << i.second << endl;
        }
        cout << "letters" << endl;
        for(auto& i : lettercnt){
            cout << i.first << " " << i.second << endl;
        }
    }
};
const bool reg1 = TestPlat::reg<UniWordCnt>("UniWordCnt");