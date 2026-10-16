#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    int test_cases=0;

    cin >> test_cases;

    int caset = 0;
    while(caset != test_cases){
        vector<int> testVector(3);
        int promedio = 0;

        int term1, term2, final, attendance, test1, test2, test3;
        cin >> term1 >> term2 >> final >> attendance >> test1 >>test2 >> test3;

        testVector[0] = test1;
        testVector[1] = test2;
        testVector[2] = test3;

        sort(testVector.begin(), testVector.end(),greater<int>());

        promedio = term1+term2+final + attendance + (testVector[0] + testVector[1])/2;

        promedio/=10;

        cout<< "Case " << caset+1 << ": ";
        if(promedio >=9) cout << 'A' ;
        else if(promedio >= 8 && promedio < 9) cout << 'B';
        else if(promedio >= 7 && promedio < 8) cout << 'C';
        else if(promedio >= 6 && promedio < 7) cout << 'D';
        else cout << 'F';
        cout<< '\n';
        caset++;
    }

}
