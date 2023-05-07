#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bst.h"

static bst_node_t *__bst_tree_remove(bst_node_t *bst_node,
                                    void *data, size_t data_size,
                                    int (*cmp)(const void *, const void *))
{
    int rc;
    bst_node_t *tmp, *max_left, *min_right;

    if (!bst_node)
        return NULL;

    rc = cmp(data, bst_node->data);

    if (rc < 0) {
        bst_node->left = __bst_tree_remove(bst_node->left, data, data_size, cmp);
    } else if (rc > 0) {
        bst_node->right = __bst_tree_remove(bst_node->right, data, data_size, cmp);
    } else {
        if (bst_node->left == NULL) {
            tmp = bst_node->right;
            free(bst_node->data);
            free(bst_node);
            return tmp;
        }

        if (bst_node->right == NULL) {
            tmp = bst_node->left;
            free(bst_node->data);
            free(bst_node);
            return tmp;
        }

        min_right = bst_node->right;
        while (min_right != NULL && min_right->left != NULL)
            min_right = min_right->left;

        max_left = bst_node->left;
        while (max_left != NULL && max_left->right != NULL)
            max_left = max_left->right;

        if (cmp(bst_node->data, max_left->data) < cmp(min_right->data, bst_node->data)) {
            memcpy(bst_node, max_left, sizeof(*max_left));
            max_left = __bst_tree_remove(bst_node->left, data, data_size, cmp);
        } else {
            memcpy(bst_node, min_right, sizeof(*min_right));
            min_right = __bst_tree_remove(bst_node->right, data, data_size, cmp);
        }
    }

    return bst_node;
}

int main(void)
{
    printf("I'm using DIE when Maria says so\n");

    return 0;
}
