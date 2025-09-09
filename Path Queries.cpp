#include<bits/stdc++.h>
using namespace std;
using ll= long long;
using ld = long double;
using pll = pair<ll,ll>;
const ll N=2e5+1;
const ll mod=1e9+7;
ll n,q,p[N],u,v,s,x,c[N],low[N],num[N],Time=0,t,bit[N];
vector<ll> a[N];

void Update(ll u, ll val)
{
    for(int i=u; i <= n ; i += i&(-i) )
    {
        bit[i]+=val;
    }
}

ll get(ll u)
{
    ll ans=0;
    for(int i=u;i>0;i -= i&(-i))
    {
        ans+=bit[i];
    }
    return ans;
}

void DFS(ll u, ll par)
{
    num[u]=++Time;
    for(ll v: a[u])
    {
        if(v!=par)
        {
            DFS(v,u);
        }
    }
    low[u]=Time;
}

void ReadInput()
{
    cin >> n >> q;
    for(ll i=1;i<=n;i++) cin >> p[i];
    for(ll i=1;i<n;i++)
    {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
}

void Solve()
{
    DFS(1,1);
    for(ll i=1;i<=n;i++)
    {
        c[num[i]]=p[i];
    }
    for(ll i=1;i<=n;i++)
    {
        Update(num[i],c[num[i]]);
        Update(low[i]+1,-c[num[i]]);
    }
    for(ll i=1;i<=q;i++)
    {
        cin >> t;
        if(t==1)
        {
            cin >> s >> x;
            Update(num[s],x-c[num[s]]);
            Update(low[s]+1,c[num[s]]-x);
            c[num[s]]=x;
        }
        else
        {
            cin >> x;
            cout << get(num[x]) << '\n';
        }
    }
}

void Print()
{

}

int main()
{
    ios_base::sync_with_stdio(false);
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
