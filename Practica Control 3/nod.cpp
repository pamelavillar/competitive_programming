#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    const int MAXN = 1000000;

    vector<int> nod(MAXN + 1, 0);

    for (int d = 1; d <= MAXN; d++) {
        for (int x = d; x <= MAXN; x += d) {
            nod[x]++;
        }
    }

    vector<int> seq;

    int n = 1;

    while (n <= MAXN) {
        seq.push_back(n);
        n += nod[n];
    }

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {

        int A, B;
        cin >> A >> B;

        // Primer elemento >= A
        auto ini = lower_bound(seq.begin(), seq.end(), A);

        // Primer elemento > B
        auto fin = upper_bound(seq.begin(), seq.end(), B);

        int ans = fin - ini;

        cout << "Case " << tc << ": " << ans << '\n';
    }

    return 0;
}