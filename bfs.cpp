#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
	map<T,list<T>> gr;
public:
	void addEdge(int u,int v){
		gr[u].push_back(v);
		gr[v].push_back(u);
	}
	void bfs(T src){
		map<T,bool> visited;
		queue<T> q;
		q.push(src);
		while(!q.empty()){
			T curr = q.front();
			visited[curr]=1;
			p.pop();
			for(auto x:gr[curr]){
				if(!visited[x]){
					visited[x]=1;
					q.push(x);
				}
			}
		}
	}

};

int main(){
	return 0;
}