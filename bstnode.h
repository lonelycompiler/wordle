#include <bool.h>

#ifndef BSTNODE_H
#define BSTNODE_H
struct bstNode
{
	struct bstNode parent;
	struct bstNode leftChild;
	struct bstNode rightChild;
	char data;
};

struct bst
{
	struct bstNode root;
	uint8_t size;
};

void insertIntoBST(struct bstNode, char newData);

bool searchBST(struct bstNode head, char targetData);
#endif
