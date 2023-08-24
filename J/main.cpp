#include <iostream>
#include <vector>
#include <map>
#include <string>
 
using namespace std;
 
int main() {
    map<string, vector<string>> rhymeMap;
    string chosenWords[2];
    int librarySize;
    cin >> librarySize;
 
    vector<string> wordList(librarySize);
    for (int i = 0; i < librarySize; i++) {
        cin >> wordList[i];
        if (i < 2) {
            chosenWords[i] = wordList[i];
        }
        string originalWord = wordList[i];
        for (int j = originalWord.size() - 1; j >= 0; j--) {
            auto it = rhymeMap.find(originalWord.substr(j));
            if (it == rhymeMap.end()) {
                rhymeMap.emplace(originalWord.substr(j), vector<string>{originalWord});
            }
            else {
                it->second.push_back(originalWord);
            }
        }
    }
 
    int checkSize;
    cin >> checkSize;
 
    for (int k = 0; k < checkSize; k++) {
        string inputWord;
        cin >> inputWord;
        string output = chosenWords[1];
 
        for (int l = inputWord.size() - 1; l >= 0; l--) {
            auto it = rhymeMap.find(inputWord.substr(l));
            if (it != rhymeMap.end()) {
                for (const string& value : it->second) {
                    if (inputWord != value) {
                        output = value;
                        break;
                    }
                }
            }
        }
 
        cout << output << endl;
    }
 
    return 0;
}
