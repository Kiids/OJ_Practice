/*
ȫ��ĸ�� ָ����Ӣ����ĸ����ÿ����ĸ����һ�εľ��ӡ�
����һ������СдӢ����ĸ��ɵ��ַ��� sentence �������ж�?sentence �Ƿ�Ϊ ȫ��ĸ�� ��
����ǣ����� true �����򣬷��� false ��
ʾ�� 1��
���룺sentence = "thequickbrownfoxjumpsoverthelazydog"
�����true
���ͣ�sentence ����Ӣ����ĸ����ÿ����ĸ����һ�Ρ�
ʾ�� 2��
���룺sentence = "leetcode"
�����false
��ʾ��
1 <= sentence.length <= 1000
sentence ��СдӢ����ĸ���
*/

class Solution {
public:
    bool checkIfPangram(string sentence) {
        int v[26] = {0}, x = 0;
    	for (int i = 0; i < sentence.length(); i++)
    		v[sentence[i] - 'a'] = 1;
    	for (int i = 0; i < 26; i++)
    		x += v[i];
    	return x == 26;
    }
};
