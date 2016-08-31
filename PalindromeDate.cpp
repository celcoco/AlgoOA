//
// Created by Allen Chen on 8/3/16.
//
#include "TestPlat.h"

class PalindromeDate : public SlnBase{
public:
    int y;
    int NumOfPilYear;
    void PrintDesc(){
        cout << "Cal the number of Palindrome dates in the centry" << endl;
    }
    void InputLocal(){
        y = 2016;
    }
    void PrintInput(){
        cout << y << endl;
    }
    void PrintResult(){
        cout << NumOfPilYear << endl;
    }
    void Algo(){
        NumOfPilYear = testPilNum(y);
    }
    int testPilNum(int year) {
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
                if(day>=1 && day<=monthlen[mon-1]) {
                    pilnum++;
                    printf("[%2d]7:%2d%02d%4d\n",pilnum,mon,day,i);
                }
            }
            //8dig
            mon = l1*10+l2;
            day = l3*10+l4;
            if(mon>=1 && mon<=12){
                if(day>=1 && day<=monthlen[mon-1]) {
                    pilnum++;
                    printf("[%2d]8:%02d%02d%4d\n",pilnum,mon,day,i);
                }
            }
        }
        return pilnum;
    }
};
const bool reg1 = TestPlat::reg<PalindromeDate>("PalindromeDate Num");