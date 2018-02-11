/*
    dp[i][j]��ʾָ��12ָ��ring[j]�ɹ�ƥ��key[0...i-1]����С�ƶ���������������min{dp[KS][0..RS-1]}
    ״̬ת�Ʒ��̣�
                dp[i][j] = min{dp[i-1][k] + min((k-j+RS)%RS,(j-k+RS)%RS)};
    ��ʼ����dp[0][0] = 0;
    ���Ӷȣ�O(KS*RS^2)
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
