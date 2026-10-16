#include <iostream>
#include <vector>
#include <cctype>
#include <map>
#include <set>
#include <string>
using namespace std;

int main() {

    int test_cases;
    cin >> test_cases;
    cin.ignore();

    for (int document_number = 1; document_number <= test_cases; document_number++) {

        vector<string> words;
        set<string> words_unique;

        string line;

        while (getline(cin, line) && line != "END") {

            string word = "";

            for (int i = 0; i < line.size(); i++) {

                if (islower(line[i])) {
                    word += line[i];
                }
                else {
                    if (!word.empty()) {
                        words.push_back(word);
                        words_unique.insert(word);
                        word = "";
                    }
                }
            }

            if (!word.empty()) {
                words.push_back(word);
                words_unique.insert(word);
            }
        }

        int diff_words = words_unique.size();

        map<string, int> times_word;

        int left = 0;
        int uniques = 0;

        int best_left = 0;
        int best_right = words.size() - 1;

        for (int right = 0; right < words.size(); right++) {

            times_word[words[right]]++;

            if (times_word[words[right]] == 1) {
                uniques++;
            }

            while (uniques == diff_words) {

                if (right - left < best_right - best_left) {
                    best_left = left;
                    best_right = right;
                }

                times_word[words[left]]--;

                if (times_word[words[left]] == 0) {
                    uniques--;
                }

                left++;
            }
        }

        cout << "Document " << document_number << ": "
             << best_left + 1 << " "
             << best_right + 1 << "\n";
    }

    return 0;
}