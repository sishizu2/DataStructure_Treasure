tree_node* find_value(tree_node* node, int val){

    // 発見したtree_nodeのポインタを返す。なければ、NULL
    if(node->value > val){
        if(node->left == NULL){   // もし左側になければ、valはない
            return NULL;
        }
        return find_value(node->left, val);
    }
    
    // 自分より大きな値ならば右側
    if(node->value < val){
        if(node->right == NULL){
            return NULL;   // もし右側になければvalはない
        }
        return find_value(node->right, val);
    }

    // 見つかれば値を返す node->value <n でも n< node->valueでもない場合= node->value == val
    return node;
}