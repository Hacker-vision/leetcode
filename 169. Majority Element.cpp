/*
	查找众数
	方法一：分治 T(n) = 2T(n/2) + O(n) O(nlgn)
	方法二：排序
	方法三：map
	方法四：Hash
	方法五：出现次数最多的数，用一个中间变量表示这个数
*/
class Solution {
public:
    int find_major(int l,int r){
        if(l == r) return data[l];
        if(l < r){
            int m = l + (r-l)/2;
            int num1 = find_major(l,m);
            int num2 = find_major(m+1,r);
            if(num1 == num2) return num1;
            int cnt1 = 0,cnt2 = 0;
            for(int i = l;i <= r;++ i){
                if(data[i] == num1) cnt1++;
                else if(data[i] == num2) cnt2++;
            }
            if(cnt1 > cnt2) return num1;
            return num2;
        }
    }
    int majorityElement(vector<int>& nums) {
        data = nums;
        int l = 0,r = nums.size() - 1;
        return find_major(l,r);
    }
private:
    vector<int>data;
};