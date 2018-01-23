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


static int count = 1;

template <class T>
bool pq_compare(Vertex<T> * v1, Vertex<T> * v2){
  return v1->post < v2->post;
}


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
                for(auto it = curr->edges.begin(); it != curr->edges.end(); it++){
                    Vertex<T> * add = g.vertices.find(*it)->second;
                    if(!add->visited){
                        stack.push(add);
                    }
                }   
                }
                
            }
            else{
                stack.pop();
                curr->post = count++;
            }
       }
    return;
}

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
                         if(v->pre < u-> pre && u->pre < u->post && u->post < v->post){
                             std::cout << "U: " << u->id << "\n";
                             std::cout << "V: " << v->id << "\n";

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
    return false;
}

template <class T>
void unvisit(Graph<T>& g){
    for(auto it = g.vertices.begin(); it != g.vertices.end(); it++){
        it->second->visited = false;
    }
}

template <class T>
std::list<T> top_order(Graph<T>& g) {
  std::list<T> res;
  std::list<T> cycle;

 
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

  //check for cycles
  for(auto it = res.begin(); it != res.end(); it++){
      unvisit(g);
      if(checkCycle(g.vertices.find(*it)->second, g)){
          return cycle;
      }
  }




    
  
  return res;
}

