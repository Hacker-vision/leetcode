/*
    通过前缀和转化成重要逆序对问题
    逆序对：统计a[j]-a[i]<0的个数
    重要逆序对：统计a[j]-2*a[i]<0的个数
    推广：统计lower<=a[j]-a[i]<=upper | 实现方式是a[j]-a[i]<=upper的个数减去a[j]-a[i]<lower的个数

    发现：lower<=S(i,j)=sum[j]-sum[i-1]<=upper可以转换成元素为前缀和为sum[i]的数组的推广逆序对的个数，注意要在该数组开头加一个元素0；
    T(n) = 2T(n/2) + O(n) => O(nlogn)
*/
class Solution {
public:
    int merge(vector<long long>&a,int l,int m,int r){
        vector<long long>b;
        int i = l,j = m+1,cnt=0;
        while(i<=m&&j<=r){
            if(a[i] > a[j]){
               b.push_back(a[j++]);
            }
            else {
                b.push_back(a[i++]);
            }
        }
        while(i<=m) b.push_back(a[i++]);
        while(j<=r) b.push_back(a[j++]);
        //count a[j]-a[i]<=upper
        i = l,j = m+1;
        int cnt1=0;
        while(i<=m&&j<=r){
            if(a[j]-a[i]<=upp){
               cnt1 += (m-i+1);
               j++;
            }
            else {
               i++;
            }
        }
        //count a[j]-a[i]<lower
        i = l,j = m+1;
        int cnt2=0;
        while(i<=m&&j<=r){
            if(a[j]-a[i]<low){
               cnt2 += (m-i+1);
               j++;
            }
            else {
               i++;
            }
        }
        int top = 0;
        for(int k = l;k <= r;++ k) a[k] = b[top++];
        return cnt1-cnt2;//lower<=a[j]-a[i]<=upper
    }
    int mergesort(vector<long long>&a,int l,int r){
        if(l == r) return 0;
        if(l < r){
           int ans = 0;
           int m = l + (r-l)/2;
           ans += mergesort(a,l,m);
           ans += mergesort(a,m+1,r);
           ans += merge(a,l,m,r);
           return ans;
        }
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long>dp(n+1,0);
        for(int i = 1;i <= n;++ i){
            dp[i] = dp[i-1] + nums[i-1];
        }
        low = lower,upp = upper;
        return mergesort(dp,0,n);
    }
private:
    int low,upp;
};
