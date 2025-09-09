#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,int>;
const int N=2e5+1;
const int mod=1e9+7;
const int inf=1e18+1;
int t,n,a[N],tree[N*4];

void Build(int id, int l, int r)
{
    if(l==r)
    {
        tree[id]=0;
        return;
    }
    int mid = (l+r)/2;
    Build(id*2,l,mid);
    Build(id*2+1,mid+1,r);
    tree[id]=min(tree[id*2],tree[id*2+1]);
}

void Update(int id, int l, int r, int i, int val)
{
    if(i<l || i>r)
    {
        return;
    }
    if(l==r)
    {
        tree[id]=val;
        return;
    }
    int mid=(l+r)/2;
    Update(id*2,l,mid,i,val);
    Update(id*2+1,mid+1,r,i,val);
    tree[id]=min(tree[id*2],tree[id*2+1]);
}

ll get(int id,int l,int r, int u, int v)
{
    if(v<l || u>r) return 2e9;
    if(u<=l && v>=r) return tree[id];
    int mid=(l+r)/2;
    return min(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}

void ReadInput()
{
    cin >> t;
}

void Solve()
{
    while(t--)
    {
        ll ans=0;
        cin >> n;
        Build(1,1,n);
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            Update(1,1,n,i,a[i]-i);
        }
        for(int i=1;i<=n;i++)
        {
            int low=i,high=n;
            while(low<=high)
            {
                int mid=(low+high)/2;
                if(get(1,1,n,i,mid)+i-1>=0) low=mid+1;
                else high=mid-1;
            }
            ans+=high-i+1;
        }
        cout << ans << '\n';
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
