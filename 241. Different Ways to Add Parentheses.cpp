class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int>ans;
        for(int i = 0;i < input.size();++ i){
            if(input[i]=='+'||input[i]=='-'||input[i]=='*'){
                vector<int>a(diffWaysToCompute(input.substr(0,i)));
                vector<int>b(diffWaysToCompute(input.substr(i+1)));
                for(int j = 0;j < a.size();++ j){
                    for(int k = 0;k < b.size();++ k){
                        int opcode;
                        if(input[i]=='+') opcode = a[j] + b[k];
                        if(input[i]=='-') opcode = a[j] - b[k];
                        if(input[i]=='*') opcode = a[j] * b[k];
                        ans.push_back(opcode);
                    }
                }
            }
        }
        if(!ans.size()) ans.push_back(atoi(input.c_str()));
        return ans;
    }
};