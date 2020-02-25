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

tree_node *tree_root = NULL;

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

int delete_tree(int val){

    // valを削除　成功すれば1、失敗すれば0を返す
    tree_node *node, *parent_node;
    tree_node *left_biggest;

    int direction;

    node = tree_root;
    parent_node = NULL;
    direction = 0;

    // while文で削除すべき対象を見つける
    while(node != NULL && node->value != val){
        if(node->value > val){
            parent_node = node;
            node = node->left;
            direction = -1;   // 親の左側
        }else{
            parent_node = node;
            node = node->right;
            direction = 1;   // 親の右側
        }
    }

    if(node == NULL){   // Not found
        return 0;
    }

    if(node->left == NULL || node->right == NULL){
        // 左か右、どちらかがNULLの場合
        if(node->left == NULL){
            // 親のポインタを変更
            if(direction == -1){
                parent_node->left = node->right;
            }
            if(direction == 1){
                parent_node->right = node->right;
            }
            if(direction == 0){
                tree_root = node->right;
            }
        }else{
            // 親のポインタを変更する
            if(direction == -1){
                parent_node->left = node->left;
            }
            if(direction == 1){
                parent_node->right = node->left;
            }
            if(direction == 0){
                tree_root = node->left;
            }
        }
        free(node);
    }else{
        // 両者ともNULLではない　子が2つ

        // nodeの左側の最大値（最も右の値）を取得
        left_biggest = node->left;
        parent_node = node;
        direction = -1;

        while(left_biggest->right != NULL){
            parent_node = left_biggest;
            left_biggest = left_biggest->right;
            direction = 1;
        }

        // left_biggestの値をnodeに代入し、left_biggestは左側の枝を入れる
        node->value = left_biggest->value;
        if(direction == -1){
            parent_node->left = left_biggest->left;
        }else{
            parent_node->right = left_biggest->left;
        }
        free(left_biggest);
    }
    return 1;
}

void print_tree(int depth, tree_node* node){
    int i;

    if(node == NULL){
        return;
    }
    print_tree(depth + 1, node->left);
    for(i = 0; i < depth; i++){
        printf(" ");
    }
    printf("%d\n", node->value);
    print_tree(depth + 1, node->right);
}

void free_tree(tree_node* node){
    if(node == NULL){
        return;
    }
    // まず子nodeのメモリを解放する
    free_tree(node->left);
    free_tree(node->right);
    // 自分自身を解放
    free(node);
}

int main(void){
    int i, action;

    for(i = 0; i < 10; i++){
        insert_tree(rand() % 99 + 1, tree_root);
    }

    for(;;){
        print_tree(0, tree_root);
        printf("1:add 2:search 3:delete other than these, end\n");
        scanf("%d", &action);
        switch(action){
            case 1:
            printf("input value from 1 ~ 100 to add\n");
            scanf("%d", &i);
            if(i < 1 || i > 100){
                continue;
            }
            insert_tree(i, tree_root);
            break;
            
            case 2:
            printf("input number to search\n");
            scanf("%d", &i);
            if(find_value(tree_root, i) != NULL){
                printf("%d is found\n", i);
            }else{
                printf("%d is not found\n", i);
            }
            break;

            case 3:
            printf("input number to be deleted\n");
            scanf("%d", &i);
            if(delete_tree(i) == 1){
                printf("%d was deleted\n");
            }else{
                printf("%d was not found\n", i);
            }
            break;
            
            default:
            free_tree(tree_root);
            return EXIT_SUCCESS;
        }
    }
}