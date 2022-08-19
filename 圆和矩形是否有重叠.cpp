/*
����һ���� (radius, x_center, y_center) ��ʾ��Բ��һ����������ƽ�еľ��� (x1, y1, x2, y2)������ (x1, y1) �Ǿ������½ǵ����꣬(x2, y2) �����Ͻǵ����ꡣ
���Բ�;������ص��Ĳ��֣����㷵�� True �����򷵻� False ��
���仰˵���������Ƿ� ���� �� (xi, yi) ��������Բ��Ҳ�ھ����ϣ����߶����������ڱ߽��ϵ��������
ʾ�� 1��
���룺radius = 1, x_center = 0, y_center = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1
�����true
���ͣ�Բ�;����й����� (1,0) 
ʾ�� 2��
���룺radius = 1, x_center = 0, y_center = 0, x1 = -1, y1 = 0, x2 = 0, y2 = 1
�����true
ʾ�� 3��
���룺radius = 1, x_center = 1, y_center = 1, x1 = -3, y1 = -3, x2 = 3, y2 = 3
�����true
ʾ�� 4��
���룺radius = 1, x_center = 1, y_center = 1, x1 = 1, y1 = -3, x2 = 2, y2 = -1
�����false
��ʾ��
1 <= radius <= 2000
-10^4 <= x_center, y_center, x1, y1, x2, y2 <= 10^4
x1 < x2
y1 < y2
*/

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
    	// ������������ֱ������Ϊ0
        int dx = x1 > xCenter ? (x1 - xCenter) : (x2 < xCenter ? xCenter - x2 : 0);
        int dy = y1 > yCenter ? (y1 - yCenter) : (y2 < yCenter ? yCenter - y2 : 0);
        return dx * dx + dy * dy <= radius * radius;
    }
};

// ��������������ĵ��Բ�ĵľ����Ƿ�С�ڵ��ڰ뾶
