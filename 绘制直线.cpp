/*
����ֱ�ߡ��и���ɫ��Ļ�洢��һ��һά�����У�ʹ��32���������ؿ��Դ����һ�� int ���Ļ���Ϊw����w�ɱ�32��������һ�� int ����ֲ��������ϣ�����Ļ�߶ȿ������鳤�ȼ���Ļ�������ó�����ʵ��һ�����������ƴӵ�(x1, y)����(x2, y)��ˮƽ�ߡ�
��������ĳ��� length����� w���Ա���Ϊ��λ����ֱ�߿�ʼλ�� x1������Ϊ��λ����ֱ�߽���λ�� x2������Ϊ��λ����ֱ����������?y�����ػ��ƹ�������顣
ʾ��1:
 ���룺length = 1, w = 32, x1 = 30, x2 = 31, y = 0
 �����[3]
 ˵�����ڵ�0�еĵ�30λ����31Ϊ��һ��ֱ�ߣ���Ļ��ʾΪ[0b000000000000000000000000000000011]
ʾ��2:
 ���룺length = 3, w = 96, x1 = 0, x2 = 95, y = 0
 �����[-1, -1, -1]
*/

class Solution {
public:
    vector<int> drawLine(int length, int w, int x1, int x2, int y) {
        vector<int> pixel(length, 0);
        int width = w / 32;
        int height = length / width;
        
        int begin = width * y + x1 / 32;
        int end = width * y + x2 / 32;

        for (int i = begin; i <= end; i++)
        {
            pixel[i] = -1;
        }
        pixel[begin] = pixel[begin] & unsigned(-1) >> (x1 % 32);
        pixel[end] = pixel[end] & unsigned(-1) << (32 - x2 % 32 - 1);

        return pixel;
    }
};
