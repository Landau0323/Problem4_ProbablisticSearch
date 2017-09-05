#include <iostream>
#include "Grids.h"

using namespace std;

int main() {
    Grids grids;
    grids.show_grids();
    grids.show_value_table();
    grids.evaluate_value_table();
    grids.show_value_table();
    grids.show_policy_table();

    return 0;
}