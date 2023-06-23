#include<bits/stdc++.h>
bool isValidParenthesis(string expression)
{
    // Write your code here.
    int n=expression.length();
    stack<char> st;
    for(int i=0;i<n;i++)
    {
        if(expression[i]=='{'|| expression[i]=='('|| expression[i]=='[')
          st.push(expression[i]);
        else
        {
            if(expression[i]=='}')
            {
                if(!st.empty() && st.top()=='{')
                  st.pop();
                else
                  return false;
            }
            if(expression[i]==')')
            {
                if(!st.empty() && st.top()=='(')
                  st.pop();
                else
                  return false;
            }
            if(expression[i]==']')
            {
                if(!st.empty() && st.top()=='[')
                  st.pop();
                else
                  return false;
            }
        }
    }

    if(!st.empty())
      return false;
    return true;
}
