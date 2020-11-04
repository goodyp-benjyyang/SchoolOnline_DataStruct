#include<iostream>
#include<algorithm>
using namespace std;
struct actime
{
    int start,finish;
}act[1002];
bool cmp(actime a,actime b){//判断第一个活动是不是在第二个活动结束之前结束
    return a.finish<b.finish;
}

int main(){
    int i,n,t,total;
    while (cin>>n) //活动的个数
    {
        for(i=0;i<n;i++){
            cin>> act[i].start >>act[i].finish;
        }
        sort(act, act+n, cmp);//按活动结束时间从小到大排序
        t=-1;
        total=0;
        for (i=0;i<n; i++)
        {
            if(t<=act[i].start){
        //若被检查的活动i的开始时间starti小于最近选择的活动j的结束时间endj，则不选择活动i，否则选择活动i加入集合中。
                total++;
                t=act[i].finish;
            }
        }
        cout<< total <<endl;

    }
    

    return 0;
}