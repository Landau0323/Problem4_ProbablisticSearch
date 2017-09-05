//
// Created by 研究用 on 2017/08/24.
//

#ifndef PROBLEM4_SEARCH_XY_H
#define PROBLEM4_SEARCH_XY_H

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


class XY {
private:
    int i,j;

public:
    int getI() const;

    int getJ() const;

    void setI(int i);

    void setJ(int j);

    void setIJ(int,int);

};


#endif //PROBLEM4_SEARCH_XY_H
