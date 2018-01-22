// CSE 101 Winter 2018, PA 1
//
// Name: TODO put both partners' info if applicable
// PID: TODO
// Sources of Help: TODO
// Due: 1/26/2018 at 11:59 PM

#include "Graph.hpp"
#include <stack>
#include <map>
#include <list>
#include <set>

template <class T>
std::set<T> dfs(Graph<T>& g, T t) {
  std::set<T> res;
  // TODO: Implement DFS
  std::stack<Vertex<T> > stack;

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

  for(auto it = v.edges.begin(); it != v.edges.end(); it++){
    auto ver = *(*(g.vertices.find(*it))).second;
      if(!ver.visited){
            stack.push(ver); 
        }
    }
  }

  return res;
}

