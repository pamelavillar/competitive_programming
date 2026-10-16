#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

int main(){
    int t;
    cin >> t;

    for(int tc = 1; tc <= t; tc++){
        int ans;

        long long n;
        cin >> n;

        vector<int> heights;
        heights.push_back(0);

        for(int i = 0; i < n; i++){
            int num;
            cin >> num;
            heights.push_back(num);
        }

        int max_dif = 0;

        vector<int> diferencias;

        for(int i = 0; i < n; i++){
            int j = i+1;

            int rest = heights[j] - heights[i];

            if(rest > max_dif)
                max_dif = rest;

            diferencias.push_back(rest);
        }

        ans = max_dif;

        bool posible = true;

        for(auto a : diferencias){
            if(a == ans)ans--;
            else if(a > ans){
                posible = false;
                break;
            }
        }

        if(!posible)
            max_dif++;

        cout << "Case " << tc << ": " << max_dif << '\n';
    }
}