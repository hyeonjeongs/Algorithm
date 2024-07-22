#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<bool> alpha;
vector<int> keyIndex;
void makeKeys(string word, int index) {
    istringstream iss(word);
    string token;
    vector<string> tokens;
    
    while(getline(iss, token, ' ')) {
        tokens.push_back(token);
    }
    for(int i=0; i<tokens.size(); i++) {
        int ch = tolower(tokens[i][0]) - 'a';
        if(!alpha[ch]) {
            alpha[ch] = true;
            keyIndex[index] = word.find(tokens[i]);
            return;
        }
    }
    for (int i = 0; i < word.size(); ++i) {
        if (word[i] != ' ') {
            char ch = tolower(word[i]);
            if (!alpha[ch - 'a']) {
                alpha[ch - 'a'] = true;
                keyIndex[index] = i;
                return;
            }
        }
    }
    keyIndex[index] = -1;
}
void makeKey(string word, int index) {

    for(int i=0; i<word.size(); i++) {
        if(i==0) {
            int ch = (int)tolower(word[i]) -97;

            if(!alpha[ch]) {
                alpha[ch] = true;
                keyIndex[index] = i;
                return;
            }
        }
        if(word[i] ==' ') {
            int ch = (int)tolower(word[i+1]) - 97;
            if(!alpha[ch]) {
                alpha[ch] = true;
                keyIndex[index] = i+1;
                return;
            }
        }
    }

    for(int i=0; i<word.size(); i++) {
        int ch = (int)tolower(word[i]) - 97;

        if(!alpha[ch] && word[i] != ' ') {

            alpha[ch] = true;
            keyIndex[index] = i;
            return;
        }
    }
    keyIndex[index] = -1;
}

void printResult(string word, int index) {
    for(int i=0; i<word.size(); i++) {
        if(i==index) {
            cout<< "[" << word[i] << "]";
            continue;
        }
        cout << word[i];
    }

    cout <<'\n';
}

int main() {
    int n;
    cin>> n;
    cin.ignore();
    string input;
    vector<string> words;

    alpha.assign(26, false);
    keyIndex.assign(n, -1);

    for(int i=0; i<n; i++) {
        getline(cin,input);
        words.push_back(input);
    }

    for(int i=0; i<n; i++) {
        makeKey(words[i], i);
    }

    for(int i=0; i<n;i++) {
        printResult(words[i], keyIndex[i]);
    }


    return 0;

}