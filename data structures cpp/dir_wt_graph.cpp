#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct node{
	int dest;
	int w;
	node* next;
};

struct list{
	node* head;
};


struct graph{
	int n;
	list* arr;
}*g;

void createGraph(int n){
	g = new graph;
	g->n = n;
	g->arr = new list[n];
	for(int i = 0; i < n; i++) g->arr[i].head = NULL;
}

node* addNode(int dest, int w){
	node* temp = new node();
	temp->dest = dest;
	temp->w = w;
	temp->next = NULL;
	return temp;
}

void addEdge(int src, int dest, int w){
	node* temp = addNode(dest, w);
	temp->next = g->arr[src].head;
	g->arr[src].head = temp;
}

void printGraph(){
	for(int i = 0; i < g->n; i++){
		cout << i << "->";
		node* temp = g->arr[i].head;
		while(temp){
			cout << temp->dest << "(" << temp->w << ")" << "->";
			temp = temp->next;
		}
		cout << "X" <<endl;
	}
}

void bfs(int src){
	bool visited[g->n];
	queue<int>q;
	q.push(src);
	while(!q.empty()){
		node* temp = g->arr[q.front()].head;
		cout << q.front() << endl;
		visited[q.front()] = true;
		q.pop();
		while(temp){
			if(!visited[temp->dest]){
				q.push(temp->dest);
				visited[temp->dest] = true;
			}
			temp = temp->next;
		}
	}
}

void dfs(int src, bool visited[]){
	visited[src] = true;
	cout << src << endl;
	node* temp = g->arr[src].head;
	while(temp){
		if(!visited[temp->dest])
			dfs(temp->dest, visited);
		temp = temp->next;
	}
}

void dfs(int src){
	bool visited[g->n];
	for(int i = 0; i < g->n; i++){
		if(!visited[i]){
			dfs(i, visited);
		}
	}
}

void topoSort(int src, bool visited[], stack<int> &rev){
	visited[src] = true;
	node* temp = g->arr[src].head;
	while(temp){
		if(!visited[temp->dest]) topoSort(temp->dest, visited, rev);
		temp = temp->next;
	}
	rev.push(src);
}

void topoSort(){
	stack<int>rev;
	bool visited[g->n];
	for(int i = 0; i < g->n; i++){
		if(!visited[i]) topoSort(i, visited, rev);
	}
	while(!rev.empty()){
		cout<<rev.top()<<endl;
		rev.pop();
	}
}

void dij(int src){
	int dist[g->n];
	for(int i = 0; i < g->n; i++) dist[i] = 99999;
	int path[g->n];
	bool visit[g->n]={0};
	dist[src] = 0;
	path[src] = src;
	node* temp = g->arr[src].head;
	int u, d_min, min_ind;
	for(int j = 0; j < g->n+2; j++){
		d_min = 99999;
		for(int i = 0; i < g->n; i++){
			if(dist[i]<=d_min && (!visit[i])){
				u = i;
				d_min = dist[u];
			}
		}
		visit[u] = true;
		temp = g->arr[u].head;
		d_min = 99999;
		bool flag = false;
		while(temp){
			if(!visit[temp->dest]){
				 int d =  dist[u] + temp->w;
				if(d < dist[temp->dest]){
					dist[temp->dest] = d;
				}
			}
			temp = temp->next;
		}
	}
	for(int i = 0; i < g->n; i++) cout<<i<<"->"<<dist[i]<<endl;
}
int main(){
	int n = 5;
	
	createGraph(n);

	addEdge(0, 1, 5);
    addEdge(0, 4, 4);
    addEdge(1, 2, 2);
    addEdge(1, 3, 1);
    addEdge(1, 4, 0);
    addEdge(2, 3, 7);
    addEdge(3, 4, 9);
	addEdge(4, 2, 9);
	addEdge(1, 0, 4);
	
	printGraph();
	
	//topoSort();
	dij(1);
	return 0;
}











