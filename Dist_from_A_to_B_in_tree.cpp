#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define pb push_back
#define P pair<int, int>
const int N = 100005, M=22;

// 1 //Input
// 7
// 1 2 1
// 2 4 4
// 2 5	5
// 5 6 9
// 1 3 2
// 3 7 10
vector<pair<int,int>> gr[N];
int Par[N],dep[N], tin[N],tout[N],timer,dist[N];

void dfs(int cur,int par){
	tin[cur]=++timer;
	Par[cur]=par;//needed for lca_brute
	for(auto x: gr[cur]){
		if(x.F!=par){
			dep[x.F]=dep[cur]+1;
			dist[x.F]=dist[cur]+x.S;
			dfs(x.F,cur);
		}
	}
	tout[cur]=timer;
	return;
}
//O(n)
int lca_brute(int u,int v){
	if(u==v) return u;	//if same
	if(dep[u]<dep[v]) swap(u,v); //assuming x as largest
	
	while(dep[u]>dep[v]){	//make it to same level
		u=Par[u];
	}
	while(u!=v){	//do it untill common ancestor is reached 
		v=Par[v];
		u=Par[u];
	}
	return u;
}
//O(logn)
int parent[N][M];

void sparse_table(int cur,int par){ //O(n*22)
	parent[cur][0]=par;
	for(int j=1;j<M;j++){	// M here is 22 max 
		parent[cur][j]=parent[parent[cur][j-1]][j-1];
	}
	for(auto x:gr[cur]){
		if(x.F!=par){
			sparse_table(x.F,cur);
		}
	}
}

int LCA_using_depth(int u,int v){
	if(u==v) return u;
	
	if(dep[u]<dep[v]) swap(u,v);
	// depth if u is always greater
	int diff = dep[u]-dep[v];

	for(int i=M-1;i>=0;i--){
		if((diff>>i)&1){
			u=parent[u][i];
		}
	}
	// u and v are at same depth
	if(u==v) return v;


	for(int i=M-1;i>=0;i--){
		if(parent[u][i]!=parent[v][i]){ //will reach untill equal
			u=parent[u][i];
			v=parent[v][i];
		}
	}
	return parent[u][0];
}

bool is_ancestor(int u,int v){ //u ancestor of v ?
	return tin[u]<=tin[v]&&tout[u]>=tout[v];
}

int LCA_using_time(int u,int v){
	if(is_ancestor(u,v)) return u;
	if(is_ancestor(v,u)) return v;
	for(int i=M;i>=0;i--){
		if(!is_ancestor(parent[u][i],v)){
			u = parent[u][i];
		}
	}
	return parent[u][0];
}

int distance(int u,int v){
	int lca = LCA_using_depth(u,v);
	return dist[u]+dist[v]-2*dist[lca]; 
}
 
void solve(){
	int i,j,k,n,m,ans=0,cnt=0,sum=0;
	cin>>n;
	for( i=1;i<n;i++){
		int x,y,w; cin>>x>>y>>w;
		gr[x].pb({y,w});
		gr[y].pb({x,w});
	}
	//root is 1
	timer=0;
	tin[0]=0;tout[0]=n+1; // making 0 as universal parent

	dfs(1,0);

	sparse_table(1,0);
	cout<<distance(4,6)<<endl;
	cout<<distance(1,7)<<endl;
	
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