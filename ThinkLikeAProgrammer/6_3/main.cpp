/*
«адача: подсчЄт отрицатальных чисал в односв€зном списке
 Ќапишите рекурсивную функцию, которой дан односв€зный список с
целочисленным типом данных. ‘ункци€ должна возвращать количество
отрицательных чисел в этом списке.
*/

/*
«адача: отображение элементов св€зного списка в пр€мом пор€дке
 Ќапишите функцию, которой передаетс€ указатель на головной элемент
 односв€зного списка, где типом данных каждого узла €вл€етс€ целое
 число, и котора€ отображает эти целые числа по одному на строке в
 пор€дке  их  следовани€  в  списке.
*/

/*
«адача: отображение элементов св€зного списка в обратном пор€дке
 Ќапишите функцию, которой передаетс€ указатель на головной элемент
 односв€зного списка, где типом данных каждого узла €вл€етс€ целое число,
 и котора€ отображает эти целые числа по одному на строке в пор€дке,
 обратном пор€дку их следовани€ в списке.
*/

#include <iostream>
#include <stack>

using namespace std;

struct ListNode{
    int data;
    ListNode * next;
};

typedef ListNode * listPrt;

int countNegative(listPrt head){
    if (head == NULL) return 0;
    int listCount = countNegative(head->next);
    if (head->data < 0) listCount++;
    return listCount;
}

void displayListForwardsIterative(listPrt head){
    for (listPrt current = head; current != NULL; current = current->next){
        cout << current->data << '\n';
    }
}

void displayListBackwardsIterative(listPrt head){
    stack<listPrt> nodes;
    for (listPrt current = head; current != NULL; current = current->next){
        nodes.push(current);
    }
    while (!nodes.empty()){
        listPrt current = nodes.top();
        nodes.pop();
        cout << current->data << '\n';
    }
}

void displayListForwardsRecursion(listPrt head){
    if (head != NULL){
        cout << head->data << '\n';
        displayListForwardsRecursion(head->next);
    }
}

void displayListBackwardsRecursion(listPrt head){
    if (head != NULL){
        displayListBackwardsRecursion(head->next);
        cout << head->data <<'\n';
    }
}

int main()
{
    ListNode *lst1 = new ListNode;
    lst1->data = -15;
    ListNode *lst2 = new ListNode;
    lst2->data = -10;
    ListNode *lst3 = new ListNode;
    lst3->data = -10;
    ListNode *lst4 = new ListNode;
    lst4->data = 10;
    ListNode *lst5 = new ListNode;
    lst5->data = 0;

    lst1->next = lst2;
    lst2->next = lst3;
    lst3->next = lst4;
    lst4->next = lst5;
    lst5->next = NULL;

    listPrt lstPrt = lst1;

    int countNeg = countNegative(lstPrt);

    cout << "Count negative numbers: "<< countNeg << '\n';

    cout << "Forwards iterative: " << '\n';
    displayListForwardsIterative(lstPrt);
    cout << "Backwards iterative: " << '\n';
    displayListBackwardsIterative(lstPrt);
    cout << "Forwards recursion: " << '\n';
    displayListForwardsRecursion(lstPrt);
    cout << "Backwards recursion: " << '\n';
    displayListBackwardsRecursion(lstPrt);
    return 0;
}
