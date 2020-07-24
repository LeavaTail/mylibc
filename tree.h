#ifndef _TREE_H
#define _TREE_H

#include <stdlib.h>
#include <stdint.h>

typedef struct node {
	uint32_t index;
	struct node *left;
	struct node *right;
} node_t;

static inline node_t* insert_node(node_t *node, uint32_t data)
{
	if (!node) {
		node = (node_t *)malloc(sizeof(node_t));
		node->index = data;
		node->left = NULL;
		node->right = NULL;
	} else {
		if(data < node->index)
			node->left = insert_node(node->left, data);
		else
			node->right = insert_node(node->right, data);
	}
	return node;
}

static inline node_t* search_node(node_t *node, uint32_t data)
{
	if (!node) {
		return NULL;
	} else if (data == node->index) {
		return node;
	} else if (data < node->index) {
			return search_node(node->left, data);
	} else {
			return search_node(node->right, data);
	}
}

#endif /*_TREE_H */
