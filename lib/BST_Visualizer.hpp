//
// From: https://github.com/YoussefRaafatNasry/bst-ascii-visualization
// modified to work with our Token class
//

#ifndef ARITHMETICTREE_BST_VISUALIZER_HPP
#define ARITHMETICTREE_BST_VISUALIZER_HPP

#include "../src/Token Classes/Token.hpp"
#include <string>
#include <queue>


using namespace std;


class BST_Visualizer
{
public:

    explicit BST_Visualizer(Token*, int = -1, int = -1);
    ~BST_Visualizer() = default;
    void visualize() const;

private:
    Token* tree_root_;
    int tree_height_;
    int tree_nodes_;
    string** values_;

    int node_length_;
    int node_type_;
    int node_shift_factor_;
    string empty_node_;

    int space_length_;
    int space_shift_factor_;

    queue<Token*> breadth_first_search();
    int get_tree_height(Token*) const;
    int get_nodes_count(int) const;
    int get_subtree_width(int) const;
};

#endif //ARITHMETICTREE_BST_VISUALIZER_HPP