/*
ʵ��һ���㷨��ȷ��һ���ַ��� s �������ַ��Ƿ�ȫ����ͬ��
ʾ�� 1��
����: s = "leetcode"
���: false 
ʾ�� 2��
����: s = "abc"
���: true
���ƣ�
0 <= len(s) <= 100
����㲻ʹ�ö�������ݽṹ����ܼӷ֡�
*/

// ���ñ������ 
class Solution {
public:
    bool isUnique(string astr) {
        vector<int> v(26, 0);
        for (int i = 0; i < astr.size(); i++)
        {
            if (v[astr[i] - 'a'])
                return false;
            v[astr[i] - 'a']++;
        }
        return true;
    }
};

// �������������ж�
class Solution {
public:
    bool isUnique(string astr) {
        sort(astr.begin(),astr.end());
        for (int i=1;i<astr.size();i++) {
            if (astr[i]==astr[i-1]) {
                return 0;
            }
        }
        return 1;
    }
};

// unordered_map��ϣ�� 
class Solution {
public:
    bool isUnique(string astr) {
        unordered_map<char,int> r;
        for(char s:astr)
        {
            r[s]++;
            if(r[s] >= 2){
                return false;
            }
        }
        return true;
    }
};

// λ����
// ���ö������ݽṹ ���ʹ��λ���㷽��
// int32λ���Ը���26����ĸ��ĳ��ȣ����á�
// ��������ڴ� 
class Solution {
public:
    bool isUnique(string astr) {
        char start = 'a';
        int memo = 0x0;
        bool isUnique = true;
        for (auto cr : astr) {
            unsigned int pos = cr - start;
            if ((memo & (0x01 << pos)) == 0) {
                memo = (0x01 << pos) | memo;
            } else {
                isUnique = false;
                break;
            }
        }
        return isUnique;
    }
};

���ߣ�tuo-yang-he-tang-he-gan-suan-3
���ӣ�https://leetcode-cn.com/problems/is-unique-lcci/solution/jian-dan-wei-yun-suan-memo-by-tuo-yang-he-tang-he-/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
