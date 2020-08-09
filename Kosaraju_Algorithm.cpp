#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define pb push_back
#define f(n) for(int i=0;i<n;i++)

const int N = 100005, M=22;
vector<int> gr[N],grr[N];
vector<int> order;
int vis[N],comp[N];
vector<int> in_comp[N];

void dfs(int cur){
	vis[cur]=1;
	for(auto x: gr[cur]){
		if(!vis[x]) dfs(x);
	}
	order.pb(cur);
}
void dfs_reverse(int cur,int col){
	comp[cur]=col;
	vis[cur]=1;
	for(auto x: grr[cur]){
		if(!vis[x]) dfs_reverse(x);
	}
}
void solve(){
	int i,j,k,n,m,ans=0,cnt=0,sum=0;
	cin>>n>>m;
	for(i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		gr[x].pb(y);
		grr[y].pb(x);
	}
	for(i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i);
		}
	}
	memset(vis,0,sizeof(vis));
	int col=1;
	for(i=n;i>=1;i--){
		if(!vis[order[i]]){
			dfs_reverse(order[i],col);
		}
		col++;
	}
	for(i=1;i<=n;i++){
		cout<<i<<"--> "<<comp[i]<<endl;
	}
}	

void init(){
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif	
}

int32_t main(){
	init();
	int t;cin>>t;while(t--){
		solve();
	}
	return 0;
}