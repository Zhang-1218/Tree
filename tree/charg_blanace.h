#pragma once

#include"head.h"

int maxDepth(Node* root)
{
	if (root == nullptr)
		return 0;

	return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int minDepth(Node* root)
{
	if (root == nullptr)
		return 0;

	return 1 + min(maxDepth(root->left), maxDepth(root->right));
}

bool chargeBlance(Node* node)
{
	if (node == nullptr)
		return true;
	
	return (maxDepth(node)-minDepth(node) <= 1);
}

