// 对于一个字符串，请设计一个算法，判断其是否为一个合法的括号串。 
// 给定一个字符串A和它的长度n，请返回一个bool值代表它是否为一个合法的括号串。
// 测试样例：
// "(()())",6
// 返回：true
// 测试样例：
// "()a()()",7
// 返回：false
// 测试样例：
// "()(()()",7
// 返回：false

class Parenthesis {
public:
    bool chkParenthesis(string A, int n) {
        // write code here
        stack<char> s;
        char* symbol[3] = {"()", "[]", "{}"};
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] == '(' || A[i] == '[' || A[i] == '{')
                s.push(A[i]);
            
            else if (A[i] == ')' || A[i] == ']' || A[i] == '}')
            {
                if (s.empty())
                    return false;
                
                for (int j = 0; j < 3; j++)
                {
                    if (A[i] == symbol[j][1])
                    {
                        if (s.top() == symbol[j][0])
                            s.pop();
                        else
                            return false;
                    }
                }
            }
        }
        if (s.empty())
            return true;
        return false;
    }
};
