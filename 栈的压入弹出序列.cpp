// ���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳��
// ����ѹ��ջ���������־�����ȡ���������1,2,3,4,5��ĳջ��ѹ��˳������4,5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У�
// ��4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С���ע�⣺���������еĳ�������ȵģ�
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        // ����ջԪ�ظ�����ͬ
        if (pushV.size() != popV.size())
            return false;
        
        int pushi = 0, popi = 0;
        stack<int> s;
        
        while (pushi < popV.size())
        {
            // ���sΪ�ջ���ջ��Ԫ�����ջԪ�ز���ȣ���ջ
            while (s.empty() || s.top() != popV[pushi])
            {
                if (popi < pushV.size())
                    s.push(pushV[popi++]);
                else
                    return false;
            }
            
            // ��ջ��Ԫ����ȣ���ջ
            s.pop();
            pushi++;
        }
        
        return true;
    }
};
