/*
    三个操作数的运算：a op b "+/-/*" c
    if(+) a op b + c = (a op b) + c
    if(-) a op b - c = (a op b) + c
    if(*) a op b * c =  a op (b * c)
    这题注意不能加括号，所以只能dfs暴力，注意前导0和只有一个操作码的时候
*/
class Solution {
public:
    string int2str(int x){
        char buf[20000];
        sprintf(buf,"%d",x);
        return buf;
    }
    void dfs(int num1,string op1,int num2,string res,string s,int tar){
        if(s == ""){
            if(op1 == "+" && num1 + num2 == tar) ans.push_back(res);
            if(op1 == "-" && num1 - num2 == tar) ans.push_back(res);
            if(op1 == "*" && num1 * num2 == tar) ans.push_back(res);
            return;
        }
        for(int i = 0;i < s.size();++ i){

            string t = s.substr(0,i+1);
            string rest = s.substr(i+1);
            int tp = atoi(t.c_str());
            if(t.size() > 1 && t[0] == '0') break;//前导0
            //+
            if(op1 == "+") dfs(num1+num2,"+",tp,res+"+"+t,rest,tar);
            if(op1 == "-") dfs(num1-num2,"+",tp,res+"+"+t,rest,tar);
            if(op1 == "*") dfs(num1*num2,"+",tp,res+"+"+t,rest,tar);
            //-
            if(op1 == "+") dfs(num1+num2,"-",tp,res+"-"+t,rest,tar);
            if(op1 == "-") dfs(num1-num2,"-",tp,res+"-"+t,rest,tar);
            if(op1 == "*") dfs(num1*num2,"-",tp,res+"-"+t,rest,tar);
            //*
            if(op1 == "+") dfs(num1,"+",num2*tp,res+"*"+t,rest,tar);
            if(op1 == "-") dfs(num1,"-",num2*tp,res+"*"+t,rest,tar);
            if(op1 == "*") dfs(num1,"*",num2*tp,res+"*"+t,rest,tar);
        }
    }
    vector<string> addOperators(string num, int target) {
        ans.clear();
        if(int2str(target) == num){
            ans.push_back(num);
        }
        for(int i = 0;i < num.size();++ i){
            for(int j = i+1;j < num.size();++ j){
                string s1 = num.substr(0,i+1);
                string s2 = num.substr(i+1,j-i);
                if(s1.size() > 1 && s1[0] == '0') continue;
                if(s2.size() > 1 && s2[0] == '0') continue;
                int num1 = atoi(s1.c_str());
                int num2 = atoi(s2.c_str());
                dfs(num1,"+",num2,s1+"+"+s2,num.substr(j+1),target);
                dfs(num1,"-",num2,s1+"-"+s2,num.substr(j+1),target);
                dfs(num1,"*",num2,s1+"*"+s2,num.substr(j+1),target);
            }
        }
        return ans;
    }
private:
    vector<string>ans;
};
