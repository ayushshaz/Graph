#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define pb push_back
#define f(n) for(int i=0;i<n;i++)

const int N = 100005, M=22;
vector<pair<int,int>> gr[N];

int findMinVertex(int *weight,bool *visited,int n){
	int minVertex=-1;
	for(int i=0;i<n;i++){
		if(!visited[i] and (minVertex==-1 or weight[i]<weight[minVertex]) ){
			minVertex=i;
		}
	}
	return minVertex;
}

void prim(int n){
	bool *visited=new bool[n];
	int *parent =new int[n];
	int *weight =new int[n];
	memset(visited,0,sizeof visited);
	f(n) weight[i]=1e9;
	weight[0]=0;
	parent[0]=-1;
	for(int i=0;i<n;i++){
		int minVertex=findMinVertex(weight,visited,n);
		visited[minVertex]=1;
		for(auto neighbour: gr[minVertex]){
			if(!visited[neighbour.first]){
				if(weight[neighbour.first]>neighbour.second){
					parent[neighbour.first]=minVertex;
					weight[neighbour.first]=neighbour.second;
				}
			}
		}
	}
	for(int i=1;i<n;i++){
		 cout<<i<<" -- "<<parent[i]<<" 	with weight "<<weight[i]<<endl;
	}
}
void solve(){
	int i,j,k,n,m,ans=0,cnt=0,sum=0;
	cin>>n>>m;
	for(i=0;i<m;i++){
		int x,y,w;cin>>x>>y>>w;
		gr[x].pb(make_pair(y,w));
		gr[y].pb(make_pair(x,w));
	}
	prim(n);
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