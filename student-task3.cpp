#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;

int main() {

    ifstream fin("sample.txt");
    ofstream fout("output3.txt");


    string out1;
    string out2;
    int sout2;
    map<string,int> c;
    map<string,int>::iterator i;


    while (!fin.eof()) {
        fin >> out1;
        fin >> out2;
        sout2 = stoi(out2);
        if (sout2 < 50) {
            if (c.find(out1) == c.end()) {
                c[out1] = 1;
            } else {
                c[out1]++;
            }
        } else {
            if (c.find(out1) == c.end()) {
                c[out1] = 0;
            }
        }
    }

    for (i = c.begin(); i != c.end(); i++) {
        fout << i->first << ' ' << i->second << endl; 
    }

    return 0;
}