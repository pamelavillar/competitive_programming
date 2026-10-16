// DO YOUR OWN HW
// HOW TO SOLVE
// 

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm> 
using namespace std;


int main(){
    int t = 1;
    cin>>t;
    for ( int k = 0; k < t ; k++){
        map<string,int> courses;
        int n_c;
        cin>>n_c;
        for(int i = 0; i < n_c; i++){
            string course;
            int days;
            cin>>course>>days;

            courses[course] = days;
        }

        int due; cin >> due;

        string course_due; cin >> course_due;

        string result;
        auto it = courses.find(course_due);
        if(it != courses.end()){
            if(it->second <= due) result = "Yesss";
            else if (it->second <= due + 5 ) result = "Late";
            else result = "Do your own homework!";

        } else result = "Do your own homework!";
       
       

        cout<<"Case "<<k+1<<": "<< result<< "\n";
    }
}