/*
    dp[i][j]表示指针12指向ring[j]成功匹配key[0...i-1]的最小移动次数，最终所求min{dp[KS][0..RS-1]}
    状态转移方程：
                dp[i][j] = min{dp[i-1][k] + min((k-j+RS)%RS,(j-k+RS)%RS)};
    初始化：dp[0][0] = 0;
    复杂度：O(KS*RS^2)
*/
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int KS = key.size(),RS = ring.size();
        vector<vector<int> >dp(KS+1,vector<int>(RS,0x3f3f3f3f));
        //for(int i = 0;i < RS;++ i) dp[0][i] = 0;
        dp[0][0] = 0;
        for(int i = 1;i <= KS;++ i){
            for(int j = 0;j < RS;++ j){
                if(ring[j] == key[i-1]){
                    for(int k = 0;k < RS;++ k) {
                        dp[i][j] = min(dp[i][j],dp[i-1][k] + min((k-j+RS)%RS,(j-k+RS)%RS));
                    }
                }
            }
        }
        int ans = INT_MAX;
        for(int i = 0;i < RS;++ i){
            if(ans > dp[KS][i]) ans = dp[KS][i];
        }
        return ans + KS;
    }
};
