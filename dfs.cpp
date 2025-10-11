#include <iostream>
#include <vector>

typedef struct{
    const int row;
    const int col;
    bool queen;
    bool movable;
    std::vector<Node> attackNode;
}Node;