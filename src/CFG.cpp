//
// Created by inte on 10/8/21.
//

#include "CFG.h"

CFG::CFG(string jsonfile)
{

    //Inlezen JSON file
    ifstream  input(jsonfile);

    json file;
    input >> file;

    //eerst kennen we de variable toe de vector
    for (auto &var : file["Variables"]) _Variables.push_back(var);
    //Sorteren van de vector
    sort(_Variables.begin(), _Variables.end());

    //Toekenen van de terminals
    for (auto &ter : file["Terminals"]) _Terminals.push_back(ter);
    //Sorteren van de vector
    sort(_Terminals.begin(), _Terminals.end());

    //Toekenen van de productions
    for(auto &pro : file["Productions"])
    {
        if (pro["body"].empty()) _Productions.emplace_back(pro["head"], vector<string>{"e"});
        else _Productions.emplace_back(pro["head"], pro["body"]);
    }

    //Toekenen van het startsymbool
    _Startsymbol = file["Start"];

}

void CFG::print()
{

    //Printen van de Variables
    cout << "V = {";
    for (const auto& var : _Variables)
    {
        if (var != _Variables[_Variables.size()-1]) cout << var << ", ";
        else cout << var;
    }
    cout << "}" << endl;

    //Printen van de Terminals
    cout << "T = {";
    for (const auto& ter : _Terminals)
    {
        if (ter != _Terminals[_Terminals.size()-1]) cout << ter << ", ";
        else cout << ter;
    }
    cout << "}" << endl;

    //Printen van de Productions
    cout << "P = {" << endl;
    for (const auto& pro : _Productions )
    {
        string body;
        for (auto &var : pro.second)
        {
            if (var != pro.second[pro.second.size()-1]) body += var + " ";
            else body += var;
        }

        cout << "\t" << pro.first << " -> `" << body << "`" << endl;
    }
    cout << "}" << endl;

    //Printen van het Startsymbool
    cout << "S = " << _Startsymbol << endl;

}