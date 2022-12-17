#include <bits/stdc++.h>

class Solution
{
    public:
    bool isOperator(string x)
    {
        return x == "*" || x == "+" || x == "-" || x == "/";
    }

    int evalRPN(vector<string> &tokens)
    {
        stack<string> stk;
        int index = 0;

        long long n1, n2;
        long long calc;
        char op;

        while (stk.size() > 1 || index < tokens.size())
        {
            if (!stk.empty() && isOperator(stk.top()))
            {
                op = stk.top()[0];
                stk.pop();
                n2 = stoll(stk.top());
                stk.pop();
                n1 = stoll(stk.top());
                stk.pop();

                switch (op)
                {
                    case '*':
                        calc = n1 * n2;
                        break;
                    case '+':
                        calc = n1 + n2;
                        break;
                    case '-':
                        calc = n1 - n2;
                        break;
                    case '/':
                        calc = n1 / n2;
                        break;
                }
                stk.push(to_string(calc));
            }
            else
            {
                stk.push(tokens[index++]);
            }
        }
        return stoll(stk.top());
    }
};