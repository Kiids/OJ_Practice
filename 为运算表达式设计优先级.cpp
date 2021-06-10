/*
����һ���������ֺ���������ַ�����Ϊ���ʽ������ţ��ı����������ȼ��������ͬ�Ľ��������Ҫ�������п��ܵ���ϵĽ������Ч��������Ű��� +, - �Լ� * ��
ʾ�� 1:
����: "2-1-1"
���: [0, 2]
����: 
((2-1)-1) = 0 
(2-(1-1)) = 2
ʾ�� 2:
����: "2*3-4*5"
���: [-34, -14, -10, -10, 10]
����: 
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
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
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
        if (v.size() == 0)
            v.push_back(stoi(expression));
        return v;
    }
};
