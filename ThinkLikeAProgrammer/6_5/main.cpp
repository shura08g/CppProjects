/*
������: ���������� ���������� ������� � �������� ������
 ��� ������, ������������ �������� ������, �������� ������������� �����,
 ������� ���������� ���������� ������� (����� ��� �������� ���������) �
 ������. ������� ������� ������ ����������� � �������������� ��������.
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
