/*
���� ��ά ƽ�������� ��ֱ�߹����ұ���������ƽ��/��ֱ �ľ��Σ�������㲢�����������θ��ǵ��������
ÿ���������� ���� ����� ���� ���������ʾ��
��һ�������������¶��� (ax1, ay1) �����϶��� (ax2, ay2) ���塣
�ڶ��������������¶��� (bx1, by1) �����϶��� (bx2, by2) ���塣
ʾ�� 1��
���룺ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2
�����45
ʾ�� 2��
���룺ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = -2, by1 = -2, bx2 = 2, by2 = 2
�����16
��ʾ��
-10^4 <= ax1, ay1, ax2, ay2, bx1, by1, bx2, by2 <= 10^4
*/

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area = (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1);

        int overlapLong = max(0, min(ax2, bx2) - max(ax1, bx1));
        int overlapWidth = max(0, min(ay2, by2) - max(ay1, by1));

        return area - overlapLong * overlapWidth;
    }
};
