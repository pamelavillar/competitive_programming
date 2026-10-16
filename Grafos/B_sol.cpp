#include <iostream>
#include <vector>
using namespace std;

struct Estado {
    int postes;
    int dobles;
};

vector<vector<int>> adj;
vector<bool> visitado;
Estado dp[1005][2];


Estado mejor(Estado a, Estado b) {

    if (a.postes != b.postes)
        return (a.postes < b.postes) ? a : b;

    return (a.dobles > b.dobles) ? a : b;
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {

        int n, m;
        cin >> n >> m;

        adj.assign(n, {});
        visitado.assign(n, false);

        for (int i = 0; i < m; i++) {

            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int totalPostes = 0;
        int totalDobles = 0;

        for (int i = 0; i < n; i++) {

            if (visitado[i])
                continue;

            vector<int> orden;
            vector<int> padre(n, -1);

            vector<int> pila;
            pila.push_back(i);
            visitado[i] = true;

            while (!pila.empty()) {

                int u = pila.back();
                pila.pop_back();

                orden.push_back(u);

                for (int v : adj[u]) {

                    if (!visitado[v]) {

                        visitado[v] = true;
                        padre[v] = u;
                        pila.push_back(v);
                    }
                }
            }

            for (int k = orden.size() - 1; k >= 0; k--) {

                int u = orden[k];

                dp[u][0] = {0, 0};
                dp[u][1] = {1, 0};

                for (int v : adj[u]) {

                    if (padre[v] != u)
                        continue;

                
                    dp[u][0].postes += dp[v][1].postes;
                    dp[u][0].dobles += dp[v][1].dobles;


                    Estado sin = dp[v][0];

                    Estado con = dp[v][1];

                   
                    con.dobles++;

                    Estado elegido = mejor(sin, con);

                    dp[u][1].postes += elegido.postes;
                    dp[u][1].dobles += elegido.dobles;
                }
            }

            Estado raiz = mejor(dp[i][0], dp[i][1]);

            totalPostes += raiz.postes;
            totalDobles += raiz.dobles;
        }

     
        int unSolo = m - totalDobles;

        cout << totalPostes << " "
             << totalDobles << " "
             << unSolo << "\n";
    }

    return 0;
}