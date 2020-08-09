#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define pb push_back
#define f(n) for(int i=0;i<n;i++)
#define vi vector<int>
#define pii pair<int,int>

const int N = 100005, M=22;

vector<vi> floydWarshall(int n,vector<vector<pii>> &adj){
	vector<vi> dist(n+1,vector<int>(n+1,2e9));
	for(int i=1;i<=n;i++){
		dist[i][i]=0;
		for(pii ed :adj[i]){//edge
			int nb=ed.f;//neighbour
			int w=ed.s;//weight
			dest[i][nb]=w;
		}
	}
	for(int k=1;k<=n;k++){
		//kth phase
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k;j++){
				dist[i][j]=min(dist[i][j],dist[j][k]+dist[k][j]);
			}
		}
	}
	return dist;//if any value in it is negative then there is a negative cycle
} 

void solve(){
	int i,j,k,n,m,ans=0,cnt=0,sum=0;
	

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