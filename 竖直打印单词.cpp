/*
����һ���ַ��� s�����㰴�յ����� s �еĳ���˳������ȫ����ֱ���ء�
����Ӧ�����ַ����б����ʽ���أ���Ҫʱ�ÿո�λ�������β���Ŀո���Ҫɾ����������β��ո񣩡�
ÿ������ֻ�ܷ���һ���ϣ�ÿһ����Ҳֻ����һ�����ʡ�
ʾ�� 1��
���룺s = "HOW ARE YOU"
�����["HAY","ORO","WEU"]
���ͣ�ÿ�����ʶ�Ӧ����ֱ��ӡ�� 
 "HAY"
 "ORO"
 "WEU"
ʾ�� 2��
���룺s = "TO BE OR NOT TO BE"
�����["TBONTB","OEROOE","   T"]
���ͣ���Ŀ����ʹ�ÿո�λ�������������ĩβ���ֿո�
"TBONTB"
"OEROOE"
"   T"
ʾ�� 3��
���룺s = "CONTEST IS COMING"
�����["CIC","OSO","N M","T I","E N","S G","T"]
��ʾ��
1 <= s.length <= 200
s ������дӢ����ĸ��
��Ŀ���ݱ�֤��������֮��ֻ��һ���ո�
*/

class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> v(200);
        int m = 0, n = 0;
        istringstream words(s);
        string w;
        while (words >> w)
        {
            m = max(m, (int)w.size());
            for (int i = 0; i < w.size(); i++)
            {
                while (v[i].size() != n)
                    v[i] += ' ';
                v[i] += w[i];
            }
            n++;
        }
        v.resize(m);
        return v;
    }
};
