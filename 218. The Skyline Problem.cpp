/*
    multiset可以用作最大堆or最小堆，而且比priority_queue优秀的是：支持查找和删除O(logn)
    本题multiset实现堆的功能
    https://briangordon.github.io/2014/08/the-skyline-problem.html
    O(nlogn)解题思路：
    （1）从左到右扫描关键点(左端点和右端点)，左端点插入堆，右端点从堆中查找并删除（思考到如果出现高度相同的两个建筑其实并不影响，因为我们第二步取最高值）
    （2）最终所求的点就是每个关键点堆内容被更新完后，大顶堆顶元素的值，当然要合并连续的水平线~
    扫描O(n)，插入和删除堆元素O(logn)，所以总的时间复杂度O(nlogn)
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
