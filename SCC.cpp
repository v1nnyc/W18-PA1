// CSE 101 Winter 2018, PA 1
//
// Name: Vincent Cannalla
// PID: A13006747
// Sources of Help: None
// Due: 1/26/2018 at 11:59 PM

#include <stack>
#include <set>
#include <iostream>
#include <string>
#include <list>
#include <queue>

#include "Graph.hpp"

//used for pre and post ordering
static int count = 1;

//comparator for priority queue for DFS on G^R
template <class T>
bool pq_compare(Vertex<T> * v1, Vertex<T> * v2){
  return v1->post < v2->post;
}

//used for DFS to get "topological" ordering from G^R for SCC
//controls pre and post ordering
template <class T>
void explore(Vertex<T> * vertex, Graph<T> &g){
    std::stack<Vertex <T> * > stack;
    stack.push(vertex);
       while(!stack.empty()){
           auto curr = stack.top();
            if(!curr->visited){
                curr->pre = count++;
                curr->visited = true;
                if(curr->edges.size() != 0){
                    //checking all the edges of nodes
                for(auto it = curr->edges.begin(); it != curr->edges.end(); it++){
                    Vertex<T> * add = g.vertices.find(*it)->second;
                    if(!add->visited){
                        stack.push(add);
                    }
                }   
                }
                
            }
            //reached node with no children, start going back
            else{
                stack.pop();
                curr->post = count++;
            }
       }
    return;
}

//from top_order class, modified to not check for cycles
//returns res which is list of topological ordering
template <class T>
std::list<T> top_order(Graph<T>& g) {
  std::list<T> res;
 
  std::priority_queue<Vertex<T> * ,std::vector<Vertex<T> *>, bool
      (*)(Vertex<T> *, Vertex<T> *)> mypq(pq_compare);

    for(auto it = g.vertices.begin(); it != g.vertices.end(); it++){
        if(!it->second->visited){
            explore(it->second, g);
        }
        mypq.push(it->second);
    }
  
  //ordering by topological 
  while(!mypq.empty()){
    res.push_back((mypq.top())->id);
    mypq.pop();
  }

  return res;
}

//used for final part of SCC algorithm, does DFS from topological ordering
//returns a set of the vertices in an SCC
//this is basically the explore method except altered for SCCs
template <class T>
std::set<T> exploreComponents(Vertex<T> * vertex, Graph<T> &g){
    std::set<T> setRet;
    std::stack<Vertex <T> * > stack;
    stack.push(vertex);
       while(!stack.empty()){
           auto curr = stack.top();
            if(!curr->visited){
                curr->visited = true;
                setRet.insert(curr->id);
                //check edges of vertices
                for(auto it = curr->edges.begin(); it != curr->edges.end(); it++){
                    Vertex<T> * add = g.vertices.find(*it)->second;
                    if(!add->visited){
                        stack.push(add);
                        setRet.insert(add->id);
                    }
                }   
            }
            else{
                stack.pop();
            }
       }
    return setRet;
}

//method for finding SCCs
//returns sccs which is a list of SCC sets
template <class T>
std::list<std::set<T> > scc(Graph<T> &g){
    std::list<std::set<T> > sccs;

    //reverse graph for top-ordering
    auto revG = g.reverse_graph();

    //list of "topological" ordering
    std::list<T> list = top_order(revG); 

    //search from list to get SCCs and add them to sccs
    for(auto it = list.begin(); it != list.end(); it++){
        if(g.vertices.find(*it)->second->visited != true){
            sccs.push_back(exploreComponents(g.vertices.find(*it)->second, g));
        }
    }

    return sccs;
}
