#include <iostream>
#include <stack>
#include <cctype>
using namespace std;
int main(){
    int n; cin >> n; cin.ignore();
    while(n--){
        string line; getline(cin, line);
        stack<string> tokens;
        // Tokenise
        int i = 0;
        while(i < line.length()){
            string t = "";
            // ABC
            if(isalnum(line[i])){
                while(i < line.length() && (isalnum(line[i]) || line[i] == '.')){
                    t += line[i]; i++;
                }
                tokens.push(t);
            }
            // . or ..
            else if(line[i] == '.'){
                i++;
                if(i < line.length() && line[i] == '.'){
                    tokens.pop();
                    i++;
                }
            }
            // Else ignore
            else{
                i++;
            }
        }
        string path = "";
        while(!tokens.empty()){
            path = tokens.top() + path;
            tokens.pop();
            if(!tokens.empty()) path = '/' + path;
        }
        if(line[0] == '/') path = '/' + path;
        cout << path << endl;
    }
    return 0;
}