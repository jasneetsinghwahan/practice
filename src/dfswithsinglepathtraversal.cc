/* DFS with Path traversal with Source and Target using recursion*/
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>
class MapSetGraph {
 public:
  MapSetGraph(std::map<int, std::set<int>> &em) : edge_map_(em) {}
  MapSetGraph(std::map<int, std::set<int>> &em,
              std::map<std::pair<int, int>, int> &w)
      : weights_(w), edge_map_(em) {}

  void DFS(int root, int target);
  void DFS_iterative(int root, int target, int allPathstracked);
  void BFS(int root);

  // A helper function for DFS that carries marks in recursive calls
  void DFS_helper(int root, int target, std::map<int, int> &marks, std::map<int, int> &parent);

  void DFS_helper_with_topo(int root, std::map<int, int> &marks,
                            std::vector<int> &topo_list);
  void printRoute(int root, int target, std::map<int, int> parent);
  // Topological sort assuming root doesn't have any incoming edges
  std::vector<int> TopologicalSort(int root);

  void PrintGraph();
  // Removes the edge between u,v
  void RemoveEdge(int u, int v);
  // Adds k intermediate nodes between u,v and
  // sets the edge weight between them to w
  void AddKNodesBetween(int u, int v, int k, int w);
  // Removes all intermediate nodes
  void RemoveAllIntermediateNodes();

  std::map<std::pair<int, int>, int> weights_;
  std::map<int, std::set<int>> edge_map_;
};

std::vector<int> 
MapSetGraph::TopologicalSort(int root){
  std::map<int, int> marks;
  std::map<int, int> parent;
  std::vector<int> topo_list;
  DFS_helper_with_topo(root, marks, topo_list);
  return topo_list;
}

void MapSetGraph::DFS_helper_with_topo(int root, std::map<int, int> &marks,
                            std::vector<int> &topo_list){
    
    //if(marks[root] == 1)    // root is visited
    //    return;
    marks[root] = 1;
    for (int child : edge_map_[root]){
        if (marks[child] != 1){
            DFS_helper_with_topo(child, marks, topo_list);
        }
    }
    topo_list.push_back(root);
}

void MapSetGraph::DFS(int root, int target) {
  std::map<int, int> marks;
  std::map<int, int> parent;
  DFS_helper(root, target, marks, parent);
  printRoute(root, target, parent);
  
}

void MapSetGraph::printRoute(int root, int target, std::map<int, int> parent){
    std::cout << "traversing from target: " << target << std::endl;
    int temp = parent[target];
    while( true){
      std::cout << "now at: " << temp << std::endl;
      if (temp == root)
        break;
      temp = parent[temp];
  }
}

void MapSetGraph::DFS_helper(int root, int target, std::map<int, int> &marks, std::map<int, int> &parent) {
  marks[root] = 1;
  std::cout << "visited: " << root << std::endl;
  // Iterate all children
  for (const int child : edge_map_[root]) {
    // Visit unmarked ones
    if (marks[child] != 1) {
      parent[child] = root;     // added to track the parent
      if (child == target)
        return;
      DFS_helper(child, target, marks, parent);
    }
  }
  // At this point, all children of root are visited.
}

void MapSetGraph::DFS_iterative(int root, int target, int allPathstracked = false){
    if (root == target){
        std::cout << "target same as src" << std::endl;
        return;
    }
    std::map<int, int> marks;       // default constructor makes value field as 0
    std::map<int, int> parent;
    std::stack<int> stk;
    stk.push(root);
    while (!stk.empty()){
        int currnode = stk.top();
        stk.pop();
        marks[currnode] = 1;    // mark as visited
        for (int child: edge_map_[currnode]){
            // parent map searched to endure that node whose parent is marked is not overwritten
            if (marks[child] != 1 && (parent.find(child) == parent.end())){
                parent[child] =  currnode;
                if (child == target && allPathstracked == false)
                    break;
                stk.push(child);
            }
        }
    }
    if (allPathstracked == false)
        printRoute(root, target, parent);
    else {
        auto itr = edge_map_.begin();
        for (; itr != edge_map_.end(); itr++){
            if (itr->first != root){
                printRoute(root, itr->first, parent);
            }
        }
    }
}

int main()
{
    std::map<int, std::set<int>> edges = {{0, {1,2, 5}},{1, {0,2, 3}}, {2, {0,1, 5, 3}}, {3, {1,2, 4, 6}}, {4, {3}}, {5, {0, 2}}, {6, {3}}};
    MapSetGraph g(edges);
    std::cout << "calling DFS recursive with path for single target" << std::endl;
    g.DFS(0, 4);
    bool allPathstracked = false;
    std::cout << "calling DFS iterative with path for single target" << std::endl;
    g.DFS_iterative(0, 1, allPathstracked);
    std::cout << "calling DFS iterative with path for all target" << std::endl;
    allPathstracked = true;
    g.DFS_iterative(0, 4, allPathstracked);
    std::map<int, std::set<int>> diredges = {{0, {1,2, 5}},{1, {2, 3}}, {2, {3}}, {3, {4, 6}}, {4, {}}, {5, {2}}, {6, {}}};
    MapSetGraph h(diredges);
    std::cout << "calling DFS with topo" << std::endl;
    std::vector<int> topo_list = h.TopologicalSort(0);
    for (int i = topo_list.size()-1; i >= 0; i--){
        std::cout << "now at: " << topo_list[i] << '\n'; 
    }
    return 0;
}