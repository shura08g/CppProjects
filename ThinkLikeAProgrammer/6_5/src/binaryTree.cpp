#include "binaryTree.h"
#include <cstddef>
#include <iostream>
#include <stack>

binaryTree::binaryTree()
{
    binaryTreeNode * node1 = new binaryTreeNode;
    node1->data = -50;
    binaryTreeNode * node2 = new binaryTreeNode;
    node2->data = -40;
    binaryTreeNode * node3 = new binaryTreeNode;
    node3->data = -60;
    binaryTreeNode * node4 = new binaryTreeNode;
    node4->data = -20;
    binaryTreeNode * node5 = new binaryTreeNode;
    node5->data = -30;
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = NULL;
    node3->right = NULL;
    node4->left = NULL;
    node4->right = NULL;
    node5->left = NULL;
    node5->right = NULL;
    _root = node1;
}

int binaryTree::privateLeafCount(treePrt rootPrt){
    if (rootPrt == NULL) return 0;
    if (rootPrt->right == NULL && rootPrt->left == NULL)
        return 1;
    int leftCount = privateLeafCount(rootPrt->left);
    int rightCount = privateLeafCount(rootPrt->right);
    std::cout << leftCount << " " << rightCount << '\n';
    return leftCount + rightCount;
}

int binaryTree::publicLeafCount(){
    return privateLeafCount(_root);
}

int binaryTree::stackBasedCountLeaves(){
    if (_root == NULL) return 0;
    int leafCount = 0;
    std::stack<binaryTreeNode *> nodes;
    nodes.push(_root);
    while (!nodes.empty()){
        treePrt currentNode = nodes.top();
        nodes.pop();
        if (currentNode->left == NULL && currentNode->right == NULL)
            leafCount++;
        else{
            if (currentNode->left != NULL) nodes.push(currentNode->left);
            if (currentNode->right != NULL) nodes.push(currentNode->right);
        }
    }
    return leafCount;
}
