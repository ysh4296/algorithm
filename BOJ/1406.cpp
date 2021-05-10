#include<iostream>
#include<string>
#include<stack>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; 
    string s;
    cin >> s;
    cin >> n;
    stack<char> s1,s2;
    //stack<char> s1(s.begin(),s.end());
    for(auto &x:s){
        s1.push(x);
    }
    while(n--){
        char cmd;
        cin >> cmd;
        
        if(cmd=='L'){
            if(!(s1.empty())){
                s2.push(s1.top());
                s1.pop(); 
            }
            
        } 
        else if(cmd=='D'){
            if(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }
        else if(cmd=='B'){
            if(!(s1.empty())){
                s1.pop();
            }
            
        }
        else if(cmd=='P'){
            char x;
            cin >> x;
            s1.push(x);
        }    
    }
    while(!(s1.empty())){
        s2.push(s1.top());
        s1.pop();
    } 
    while(!(s2.empty())){
        cout << s2.top();
        s2.pop();
    }
    return 0;     
}
