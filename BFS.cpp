// CSE 101 Winter 2018, PA 1
//
// Name: Vincent Cannalla
// PID: A13006747
// Sources of Help: None
// Due: 1/26/2018 at 11:59 PM

#include "Graph.hpp"
#include <queue>
#include <map>
#include <list>
#include <set>

//method to perform BFS on a graph
//returns res which is a set of vertex IDs
template <class T>
std::set<T> bfs(Graph<T>& g, T t) {
  std::set<T> res;
  std::queue<Vertex<T> > queue;

  auto myVertex = g.vertices.find(t);

  //dereference myvertex iterator and use .second bc pair
  queue.push(*(*myVertex).second);

  while(!queue.empty()){
  Vertex<T> v = queue.front();
  queue.pop();

  if(!v.visited){
  v.visited = true;
  res.insert(v.id);
  }

  for(auto it = v.edges.begin(); it != v.edges.end(); it++){
    auto ver = *(*(g.vertices.find(*it))).second;
      if(!ver.visited){
            queue.push(ver); 
        }
    }
  }

  return res;
}

