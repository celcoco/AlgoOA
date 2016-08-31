//
// Created by Allen Chen on 8/29/16.
//

#include "TestPlat.h"

class Lamps : public SlnBase {
    int grid_width,grid_height;
    int conn_x1,conn_y1,conn_x2,conn_y2,start_x,start_y;
    int re;
    void PrintDesc() {
        cout << "Find all light lamb" << endl;
    }

    void InputLocal() {
        grid_width = 5;
        grid_height = 3;
        conn_x1 = -1;
        conn_y1 = 0;
        conn_x2 = -1;
        conn_y2 = -1;
        start_x = 4;
        start_y = 2;
    }

    void InputFromFile(ifstream &fh) {
        fh >> grid_width;
        fh >> grid_height;
        fh >> conn_x1 >>
              conn_y1 >>
              conn_x2 >>
              conn_y2 >>
              start_x >>
              start_y;
    }

    void PrintInput() {
        cout << grid_width <<
                " " <<
                grid_height <<
                " (" <<
                conn_x1 <<
                "," <<
                conn_y1 <<
                " ),(" <<
                conn_x2 <<
                "," <<
                conn_y2 <<
                "),start(" <<
                start_x <<
                "," <<
                start_y <<
                ")" << endl;
    }

    void PrintResult() {
        cout << re << endl;
    }

    void Algo(){
        re = test(grid_width,grid_height,conn_x1,conn_y1,conn_x2,conn_y2,start_x,start_y);
    }

    int test(int w,int h,int x1,int y1,int x2,int y2,int sx,int sy) {
        if(w*h <= 1)
            return 0;
        vector<int> tmplist;
        set<int> finallist;
        finallist.insert(sy*w+sx);
        // turn off all possible (x1,y1)
        bool availabe = true;
        int newx = sx;
        int newy = sy;
        while(newx >= 0 && newx < w && newy >= 0 && newy < h){
            tmplist.push_back(newy*w+newx);
            newx += x1;
            newy += y1;
        }
        unsigned long n = tmplist.size();
        for(int i = 0;i < n; i++){
            newx = tmplist[i]%w;
            newy = tmplist[i]/w;
            while(newx >= 0 && newx < w && newy >= 0 && newy < h){
                finallist.insert(newy*w+newx);
                newx += x2;
                newy += y2;
            }
        }
        return (int)(w*h - finallist.size());
    };
};
const bool reg1 = TestPlat::reg<Lamps>("Lamps: Akuna Grid search");