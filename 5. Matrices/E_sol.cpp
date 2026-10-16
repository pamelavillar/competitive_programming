#include <iostream>
#include <vector>
#include <vector>
#include <cmath>

using namespace std;

pair<int,int> findi(int b,const vector<vector<int>>& piles  ){
    for(int i = 0; i < piles.size(); i++){
        for(int j = 0; j < piles[i].size(); j++){
            if(piles[i][j] == b){
                return {i,j};
            }
        }
    }
    return {0,0};
}

int main(){
    int num_blocks = 0;
    cin >> num_blocks;
    string command;
    vector<vector<int>> piles (num_blocks);
    for(int i = 0; i < num_blocks; i++){
        piles[i].push_back(i);
    }

    while(true){
        
        string comm1, comm2;
        int b1 , b2 = 0;
        cin>>comm1; if (comm1 == "quit") break;
        cin>>b1>>comm2>>b2;

        if(b1 == b2) continue;
    
        pair<int,int> A = findi(b1, piles);
        pair<int,int> B = findi(b2, piles);
        int pileA = A.first; 
        int posA = A.second;
        int pileB = B.first; 
        int posB = B.second;


        if(pileA == pileB ) continue;

        if(comm1 == "move"){
            while(piles[pileA].size() > posA + 1){
                int block = piles[pileA].back();
                piles[pileA].pop_back();
                piles[block].push_back(block);
            }

            if(comm2 == "onto"){
                while(piles[pileB].size() > posB + 1){
                    int block = piles[pileB].back();
                    piles[pileB].pop_back();
                    piles[block].push_back(block);
                }
            }            

            
            piles[pileA].pop_back();
            piles[pileB].push_back(b1);

        }
        else{
            vector<int> moved_blocks;

            for(int i = posA; i < piles[pileA].size(); i++){
                moved_blocks.push_back(piles[pileA][i]);
            }

            if(comm2 == "onto"){
                while(piles[pileB].size() > posB + 1){
                    int block = piles[pileB].back();
                    piles[pileB].pop_back();
                    piles[block].push_back(block);
                }
            }            

            while(piles[pileA].size() > posA){
                piles[pileA].pop_back();
            }

            for(int block : moved_blocks){
                piles[pileB].push_back(block);
            }
                    
                
        }
    }
    for(int i = 0; i < num_blocks; i++){
        cout << i << ":";

        for(int j = 0; j < piles[i].size(); j++){
            cout << " " << piles[i][j];
        }

        cout << endl;
    }
    
}