/*
**    Topological Sorting Algorithm
**    Author: Darpan Kalra
**    Created: 24 Jun, 2013
**    
**    Description:
**    A topological sorting of a directed graph is a linear ordering of its 
**    vertices such that for every directed edge uv from vertex u to vertex v,
**    u comes before vertex v in the ordering.
**
**    Approach:
**    We accept as input the number of vertices and the number of edges and then
**    we accept each edge from the user. With this input we construct an 
**    adjacency list of the graph and also construct an array which stores the 
**    number of incoming edges for each vertex. Then we add the vertices with no
**    incoming edges to a stack. We then pop the stack elements one by one. With 
**    each pop operation we decrease the number of incoming edges of all the 
**    vertices which are adjacent to the vertex wich has been just popped. We 
**    continue in this fashion until the stack is empty. When the stack is empty 
**    we check if there is a vertex with one or more incoming edges. If such a 
**    vertex is there it means that the graph is cyclic and no possible ordering 
**    exists. Otherwise we print the vertices in the order in which they were 
**    popped from the stack.
*/

#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

// arr is the adjacency list
// Assuming there can be maximux 10000 vertices 
vector<vector <int> > arr(10000);

// b stores the number of incoming edges for each vertex
int b[10000];

//mystack is the stack in which vertices with 0 incoming edges are stored
stack<int> mystack;

//res stores the vertices which have been popped from the stack
int res[10000];

int main()
{
    int n,m,i,x,y,k,v=0;
    // Input number of vertices and number of edges
    // n is the number of vertices
    // m is the number of edges
    scanf("%d%d",&n,&m);
    
    // Input the dependency for each edge and construct the adjacency list. A
    // dependency means that there is a directed edge from vertex x to vertex y.
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        arr[x].push_back(y);
        b[y]++;
    }
    
    // Push the vertices with no incoming edges on the stack.
    for(i=0;i<n;i++)
    {
        if(b[i]==0)
        {
            mystack.push(i);
        }
    }
    
    // While stack is not empty pop a vertex and reduce by one the number of 
    // incoming edges of all vertices which are adjacent to the popped vertex. 
    // Push onto the stack vertices for which the number of incoming edges 
    // becomes 0.
    vector<int>::iterator it;
    while(!mystack.empty())
    {
        k = mystack.top();
        res[v++]=k;
        mystack.pop();
        
        it = arr[k].begin();
        for(;it!=arr[k].end();it++)
        {
            b[*it]--;
            if(b[*it]==0)
            {
                mystack.push(*it);
            }
        }
    }
    
    // If a vertex exists with one or more incoming edges then the graph is not 
    // cyclic and no ordering exists for it.
    for(i=0;i<n;i++)
    {
        if(b[i]>0)
        {
            printf("No possible ordering exists\n");
            break;
        }
    }
    
    //If an ordering exists then print it.
    if(i==n)
    {
        for(i=0;i<n;i++)
            printf("%d ",res[i]);
        printf("\n");
    }
    return 0;
}

