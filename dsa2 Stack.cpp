#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <stdexcept>
#include <cstring>
using namespace std;

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(NULL) {}
    };
    Node* topNode;
public:
    Stack() : topNode(NULL) {}
    ~Stack() {
        while (!isEmpty()) pop();
    }
    void push(T value) {
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
    }
    void pop() {
        if (isEmpty()) return;
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }
    T top() {
        if (isEmpty()) throw runtime_error("Stack is empty");
        return topNode->data;
    }
    bool isEmpty() {
        return topNode == NULL;
    }
};

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

string infixToPostfix(string infix) {
    Stack<char> st;
    string result = "";
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        if (isalnum(c)) {
            result += c;
        } else if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (!st.isEmpty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            if (!st.isEmpty()) st.pop();
        } else if (isOperator(c)) {
            while (!st.isEmpty() && precedence(st.top()) >= precedence(c)) {
                if (c == '^' && st.top() == '^') break;
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.isEmpty()) {
        result += st.top();
        st.pop();
    }
    return result;
}

string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }
    string postfix = infixToPostfix(infix);
    reverse(postfix.begin(), postfix.end());
    return postfix;
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    try {
        string postfix = infixToPostfix(infix);
        string prefix = infixToPrefix(infix);
        cout << "Infix : " << infix << endl;
        cout << "Postfix : " << postfix << endl;
        cout << "Prefix : " << prefix << endl;
    } catch (exception &e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}

