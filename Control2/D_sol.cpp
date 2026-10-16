#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {

        int n, k;
        cin >> n >> k;

        vector<string> name(n);
        vector<int> freq(n);

        set<pair<int,int>> pendiente;

        for(int i = 0; i < n; i++) {
            cin >> name[i] >> freq[i];
            pendiente.insert({freq[i], i});
        }

        for(int i = 0; i < k; i++) {

            auto it = pendiente.begin();

            int next_time = it->first;
            int priority = it->second;

            cout << next_time << " " << name[priority] << "\n";

            pendiente.erase(it);

            pendiente.insert({ next_time + freq[priority], priority });
        }
    }

    return 0;
}