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
        string str;
        string word;
        char letter;
        map<string, int> wordlist;
        int letterlist[26];
        map<string, int>::iterator wordit;
        for (int i = 0; i < 26; i++) {
            letterlist[i] = 0;
        }
        //getline(cin, str);
        int wordcnt = 0;
        int id = 0;
        while (strlist.size() != id) {
            str = strlist[id];
            stringstream sstr(str);
            while (getline(sstr, word, ' ')) {
                wordit = wordlist.find(word);
                if (wordit == wordlist.end()) {
                    map<string, int>::value_type vt = {word,0};
                    wordlist.insert(vt);
                }
                wordlist[word]++;
                wordcnt++;
                for (int i = 0; i < word.length(); i++) {
                    letter = word[i];
                    int asc = letter - 'a' - 0;
                    letterlist[asc]++;
                }
            }
            //getline(cin, str);
            id ++;
        }
        cout << wordcnt << endl << "words" << endl;
        for (wordit = wordlist.begin(); wordit != wordlist.end(); wordit++) {
            cout << wordit->first << " " << wordit->second << endl;
        }
        cout << "letters" << endl;
        for (int i = 0; i < 26; i++) {
            cout << (char) (i + 'a') << " " << letterlist[i] << endl;
        }
    }
};
const bool reg1 = TestPlat::reg<UniWordCnt>("UniWordCnt");