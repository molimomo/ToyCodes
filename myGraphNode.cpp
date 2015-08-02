#include<iostream>
#include<list>
#include<vector>

using namespace std;

class undirectedGraph{
    public:
        undirectedGraph(int num);   // constructor
        void addEdge(int src, int tar);
        bool isCyclic();
        void dfs(int start);

    private: 
        int num;  // # of vertices
        list<int> *adj;
        bool isCyclicUtil(int num, vector<bool> &visited, vector<bool> &rs);
        void dfsHelp(int v, vector<bool> &visited);
};

undirectedGraph::undirectedGraph(int num){
    this->num = num;
    adj = new list<int>[num];
}

void undirectedGraph::addEdge(int src, int tar){
    adj[src].push_back(tar);
}

bool undirectedGraph::isCyclicUtil(int v, vector<bool> &visited, vector<bool> &rs){
    if(visited[v] == false){
        // Mark node v as visited and push it into recursion stack
        visited[v] = true;
        rs[v] = true;

        // traverse all adjacent vertice of v
        list<int>:: iterator it;
        for(it=adj[v].begin();it!=adj[v].end();it++){
            if(!visited[*it] && isCyclicUtil(*it, visited, rs))
                return true;
            else if(rs[*it])
                return true;    
        }
    }
    // remove the vetex from recursion stack
    rs[v] = false;
    return false;    
}

bool undirectedGraph::isCyclic(){
    vector<bool> visited(num, false);
    vector<bool> recStack(num, false);
    for(int i=0;i<num;i++){
        if(isCyclicUtil(i, visited, recStack))
            return true;
    }
    return false;
}

void undirectedGraph::dfsHelp(int v, vector<bool> &visited){
    visited[v] = true;
    cout<<v<<" ";
    list<int>::iterator it;
    for(it=adj[v].begin();it!=adj[v].end();it++){
        if(!visited[*it])
            dfsHelp(*it, visited);
    }
}

void undirectedGraph::dfs(int start){
    vector<bool> visited(num,false);
    dfsHelp(start, visited);
}

int main(){
    // Generate a graph
    undirectedGraph* myGraph = new undirectedGraph(4);
    myGraph->addEdge(0, 1);
    myGraph->addEdge(0, 2);
    myGraph->addEdge(1, 2);
    myGraph->addEdge(2, 0);
    myGraph->addEdge(2, 3);
    myGraph->addEdge(3, 3);
    
    // DFS traversal
    cout<<"DFS traversal:"<<endl;
    myGraph->dfs(1);
    cout<<endl;

    // Detect cycle
    if(myGraph->isCyclic())
        cout<<"Exists cycle!"<<endl;
    else 
        cout<<"No cycle!"<<endl;
    
    return 0;
}


