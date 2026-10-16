#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <algorithm>


int main(){

    vector<pair<string,string>> books;
    string book;
    

    while(getline(cin,book) && book != "END"){
        
        int ini = book.find('"');
        int fin = book.find('"', ini + 1);

        string title = book.substr(ini, fin+1);
        string author = book.substr(fin + 5);


        books.push_back({author,title});       
    }

    sort(books.begin(), books.end());  
    map<string,int> index;

    for(int i = 0; i < books.size(); i++){
        index[books[i].second] = i;
    }


    vector<bool> on_shelve (books.size(),true);
    vector<bool> returned (books.size(),false);


    string record;

    while(cin>>record && record != "END"){
        
        if (record == "BORROW"){
            cin.ignore();

            getline(cin,record);

            on_shelve[index[record]] = false;
            returned[index[record]] = false;
        }
        else if(record == "RETURN"){
            cin.ignore();

            getline(cin,record);

            returned[index[record]] = true;
        }
        else {

            for(int i  = 0; i < books.size(); i++){
                if(returned[i]){
                    int id_prev = -1;   

                    for(int j = i-1; j >= 0; j--){
                        if(on_shelve[j]){
                            id_prev = j;
                            break;
                        }
                    }


                    on_shelve[i] = true;
                    returned[i] = false;

                    if(id_prev != -1 ){ 
                        cout<< "Put "<< books[i].second <<" after " << books[id_prev].second << "\n";
                    }
                    else{
                        cout<< "Put "<< books[i].second <<" first\n";
                    }
                }
            }

            cout<<"END\n";
        }
        
    
    }

}