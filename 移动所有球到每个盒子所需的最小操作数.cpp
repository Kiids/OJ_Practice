/*
�� n �����ӡ�����һ������Ϊ n �Ķ������ַ��� boxes ������ boxes[i] ��ֵΪ '0' ��ʾ�� i �������� �� �ģ��� boxes[i] ��ֵΪ '1' ��ʾ�������� һ�� С��
��һ�������У�����Խ� һ�� С���ĳ�������ƶ���һ����֮���ڵĺ����С��� i �����Ӻ͵� j ���������������� abs(i - j) == 1 ��ע�⣬����ִ�к�ĳЩ�����п��ܻ���ڲ�ֹһ��С��
����һ������Ϊ n ������ answer ������ answer[i] �ǽ�����С���ƶ����� i ����������� ��С ��������
ÿ�� answer[i] ����Ҫ���ݺ��ӵ� ��ʼ״̬ ���м��㡣
ʾ�� 1��
���룺boxes = "110"
�����[1,1,3]
���ͣ�ÿ�����Ӷ�Ӧ����С���������£�
1) �� 1 �����ӣ���һ��С��ӵ� 2 �������ƶ����� 1 �����ӣ���Ҫ 1 ��������
2) �� 2 �����ӣ���һ��С��ӵ� 1 �������ƶ����� 2 �����ӣ���Ҫ 1 ��������
3) �� 3 �����ӣ���һ��С��ӵ� 1 �������ƶ����� 3 �����ӣ���Ҫ 2 ����������һ��С��ӵ� 2 �������ƶ����� 3 �����ӣ���Ҫ 1 ������������ 3 ��������
ʾ�� 2��
���룺boxes = "001011"
�����[11,8,5,4,3,4]
��ʾ��
n == boxes.length
1 <= n <= 2000
boxes[i] Ϊ '0' �� '1'
*/

class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> left(boxes.size()), right(boxes.size()), result_left(boxes.size()),  result_right(boxes.size()), result(boxes.size());
        for (int i = 1, j = boxes.size() - 2; i < boxes.size(); i++, j--)
        {
            left[i] = left[i - 1] + (boxes[i - 1] - '0');
            right[j] = right[j + 1] + (boxes[j + 1] - '0');
            result_left[i] = result_left[i - 1] + left[i];
            result_right[j] = result_right[j + 1] + right[j];
            result[i] += result_left[i];
            result[j] += result_right[j];
        }
        return result;
    }
};
