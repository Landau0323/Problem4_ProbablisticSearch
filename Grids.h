//
// Created by 研究用 on 2017/08/24.
//

#ifndef PROBLEM4_SEARCH_GRIDS_H
#define PROBLEM4_SEARCH_GRIDS_H

#include <string>
#include <limits>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "XY.h"

using namespace std;


class Grids {
private:
    vector<vector<int> > grids;
    vector<vector<double> > value_table;
    vector<vector<char> > policy_table;
    XY goal;

public:
    Grids();
    void evaluate_value_table();
    void evaluate_value(int,int);
    void show_grids();
    void show_value_table();
    void show_policy_table();


};


#endif //PROBLEM4_SEARCH_GRIDS_H
