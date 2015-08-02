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
        bool isCyclicUtil(int num, bool visited[], bool *rs);
        void dfsHelp(int v, vector<bool> &visited);
};

undirectedGraph::undirectedGraph(int num){
    this->num = num;
    adj = new list<int>[num];
}

void undirectedGraph::addEdge(int src, int tar){
    adj[src].push_back(tar);
}

bool undirectedGraph::isCyclicUtil(int num, bool visited[], bool *rs){
    return false;    
}

bool undirectedGraph::isCyclic(){
    bool *visited = new bool[num];
    bool *recStack = new bool[num];
    for(int i=0;i<num;i++){
        visited[i] = false;
        recStack[i] = false;
    }
    return isCyclicUtil(num, visited, recStack);
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

    // Detect cycle
    if(myGraph->isCyclic())
        cout<<"Exists cycle!"<<endl;
    cout<<"No cycle!"<<endl;
    
    return 0;
}


