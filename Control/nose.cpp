#include <iostream>
#include <vector>
using namespace std;


int main(){
    int cards = 0;
    
    while(cin>>cards && cards){
        vector<pair<string, bool>> initial(cards);

        for(int i = 0; i < cards; i++){
            initial[i].second = true;
        }

        int last = -1;

        for(int i = 0; i < cards; i++){
            string carta = "";
            string word = "";

            cin >> carta >> word;

            int size = word.size();

            while(size){
                if(initial[last].second){
                    size--;
                }

                if(size > 0){
                    last = (last + 1) % cards;
                }
            }

            initial[last].first = carta;
            initial[last].second = false;

            last = (last + 1) % cards;
        }


        for(int i = 0 ; i < cards; i++){
            cout<<initial[i].first;
            if(i < cards-1)cout << " ";
        }
        cout<<"\n";
    }
}