#pragma once

#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<map>

using namespace std;

#define MAXNUM 26


struct TrieNode {
	int pass;   // 经过此节点的字符串数目
	int end;	// 以此节点为结尾的字符串数目
	struct TrieNode* nexts[MAXNUM];	// 所有可能路径的数组

	TrieNode()
		:pass(0)
		,end(0)
	{
		memset(nexts, NULL, sizeof(TrieNode*) * MAXNUM);
	}
};

class TrieTree
{
public:
	TrieTree()
		:root(new TrieNode)
	{}

	~TrieTree()
	{
		if (root)
		{
			delete root;
			root = NULL;
		}
	}

	// 插入字符串str
	void insert(const string word)
	{
		if (word.empty())
			return;

		TrieNode* node = root;
		node->pass++;
		int path = 0;
		for (int i=0; i<word.size(); i++)	// 从左往右遍历字符
		{
			path = word[i] - 'a';			// 有字符，对应走那条路
			if (node->nexts[path] == nullptr)
			{
				node->nexts[path] = new TrieNode();
			}
			node = node->nexts[path];		// 按照树路径往下走
			node->pass++;					// 更新对应节点pass
		}
		node->end++;						// 结尾节点end更新
	}

	// 查询word这个单词加入过几次
	int search(const string word)
	{
		if (word.empty())
			return 0;

		TrieNode* node = root;
		int path = 0;
		for (int i = 0; i < word.size(); i++)
		{
			path = word[i] - 'a';
			if (node->nexts[path] == nullptr)
				return 0;
			node = node->nexts[path];
		}

		return node->end;				// end表示以此路径结尾的字符串数目
	}

	// 所有加入的字符串中，有几个是以pre这个字符串作为前缀的
	int prefixNumber(const string pre)
	{
		if (pre.empty())
			return 0;

		TrieNode* node = root;
		int path = 0;
		for (int i = 0; i < pre.size(); i++)	// 寻找路径
		{
			path = pre[i] - 'a';
			if (node->nexts[path] == nullptr)
				return 0;
			node = node->nexts[path];
		}

		return node->pass;
	}

	// 销毁前缀树
	void destory(TrieNode* node)
	{
		if (node == nullptr)
			return;

		for (int i = 0; i < MAXNUM; i++)
		{
			destory(node->nexts[i]);
		}
		delete node;
		node = nullptr;
	}

	// 删除某一个字符串
	void deleteWord(const string word)
	{
		if (word.empty())
			return;

		// 先搜索一下是否包含此字符串
		if (search(word) != 0)
		{
			TrieNode* node = root;
			TrieNode* tmp = nullptr;
			set<TrieNode*> deleteSet;	// 要删除的节点集合
			int deleteIndex = -1;		// 第一个要删除的节点位置标记
			root->pass--;

			int path = 0;
			for (int i = 0; i < word.size(); i++)
			{
				path = word[i] - 'a';
				if (--(node->nexts[path]->pass) == 0)	// 如果某个节点的pass减为0，说明此节点及之后的所有节点都要进行删除，释放空间
				{	
					tmp = tmp == nullptr ? node : tmp;	// tmp保存要删除的第一个节点的上一个节点
					deleteIndex = deleteIndex == -1 ? path : deleteIndex;	// deleteIndex保存要删除的第一个节点在上一个节点中的所处位置即下标
					deleteSet.insert(node->nexts[path]);	// 将要删除的节点加入集合
				}
				node = node->nexts[path];				// 继续遍历前缀树
			}
			--node->end;								// 更新结尾节点的end

			if (tmp != nullptr && !deleteSet.empty())	// 判断是否要进行节点的删除，空间的释放
			{
				tmp->nexts[deleteIndex] = nullptr;
				for (auto deletenode : deleteSet)
				{
					delete deletenode;
					deletenode = nullptr;
				}
			}
		}
		return;
	}

private:
	TrieNode* root;
};

