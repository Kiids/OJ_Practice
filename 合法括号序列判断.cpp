// ����һ���ַ����������һ���㷨���ж����Ƿ�Ϊһ���Ϸ������Ŵ��� 
// ����һ���ַ���A�����ĳ���n���뷵��һ��boolֵ�������Ƿ�Ϊһ���Ϸ������Ŵ���
// ����������
// "(()())",6
// ���أ�true
// ����������
// "()a()()",7
// ���أ�false
// ����������
// "()(()()",7
// ���أ�false

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
