#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <functional>
#include <algorithm>

#include <cctype>

using namespace std;

int main(){
    int binders;
    cin >> binders;

    vector<pair<string, priority_queue<pair<int,string>, vector<pair<int,string>>, greater<pair<int,string>>>>> binders_names;

    while(binders--){
        string binder_name;
        cin.ignore();
        getline(cin, binder_name);

        int m, n, b;
        cin >> m >> n >> b;

        map<string, int> ingredients;

        while(m--){
            string ingredient;
            int cost;
            cin >> ingredient >> cost;
            ingredients[ingredient] = cost;
        }

        priority_queue<pair<int,string>, vector<pair<int,string>>, greater<pair<int,string>>> recetas_posibles;

        while(n--){
            string recipe;
            cin.ignore();
            getline(cin, recipe);

            int ingre;
            cin >> ingre;

            int suma_total = 0;
            bool possible = true;

            while(ingre--){
                string requirement;
                int cantidad;
                cin >> requirement >> cantidad;

                auto it = ingredients.find(requirement);
                if(it == ingredients.end()){
                    possible = false;
                } else {
                    suma_total += cantidad * it->second;
                }
            }

            if(possible && suma_total <= b){
                recetas_posibles.push({suma_total, recipe});
            }
        }

        binders_names.push_back({binder_name, recetas_posibles});
    }

    for(auto &binder : binders_names){
        transform(binder.first.begin(), binder.first.end(), binder.first.begin(), ::toupper);
        cout << binder.first << "\n";

        if(binder.second.empty()){
            cout << "Too expensive!\n";
        } else {
            while(!binder.second.empty()){
                cout << binder.second.top().second << "\n";
                binder.second.pop();
            }
        }

        cout << "\n";
    }
}