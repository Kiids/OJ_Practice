/*
��дһ��������������ʱ������ֱ�ӽ���numbers = [a, b]��a��b��ֵ��
ʾ����
����: numbers = [1,2]
���: [2,1]
��ʾ��
numbers.length == 2
*/

class Solution {
public:
    vector<int> swapNumbers(vector<int>& numbers) {
        numbers[0] ^= numbers[1];
        numbers[1] ^= numbers[0];
        numbers[0] ^= numbers[1];
        return numbers;
    }
};
