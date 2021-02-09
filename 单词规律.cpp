/*
����һ�ֹ��� pattern ��һ���ַ��� str ���ж� str �Ƿ���ѭ��ͬ�Ĺ��ɡ�
����� ��ѭ ָ��ȫƥ�䣬���磬 pattern ���ÿ����ĸ���ַ��� str �е�ÿ���ǿյ���֮�������˫�����ӵĶ�Ӧ���ɡ�
ʾ��1:
����: pattern = "abba", str = "dog cat cat dog"
���: true
ʾ�� 2:
����:pattern = "abba", str = "dog cat cat fish"
���: false
ʾ�� 3:
����: pattern = "aaaa", str = "dog cat cat dog"
���: false
ʾ�� 4:
����: pattern = "abba", str = "dog dog dog dog"
���: false
˵��:
����Լ��� pattern ֻ����Сд��ĸ�� str �������ɵ����ո�ָ���Сд��ĸ��    
*/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> map;
        unordered_map<string, char> rmap;
        stringstream ss(s);
        string str;
        for (char c : pattern)
        {
            if (!(ss >> str) || (map.count(c) == 1 && map[c] != str) || (rmap.count(str) == 1 && rmap[str] != c))
                return false;
            map[c] = str;
            rmap[str] = c;
        }
        return (ss >> str) ? false : true;
    }
};

//��������map����ֹ[aaaa]��[cat dog dog cat]��[abba]��[cat cat cat cat]ʱ���true
//��stringstream�Զ��������
//�жϣ�!(ss >> s)�ж�pattern�����Ƿ����str���ȣ��ҽ�ss�������ַ�����ֵ��s
//�жϣ�(map.count(c) == 1 && map[c] != s) || (rmap.count(s) == 1 && rmap[s] != c)) ���ж��Ƿ�ƥ��
//�жϣ�(ss >> s) ? false : true �ж�str�����Ƿ����pattern����
