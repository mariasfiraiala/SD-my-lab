#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>

/* useful macro for handling error codes */
#define DIE(assertion, call_description)				\
	do {								\
		if (assertion) {					\
			fprintf(stderr, "(%s, %d): ",			\
					__FILE__, __LINE__);		\
			perror(call_description);			\
			exit(errno);					\
		}							\
	} while (0)

#define MAX_PRIORITY 1000

typedef struct treap_node_t treap_node_t;
struct  treap_node_t {
	/* informatia nodului */
	void *data;

	/* prioritatea nodului */
	int priority;

	/* cei doi copii, stang si drept */
	treap_node_t *left, *right;
};

typedef struct treap_tree_t treap_tree_t;
struct treap_tree_t {
	/* radacina arborelui */
	treap_node_t  *root;

	 /* dimensiunea datelor continute in fiecare nod */
	size_t data_size;

	/* functie de comparare a doua noduri */
	int	(*cmp)(void *key1, void *key2);
};

/**
 * @brief Creeaza structura treap-ului
 * 
 * @param data_size Numarul de octeti pe care se scrie valoarea
 * @param cmp Functia de comparare a doua noduri
 * @return treap_tree_t* 
 */
treap_tree_t* treap_create(size_t data_size, int (*cmp)(void*, void*))
{
	// prioritatea va fi random
	srand(time(NULL));

	treap_tree_t *t = malloc(sizeof(*t));
    DIE(!t, "malloc() failed\n");

    t->cmp = cmp;
    t->data_size = data_size;
    t->root = NULL;

    return t;
}

/**
 * @brief Elibereaza memoria, plecand dintr-un nod
 * si mergand recursiv pe tot subarborele
 * 
 * @param node Nodul din care porneste
 */
static void __treap_node_free(treap_node_t** node, void (*free_data)(void *))
{
	if (!(*node))
        return;

    __treap_node_free(&(*node)->left, free_data);
    __treap_node_free(&(*node)->right, free_data);

    free_data((*node)->data);
    free(*node);
}

/**
 * @brief Elibereaza intreaga memoria folosita de treap
 * 
 * @param tree Arborele curent
 */
void treap_free(treap_tree_t* treap, void (*free_data)(void *))
{
	__treap_node_free(&(treap->root), free_data);
	free(treap);
}

/**
 * @brief Creeaza un nod
 * 
 * @param value Valoarea ce trebuie pusa in nod
 * @return treap_node_t
 */
static treap_node_t* __treap_node_create(void* data, size_t data_size)
{
	treap_node_t* node = malloc(sizeof(treap_node_t));
	DIE(!node, "malloc node");

	node->data = malloc(data_size);
	DIE(!node->data, "malloc node->data");

	memcpy(node->data, data, data_size);

	// Nodurile frunze au inaltimea 0
	node->priority = rand() % MAX_PRIORITY;
	node->left = NULL;
	node->right = NULL;

	return node;
}

int max(int a, int b)
{
	if (a > b) {
		return a;
	}

	return b;
}

int priority(treap_node_t* node)
{
	// Nodurile NULL au prioritatea -1 pentru a pastra proprietatea de max-heap
	if (!node) {
		return -1;
	}

	return node->priority;
}

/* Rotire dreapta
 * Pentru a nu fi nevoie sa mentinem pointer catre nodul parinte,
 * se vor folosi pointeri la noduri
 *
 *      node  			    lson
 *     /    \			   /    \
 *   lson    y    --->    x    node
 *   /  \     		           /   \
 *  x   lrson                lrson  y
 */
static void __rotate_right(treap_node_t** node)
{
	// TODO
}

/* Rotire stanga
 * Pentru a nu fi nevoie sa mentinem pointer catre nodul parinte,
 * se vor folosi pointeri la noduri
 *
 *     node  			    rson
 *    /    \			   /    \
 *   x     rson    --->  node    y
 *         /   \		 /   \
 *       rlson  y       x   rlson
 */
static void __rotate_left(treap_node_t** node)
{
    // TODO
}

/**
 * @brief Inserare in treap pornind dintr-un nod dat
 * 
 * @param node Nodul radacina al subarborelui din parcurgerea recursiva
 * @param data Valoare de adaugat in treap
 * @param data_size Numarul de octeti pe care se scrie valoarea
 * @param cmp Functia de comparare pentru datele din treap
 */
static void __treap_insert(treap_node_t** node,
						void* data,
						int data_size,
						int (*cmp)(void*, void*))
{
	// TODO
}

/**
 * @brief Inserare in treap
 * 
 * @param treap Arborele curent
 * @param data Valoare de adaugat in treap
 */
void treap_insert(treap_tree_t* treap, void* data) {
	__treap_insert(&(treap->root), data, treap->data_size, treap->cmp);
}

/**
 * @brief Stergere din treap pornind dintr-un nod dat
 * 
 * @param node Nodul radacina al subarborelui din parcurgerea recursiva
 * @param data Valoare de sters din treap
 */
static void __treap_delete(treap_node_t** node,
						void* data,
						int (*cmp)(void*, void*),
						void (*free_data)(void *))
{
	// TODO
}

/**
 * @brief Stergere din treap
 * 
 * @param treap Arborele curent
 * @param data Valoare de sters din treap
 */
void treap_delete(treap_tree_t* treap, void* data, void (*free_data)(void *)) {
	__treap_delete(&(treap->root), data, treap->cmp, free_data);
}

/**
 * @brief Gasirea unei valoari date in treap pornind dintr-un nod dat
 * 
 * @param node Nodul radacina al subarborelui din parcurgerea recursiva
 * @param data Valoare de sters in treap
 * @param cmp Functia de comparare pentru datele din treap
 * @return void* Valoarea gasita (data) sau NULL daca nu exista
 */
static void* __get_key(treap_node_t* node, void* data, int (*cmp)(void*, void*))
{
	// TODO
}

/**
 * @brief Gasirea unei valoari date in treap
 * 
 * @param treap Arborele curent
 * @param data Valoare de sters din treap
 * @return void* Valoarea gasita (data) sau NULL daca nu exista
 */
void* get_key(treap_tree_t* treap, void* data) {
	return __get_key(treap->root, data, treap->cmp);
}

/**
 * @brief Obtinerea cheilor sortate crescator,
 * presupunand ca datele din noduri sunt int-uri
 * 
 * @param node Nodul curent in parcurgerea recursiva
 * @param keys Array-ul prin care se intorc cheile sortate crescator
 * @param num_keys Numarul de chei adaugate in array
 */
void treap_ascending_nodes(treap_node_t* node, int* keys, int* num_keys)
{
	// TODO
}

/**
 * @brief Verifica daca un arbore respecta proprietatile unui treap
 * 
 * @param node Nodul curent in parcurgerea recursiva
 * @param compar Functia de comparare a datelor din fiecare nod
 * @return int Daca arborele e treap, vom returna numarul de noduri al arborelui,
 * altfel, vom returna o valoare negativa
 */
int check_treap(treap_node_t* node, int (*compar)(void*, void*))
{
	if (node == NULL) {
		return 0;
	} else if (node->left == NULL && node->right == NULL) {
		return 1;
	} else if (node->left == NULL) {
		if (priority(node) >= priority(node->right) &&
			compar(node->data, node->right->data) <= 0) {
			return 1 + check_treap(node->right, compar);
		}

		return INT_MIN;
	} else if (node->right == NULL) {
		if (priority(node) >= priority(node->left) &&
			compar(node->data, node->left->data) >= 0) {
			return 1 + check_treap(node->left, compar);
		}

		printf("%d %d %d\n",
			   priority(node),
			   priority(node->left),
			   priority(node->right));

		return INT_MIN;
	} else {
		if (priority(node) >= priority(node->left) &&
			priority(node) >= priority(node->right) &&
			compar(node->data, node->left->data) >= 0 &&
			compar(node->data, node->right->data) <= 0) {
			
			return 1 + check_treap(node->left, compar) +
				   check_treap(node->right, compar);
		}

		printf("%d %d %d\n",
			   priority(node),
			   priority(node->left),
			   priority(node->right));

		return INT_MIN;
	}
}

/* --- TEST CODE BEGINS HERE --- */

/* don't change this */
#define MAX_NODES 1000

int treap_cmp_int(void* value1, void* value2)
{
	int* a = (int*)value1;
	int* b = (int*)value2;

	if ((*a) > (*b)) {
		return 1;
	} else if ((*a) < (*b)) {
		return -1;
	}

	return 0;
}

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	treap_tree_t* treap = treap_create(sizeof(int), (int (*)(void*, void*))(treap_cmp_int));

	int task, no_inserts, no_deletes, no_finds;
	int value, no_nodes;
	char buf[256];
	char *ptr = NULL;
	
	fgets(buf, 256, stdin);
	sscanf(buf, "%d\n", &task);
	fgets(buf, 256, stdin);
	sscanf(buf, "%d\n", &no_inserts);
	fgets(buf, 256, stdin);
	
	if (task == 1) {
		printf("%s\n", "------------- TASK 1 -------------");
	} else if (task == 2) {
		printf("%s\n", "------------- TASK 2 -------------");
	} else if (task == 3) {
		printf("%s\n", "------------- TASK 3 -------------");
	} else {
		printf("%s\n", "------------- TASK 4 -------------");
	}

	// ------------- TASK 1 -------------
	ptr = buf;
	for (int i = 1; i <= no_inserts; ++i) {
		sscanf(ptr, "%d", &value);
		ptr = strchr(ptr + 1, ' ') + 1;
		treap_insert(treap, &value);

		// Used for checker.
		if (task == 1) {
			if (check_treap(treap->root, treap->cmp) == i) {
				printf("Correct insertion. Treap has %d nodes.\n",
					check_treap(treap->root, treap->cmp));
			} else {
				printf("%s\n", "Wrong insertion.");
			}
		}
	}

	// ------------- TASK 2 ------------
	if (task >= 2) {
		fgets(buf, 256, stdin);
		sscanf(buf, "%d", &no_finds);
		fgets(buf, 256, stdin);
		ptr = buf;

		for (int i = 1; i <= no_finds; ++i) {
			sscanf(ptr, "%d", &value);
			ptr = strchr(ptr + 1, ' ') + 1;

			if (task == 2) {
				if (get_key(treap, &value)) {
					printf("%d %s\n", value, "is in Treap.");
				} else {
					printf("%d %s\n", value, "is NOT in Treap.");
				}
			}
		}
	}

	// ------------- TASK 3 -------------
	if (task >= 3) {
		fgets(buf, 256, stdin);
		sscanf(buf, "%d", &no_deletes);
		fgets(buf, 256, stdin);
		ptr = buf;
		no_nodes = check_treap(treap->root, treap->cmp);

		for (int i = 1; i <= no_deletes; ++i) {
			sscanf(ptr, "%d", &value);
			ptr = strchr(ptr + 1, ' ') + 1;

			if (task == 3) {
				treap_delete(treap, &value, free);
				
				// Used for checker.
				if (check_treap(treap->root, treap->cmp) == no_nodes - i) {
					printf("Correct deletion. Treap has %d nodes.\n",
						   check_treap(treap->root, treap->cmp));
				} else {
					printf("%s\n", "Wrong deletion.");
				}
			}
		}
	}

	// ------------- TASK 4 -------------
	if (task == 4) {
		int keys[MAX_NODES] = { 0 };
		int num_keys = 0;

		treap_ascending_nodes(treap->root, keys, &num_keys);

		printf("Ascending keys: ");
		for (int i = 0; i < num_keys; ++i) {
			printf("%d ", keys[i]);
		}
		printf("\n");
	}

	treap_free(treap, free);
	return 0;
}
