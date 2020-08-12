/*
����һ������  f(x, y) ��һ��Ŀ���� z��������㷽�� f(x,y) == z ���п��ܵ������� ���� x �� y��
�����������ϸ񵥵��ģ�Ҳ����˵��
f(x, y) < f(x + 1, y)
f(x, y) < f(x, y + 1)
�����ӿڶ������£�
interface CustomFunction {
public:
  // Returns positive integer f(x, y) for any given positive integer x and y.
  int f(int x, int y);
}
��������Զ�����ԣ�������������� function_id ��һ��Ŀ���� z ��Ϊ���룬���� function_id ��ʾһ�����غ����б��е�һ��������ţ���Ŀֻ��������б��е� 2 ��������  
����Խ����������� ������� ������˳�򷵻ء�
ʾ�� 1��
���룺function_id = 1, z = 5
�����[[1,4],[2,3],[3,2],[4,1]]
���ͣ�function_id = 1 ��ʾ f(x, y) = x + y
ʾ�� 2��
���룺function_id = 2, z = 5
�����[[1,5],[5,1]]
���ͣ�function_id = 2 ��ʾ f(x, y) = x * y
��ʾ��
1 <= function_id <= 9
1 <= z <= 100
��Ŀ��֤ f(x, y) == z �Ľ⴦�� 1 <= x, y <= 1000 �ķ�Χ�ڡ�
�� 1 <= x, y <= 1000 ��ǰ���£���Ŀ��֤ f(x, y) ��һ�� 32 λ�з���������
*/

/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> ret;
        int x = 1;
        int y = 1;
        while (x <= 1000)
        {
            if (customfunction.f(x,1) > z)
                break;
            
            if (customfunction.f(x, 1000) < z)
            {
                x++;
                continue;
            }
            int xx = 1, yy = 1000;
            int mid;
            while (xx < yy)
            {
                mid = xx + (yy - xx) / 2;
                int mv = customfunction.f(x, mid);
                if (mv == z)
                    ret.push_back(vector<int>{x, mid});
                
                if (mid == xx)
                    break;
                
                if (mv < z)
                    xx = mid;
                else
                    yy = mid;
            }
            x++;
        }
        return ret;
    }
};
/*
x����ʱ��y����f���ӡ�y����ʱ��x����f���ӡ�
x��1��1000ʱ����y�ö��֣�ȷ��f��ֵ��
���f(x,1) > zʱ���������к��ʵģ�x��y��ֵ���㷨������
���f(x,1000) < zʱ��x����һ��ֵ��
��f(x,1) <= z <= f(x,1000)ʱ����y��(1,1000)�ж��֡�
*/
