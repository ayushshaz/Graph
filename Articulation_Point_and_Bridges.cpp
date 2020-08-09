#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define pb push_back

const int N = 100005, M=22;

vector<int> gr[N];
int disc[N],low[N],tme;
set<int> art_p;
vector<pair<int,int>> bridge; 

void dfs(int cur,int par){
	disc[cur]=low[cur]=tme++;
	int no_child=0;
	for(auto child : gr[cur]){	
		//not visited
		if(disc[child]==0){
			dfs(child,cur);
			no_child++;
			low[cur]=min(low[cur],low[child]);
			//art point
			if(par!=0 && low[child]>=disc[cur]){ //Even if par!=0 removed doesn't affect the code 
				art_p.insert(cur);
			}
			//bridge
			if(low[child]>disc[cur]){
				bridge.pb({cur,child});
			}
		}else if(child!=par){
			//backedge //cycle found
			low[cur]=min(low[cur],low[child]);
		}
	}
	//separate case to handle root
	if(par==0 && no_child>=2){
		art_p.insert(cur);
	}
	return;
}

void solve(){
	int i,j,k,n,m,ans=0,cnt=0,sum=0;
	cin>>n>>m;
	for(i=0;i<m;i++){
		int x,y;cin>>x>>y;
		gr[x].pb(y);
		gr[y].pb(x);
	}
	tme=1;
	dfs(1,0);
	for(auto x: art_p) cout<<x<<" ";
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