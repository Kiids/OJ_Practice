/*
����һ������ coordinates ������һ���ַ�������ʾ��������������һ�����ӵ����ꡣ��ͼ�ǹ�����������ʾ��ͼ��
����������ӵ���ɫ�ǰ�ɫ�����㷵�� true������Ǻ�ɫ���뷵�� false ��
��������һ�������������������һ�����ڵĸ��ӡ������һ���ַ�����ĸ���ڶ����ַ������֡�
ʾ�� 1��
���룺coordinates = "a1"
�����false
���ͣ�����ͼ������ʾ��"a1" ����ĸ����Ǻ�ɫ�ģ����Է��� false ��
ʾ�� 2��
���룺coordinates = "h3"
�����true
���ͣ�����ͼ������ʾ��"h3" ����ĸ����ǰ�ɫ�ģ����Է��� true ��
ʾ�� 3��
���룺coordinates = "c7"
�����false
��ʾ��
coordinates.length == 2
'a' <= coordinates[0] <= 'h'
'1' <= coordinates[1] <= '8'
*/

class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int x = coordinates[0] - 'a';
        int y = coordinates[1] - '1';
        return (x + y) % 2 == 1;
    }
};
