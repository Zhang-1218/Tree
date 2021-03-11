#pragma once

#ifndef __HEAD_H__ 
#define __HEAD_H__ 

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<list>
#include<queue>
#include<stack>


using namespace std;

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
    struct Node* next;
    Node(int x) :val(x), left(NULL), right(NULL), next(NULL) {}
};

#endif __HEAD_H__