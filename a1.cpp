#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
#define mp make_pair
#define pb push_back
#define endl '\n'
#define int long long
#define pi 3.1415926536
using namespace std;

ll powermod(ll _a,ll _b,ll _m){ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}
ll string_to_number(string s){ll x=0; stringstream convert(s); convert>>x; return x;}
ll add(ll a,ll b){ll x = (a%mod + b%mod)%mod; return x; }
ll mul(ll a,ll b){ll x = (a%mod * b%mod)%mod; return x; }
ll sub(ll a,ll b){ll x = (a-b+mod)%mod; return x; }
ll divi(ll a,ll b){ll x = a;ll y = powermod(b,mod-2,mod);ll res = (x*y)%mod;return res;}

vector<vector<int>>adj[2000000];
int pow1(int a, ll b, ll c) {
        if (b == 0)
            return 1;
        ll p = pow1(a, b / 2, c);
        p = (p * p) % c;
        return (b % 2 == 0) ? p : (a * p) % c;
    }        
int dfs(int c,int size[], int fact[]){
    size[c]=1;
    int cc=1;
    
    for(auto a:adj[c]){
        int val=dfs(a,size,fact);
        size[c]+=size[a];
        cc=mul(cc,pow1(fact[size[a]],mod-2,mod));
        cc=mul(cc,val);
    }
    cc=mul(cc,fact[size[c]-1]);
    return cc;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    
    int fact[2000001];
    fact[0]=1;
    for(int i=1;i<=2000000;i++){
        fact[i]=mul(fact[i-1],i);
    }
    
    while(t--){
        int n,m;
        cin>>n>>m;
        int size[n]={0};
        bool vis[n]={0};
        adj.clear();        
        while(m--){
            
            int x,y;
            cin>>x>>y;
            adj[x-1].pb(y-1);
            vis[y-1]=1;
        }
        int ans=fact[n];
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans=mul(ans,dfs(i,size,fact));
                ans=mul(ans,pow1(fact[size[i]],mod-2,mod));
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}
