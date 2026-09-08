
#include <iostream>
using namespace std;

class Stack {
    public: 
    int arr[5];
    int top;
    
    //QUESTION 1
    Stack() {
        top = -1;
    }
    
    bool isEmpty() {
        return top == -1;
    }
    
    bool isFull() {
        return top == 4;
    }
    void push(int val) {
        if(isFull()) {
            cout << "Stack overflow";
            return;
        }
        arr[++top] = val;
    }
    
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow";
            return '\0';
        }
        return arr[top--];
    }
    
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty";
            return -1;
        }
        return arr[top];
    }
    
    void display() {
        if (isEmpty()) {
            cout << "Stack underflow";
        }
        for (int i = top; i >= 0; i--) {
            cout << arr[i];
        }
    }
    
    
    //QUESTION 2
    void reverse(string s) {
        for (int i = 0; i < s.length(); i++) {
            push(s[i]);
        }
        for (int i = 0; i < s.length(); i++) {
            cout << pop();
        }
    }
    
    
    //QUESTION 3
    bool validParantheses(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                push(s[i]);
            }
            if (s[i] == ')') {
                if (isEmpty() || peek() != '(') {
                    return false;
                }
                pop();
            }
            if (s[i] == ']') {
                if (isEmpty() || peek() != '[') {
                    return false;
                }
                pop();
            }
            if (s[i] == '}') {
                if (isEmpty() || peek() != '{') {
                    return false;
                }
                pop();
            }
        }
        
        if (!isEmpty()) {
            return false;
        }
        return true;
    }
    
    
    
    //QUESTION 4 
    int precedence(char op) {
        if (op == '^')
            return 3;
        if (op == '*' || op == '/')
            return 2;
        if (op == '+' || op == '-')
            return 1;
        return 0;
    }
    
    string infixToPostfix(string s) {
        Stack st;
        string result = "";
        s = "(" + s + ")";

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            
            if (ch >= 'A' && ch <= 'Z' ||
                ch >= 'a' && ch <= 'z' ||
                ch >= '0' && ch <= '9') {
                result += ch;
            }
            
            else if (ch == '(') {
                st.push(ch);
            }
            else if (ch == ')') {
                while (!st.isEmpty() && st.peek() != '(') {
                    result += st.peek();
                    st.pop();
                }
                st.pop();
            }
            else {
                while(!st.isEmpty() && precedence(st.peek()) >= precedence(ch)) {
                    result += st.peek();
                    st.pop();
                }
                st.push(ch);
            }
        }
        return result;
    }
    
    //QUESTION 5
    int evaluatePostfix(string s) {
        Stack st;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
        
            if (ch >= '0' && ch <= '9') {
                st.push(ch - '0');
            }
            else {
                int a = st.pop();
                int b = st.pop();
                
                if (ch == '+') {
                    st.push(b + a);
                }
                else if (ch == '-') {
                    st.push(b - a);
                }
                else if (ch == '/') {
                    st.push(b / a);
                }
                else if (ch == '*') {
                    st.push(b * a);
                }
               
            }
        }
        return st.pop();
    }
     
};
int main()
{
    Stack s;
    s.validParantheses("())");
    // s.reverse("Data");
}