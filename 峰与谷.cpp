/*
��һ�����������У����塱�Ǵ��ڻ��������������Ԫ�أ���Ӧ�أ����ȡ���С�ڻ��������������Ԫ�ء����磬������{5, 8, 6, 2, 3, 4, 6}�У�{8, 6}�Ƿ壬 {5, 2}�ǹȡ����ڸ���һ���������飬�������鰴����ȵĽ���˳������
ʾ��:
����: [5, 3, 1, 2, 3]
���: [5, 1, 3, 2, 3]
��ʾ��
nums.length <= 10000
*/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> v = nums;
        sort(v.begin(), v.end(), greater<int>());
        int peek = 0, valley = nums.size() / 2;
        if (nums.size() & 0x1)
            valley++;
        for (int i = 0; i < nums.size(); i += 2)
        {
            if (peek < valley)
                nums[i] = v[peek++];
        }
        for (int i = 1; i < nums.size(); i += 2)
        {
            if (valley < nums.size())
                nums[i] = v[valley++];
        }
    }
};
