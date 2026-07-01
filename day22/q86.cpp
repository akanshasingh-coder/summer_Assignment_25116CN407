//wap to count words in a sentence
#include <iostream>
#include <sstream>
using namespace std;

int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    stringstream ss(sentence);
    string word;
    int wordCount = 0;

    while (ss >> word) {
        wordCount++;
    }

    cout << "Number of words: " << wordCount << endl;

    return 0;
}       