/*
���������ڶ�ȡһ��������ÿ��һ��ʱ�䣬��ϣ�����ҳ����� x ����(С�ڻ���� x ��ֵ�ĸ���)����ʵ�����ݽṹ���㷨��֧����Щ������Ҳ����˵��
ʵ�� track(int x) ������ÿ����һ�����ֶ�����ø÷�����
ʵ�� getRankOfNumber(int x) ����������С�ڻ���� x ��ֵ�ĸ�����
ע�⣺�������ԭ�������Ķ�
ʾ��:
����:
["StreamRank", "getRankOfNumber", "track", "getRankOfNumber"]
[[], [1], [0], [0]]
���:
[null,0,null,1]
��ʾ��
x <= 50000
track �� getRankOfNumber �����ĵ��ô����������� 2000 ��
*/

class StreamRank {
private:
    vector<int> nums;
public:
    StreamRank() {
        
    }
    
    void track(int x) {
        stack<int> tmp;
        while (nums.size() && nums.back() > x)
            tmp.push(nums.back()), nums.pop_back();
        nums.push_back(x);
        while (tmp.size()) nums.push_back(tmp.top()), tmp.pop(); 
    }
    
    int getRankOfNumber(int x) {
        if (nums.empty() || nums[0] > x)
            return 0;
        if (nums.back() <= x)
            return nums.size();
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if (nums[mid] <= x)
                l = mid;
            else
                r = mid - 1;
        }
        return r + 1;
    }
};

/**
 * Your StreamRank object will be instantiated and called as such:
 * StreamRank* obj = new StreamRank();
 * obj->track(x);
 * int param_2 = obj->getRankOfNumber(x);
 */
