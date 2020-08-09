#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define pb push_back

const int N = 100005, M=22;

vector<int> gr[N];
// vector<int> dead(N,0),discovered(N,0);
// bool deadVertex[N]={0};
// int ans=INT_MAX;

// void dfs(int current,int parent,int time){
// 	discovered[current] = time++;
// 	for(auto neighbour : gr[current]){
// 		if(discovered[neighbour]==0){
// 			//not visited
// 			dfs(neighbour,current,time);
// 			dead[current]+=dead[neighbour];
// 		}else if(neighbour!=parent and discovered[neighbour]<discovered[current]){
// 			//backedge found
// 			dead[current]+=discovered[current]-discovered[neighbour]-1;
// 			ans=min(ans,discovered[current]-discovered[neighbour]+1-dead[parent]);
// 			for(int i=neighbour+1;i<current;i++){
// 				deadVertex[i]=1;
// 			}
// 		}
// 	}
// 	if(!deadVertex[current]){
// 		dead[current]+=1;
// 	}
// 	cout<<current<<" "<<ans<<endl;
// 	return;
// }
void bfs(int src,int n,int &ans){
	vector<int> distance(n+1,INT_MAX);
	distance[src]=0;
	queue<int> q;
	q.push(src);
	while(!q.empty()){
		int node=q.front();
		q.pop();
		for(int neighbour:gr[src]){
			if(distance[neighbour]==INT_MAX){
				//then visit it
				q.push(neighbour);
				distance[neighbour]=distance[node]+1;
			}else if(distance[neighbour]>=distance[node]){
				//we have visited
				ans=min(ans,1+distance[node]+distance[neighbour]);
			}
		}			
	}
}

void solve(){
	int i,j,k,n,m,cnt=0,sum=0;
	cin>>n>>m;
	for(i=0;i<m;i++){
		int x,y;cin>>x>>y;
		gr[x].pb(y);
		gr[y].pb(x);
	}
	// dfs(1,0,1);
	// cout<<ans<<endl;
	int ans=n+1;
	for(int i=1;i<=n;i++){
		bfs(i,n,ans);
	}
	if(ans==n+1){
		cout<<"No Cycle found"<<endl;
	}else{
		cout<<"Shortest Cycle is of length "<<ans<<"\n";
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