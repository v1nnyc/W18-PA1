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
#include <stack>
#include <queue>

int count1 = 0;

template <class T>
bool pq_compare(Vertex<T> * v1, Vertex<T> * v2){
  return v1->post < v2->post;
}


template <class T>
static void explore(Vertex<T> * vertex){
    std::stack<Vertex <T> * > stack1;
    if(!vertex->visited){
        stack1.push(vertex);
        vertex->pre = count1;
        count1++;
    }
    else
        return;
    while(!stack1.isempty()){
        auto curr = stack1.top();
        if(curr->edges.size() !=0){
            for(auto it = curr->edges.begin(); it != curr->edges.end(); it++){
                stack1.push(*it);
            }
        }
        else{
            curr = stack1.pop();
            curr->post = count1;
            count1++;
        }
    }
    return;
}

template <class T>
std::list<T> top_order(Graph<T>& g) {
  std::list<T> res;

  
  std::priority_queue<Vertex<T> * ,std::vector<Vertex<T> *>, bool
      (*)(Vertex<T> *, Vertex<T> *)> mypq(pq_compare);

  for(auto it = g.vertices.begin(); it != g.vertices.end(); it++){
      //explore(&it);
      //mypq.push((*it));
  }

  //res.add(mypq.pop());





/*  int i = 0;
  for(auto it = revG.vertices.begin(); it != revG.vertices.end(); it++){
    int count = (*(*it).second).edges.size();
    if(count == 0){
    mymap.insert(std::pair<int, T>(i, (*(*it).second).id));
    i++;
    }
  }

  std::stack<Vertex <T> > stack;




  int count = 1;
  for(auto it = mymap.begin(); it != mymap.end(); it++){
      auto curr = g.vertices.find((*it).second);
      stack.push(*(*curr).second);

      while(!stack.empty()){
          Vertex<T> v = stack.top();

          if(!v.visited){
          v.pre = count;
          count++;
          v.visited=true;
          }

          for(auto it2 = v.edges.begin(); it2 != v.edges.end(); it2++){
               std::cout << "HEY\n" ;

           if(!(*(g.vertices.find(*it2))).second->visited){
               for(auto it3 = ((*(g.vertices.find(*it2))).second->edges).begin(); it3 !=  ((*(g.vertices.find(*it2))).second->edges).end(); it3++){
                   std::cout << "HEY2\n" ;
                   if(!(*g.vertices.find(*it3)).second->visited){
                       // stack.push((*(*(g.vertices.find(*it3))).second));
                       (*g.vertices.find(*it3)).second->visited = true;
                       std::cout << "HEY3\n";
                   }
               }
          }
           else{
               v.post = count;
               count++;
               stack.pop();
           }
      }

               
  }
}*/
    
  
  return res;
}

