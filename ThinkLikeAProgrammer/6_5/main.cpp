/*
«адача: нахождение количества листьев в двоичном дереве
 ƒл€ класса, реализующего двоичное дерево, добавьте общедоступный метод,
 который возвращает количество листьев (узлов без дочерних элементов) в
 дереве. ѕодсчет листьев должен выполн€тьс€ с использованием рекурсии.
*/

#include <iostream>
#include "binaryTree.h"

using namespace std;

int main()
{

    binaryTree bt;
    int leafCount = bt.publicLeafCount();
    cout << leafCount << '\n';

    int stackLeafCount = bt.stackBasedCountLeaves();
    cout << stackLeafCount << '\n';
    return 0;
}
