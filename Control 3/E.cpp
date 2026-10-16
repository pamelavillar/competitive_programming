// FACTORIAL

// HOW TO SOLVE
// SOLO HAYAS EL FACTORIAL MAS  GRANDE QUE NO PASE EL NUMERO Y HACES UN LOOP CON EL RESTO DE LA CANTIDAD Y YA 
// NO VA TOMAR MUCHO TIEMPO PORQUE CRECE EXPONENCIALMENTE


#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    int num;

    while(cin>>num){
        long long fac =1,fac1=1;
        int c=0;

        int j=1;

        int res = num;

        while(res){
            fac = 1;
            j = 1;
            while((fac*=j) <= res){
                j++;
                fac1=fac;
            }
            res -=fac1;
            c++;
        }

        cout<<c<<endl;

    }
}