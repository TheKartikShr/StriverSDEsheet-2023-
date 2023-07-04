#include<bits/stdc++.h>

using namespace std;

bool isValidParenthesis(string expression)
{
    int n = expression.size();
    stack<char> st;
    for(int i = 0; i < n; i++){
        if(expression[i] == '(' || expression[i] == '{' || expression[i] == '['){
            st.push(expression[i]);
        }else{
            if(!st.empty()){
                char ch = st.top();
                st.pop();
                if (expression[i] == ')' && ch != '(') {
                  return false;
                }
                if (expression[i] == '}' && ch != '{') {
                  return false;
                }
                if(expression[i] == ']' && ch != '['){
                    return false;
                }
            }else{
                return false;
            }
        }
    }
    return st.empty();
}
int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		cout << (isValidParenthesis(s) == true ? "Balanced" : "Not Balanced") << endl;
	}
}