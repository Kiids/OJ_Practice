/*
n �Ŷ���ŵ�����ų�һ�У���ÿ�Ŷ���ŵ���ƴ�ֱ�������ڿ�ʼʱ��ͬʱ��һЩ����ŵ��������������ơ�
ÿ��һ�룬������ߵĶ���ŵ���ƻ��ƶ���������ڵĶ���ŵ���ơ�ͬ���أ������ұߵĶ���ŵ����Ҳ���ƶ����������Ҳ�����ڶ���ŵ���ơ�
���һ�Ŵ�ֱ�����Ķ���ŵ���Ƶ�����ͬʱ�ж���ŵ���Ƶ���ʱ����������ƽ�⣬ �ù�����Ȼ���ֲ��䡣
�����������ԣ����ǻ���Ϊһ�����ڵ��µĶ���ŵ���Ʋ�����������ڵ��»��Ѿ����µĶ���ŵ����ʩ�Ӷ��������
����һ���ַ��� dominoes ��ʾ��һ�ж���ŵ���Ƶĳ�ʼ״̬�����У�
dominoes[i] = 'L'����ʾ�� i �Ŷ���ŵ���Ʊ�������࣬
dominoes[i] = 'R'����ʾ�� i �Ŷ���ŵ���Ʊ������Ҳ࣬
dominoes[i] = '.'����ʾû���ƶ��� i �Ŷ���ŵ���ơ�
���ر�ʾ����״̬���ַ�����
ʾ�� 1��
���룺dominoes = "RR.L"
�����"RR.L"
���ͣ���һ�Ŷ���ŵ����û�и��ڶ���ʩ�Ӷ��������
ʾ�� 2��
���룺dominoes = ".L.R...LR..L.."
�����"LL.RR.LLRRLL.."
��ʾ��
n == dominoes.length
1 <= n <= 10^5
dominoes[i] Ϊ 'L'��'R' �� '.'
*/

class Solution {
public:
    string pushDominoes(string dominoes) {
        dominoes = "L" + dominoes + "R";
        int l = 0;
        string ret = "";
        for (int r = 1; r < dominoes.size(); r++) {
            if (dominoes[r] == '.')
                continue;
            if (l != 0)
                ret += dominoes[l];
        
            int mid = r - l - 1;
            if (dominoes[l] == dominoes[r])
                ret += string(mid, dominoes[l]);
            else if (dominoes[l] == 'L' && dominoes[r] == 'R')
                ret += string(mid, '.');
            else
                ret += string(mid / 2, 'R') + (mid % 2 == 1? "." : "") + string(mid / 2, 'L');
            l = r;
        }
        return ret;
    }
};
