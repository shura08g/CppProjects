/*
������: ��������� ������� �������
�������� DelegateCorp ������ ����������, ����� �� ������ �������� ��������
��� �������� ���������� �������. ��� ������� ��������� ��� � ������
���������� ������� ������. ��-������, ����������� ����� ������� �� �������
������� �������� ���� ������ ����� ������� � �������� �������� �� ��������
������� � ���������. ��-������, ���������� DelegateCorp, ��� ������� ��
��������, ����� ������������, � ������ ��������� ��� ����� �����������
��������� �������� ������ ������ ������������. ����� �������� �� �����
��-��� ��������, �������� ������������� �������, �������� �������� ���
������������� ��������� ������ ��������� ����� ������ ��������������
� �������� ������������ ������ ������, ��� ��������� ��� ������.

���������               ����
 ��������                 1
 ����-��������            2
 �����������  ���������   3
 ��������  ���������      4
 �������  ��������        5
 ������             	  6

 ����� �������    �������
 �0001            $172000
 �0002            $68000
 �0003            $193000
 �0004            $13000
 �0005            $256000
 �0006            $99000

*/

#include <iostream>
//#include <string>

int maximum(int a, int b){
    if (a > b) return a;
    if (a < b) return b;
    return a;
}

int max_profit(int arr[], int size){
    if (size == 0) return 0;
    return maximum(arr[size - 1], max_profit(arr, size - 1));
}

int find_client_index(int arr[], int profit_cl, int size){
    int index = 0;
    for (int i = 0; i < size; ++i){
        if (arr[i] == profit_cl){
            index = i;
            return index;
        }
    }
    return index;
}

int main()
{
    const int COUNT_CLIENT = 6;
    std::string employe[] = {"Manager",
                             "Vice-manager",
                             "Zam-manager",
                             "Pom-manager",
                             "Junior-manager",
                             "Trainer"};
    int rang[] = {1, 2, 3, 4, 5, 6};

    std::string client[] = {"#0001",
                            "#0002",
                            "#0003",
                            "#0004",
                            "#0005",
                            "#0006"};

    int profit[COUNT_CLIENT] = {172000, 68000, 193000, 13000, 256000, 99000};

    int max_prof = max_profit(profit, COUNT_CLIENT);

    int client_index = find_client_index(profit, max_prof, COUNT_CLIENT);

    std::cout << "Max profit: " << max_prof << "$" << " from client " << client[client_index] << '\n';

    return 0;
}
