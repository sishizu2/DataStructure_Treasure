typedef struct _tag_tree_node
{
    // このノードが保持する値
    int value;
    // 自分より小さい値のnode:図では左側のノード
    struct _tag_tree_node *left;
    
    // 自分より大きい値のnode:図では右側のノード
    struct _tag_tree_node *right;
    
} tree_node;
