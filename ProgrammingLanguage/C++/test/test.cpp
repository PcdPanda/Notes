/* 
 * Starter file for: 
 *   W21, Final Exam, Question 25
 * 
 * Do not try to submit this file to the autograder!
 * Upload it to Gradescope: 
 *   [W21] Final Question 25
 *
 * Before uploading, as you "browse" for the file, check the last modified time!
 * It should be when you last saved the file. 
 * Make sure you are uploading a file named question_25.cpp 
 */


// You may NOT add any additional includes
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

// DO NOT MODIFY ANYTHING ABOVE THIS LINE!


struct Location {
   int id;
   int distance;
   bool visited;
   Location(int id_in, int distance_in, int visited_in)
     : id(id_in), distance(distance_in), visited(visited_in) {}
};

struct LocationComp {
   bool operator() (const Location& v1, const Location& v2) {
       if(v1.distance==v2.distance){
           return v1.id<v2.id;
       }else{
           return v1.distance<v2.distance;
       }
   }
};


// REQUIRES: initialized adjacency list of Locations IDs (adjlst)
// EFFECTS: implements the postal routing algorithm described
//          in Question #25
// CONSTRAINTS: Worst case O(V log V + E) time and O(V) space,
//              where N is the number of vertices (locations).
vector<int> question_25(const vector<vector<int> > &adjlst) {
    if(adjlst.empty()) return {};
    vector<Location> graph;
    for(size_t j=0;j<adjlst.size();++j){
        graph.emplace_back(j,0,false);
    }
    graph[0].visited = true;
    vector<int> res(adjlst.size());
    vector<int> res;
    queue<Location> BFS;
    int distance = 1;
    BFS.emplace(0,0,true);
    while(!BFS.empty()){
        size_t sz = BFS.size();
        for(size_t i = 0;i<sz;++i){
            Location cur = BFS.front();
            BFS.pop();
            for(int id:adjlst[cur.id]){//each adj
                if(!graph[id].visited){// if not visited
                    graph[id].visited=true;
                    graph[id].distance = distance;
                    BFS.emplace(graph[id]);
                }
            }// end each adj
        }//end for
        distance++;
    }//end while
    sort(graph.begin(),graph.end(),LocationComp());
    std::cout << graph.size();
    for(Location & lc:graph){
        res.push_back(lc.id);
    }
    return res;
} // question_25()

int main(){
    auto x = question_25({{1,3}, {4, 0}, {5,3,4}, {0,2}, {1,2}, {2}});
    std::cout << x.size();
    // for(auto ans:x){
    //     std::cout << ans << "\n";
    // }
}
