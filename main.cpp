
#include <set>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#include <iostream>
#include <utility>
using namespace std;

const string filename = "GOT.txt";

int main()
{
    vector<string> tokens;
    set <string> unique;
    string next_line;
    ifstream in;
    in.open(filename, ios::in);
    // Get lines from the file and remove the punctuation.
    while (getline(in, next_line)) {
        istringstream iss(next_line);
        string token;
        while (iss >> token) {
            string nopunct = "";
            for(auto &c : token) {
                if (isalpha(c)) {
                    nopunct +=c;
                }
            }
            tokens.push_back(nopunct);
            unique.insert(nopunct);
        }
    }
    cout << "Number of words "<<tokens.size()<<endl;
    cout << "Number of unique words "<<unique.size()<<endl;

    map<string, vector<string>> wordmap;
    string state = "";
    // Populate the map with strings from tokens
    for(vector<string>::iterator it=tokens.begin(); it !=tokens.end(); it++) {
        wordmap[state].push_back(*it);
        state = *it;
    }
    cout << endl;
    srand(time(NULL)); 
    state = "";
    // Generate 100 words that sound like the author from the text file
    for (int i = 0; i < 100; i++) {
        int ind = rand() % wordmap[state].size();
        cout << wordmap[state][ind] << " ";
        state = wordmap[state][ind];
    }
    cout << endl;
}