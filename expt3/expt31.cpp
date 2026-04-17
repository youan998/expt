#include <iostream>
#include "mystack.h" 
#include <string>
using namespace std;
void deside(stack <char> &s, string input) {
    char topChar;
    for (char c : input) {
        if (c == '(' || c == '{' || c == '[') {
            s.push(c); 
        } else {
            if (s.peek(topChar) != SUCCESS) {
                cout << "无左括号";
                return;
            }
            if((c == ')' && topChar == '(') || 
            (c == '}' && topChar == '{') || 
            (c == ']' && topChar == '[')) {
                s.pop(topChar); 
            } else {
                cout << "括号不匹配";
                return;
            }   
        }
    }
    if (s.peek(topChar) == SUCCESS) {
        cout << "无右括号";
    } else {
        cout << "括号匹配";
    }       
}
int main() {
    stack<char> s(100), s2(100); 
    string input1 = "{[](){}}";
    cout <<"第一次测试: " << endl;  
    cout << "输入的括号字符串: " << input1 << endl;
    deside(s, input1);
    string input2 = "{[(})]";
    cout << "\n\n第二次测试: " << endl;
    cout << "输入的括号字符串: " << input2 << endl;
    deside(s2, input2);
    return 0;
}