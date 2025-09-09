#include<bits/stdc++.h>
using namespace std;
using ll= long long;
using ld = long double;
using pll = pair<ll,ll>;
const int N=2e5+1;
const int mod=1e9+7;
const ll inf=1e18+1;
int t,n,k,p[N],h[N],c,cnt[N],a[N];
vector<int> x[N];

void DFS(int u, int par)
{
    cnt[h[u]]++;
    for(int v: x[u])
    {
        if(v!=par)
        {
            h[v]=h[u]+1;
            DFS(v,u);
        }
    }
}

bool check(int m)
{
    int res=0;
    for(int i=1;i<=n;i++) h[i]=1;
    for(int i=n;i>=2;i--)
    {
        if(h[i]==m && a[i]!=1) res++;
        else h[a[i]]=max(h[a[i]],h[i]+1);
    }
    if(res<=k) return true;
    return false;
}

void ReadInput()
{
    cin >> t;
}

void Solve()
{
    while(t--)
    {
        cin >> n >> k;
        for(int i=1;i<=n;i++)
        {
            //h[i]=0;
            x[i].clear();
            //cnt[i]=0;
        }
        for(int i=2;i<=n;i++)
        {
            cin >> a[i];
            x[a[i]].push_back(i);
        }
        //DFS(1,1);
        int low=1,high=n+1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(check(mid)) high=mid-1;
            else low=mid+1;
        }
        cout << low << '\n';
    }
}

void Print()
{

}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(nullptr);
    if(fopen("WILDLIFE.INP","r"))
    {
        freopen("WILDLIFE.INP","r",stdin);
        freopen("WILDLIFE.OUT","w",stdout);
    }
    ReadInput();
    Solve();
    Print();
}
