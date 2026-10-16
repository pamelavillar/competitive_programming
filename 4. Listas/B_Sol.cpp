#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <string>

using namespace std;

bool sumaValida(int a, int b, int c) {
    int suma = a + b + c;
    return suma == 10 || suma == 20 || suma == 30;
}

string getState(const vector<vector<int>>& piles,const list<int>& deck,int currentPile) {

    string state;

    for (int i = 0; i < 7; i++) {
        state += "|";

        for (int card : piles[i]) {
            state += to_string(card) + ",";
        }
    }

    state += "|";

    for (int card : deck) {
        state += to_string(card) + ",";
    }

    state += "|" + to_string(currentPile);

    return state;
}

int main() {

    int firstCard;

    while (cin >> firstCard && firstCard != 0) {

        vector<vector<int>> piles(7);
        list<int> deck;

        // La primera carta
        deck.push_back(firstCard);

        // Leer las otras 51 cartas
        for (int i = 1; i < 52; i++) {
            int card;
            cin >> card;
            deck.push_back(card);
        }

        // Repartir las primeras 7 cartas
        for (int i = 0; i < 7; i++) {
            piles[i].push_back(deck.front());
            deck.pop_front();
        }

        int currentPile = 0;

        // Ya se repartieron 7 cartas
        int cards = 7;

        set<string> visited;

        while (true) {

            // -------------------------------------------------
            // 1. Jugar una carta
            // -------------------------------------------------

            if (deck.empty()) {
                cout << "Loss: " << cards << "\n";
                break;
            }

            piles[currentPile].push_back(deck.front());
            deck.pop_front();

            cards++;

            // -------------------------------------------------
            // 2. Buscar combinaciones
            // -------------------------------------------------

            while (piles[currentPile].size() >= 3) {

                int n = piles[currentPile].size();

                int first = piles[currentPile][0];
                int second = piles[currentPile][1];

                int last = piles[currentPile][n - 1];
                int last2 = piles[currentPile][n - 2];
                int last3 = piles[currentPile][n - 3];

                // ---------------------------------------------
                // Situación 1:
                // first + second + last
                // ---------------------------------------------

                if (sumaValida(first, second, last)) {

                    deck.push_back(first);
                    deck.push_back(second);
                    deck.push_back(last);

                    // Elimina last
                    piles[currentPile].pop_back();

                    // Elimina first
                    piles[currentPile].erase(
                        piles[currentPile].begin()
                    );

                    // Elimina second
                    piles[currentPile].erase(
                        piles[currentPile].begin()
                    );

                    continue;
                }

                // ---------------------------------------------
                // Situación 2:
                // first + last2 + last
                // ---------------------------------------------

                if (sumaValida(first, last2, last)) {

                    deck.push_back(first);
                    deck.push_back(last2);
                    deck.push_back(last);

                    // Elimina last
                    piles[currentPile].pop_back();

                    // Elimina last2
                    piles[currentPile].pop_back();

                    // Elimina first
                    piles[currentPile].erase(
                        piles[currentPile].begin()
                    );

                    continue;
                }

                // ---------------------------------------------
                // Situación 3:
                // last3 + last2 + last
                // ---------------------------------------------

                if (sumaValida(last3, last2, last)) {

                    deck.push_back(last3);
                    deck.push_back(last2);
                    deck.push_back(last);

                    // Elimina las últimas 3
                    piles[currentPile].pop_back();
                    piles[currentPile].pop_back();
                    piles[currentPile].pop_back();

                    continue;
                }

                // No hay combinación
                break;
            }

            // -------------------------------------------------
            // 3. ¿Ganamos?
            // -------------------------------------------------

            bool win = true;

            for (int i = 0; i < 7; i++) {
                if (!piles[i].empty()) {
                    win = false;
                    break;
                }
            }

            if (win) {
                cout << "Win : " << cards << "\n";
                break;
            }

            // -------------------------------------------------
            // 4. ¿Se repitió el estado?
            // -------------------------------------------------

            string state = getState(
                piles,
                deck,
                currentPile
            );

            if (visited.count(state)) {
                cout << "Draw: " << cards << "\n";
                break;
            }

            visited.insert(state);

            // -------------------------------------------------
            // 5. Buscar siguiente pila que no esté vacía
            // -------------------------------------------------

            currentPile = (currentPile + 1) % 7;

            while (piles[currentPile].empty()) {
                currentPile = (currentPile + 1) % 7;
            }
        }
    }

    return 0;
}