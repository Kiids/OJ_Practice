/*
����һ���������ַ��б� letters ���б���ֻ����СдӢ����ĸ�������һ��Ŀ����ĸ target������Ѱ������һ�����б����Ŀ����ĸ�����С��ĸ��
�ڱȽ�ʱ����ĸ������ѭ�����ֵġ��ٸ����ӣ�
���Ŀ����ĸ target = 'z' �����ַ��б�Ϊ letters = ['a', 'b']����𰸷��� 'a'
ʾ����
����:
letters = ["c", "f", "j"]
target = "a"
���: "c"
����:
letters = ["c", "f", "j"]
target = "c"
���: "f"
����:
letters = ["c", "f", "j"]
target = "d"
���: "f"
����:
letters = ["c", "f", "j"]
target = "g"
���: "j"
����:
letters = ["c", "f", "j"]
target = "j"
���: "c"
����:
letters = ["c", "f", "j"]
target = "k"
���: "c"
��ʾ��
letters���ȷ�Χ��[2, 10000]�����ڡ�
letters ����Сд��ĸ��ɣ����ٰ���������ͬ����ĸ��
Ŀ����ĸtarget ��һ��Сд��ĸ��
*/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for (char e : letters)
            if (e > target)
                return e;
        return letters[0];
    }
};
