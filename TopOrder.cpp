// CSE 101 Winter 2018, PA 1
//
// Name: TODO put both partners' info if applicable
// PID: TODO
// Sources of Help: TODO
// Due: 1/26/2018 at 11:59 PM

#include "Graph.hpp"
// include more libraries as needed
#include <map>
#include <list>
#include <iostream>
#include <array>

template <class T>
std::list<T> top_order(Graph<T>& g) {
  std::list<T> res;
  // TODO: Implement TopOrder

  
  std::map<int, T> mymap;

  auto revG = g.reverse_graph();

  int i = 0;
  for(auto it = revG.vertices.begin(); it != revG.vertices.end(); it++){
    int count = (*(*it).second).edges.size();
    if(count == 0){
    mymap.insert(std::pair<int, T>(i, (*(*it).second).id));
    i++;
    }
  }

  for(auto it = mymap.begin(); it != mymap.end(); it++){
      auto curr = g.vertices.find((*it).second);
      
  }
    
  
  return res;
}

