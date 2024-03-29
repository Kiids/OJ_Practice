/*
给定一个含有数字和运算符的字符串，为表达式添加括号，改变其运算优先级以求出不同的结果。你需要给出所有可能的组合的结果。有效的运算符号包含 +, - 以及 * 。
示例 1:
输入: "2-1-1"
输出: [0, 2]
解释: 
((2-1)-1) = 0 
(2-(1-1)) = 2
示例 2:
输入: "2*3-4*5"
输出: [-34, -14, -10, -10, 10]
解释: 
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10
*/

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> v;
        for (int i = 0; i < expression.size(); i++)
        {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*')
            {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));  // 递归 
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));
                for (int& l : left)
                {
                    for (int& r : right)
                    {
                        switch(c)
                        {
                            case '+':
                                v.push_back(l + r);
                                break;
                            case '-':
                                v.push_back(l - r);
                                break;
                            case '*':
                                v.push_back(l * r);    
                                break;
                        }
                    }
                }
            }
        }
        if (v.size() == 0)  // 结果 
            v.push_back(stoi(expression));
        return v;
    }
};
