#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "trie.h"

#define ALPHABET_SIZE 26

struct trie_node_t *init_node()
{
    struct trie_node_t *root = malloc(sizeof(*root));
    DIE(!root, "malloc() failed");
    root->children = NULL;
    root->count = 0;
    root->partial_count = 0;
    return root;
}

void insert_trie(struct trie_node_t *root, const char *str)
{
    char letter = *str;

    if (!root->children)
    {
        root->children = malloc(ALPHABET_SIZE * sizeof(struct trie_node_t *));
        DIE(!root->children, "malloc() failed");
        for (int i = 0; i < ALPHABET_SIZE; ++i)
            root->children[i] = NULL;
    }

    if (!root->children[letter - 'a'])
        root->children[letter - 'a'] = init_node();

    if (*(str + 1) != '\0')
        insert_trie(root->children[letter - 'a'], str + 1);
    else
        root->count++;

    root->partial_count++;
}

void free_trie(struct trie_node_t *root)
{
    if (root->children) {
        for (int i = 0; i < ALPHABET_SIZE; ++i) 
            if (root->children[i])
                free_trie(root->children[i]);
        free(root->children);
    }
    free(root);
}

int main()
{
    printf("Trie again!\n");
    return 0;
}
