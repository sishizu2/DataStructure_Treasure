#include <stdio.h>
#include <stdlib.h>


typedef struct _tag_tree_node
{
    // このノードが保持する値
    int value;
    // 自分より小さい値のnode:図では左側のノード
    struct _tag_tree_node *left;
    
    // 自分より大きい値のnode:図では右側のノード
    struct _tag_tree_node *right;
    
} tree_node;

tree_node* create_new_node(int num){

    tree_node *tree_new;

    // 新しいnodeを作成して初期化する
    tree_new = (tree_node*)malloc(sizeof(tree_node));

    if(tree_new == NULL){
        exit(EXIT_FAILURE);
    }
    tree_new-> left = NULL;
    tree_new-> right = NULL;
    tree_new-> value = num;

    return tree_new;
}

// num = 挿入する値 node = 値を挿入するツリーの根を指すポインタ
void insert_tree(int num, tree_node *node){

    // 一つも挿入されていない場合
    if(node == NULL){
        tree_root = create_new_node(num);
        return;
    }

    // numが現在のnodeの値よりも小さい場合
    if(node->value > num){
        if(node->left != NULL){
            insert_tree(num, node->left);
        }else{
            // 左側に追加
            node->left = create_new_node(num);
        }
    }else{
        // num が現在のnodeの値以上の場合
        if(node->right != NULL){
            insert_tree(num, node->right);
        }else{
            // 右側に追加
            node->right = create_new_node(num);
        }
    }
    return;
}