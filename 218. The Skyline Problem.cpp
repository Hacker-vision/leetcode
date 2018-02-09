/*
    multiset������������or��С�ѣ����ұ�priority_queue������ǣ�֧�ֲ��Һ�ɾ��O(logn)
    ����multisetʵ�ֶѵĹ���
    https://briangordon.github.io/2014/08/the-skyline-problem.html
    O(nlogn)����˼·��
    ��1��������ɨ��ؼ���(��˵���Ҷ˵�)����˵����ѣ��Ҷ˵�Ӷ��в��Ҳ�ɾ����˼����������ָ߶���ͬ������������ʵ����Ӱ�죬��Ϊ���ǵڶ���ȡ���ֵ��
    ��2����������ĵ����ÿ���ؼ�������ݱ�������󣬴󶥶Ѷ�Ԫ�ص�ֵ����ȻҪ�ϲ�������ˮƽ��~
    ɨ��O(n)�������ɾ����Ԫ��O(logn)�������ܵ�ʱ�临�Ӷ�O(nlogn)
*/
class Solution {
public:

    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
         vector<node>point;
         for(int i = 0;i < buildings.size();++ i){
             point.push_back(node(buildings[i][0],buildings[i][2]));
             point.push_back(node(buildings[i][1],-buildings[i][2]));
         }
         sort(point.begin(),point.end());
         multiset<int>height({0});
         vector<pair<int,int> >ans;
         for(int i = 0;i < point.size();++ i){
             int x = point[i].x;
             int h = point[i].h;
             if(h > 0) height.insert(h);
             else height.erase(height.find(-h));//???????????
             if(ans.empty() || *height.rbegin()!=ans[ans.size()-1].second )
                 ans.push_back(make_pair(x,*height.rbegin()));
             //ans.push_back(make_pair(x,1));
         }
        return ans;
    }
private:
    struct node{
        int x,h;//h > 0,left;h < 0,right;
        node(int _x=0,int _h=0):x(_x),h(_h){}
        friend bool operator < (node a,node b){
            if(a.x == b.x) return a.h > b.h;
            return a.x < b.x;
        }
    };
};
