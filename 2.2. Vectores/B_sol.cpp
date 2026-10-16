#include <iostream>
#include <vector>
using namespace std;

int main(){

    int num_soldiers = 0;
    int num_loss = 0;

    while(cin >> num_soldiers >> num_loss && num_soldiers != 0){

        vector<int> left(num_soldiers + 1);
        vector<int> right(num_soldiers + 1);

        for(int i = 1; i <= num_soldiers; i++){
            left[i] = i - 1;
            right[i] = i + 1;
        }

        left[1] = 0;
        right[num_soldiers] = 0;

        for(int i = 0; i < num_loss; i++){
            int L, R;
            cin >> L >> R;

            int L_buddy = left[L];
            int R_buddy = right[R];

            if(L_buddy == 0)
                cout << "* ";
            else
                cout << L_buddy << ' ';

            if(R_buddy == 0)
                cout << '*';
            else
                cout << R_buddy;

            cout << '\n';

            if(L_buddy != 0)
                right[L_buddy] = R_buddy;

            if(R_buddy != 0)
                left[R_buddy] = L_buddy;
        }

        cout << "-\n";
    }
}