void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test7();
void test8();
void test9();

/*
C++: ��� ���������� ��������� �� ������?

1. ������ �������� ������ ������.
2. � ������ ��� ������.
3. ���������� ���������� ����������, �� ��� ���������� ������.
4. ��������� ����� ����� ����������� �������� � �������
��� ����� �������� ����� ��������������.


1. ��������� ����� ���� ������������ ����� ���������� ���,
� �� ����� ��� ������ ����� �������� �� ����� ���� ����������
 �� ������ ������ ������.

2. ��������� ����� ��������� "� ������" (���� ������� NULL),
� �� ����� ��� ������ ������ ��������� �� ������������ ������.
GCC ����� ��� ������ �������������� ���������� ��� ���������
int &x = *(int*)0;, ������ ��������� ��������� ���� �����
���� ���������������.

3. �� �� ������ �������� ����� ������, ��� ������ ��� ������
� �����������.

4. �� ���������� ���������� ������, � �� ����� ��� ����������
���������� ����������. ������ ���� ����������� �������� �����
�������, ���������� �� ������, � ��������� � ����� ������
���������� ���������� (�������� &obj + 5).


*/
/*
��� ����� int (* m1)() ?
��������� �� ������� ������� �� ����� ���������� � ���������� �����
��� ����� float (*(* m2)(int, float))(int) ?
��������� �� ������� ������� ��������� int � float � ����������
��������� �� ������� ������� ��������� int � ���������� float
*/

/*
��� ���������� unique_ptr �� shared_ptr?

1. ����������� unique_ptr , ���� ��� ����� ���� ��������� �� ������,
������� ����� ������������ ��� ����������� ����� ������������� ���������.
2. ����������� shared_ptr , ���� ��� ����� ��������� ���������� �� ����
� ��� �� ������.

*/
