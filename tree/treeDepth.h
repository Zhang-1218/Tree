#pragma once

#include"head.h"

// 递归解法
int treeDepth(Node* node)
{
	if (node == nullptr)
		return 0;

	int leftd = treeDepth(node->left);
	int rightd = treeDepth(node->right);

	return 1 + max(leftd, rightd);
}

// 循环解法
int treeDepthFor(Node* node)
{
	if (node == nullptr)
		return 0;

	queue<Node*> q;
	int depth = 0;
	
	q.push(node);
	while (!q.empty())
	{
		int len = q.size();
		while (len--)
		{
			Node* cur = q.front();
			q.pop();
			if (cur->left != nullptr)
				q.push(cur->left);
			if (cur->right != nullptr)
				q.push(cur->right);
		}
		
		++depth;
	}
	return depth;
}

int minDept(Node* root) {
	if (root == nullptr) {
		return 0;
	}
	return 1 + min(minDept(root->left), minDept(root->right));
}

