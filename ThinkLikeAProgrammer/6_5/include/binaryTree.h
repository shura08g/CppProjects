#ifndef BINARYTREE_H
#define BINARYTREE_H


class binaryTree
{
    public:
        binaryTree();
        int publicLeafCount();
        int stackBasedCountLeaves();
    private:
        struct binaryTreeNode{
            int data;
            binaryTreeNode * left;
            binaryTreeNode * right;
        };
        typedef binaryTreeNode * treePrt;
        treePrt _root;
        int privateLeafCount(treePrt rootPrt);
};

#endif // BINARYTREE_H
