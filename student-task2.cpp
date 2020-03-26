#include <iostream>
#include <string>
#include <fstream>
#include <set>

using namespace std;

int main() {

    ifstream fin("sample.txt");
    ofstream fout("output2.txt");

    string out1;
    string out2;
    int sout2;
    set<string> c;

    while (!fin.eof()) {
        fin >> out1;
        fin >> out2;
        sout2 = stoi(out2);
        if (sout2 < 50) {
            c.insert(out1);
        }
    }

    set<string>::iterator i;
    for (i = c.begin(); i != c.end(); i++) {
        fout << *i << endl;
    }

    return 0;
}