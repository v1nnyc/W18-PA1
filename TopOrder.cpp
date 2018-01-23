// CSE 101 Winter 2018, PA 1
//
// Name: Vincent Cannalla
// PID: A13006747
// Sources of Help: None
// Due: 1/26/2018 at 11:59 PM

#include "Graph.hpp"
// include more libraries as needed
#include <map>
#include <list>
#include <iostream>
#include <array>
#include <stack>
#include <queue>

//used for pre and post ordering
static int count = 1;

//comparator for priority queue used for top ordering
template <class T>
bool pq_compare(Vertex<T> * v1, Vertex<T> * v2){
  return v1->post < v2->post;
}

//dfs method to explore through all nodes
template <class T>
void explore(Vertex<T> * vertex, Graph<T> &g){
    std::stack<Vertex <T> * > stack;
    stack.push(vertex);
       while(!stack.empty()){
           auto curr = stack.top();
            if(!curr->visited){
                //increment preorder
                curr->pre = count++;
                curr->visited = true;
                if(curr->edges.size() != 0){
                    //explore nodes
                for(auto it = curr->edges.begin(); it != curr->edges.end(); it++){
                    Vertex<T> * add = g.vertices.find(*it)->second;
                    if(!add->visited){
                        stack.push(add);
                    }
                }   
                }
                
            }
            //reached a node without children, go back
            else{
                stack.pop();
                //increment post order
                curr->post = count++;
            }
       }
    return;
}

//helper method to check for cycles in graph by comparing
//pre and post ordering to check for back edges
//basically just modified explore method
//returns true if there is a cycle
template <class T>
bool checkCycle(Vertex<T> * vertex, Graph<T> &g){
    std::stack<Vertex <T> * > stack;
    stack.push(vertex);
       while(!stack.empty()){
           auto curr = stack.top();
            if(!curr->visited){
                curr->visited = true;
                if(curr->edges.size() != 0){
                for(auto it = curr->edges.begin(); it != curr->edges.end(); it++){
                    Vertex<T> * add = g.vertices.find(*it)->second;
                    if(!add->visited){
                         auto v = add;
                         auto u = vertex;
                         //compare pre and post ordering to check for back edge
                         if(v->pre < u-> pre && u->pre < u->post && u->post < v->post){
                             //cycle
                             return true;
                         }
                        stack.push(add);
                    }
                }   
                }
                
            }
            else{
                stack.pop();
            }
       }
       //no cycles
    return false;
}

//method to find topological ordering in a graph
//returns a list of vertex IDs in topological ordering
template <class T>
std::list<T> top_order(Graph<T>& g) {
  std::list<T> res;
  std::list<T> cycle;

 
  std::priority_queue<Vertex<T> * ,std::vector<Vertex<T> *>, bool
      (*)(Vertex<T> *, Vertex<T> *)> mypq(pq_compare);

  //explore and then add to priority queue to sort by ordering
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

  //check for cycles
  for(auto it = res.begin(); it != res.end(); it++){
      g.reset_graph();
      if(checkCycle(g.vertices.find(*it)->second, g)){
          return cycle;
      }
  }

  return res;
}

