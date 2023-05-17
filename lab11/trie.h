#ifndef __TRIE_H__
#define __TRIE_H__

#define DIE(assertion, call_description)                       \
    do                                                         \
    {                                                          \
        if (assertion)                                         \
        {                                                      \
            fprintf(stderr, "(%s, %d): ", __FILE__, __LINE__); \
            perror(call_description);                          \
            exit(errno);                                       \
        }                                                      \
    } while (0)

struct trie_node_t {
    struct trie_node_t **children;
    int count;
    int partial_count;
};

#endif /* __TRIE_H__ */