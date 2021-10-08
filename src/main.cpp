#include <iostream>
#include "CFG.h"

using namespace std;

int main() {
    CFG cfg("../../test1.json");
    cfg.print();
    return 0;
}