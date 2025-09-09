#include<bits/stdc++.h>
using namespace std;
using ll= long long;
using ld = long double;
using pll = pair<ll,ll>;
const int N=100;
const int mod=1e9+7;
const ll inf=1e18+1;
int t,n,par[N];
char p[N];
string s;
bool check[N];
bool check2[N];

int Find(int u)
{
    if(u==par[u]) return u;
    else return par[u]=Find(par[u]);
}

void Union(int u, int v)
{
    par[v]=u;
}

void ReadInput()
{
    cin >> t;
}

void Solve()
{
    while(t--)
    {
        cin >> n >> s;
        fill(check,check+N,1);
        string ans;
        for(char j='a';j<='z';j++)
        {
            p[j-'a']=-1;
            par[j-'a']=j-'a';
        }
        for(int i=0;i<s.size();i++)
        {
            if(p[s[i]-'a']!=-1) ans.push_back(p[s[i]-'a']);
            else
            {
                for(char j='a';j<='z';j++)
                {
                    int u=Find(s[i]-'a');
                    int v=Find(j-'a');
                    if(u!=v && check[j-'a'] && j!=s[i])
                    {
                        Union(u,v);
                        check[j-'a']=false;
                        p[s[i]-'a']=j;
                        break;
                    }
                }
                if(p[s[i]-'a']==-1)
                {
                    for(char j='a';j<='z';j++)
                    {
                        if(check[j-'a'] && j!=s[i])
                        {
                            check[j-'a']=false;
                            p[s[i]-'a']=j;
                        }
                    }
                }
                ans.push_back(p[s[i]-'a']);
            }
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
