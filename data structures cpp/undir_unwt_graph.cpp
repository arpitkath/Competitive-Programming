#include <iostream>
#include <queue>
using namespace std;

struct node{
	int dest;
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

node* addNode(int dest){
	node* temp = new node;
	temp->dest = dest;
	temp->next = NULL;
	return temp;
}

void addEdge(int src, int dest){
	node* temp = addNode(dest);
	temp->next = g->arr[src].head;
	g->arr[src].head = temp;
	
	temp = addNode(src);
	temp->next = g->arr[dest].head;
	g->arr[dest].head = temp;
}

void printGraph(){
	node* temp;
	for(int i = 0; i < g->V; i++){
		cout << i << "->";
		temp = g->adj[i].head;
		while(temp != NULL){
			cout << temp->vert << "->";
			temp = temp->next;
		}
		cout << endl;
	}
}

bool hasEdge(int src, int dest){
	node* temp = g->arr[src].head;
	while((temp != NULL) && (temp->dest != dest)) temp = temp->next;
	if(temp == NULL) return false;
	else return true;
}

void dfs(int src, bool visited[]){
	visited[src] = true;
	node* temp = g->arr[src].head;
	while(temp != NULL){
		if(!visited[temp->dest]){
			cout << temp->dest <<endl;
			dfs(temp->dest, visited);
		}
		temp = temp->next;
	}
}

void dfs(int src){
	bool visited[g->n];
	dfs(src, visited);
}

void bfs(int src){
	bool visited[g->n];
	queue<int> q;
	q.push(src);
	node* temp;
	while(!q.empty()){
		cout << q.front() << endl;
		visited[q.front()] = true;
		temp = g->arr[q.front()].head;
		q.pop();
		while(temp != NULL){
			if(!visited[temp->dest]){
				q.push(temp->dest);
				visited[temp->dest] = true;
			}
			temp = temp->next;
		}
	}
}

void connected(int src, bool visited[], int count, int connect[]){
	visited[src] = true;
	connect[src] = count;
	node* temp = g->arr[src].head;
	while(temp != NULL){
		if(!visited[temp->dest])
			connected(temp->dest, visited, count, connect);
		temp = temp->next;
	}
}

void connected(){
	bool visited[g->n];
	int count = 0;
	int connect[g->n];
	for(int i = 0; i < g->n; i++){
		if(!visited[i]){
			connected(i, visited, count, connect);
			count++;
		}
	}
	for(int i = 0; i < g->n; i++) cout<<connect[i]<<" ";
}

void shortestPath(int src){
	int path[g->n];
	int dist[g->n];
	int count = 1;
	for(int i = 0; i < g->n; i++) dist[i] = -1;
	path[src] = src;
	dist[src] = 0;
	queue<int>q;
	q.push(src);
	while(!q.empty()){
		node* temp = g->arr[q.front()].head;
		while(temp){
			if(dist[temp->dest] == -1){
				q.push(temp->dest);
				path[temp->dest] = q.front();
				dist[temp->dest] = dist[q.front()] + 1;
			}
			temp = temp->next;
		}
		q.pop();
	}
	for(int i = 0; i < g->n; i++) cout << i << " - " << dist[i]<<endl;
}

int main(){
	int n = 5;
	
	createGraph(n);

	addEdge(0, 1);
    addEdge(0, 4);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 3);
    addEdge(3, 4);
	
	printGraph();
	
	shortestPath(0);
	//connected();
	
	//cout<<hasEdge(2,4);
}

