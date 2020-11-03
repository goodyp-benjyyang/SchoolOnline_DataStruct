#include<iostream>
#include<algorithm>
using namespace std;
typedef struct firstCode
{
    int w;   //物品重量
    int v;   //物品价值
    double avg;  //物品每单位的平均价值
}P;
bool cmp(P a,P b){
    return a.avg>b.avg;
}
int main(){
    P *p;
    int n,i,m;//n物品个数 ， m背包容量   
    while (cin>>n>>m)
    {
        p=new P[n];
        for(i=0;i<n;i++){
            cin>> p[i].w>>p[i].v;
            p[i].avg = p[i].v/p[i].w*1.0;
        }
        sort(p,p+n,cmp);
        int maxvlaue=0;
        for(int i=0;i<n;i++){
            if(p[i].w <= m){
                m-=p[i].w;
                maxvlaue+=p[i].v;
            }else{
                break;
            }
        }
        cout<< maxvlaue <<endl;
    }
    

    return 0;
}