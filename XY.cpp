//
// Created by 研究用 on 2017/08/24.
//

#include "XY.h"

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

void XY::setI(int i) {
    XY::i = i;
}

void XY::setJ(int j) {
    XY::j = j;
}

int XY::getI() const {
    return i;
}

int XY::getJ() const {
    return j;
}

void XY::setIJ(int i_input, int j_input) {
    i=i_input;
    j=j_input;
}
