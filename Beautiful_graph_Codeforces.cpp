#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define mod 998244353 
 
vector<vi> gr;
int n,m;
int cntO=0,cntE=0;
bool ifPossible=1;
 
int pw(int a,int n){
    if(!n) return 1;
    int pt = pw(a,n/2);
    pt*=pt,pt%=mod;
    if(n&1)
        pt*=a,pt%=mod;
    return pt;
} 
 
void dfs(int curr,vi &visited,bool parity){
 
    if(visited[curr]){
        if(1+parity!=visited[curr]) ifPossible=0;
        return;
    }
 
    visited[curr]=1+parity;//2 for even and 1 for odd 
    if(parity) cntE++;
    else cntO++;
    
    for(auto x:gr[curr]){
        // if(visited[x]==0){
            dfs(x,visited,1-parity);   
        // }else if(x!=curr){
        //     //when already visited check for its possibility 
        //     if(visited[curr]==visited[x]){
        //         ifPossible=false;
        //         return;
        //     }
        // }
    }
    return;
}
 
int solve(){
    int ans=1;
    vi visited(n+1,0);
    for(int i=1;i<=n;i++){
        if(visited[i]==0){
            cntO=0;cntE=0,ifPossible=1;
            dfs(i,visited,0);//parity 0 for odd
            if(!ifPossible){
                return 0;
            }
            ans= (ans*(pw(2,cntE)+pw(2,cntO)))%mod;
 
        }
    }
    return ans;
}
 
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
 
int32_t main()
{
    //c_p_c();
    FIO;
    w(t){
        cin>>n>>m;
        gr.clear();
        gr.resize(n+1);    
        for(int i=0;i<m;i++){
            int x,y; cin>>x>>y;
            gr[x].pb(y);
            gr[y].pb(x);
        }
        cout<<solve()<<"\n";
    }
    return 0;
}