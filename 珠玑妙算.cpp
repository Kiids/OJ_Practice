/*
����������Ϸ��the game of master mind�����淨���¡�
�������4���ۣ�ÿ���۷�һ������ɫ�����Ǻ�ɫ��R������ɫ��Y������ɫ��G������ɫ��B�������磬�����������RGGB 4�֣���1Ϊ��ɫ����2��3Ϊ��ɫ����4Ϊ��ɫ������Ϊ�û�������ͼ�³���ɫ��ϡ�����ȷ�������ܻ��YRGB��Ҫ�ǲ¶�ĳ���۵���ɫ������һ�Ρ����С���Ҫ��ֻ�¶���ɫ����λ�´��ˣ�����һ�Ρ�α���С���ע�⣬�����С��������롰α���С���
����һ����ɫ���solution��һ���²�guess����дһ�����������ز��к�α���еĴ���answer������answer[0]Ϊ���еĴ�����answer[1]Ϊα���еĴ�����
ʾ����
���룺 solution="RGBY",guess="GGRR"
����� [1,1]
���ͣ� ����1�Σ�α����1�Ρ�
��ʾ��
len(solution) = len(guess) = 4
solution��guess������"R","G","B","Y"��4���ַ�
*/

class Solution {
public:
    vector<int> masterMind(string solution, string guess) {
        map<char, int> m;
        int a = 0, b = 0;
        for (int i = 0; i < solution.size(); i++)
        {
            if (solution[i] == guess[i])
                a++;
            if (m.count(solution[i]))
                m[solution[i]]++;
            else
                m[solution[i]]=1;
        }
        for (int i = 0; i < solution.size(); i++)
        {
            if (m.count(guess[i]) && m[guess[i]]>0)
            {
                b++;
                m[guess[i]]--;
            }
        }
        return vector<int>{a, b - a};
    }
};
