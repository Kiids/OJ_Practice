/*
�ַ���S�� T ֻ����Сд�ַ�����S�У������ַ�ֻ�����һ�Ρ�
S �Ѿ�����ĳ�ֹ����������������Ҫ����S�е��ַ�˳���T�������򡣸������˵�����S��x��y֮ǰ���֣���ô���ص��ַ�����xҲӦ������y֮ǰ��
��������һ�ַ����������ַ���T��
ʾ��:
����:
S = "cba"
T = "abcd"
���: "cbad"
����: 
S�г������ַ� "a", "b", "c", ���� "a", "b", "c" ��˳��Ӧ���� "c", "b", "a". 
���� "d" û����S�г���, �����Է���T������λ��. "dcba", "cdba", "cbda" ���ǺϷ��������
ע��:
S����󳤶�Ϊ26������û���ظ����ַ���
T����󳤶�Ϊ200��
S��Tֻ����Сд�ַ���
*/

class Solution {
public:
    string customSortString(string order, string str) {
        int index = 0;
        for (const auto& e : order)
            for (int i = 0; i < str.size(); i++)
                if (e == str[i])
                    swap(str[i], str[index++]);
        return str;
    }
};
