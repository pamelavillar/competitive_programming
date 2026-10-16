#include <iostream>
#include <list>
using namespace std;

int main(){

    string text;
    

    while(cin>>text){

        list<char> textOuput;

        list<char>::iterator it;
        it = textOuput.begin();
        
        for(int i = 0; i < text.size(); i++){
            
            if(text[i] == '[' ){
                //advance(it1,i);
                it = textOuput.begin();
            }
            else if(text[i] == ']' ){
                it = textOuput.end();
            }
            else{
                it = textOuput.emplace(it,text[i]);
                ++it;
            }
        }

        for(char c : textOuput){
            cout<<c;
        }
        cout<<"\n";
    }

}