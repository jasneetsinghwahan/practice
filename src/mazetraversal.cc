/* DFS with Path traversal with Source and Target using recursion*/
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>


// clang-format off
// This macro converts a 4D index (i, j, k, l) with respective dimensions
// (dim_i, dim_j, dim_k, dim_l) into a 1D index.
#define INDEX_2D_TO_1D(i, j, dim_i, dim_j) \
    (                                                           \
        (i) * (dim_j) +                                         \
        (j)                                                     \
    )
// clang-format on

#define INDEX_LEFTNEIGHBOR(i) (i-1)
#define INDEX_UPNEIGHBOR(i) (i-COLDIM)
#define INDEX_RIGHTNEIGHBOR(i) (i+1)
#define INDEX_DOWNNEIGHBOR(i) (i+COLDIM)

class GraphMaze{
    public:
    GraphMaze(std::vector<std::vector<int>> &g) : graph(g){}
    
    void printRoute(int root, int target, std::map<int, int> parent);
    void gridhaspath(std::pair<int, int> start, std::pair<int, int> finish);
    std::map<int, int> findneighbors(int focusnode);

    std::vector<std::vector<int>> graph;
    const int ROWDIM = 4;
    const int COLDIM = 4;
};

void GraphMaze::printRoute(int root, int target, std::map<int, int> parent){
    std::cout << "traversing from target: " << target << " row: " << target/ROWDIM << " col: "<< target%COLDIM << std::endl;
    int temp = parent[target];
    while( true){
      std::cout << "now at: " << temp << " row: " << temp/ROWDIM << " col: "<< temp%COLDIM<< std::endl;
      if (temp == root)
        break;
      temp = parent[temp];
  }
}

/**
*    @return std::map<int, int>: neighbors of the focus node in the format L, U, R, D 
*/ 
std::map<int, int> GraphMaze::findneighbors(int focusnode){
    std::map<int, int> neighbors;
    int row, col;
    row = focusnode/ROWDIM;
    col = focusnode%COLDIM;
    // if left neighbor exists
    if (col != 0 && (graph[row][col-1] == 1))
        neighbors[0] = 1;
    else
        neighbors[0] = 0;
    // if top neighbor exists
    if (row != 0 && (graph[row-1][col] == 1))
        neighbors[1] = 1;
    else
        neighbors[1] = 0;
    // if right neighbor exists
    if ((col != (COLDIM-1)) && (graph[row][col+1] == 1))
        neighbors[2] = 1;
    else
        neighbors[2] = 0;
    // if down neighbor exists
    if ((row != (ROWDIM-1)) && (graph[row+1][col] == 1))
        neighbors[3] = 1;
    else
        neighbors[3] = 0;

    return neighbors;
}


void 
GraphMaze::gridhaspath(std::pair<int, int> start, std::pair<int, int> finish){
    std::map<int, int> visited;
    std::map<int, int> parent;
    std::queue<int> q;
    q.push(INDEX_2D_TO_1D(start.first, start.second, ROWDIM,COLDIM));
    visited[INDEX_2D_TO_1D(start.first, start.second, ROWDIM,COLDIM)] = 1;
    bool found = false;
    while (!q.empty() && !found){
        int currnode = q.front();
        q.pop();
        std::map<int, int> neighbor = findneighbors(currnode);
        auto itr = neighbor.begin();
        for (; itr != neighbor.end(); itr++){
            if (itr->first == 0 && itr->second != 0) {
                if (visited[INDEX_LEFTNEIGHBOR(currnode)] != 1){
                    visited[INDEX_LEFTNEIGHBOR(currnode)] = 1;
                    parent[INDEX_LEFTNEIGHBOR(currnode)] = currnode;
                    q.push(INDEX_LEFTNEIGHBOR(currnode));
                    if (INDEX_LEFTNEIGHBOR(currnode) == INDEX_2D_TO_1D(finish.first, finish.second, ROWDIM, COLDIM))
                        found = true;
                }
            }
            if (itr->first == 1 && itr->second != 0) {
                if (visited[INDEX_UPNEIGHBOR(currnode)] != 1){
                    visited[INDEX_UPNEIGHBOR(currnode)] = 1;
                    parent[INDEX_UPNEIGHBOR(currnode)] = currnode;
                    q.push(INDEX_UPNEIGHBOR(currnode));
                    if (INDEX_UPNEIGHBOR(currnode) == INDEX_2D_TO_1D(finish.first, finish.second, ROWDIM, COLDIM))
                        found = true;
                }
            }
            if (itr->first == 2 && itr->second != 0) {
                if (visited[INDEX_RIGHTNEIGHBOR(currnode)] != 1){
                    visited[INDEX_RIGHTNEIGHBOR(currnode)] = 1;
                    parent[INDEX_RIGHTNEIGHBOR(currnode)] = currnode;
                    q.push(INDEX_RIGHTNEIGHBOR(currnode));
                    if (INDEX_RIGHTNEIGHBOR(currnode) == INDEX_2D_TO_1D(finish.first, finish.second, ROWDIM, COLDIM))
                        found = true;
                }
            }
            if (itr->first == 3 && itr->second != 0) {
                if (visited[INDEX_DOWNNEIGHBOR(currnode)] != 1){
                    visited[INDEX_DOWNNEIGHBOR(currnode)] = 1;
                    parent[INDEX_DOWNNEIGHBOR(currnode)] = currnode;
                    q.push(INDEX_DOWNNEIGHBOR(currnode));
                    if (INDEX_DOWNNEIGHBOR(currnode) == INDEX_2D_TO_1D(finish.first, finish.second, ROWDIM, COLDIM))
                        found = true;
                }
            }
        }
    }
    if (found == false)
        std::cout << "path doesn't exist between start: " << INDEX_2D_TO_1D(start.first, start.second, ROWDIM, COLDIM) << " row: " << start.first<< " col: " << start.second << " and \nfinish: " << INDEX_2D_TO_1D(finish.first, finish.second, ROWDIM, COLDIM) << " row: "<< finish.first << " col: " << finish.second << std::endl;
    else {
        std::cout << "path exists " << std::endl;
        printRoute(INDEX_2D_TO_1D(start.first, start.second, ROWDIM, COLDIM), INDEX_2D_TO_1D(finish.first, finish.second, ROWDIM, COLDIM), parent);
    }
}

int main()
{
    std::vector<std::vector<int>> grid = {
        {1,1,1,1},
        {1,0,1,1},
        {1,1,0,1},
        {1,0,1,1}
    };

    GraphMaze g1(grid);
    std::pair<int, int> start(0,0);
    std::pair<int, int> finish(2,2);
    g1.gridhaspath(start, finish);
    return 0;
}