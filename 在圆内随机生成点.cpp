/*
����Բ�İ뾶��Բ�ĵ�λ�ã�ʵ�ֺ��� randPoint ����Բ�в�����������㡣
ʵ�� Solution ��:
Solution(double radius, double x_center, double y_center) ��Բ�İ뾶 radius ��Բ�ĵ�λ�� (x_center, y_center) ��ʼ������
randPoint() ����Բ�ڵ�һ������㡣Բ���ϵ�һ�㱻��Ϊ��Բ�ڡ�����Ϊ���鷵�� [x, y] ��
ʾ�� 1��
����: 
["Solution","randPoint","randPoint","randPoint"]
[[1.0, 0.0, 0.0], [], [], []]
���: [null, [-0.02493, -0.38077], [0.82314, 0.38945], [0.36572, 0.17248]]
����:
Solution solution = new Solution(1.0, 0.0, 0.0);
solution.randPoint ();//����[-0.02493��-0.38077]
solution.randPoint ();//����[0.82314,0.38945]
solution.randPoint ();//����[0.36572,0.17248]
��ʾ��
0 < radius <= 10^8
-10^7 <= x_center, y_center <= 10^7
randPoint ��౻���� 3 * 10^4 ��
*/

class Solution {
    double r, x, y;
public:
    Solution(double radius, double x_center, double y_center) {
        r = radius, x = x_center, y = y_center;
    }
    
    vector<double> randPoint() {
        while(true)
        {   //��ʼֵΪ�����ε����½� + ���ֵ
            double randx = x - r + (double(rand()) / RAND_MAX * r) * 2;
            double randy = y - r + (double(rand()) / RAND_MAX * r) * 2;
            double dis = sqrt((randx - x) * (randx - x) + (randy - y) * (randy - y));
            if (dis <= r)
                return {randx, randy};
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */

