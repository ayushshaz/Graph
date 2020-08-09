#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define pb push_back
#define f(n) for(int i=0;i<n;i++)

const int N = 100005, M=22;

struct disjointSetUnion{
	vector<int> par;
	void initialize(int n){
		par.resize(n);
		f(n) par[i]=i;
	}
	int get(int x){
		return x==par[x] ? x : (par[x]=get(par[x]));
	} 
	void unite(int x,int y){
		int x=get(x);
		int y=get(y);
		if(x!=y){
			par[x]=y;
		}
	}
};

void solve(){
	int i,j,k,n,m,ans=0,cnt=0,sum=0;
	cin>>n>>m;
	vector<vector<int> > edges(m);
	for(i=0;i<m;i++){
		int x,y,w;cin>>x>>y>>w;
		x--,y--;//zero based indexing
		edges[i]={w,x,y};
	}
	sort(edges.begin(),edges.end()); // will be sorted on the basis of weight
	disjointSetUnion G;
	G.initialize(n);
	for(i=0;i<m;i++){
		int x=edges[i][1];
		int y=edges[i][2];
		int w=edges[i][0];
		if(G.get(x)!=G.get(y)){
			G.unite(x,y);
			ans+=w;
		}
	}
	cout<<ans<<endl;
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