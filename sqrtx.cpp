class Solution {
public:
    int sqrt(int x) {
        long long l = 0,r = x,m;
        while(l <= r){
        	m = l + (r-l)/2;
            if(m*m <= x) l = m + 1;
            else r = m - 1;
        }
        return l - 1;
    }
};