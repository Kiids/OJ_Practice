/*
һ�� ���� ��һЩ ���� �Լ�����֮��ĵ����ո���ɣ����ӵĿ�ͷ�ͽ�β�����ж���ո�
����һ���ַ������� sentences ������ sentences[i] ��ʾ���� ���� ��
���㷵�ص��������� ���ʵ������Ŀ ��
ʾ�� 1��
���룺sentences = ["alice and bob love leetcode", "i think so too", "this is great thanks very much"]
�����6
���ͣ�
- ��һ������ "alice and bob love leetcode" �ܹ��� 5 �����ʡ�
- �ڶ������� "i think so too" �ܹ��� 4 �����ʡ�
- ���������� "this is great thanks very much" �ܹ��� 6 �����ʡ�
���ԣ���������������൥�������ǵ��������ӣ��ܹ��� 6 �����ʡ�
ʾ�� 2��
���룺sentences = ["please wait", "continue to fight", "continue to win"]
�����3
���ͣ������ж����������ͬ��������
��������У��ڶ������Ӻ͵��������ӣ��Ӵ�б�壩����ͬ��Ŀ�ĵ�������
��ʾ��
1 <= sentences.length <= 100
1 <= sentences[i].length <= 100
sentences[i] ֻ����СдӢ����ĸ�� ' ' ��
sentences[i] �Ŀ�ͷ�ͽ�β��û�пո�
sentences[i] �����е����ɵ����ո������
*/

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ret = 0;
        for (auto& e : sentences)
        {
           int n = count(e.begin(), e.end(), ' ') + 1;
           ret = max(ret, n);
        }
        return ret; 
    }
};
