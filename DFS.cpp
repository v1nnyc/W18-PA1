// CSE 101 Winter 2018, PA 1
//
// Name:Vincent Cannalla 
// PID: A13006747
// Sources of Help: None
// Due: 1/26/2018 at 11:59 PM

#include "Graph.hpp"
#include <stack>
#include <map>
#include <list>
#include <set>

//method for performing DFS
//returns res, which is a set of vertex IDs
template <class T>
std::set<T> dfs(Graph<T>& g, T t) {
  std::set<T> res;
  std::stack<Vertex<T> > stack;

  //finding vertex from map of vertices
  auto myVertex = g.vertices.find(t);

  //dereference myvertex iterator and use .second bc pair
  stack.push(*(*myVertex).second);

  while(!stack.empty()){
    Vertex<T> v = stack.top();
    stack.pop();

    if(!v.visited){
        v.visited = true;
        res.insert(v.id);
    }

    //go through all the edges
    for(auto it = v.edges.begin(); it != v.edges.end(); it++){
        auto ver = *(*(g.vertices.find(*it))).second;
        if(!ver.visited){
            stack.push(ver); 
        }
    }
  }
  return res;
}

