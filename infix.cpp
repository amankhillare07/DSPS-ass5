#include <iostream>
#include <stack>
#include <string>
using namespace std;

int prec(char op)
{  
if (op == '+' || op == '-')
 return 1;
if (op == '*' || op == '/')
return 2;
return 0;
}
string infixToPostfix(string infix)
{
stack<char> st;
string postfix = "";
for (int i = 0; i < infix.length(); i++) {
char c = infix[i];

if (isalnum(c))
postfix += c;

else if (c == '(')
st.push('(');


else if (c == ')') {
while (st.top() != '(') {
postfix += st.top();
 st.pop();
 }
st.pop();
 }

      
else {
while (!st.empty()
                   && prec(c)
<= prec(st.top())) {
 postfix += st.top();
st.pop();
}
 st.push(c);
}
}

while (!st.empty()) {
postfix += st.top();
st.pop();
    }

    return postfix;
}

int main()
{
string infix_exp;
 cout<<"enter the infix expression" <<endl;
 cin>>infix_exp;
 

    cout << "Postfix Expression: " << infixToPostfix(infix_exp)<<endl; 
       
    return 0;
}

