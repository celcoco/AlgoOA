//
// Created by Allen Chen on 8/3/16.
//

#ifndef ALGOOA_TREE_H
#define ALGOOA_TREE_H

#include <iostream>
using namespace std;
struct TreeNode{
    int val = 0;
    TreeNode* left;
    TreeNode* right;
    TreeNode* ParalRigt;
    TreeNode(int x) : val(x),left(NULL),right(NULL),ParalRigt(NULL){};
};
int TreeLen(TreeNode* node);
int TreeLenMini(TreeNode* node);
void TreeInsert(TreeNode*& node,int data);
void TreeDele(TreeNode*& node);
void RecPrint(TreeNode* node);
void RecPrint2(TreeNode* node);
void TreePrint(TreeNode* node);
int TreeMiniDist(TreeNode* node);
#endif //ALGOOA_TREE_H
