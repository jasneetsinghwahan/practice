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
  void DFS_iterative(int root, int target);
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

void MapSetGraph::DFS_iterative(int root, int target){
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
            if (marks[child] != 1){
                parent[child] =  currnode;
                if (child == target)
                    break;
                stk.push(child);
            }
        }
    }
    printRoute(root, target, parent);
}

int main()
{
    std::map<int, std::set<int>> edges = {{0, {1,2}},{1, {0,3}}, {2, {0,3}}, {3, {1,2,4,5}}, {4, {3}}, {5, {3}}};
    MapSetGraph g(edges);
    g.DFS(0, 4);
    g.DFS_iterative(0, 4);
    return 0;
}