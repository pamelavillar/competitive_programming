#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {

    int test_cases;
    cin >> test_cases;

    while (test_cases--) {

        int num_candidates, num_states;
        cin >> num_candidates >> num_states;

        vector<long long> votos(num_candidates, 0);
        long long total_votes = 0;

        for (int i = 0; i < num_states; i++) {

            vector<double> percentage(num_candidates);

            for (int j = 0; j < num_candidates; j++) {
                cin >> percentage[j];
            }

            long long state_votes;
            cin >> state_votes;

            total_votes += state_votes;

            for (int j = 0; j < num_candidates; j++) {
                votos[j] += llround(percentage[j] / 100.0 * state_votes);
            }
        }


        vector<pair<long long, int>> candidatos;

        for (int i = 0; i < num_candidates; i++) {
            candidatos.push_back({votos[i], i + 1});
        }

        sort(candidatos.begin(), candidatos.end(),
            [](const pair<long long, int>& a,
               const pair<long long, int>& b) {

                if (a.first != b.first)
                    return a.first > b.first;

                return a.second < b.second;
            });

        if (candidatos[0].first * 1000 >= total_votes * 501) {

            cout << candidatos[0].second << " "
                 << candidatos[0].first << "\n";

        } else {

            cout << candidatos[0].second << " "
                 << candidatos[0].first << "\n";

            cout << candidatos[1].second << " "
                 << candidatos[1].first << "\n";
        }

        if (test_cases > 0)
            cout << "\n";
    }

    return 0;
}