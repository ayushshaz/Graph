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
	//initialize
	int totalComponent=n;
	void initialize(int n){
		par.resize(n);
		f(n) par[i]=i;
	}
	int getSuperParent(int x){
		if(x==par[x])return x;
		else return par[x]=getSuperParent(par[x]);
	} 
	void mergeUnion(int x,int y){
		int superParentX=getSuperParent(x);
		int superParentY=getSuperParent(y);
		if(superParentX!=superParentY){
			par[superParentX]=superParentY;//just connecting the two
			totalComponent--;//total component is decreasing whenever we are merging 
		}
	}
} G;

void solve(){
	int i,j,k,n,m,ans=0,cnt=0,sum=0;
	cin>>n>>m;
	G.initialize(n);
	bool cycle=0;
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		x--,y--;//zero based indexing
		if(G.getSuperParent(x)!=G.getSuperParent(y)){
			G.mergeUnion(x,y);
		}else{
			cycle=1;
		}
	}
	if(cycle){
		cout<<"Cycle was found";
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