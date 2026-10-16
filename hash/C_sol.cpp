#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm> 
using namespace std;


int main(){
    int size = 1;
    while(cin>>size && size != 0){
        string encoded;
        cin >> encoded;

        map<string,int> hash;

        for(int i = 0; i+size < encoded.size(); i++){
            string window = encoded.substr(i,size);

            hash[window]++;
        }
        auto max_it = std::max_element(
            hash.begin(), hash.end(),[](const pair<const string, int>& a, const pair<const string, int>& b) {
                return a.second < b.second;
            });

        cout<< max_it->first<<"\n";
    }
}