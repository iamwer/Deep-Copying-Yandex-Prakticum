#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

vector<string> SplitIntoWords(string& text) {
    vector<string> words;
    string word;
    for (char c : text) {
        if (c == ' ') {
            words.push_back(word);
            word = "";
        }
        else {
            word += c;
        }
    }
    words.push_back(word);

    return words;
}

set<string> ParseStopWords(string& text) {
    set<string> stop_words;
    for (string& word : SplitIntoWords(text)) {
        stop_words.insert(word);
    }
    return stop_words;
}

vector<string> ParseQuery(string& text, set<string>& stop_words) {
    vector<string> words;
    for (string& word : SplitIntoWords(text)) {
        if (stop_words.count(word) == 0) {
            words.push_back(word);
        }
    }
    return words;
}

int main() {
    
    string stop_words_joined;
    getline(cin, stop_words_joined);
    set<string> stop_words = ParseStopWords(stop_words_joined);

    
    string query;
    getline(cin, query);
    vector<string> query_words = ParseQuery(query, stop_words);

    for (string& word : query_words) {
        cout << '[' << word << ']' << endl;
    }
}