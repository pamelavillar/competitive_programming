#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

int main(){

    int cases;
    cin >> cases;
    cin.ignore();

    vector<vector<vector<int>>> results;

    for(int i = 0; i < cases; i++){
        cout << "Case #" << i + 1 << ":\n";
        map<int, bool> friend1;
        map<int, bool> friend2;
        map<int, bool> friend3;

        // LECTURA DE PROBLEMAS RESUELTOS

        string problems;
        int n, pro;

        getline(cin, problems);
        stringstream ss1(problems);

        ss1 >> n;

        for(int j = 0; j < n; j++){
            ss1 >> pro;
            friend1.insert({pro, false});
        }

        getline(cin, problems);
        stringstream ss2(problems);

        ss2 >> n;

        for(int j = 0; j < n; j++){
            ss2 >> pro;
            friend2.insert({pro, false});
        }

        getline(cin, problems);
        stringstream ss3(problems);

        ss3 >> n;

        for(int j = 0; j < n; j++){
            ss3 >> pro;
            friend3.insert({pro, false});
        }

        // PROBLEMAS EXCLUSIVOS

        int fr1_result = 0;
        int fr2_result = 0;
        int fr3_result = 0;

        for(auto& par : friend1){

            int pro = par.first;

            if(friend2.find(pro) == friend2.end() &&
               friend3.find(pro) == friend3.end()){

                par.second = true;
                fr1_result++;
            }
        }

        for(auto& par : friend2){

            int pro = par.first;

            if(friend1.find(pro) == friend1.end() &&
               friend3.find(pro) == friend3.end()){

                par.second = true;
                fr2_result++;
            }
        }

        for(auto& par : friend3){
            int pro = par.first;
            if(friend1.find(pro) == friend1.end() &&
               friend2.find(pro) == friend2.end()){

                par.second = true;
                fr3_result++;
            }
        }

        int maxi = max(fr1_result, max(fr2_result, fr3_result));

        

        if(fr1_result == maxi){
            cout<< "1 "<< maxi;
            for(auto& pair : friend1){
                if(pair.second){
                    cout<< " " << pair.first;
                }
            }

            cout << "\n";
        }

        if(fr2_result == maxi){
            cout<< "2 "<< maxi;
            for(auto& pair : friend2){
                
                if(pair.second){
                    cout<< " " << pair.first;
                }
            }

            cout << "\n";
        }

        if(fr3_result == maxi){
            cout<< "3 "<< maxi;
            for(auto& pair : friend3){
                
                if(pair.second){
                    cout<< " " <<pair.first;
                }
            }

            cout << "\n";
        }

        

    }


    return 0;
}