class Solution {
public:
    bool judge(string s){
        if(s.size() > 1 && s[0] == '0') return false;
        int x = atoi(s.c_str());
        if(x<=255) return true;
        return false;
    }
    void dfs(string s,string t,int cnt){
        if(cnt == 4 && t == ""){
            ans.push_back(s);
        	return;
        }
        string x;
        for(int i = 0;i < t.size();++ i){
            x = x + t[i];
            if(judge(x) == false) break;
            if(s == "") dfs(t.substr(0,i+1),t.substr(i+1),cnt+1);
            else dfs(s+"."+t.substr(0,i+1),t.substr(i+1),cnt+1);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        ans.clear();
        dfs("",s,0);
        return ans;
    }
private:
    vector<string>ans;
};
