//
// Created by inte on 10/8/21.
//

#ifndef MB_PROGRAMMEEROPDRACHT_2_CFG_H
#define MB_PROGRAMMEEROPDRACHT_2_CFG_H

#include <iostream>
#include <vector>
#include <tuple>
#include <fstream>
#include "json.hpp"
#include <iomanip>

using namespace std;
using json = nlohmann::json;

typedef string variable;
typedef string terminal;
//prodoction bestaat uit een head en body
typedef pair<string, vector<string>> production;

class CFG {

    vector<variable> _Variables;
    vector<terminal> _Terminals;
    vector<production> _Productions;
    string _Startsymbol;

public:

    CFG(string jsonfile);

    void print();

};

#endif //MB_PROGRAMMEEROPDRACHT_2_CFG_H
