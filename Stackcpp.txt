
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

string infixToPostfix(string s) {
    stack<char> st; string res = "";
    for (char c : s) {
        if (isalnum(c)) res += c;
        else if (c == '(') st.push(c);
        else if (c == ')') {
            while (!st.empty() && st.top() != '(')
                res += st.top(), st.pop();
            st.pop();
        } else {
            while (!st.empty() && prec(st.top()) >= prec(c))
                res += st.top(), st.pop();
            st.push(c);
        }
    }
    while (!st.empty()) res += st.top(), st.pop();
    return res;
}

string infixToPrefix(string s) {
    reverse(s.begin(), s.end());
    for (char &c : s)
        if (c == '(') c = ')'; 
        else if (c == ')') c = '(';
    string pre = infixToPostfix(s);
    reverse(pre.begin(), pre.end());
    return pre;
}

int main() {
    string infix;
    cout << "Enter infix: ";
    cin >> infix;
    cout << "Postfix: " << infixToPostfix(infix) << "\n";
    cout << "Prefix: " << infixToPrefix(infix) << "\n";
}



