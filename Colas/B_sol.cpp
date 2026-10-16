#include <iostream>
#include <vector>
#include <stack>
using namespace std;


int orden(string c){
    if(c =="+"||c == "-") return 1;
    if(c== "*"|| c=="/") return 2;
    return 0;
}


int main(){

    int test_cases = 1;

    cin >> test_cases;
     string operand;

    getline(cin, operand);

    getline(cin, operand);

    while(test_cases--){
        stack<string>cola;
        vector<string> nums;



        while(getline(cin, operand) && !operand.empty()){
            
            if (operand != "+"  && operand != "-" && operand != "*" && operand != "/" && operand != "(" && operand != ")"  ){
                    nums.push_back(operand);
            }
            else{
                if(operand == "("){
                    cola.push("(");
                }
                else if(operand == ")"){
                    while(!cola.empty() && cola.top() != "("){
                        nums.push_back(cola.top());
                        cola.pop();
                    }
                    if(!cola.empty()) cola.pop();
                }

                else{
                    while(!cola.empty() && cola.top() != "(" && orden(cola.top()) >= orden(operand)){
                        //if(  || orden(cola.top()) == orden(operand) && operand!="(" ){
                            nums.push_back(cola.top());
                            cola.pop();
                        //}
                        
                    }
                    cola.push(operand);
                }
            }
            
        }
        while(!cola.empty()){
           
            nums.push_back(cola.top());
            cola.pop();
            
            
        }

        for(auto a: nums){
            cout<<a;
        }   
        cout<< '\n';
        if(test_cases)cout<< '\n';
    }   

}