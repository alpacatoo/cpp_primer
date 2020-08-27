#include <stack>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
int main()
{
    string expr{"11+2*5+(14*2+3)*6"};
    vector<string> v;
    //split
    string::size_type front_pos = 0;
    string::size_type back_pos = expr.find_first_of("-+*/()");
    while (string::npos != back_pos)
    {
        if (front_pos != back_pos)  // number
            v.push_back(expr.substr(front_pos, back_pos - front_pos));
        v.push_back(expr.substr(back_pos, 1));  // operator
        front_pos = back_pos + 1;
        back_pos = expr.find_first_of("-+*/()", front_pos);
    }
    v.push_back(expr.substr(front_pos));
    //打印分段
    std::cout << "split v: " << endl;
    for (auto s : v)
        std::cout << s << endl;

    // back format
    stack<string> stk;
    vector<string> v_back;
    for (auto s : v)
    {
        if (s.size() > 1 || string::npos == s.find_first_of("-+*/()"))
        {   //操作数
            v_back.push_back(s);
        }
        else if (s == ")")
        {
            while (stk.top() != "(")
            {
                
                v_back.push_back(stk.top());
                stk.pop();
            }
            stk.pop();
        }
        else
        {   // "-+*/("
            while (!stk.empty())
            {
                if ((s == "-" || s == "+") &&
                    (stk.top() == "*" || stk.top() == "/"))
                {   //当前字符优先级低于栈顶元素，出栈
                    v_back.push_back(stk.top());
                    stk.pop();
                }
                else
                {
                    break;
                }
            }
            //出栈后，将字符压入
            stk.push(s);
        }
    }
    while (!stk.empty())
    {
        v_back.push_back(stk.top());
        stk.pop();
    }
    //打印后缀
    std::cout << "back v: " << endl;
    for (auto s : v_back)
        std::cout << s << endl;
    // calculate
    stack<double> stk_sum;
    for (auto s : v_back)
    {
        if (s.size() > 1 || string::npos == s.find_first_of("-+*/()"))
        {   //操作数
            stk_sum.push(stod(s));
        }
        else
        {
            auto op1 = stk_sum.top();
            stk_sum.pop();
            auto op2 = stk_sum.top();
            stk_sum.pop();
            switch (s[0])
            {
            case '-': stk_sum.push(op2 - op1); break;
            case '+': stk_sum.push(op2 + op1); break;
            case '*': stk_sum.push(op2 * op1); break;
            case '/': stk_sum.push(op2 / op1); break;
            default: break;
            }
        }
    }
    std::cout << "Result: " << stk_sum.top() << endl;
 
}