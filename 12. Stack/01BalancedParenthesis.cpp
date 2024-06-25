#include <bits/stdc++.h>
using namespace std;

bool isParenthesis(string s){
    stack <char> st;
    for(char c: s){
        if (c == '(' || c=='{' || c=='['){
            st.push(c);
        }
        else if(c == ')' || c=='}' || c==']'){

            if(st.empty()) return false;
            
            char top=st.top();
            st.pop(); //Yeh line stack ke top element ko hata deti hai kyunki ab humne usse top variable mein store kar liya hai.
            
            if ((c == ')' && top != '(') || ///Agar c closing parenthesis ')' hai, to top opening parenthesis '(' hona chahiye.
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }         
        } 
    }
    return st.empty();  //Agar loop ke baad stack empty hai, iska matlab saare opening parentheses ko unka matching closing parenthesis mil gaya hai.
                        //Agar stack empty nahi hai, iska matlab kuch opening parentheses aise hain jinhe closing parenthesis nahi mila, aur expression balanced nahi hai.
}

int main() {
    string s = "(({})){}";
    if (isParenthesis(s)) {
        cout << "It's valid" << endl;
    } 
    else {
        cout << "It's invalid" << endl;
    }
    return 0;
}