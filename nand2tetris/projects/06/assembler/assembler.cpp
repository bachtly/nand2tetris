#include <bits/stdc++.h>
using namespace std;

#include "preprocess.cpp"
#include "delsymbol.cpp"
#include "symboless.cpp"

string file_inp;
string file_out;


void IOProc() {
    cin >> file_inp;
    freopen(file_inp.c_str(), "r", stdin);
    int n = file_inp.size();
    
    file_out = file_inp;
    file_out[n-3] = 'h';
    file_out[n-2] = 'a';
    file_out[n-1] = 'c';
    file_out.push_back('k');
    freopen(file_out.c_str(), "w", stdout);
}

int main() {

    IOProc();
    vector<string> content = preprocess();
    map<string, int> label_map = delsymbol(content);
    symboless(content);

    for (string i : content) cout << i << endl;

    // cout << "DEBUG" << endl;
    // bitset<16> bits(17);
    // cout << "4 to bin "<< bits.to_string() << endl;

    return 0;
}