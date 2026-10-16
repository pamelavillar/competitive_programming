// STUDENTS

// HOW TO SOLVE

// aqui recuerda usar un set para identificar repetidos
#include <iostream>
#include <list>
#include <set>
#include <vector>

using namespace std;

int main() {

    int n;
    int caseNum = 1;

    while (cin >> n && n) {
    
        vector<int> a(n),b(n),c(n);

        for(int i = 0; i < n; i++){
            cin>>a[i]>>b[i]>>c[i];
        } 

        int answer = -1;

        set<vector<int>> random;
        int time = 1;
    

        while(random.insert(c).second){

            int awaken =0;
            int sleeping =0;

            for(int i = 0; i < n; i++){
                if(c[i] <=a[i]){
                    awaken++;
                }
            } 

            if(awaken == n){
                answer = time;
                break;
            }

            sleeping = n-awaken;

            for(int i = 0; i < n; i++){
                if(c[i] == a[i] + b[i]){
                    c[i] = 1;
                }
                else if(c[i] == a[i] && sleeping <= awaken ){
                    c[i] = 1;
                }
                else {
                    c[i]++;
                }
            }

            time++;
        }        

        cout << "Case " << caseNum++ << ": " << answer << '\n';
        
    }

    return 0;
}