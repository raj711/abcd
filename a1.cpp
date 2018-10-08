#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
#define mp make_pair
#define pb push_back
#define int long long
#define endl '\n'
#define pi 3.1415926536
using namespace std;

ll powermod(ll _a,ll _b,ll _m){ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}
ll string_to_number(string s){ll x=0; stringstream convert(s); convert>>x; return x;}
ll add(ll a,ll b){ll x = (a%mod + b%mod)%mod; return x; }
ll mul(ll a,ll b){ll x = (a%mod * b%mod)%mod; return x; }
ll sub(ll a,ll b){ll x = (a-b+mod)%mod; return x; }
ll divi(ll a,ll b){ll x = a;ll y = powermod(b,mod-2,mod);ll res = (x*y)%mod;return res;}



int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m,b;
    cin>>m>>n>>b;
    
    int arr[n][m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
    set<int>st;
    int temp[n][m];
    while(b--){
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                int cnt=0;
                cnt+=arr[i][j];
                cnt+=arr[i][(j+1+m)%m];
                cnt+=arr[i][(j-1+m)%m];
                cnt+=arr[(i-1+n)%n][j];
                cnt+=arr[(i+1+n)%n][j];
                cnt+=arr[(i+1+n)%n][(j+1+m)%m];
                cnt+=arr[(i-1+n)%n][(j+1+m)%m];
                cnt+=arr[(i+1+n)%n][(j-1+m)%m];
                cnt+=arr[(i-1+n)%n][(j-1+m)%m];
                temp[i][j]=cnt;
            }
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                arr[i][j]=temp[i][j];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            st.insert(arr[i][j]);
        }
    }
    cout<<(int)st.size()<<endl;
    return 0;
}
