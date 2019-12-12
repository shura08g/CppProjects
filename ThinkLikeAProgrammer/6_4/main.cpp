/*
Задача: нахождение наибольшеге значения в двоичном дереве
 Напишите функцию, которая при передаче двоичного дерева, где каждый
 узел содержит целое число, возвращает наибольшее целое число в дереве.

*/

#include <iostream>

using namespace std;

struct treeNode{
    int data;
    treeNode * left;
    treeNode * right;
};

typedef treeNode * treePtr;

int maxValue(treePtr root){
    if (root == NULL) return 0;
    if (root->right == NULL && root->left == NULL)
        return root->data;
    int leftMax = maxValue(root->left);
    int rightMax = maxValue(root->right);
    int maxNum = root->data;  // чтобы избежать возврата 0 если все числа отрицательные
    // cout << maxNum << '\n';
    if (leftMax > maxNum) maxNum = leftMax;
    if (rightMax > maxNum) maxNum = rightMax;
    return maxNum;
}

int main()
{
    treeNode * node1 = new treeNode;
    node1->data = -50;
    treeNode * node2 = new treeNode;
    node2->data = -40;
    treeNode * node3 = new treeNode;
    node3->data = -60;
    treeNode * node4 = new treeNode;
    node4->data = -20;
    treeNode * node5 = new treeNode;
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

    int maxVal = maxValue(node1);

    string rawStr = R"(Print "RAW"
                       string \n)";

    cout << rawStr << '\n';

    cout << R"(Test
               "RAW"
               string)" << '\n';
    cout << R"stuff(Test
               )))"RAW"(((
               string)stuff" << '\n';
    cout << maxVal << '\n';

    return 0;
}
