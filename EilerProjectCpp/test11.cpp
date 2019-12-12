#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
using namespace std;
/*
https://euler.stephan-brumme.com/
Задача 11
Наибольшее произведение в таблице

В таблице 20×20 (внизу) четыре числа на одной диагонали выделены красным.

08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08
49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00
81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65
52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91
22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80
24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50
32 98 81 28 64 23 67 10 [26] 38 40 67 59 54 70 66 18 38 64 70
67 26 20 68 02 62 12 20 95 [63] 94 39 63 08 40 91 66 49 94 21
24 55 58 05 66 73 99 26 97 17 [78] 78 96 83 14 88 34 89 63 72
21 36 23 09 75 00 76 44 20 45 35 [14] 00 61 33 97 34 31 33 95
78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92
16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57
86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58
19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40
04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66
88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69
04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36
20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16
20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54
01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48

Произведение этих чисел 26 × 63 × 78 × 14 = 1788696.

Каково наибольшее произведение четырех подряд идущих чисел в
таблице 20×20, расположенных в любом направлении (вверх, вниз,
вправо, влево или по диагонали)?

In the 20×20 grid below, four numbers along a diagonal line have
been marked in red.

08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08
49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00
81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65
52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91
22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80
24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50
32 98 81 28 64 23 67 10 [26] 38 40 67 59 54 70 66 18 38 64 70
67 26 20 68 02 62 12 20 95 [63] 94 39 63 08 40 91 66 49 94 21
24 55 58 05 66 73 99 26 97 17 [78] 78 96 83 14 88 34 89 63 72
21 36 23 09 75 00 76 44 20 45 35 [14] 00 61 33 97 34 31 33 95
78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92
16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57
86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58
19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40
04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66
88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69
04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36
20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16
20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54
01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48

The product of these numbers is 26 × 63 × 78 × 14 = 1788696.

What is the greatest product of four adjacent numbers in the
same direction (up, down, left, right, or diagonally) in the 20×20 grid?
*/

string s = "08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08 "
           "49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00 "
           "81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65 "
           "52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91 "
           "22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80 "
           "24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50 "
           "32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70 "
           "67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21 "
           "24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72 "
           "21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95 "
           "78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92 "
           "16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57 "
           "86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58 "
           "19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40 "
           "04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66 "
           "88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69 "
           "04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36 "
           "20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16 "
           "20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54 "
           "01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48";

int const count_el_in_list = 20;
int seq_num = 4;
int int_arr[count_el_in_list][count_el_in_list];

vector<string> split_str(const string &delimiter, const string &str){
    vector<string> arr;
    int strlen = str.length();
    int dellen = delimiter.length();
    if (dellen == 0) return arr; // no change
    int i = 0;
    int k = 0;
    while (i < strlen){
        int j = 0;
        while (i + j < strlen && j < dellen && str[i + j] == delimiter[j]) j++;
        if (j == dellen){ // found delimeter
            arr.push_back(str.substr(k, i - k));
            i += dellen;
            k = i;
        }
        else i++;
    }
    arr.push_back(str.substr(k, i - k));
    return arr;
}

vector<int> str_to_int(vector<string> str_v){
    vector<int> int_v;
    int len = str_v.size();
    for (int i = 0; i < len; i++){
        int_v.push_back(stoi(str_v[i]));
    }
    return int_v;
}

vector<vector<int>> v_slice(vector<string> &origin, int slice_count){
    vector<vector<int>> sliced_v;
    vector<int> temp_v;
    int len_v = origin.size();
    int index = 0;
    while (index < len_v){
        for (int i = 0; i < slice_count; i++){
            temp_v.push_back(stoi(origin[index]));
            index++;
        }
        sliced_v.push_back(temp_v);
        temp_v.clear();
    }
    return sliced_v;
}

vector<vector<int>> seq;
void get_seq_horizont(vector<vector<int>> v, int numbers){
    vector<int> temp_seq;
    int len = v[0].size();
    int len_v = v.size();
    int i = 0, j = 0;
    int next_step = 0;
    while (i < len_v){
        for (; j < numbers + next_step; j++){
            temp_seq.push_back(v[i][j]);
            //cout << i << " " << j << " " << v[i][j] << endl;
        }
        next_step++;
        int temp_len = temp_seq.size();
        if (temp_len == numbers){
            seq.push_back(temp_seq);
            temp_seq.clear();
        }
        if (j < len) j = next_step;
        if (j == len){
            j = 0;
            i++;
            next_step = 0;
        }
    }
}

void get_seq_vertic(vector<vector<int>> v, int numbers){
    vector<int> temp_seq;
    int len = v[0].size();
    int len_v = v.size();
    int i = 0, j = 0;
    int next_step = 0;
    while (j < len_v){
        for (; i < numbers + next_step; i++){
            temp_seq.push_back(v[i][j]);
            //cout << i << " " << j << " " << v[i][j] << endl;
        }
        next_step++;
        int temp_len = temp_seq.size();
        if (temp_len == numbers){
            seq.push_back(temp_seq);
            temp_seq.clear();
        }
        if (i < len) i = next_step;
        if (i == len){
            i = 0;
            j++;
            next_step = 0;
        }
    }
}

void get_seq_diag_left(vector<vector<int>> v, int numbers){
    vector<int> temp_seq;
    int len = v[0].size();
    int len_v = v.size();
    int index = 0;
    int i = 0, j = 0;
    int next_step = 0;
    while (index <= len_v - numbers){
        for (; j < numbers + next_step; i++, j++){
            temp_seq.push_back(v[i][j]);
            //cout << i << " " << j << " " << v[i][j] << endl;
        }
        next_step++;
        int temp_len = temp_seq.size();
        if (temp_len == numbers){
            seq.push_back(temp_seq);
            temp_seq.clear();
        }
        i = index;
        j = next_step;
        if (next_step > len - numbers){
            index++;
            next_step = 0;
            i = index;
            j = 0;
        }
    }
}

void get_seq_diag_right(vector<vector<int>> v, int numbers){
    vector<int> temp_seq;
    int len = v[0].size();
    int len_v = v.size();
    int index = 0;
    int i = 0;
    int j = len - 1;
    int next_step = len - 1;
    while (index <= len_v - numbers){
        for (; j > next_step - numbers; i++, j--){
            temp_seq.push_back(v[i][j]);
            //cout << i << " " << j << " " << v[i][j] << endl;
        }
        next_step--;
        int temp_len = temp_seq.size();
        if (temp_len == numbers){
            seq.push_back(temp_seq);
            temp_seq.clear();
        }
        i = index;
        j = next_step;
        if (next_step < numbers - 1){
            index++;
            next_step = len - 1;
            i = index;
            j = len - 1;
        }
    }
}

vector<vector<int>> get_seq(vector<vector<int>> v, int numbers){
    vector<int> temp_seq;
    int len = v[0].size();
    int len_v = v.size();
    int index = 0;
    int i = 0, j = 0;
    int next_step = 0;
    while (i < len_v){
        for (; j < numbers + next_step; j++){
            temp_seq.push_back(v[i][j]);
            //cout << i << " " << j << " " << v[i][j] << endl;
        }
        next_step++;
        int temp_len = temp_seq.size();
        if (temp_len == numbers){
            seq.push_back(temp_seq);
            temp_seq.clear();
        }
        if (j < len) j = next_step;
        if (j == len){
            j = 0;
            i++;
            next_step = 0;
        }
    }
    i = 0;
    j = 0;
    next_step = 0;
    while (j < len_v){
        for (; i < numbers + next_step; i++){
            temp_seq.push_back(v[i][j]);
            //cout << i << " " << j << " " << v[i][j] << endl;
        }
        next_step++;
        int temp_len = temp_seq.size();
        if (temp_len == numbers){
            seq.push_back(temp_seq);
            temp_seq.clear();
        }
        if (i < len) i = next_step;
        if (i == len){
            i = 0;
            j++;
            next_step = 0;
        }
    }
    i = 0;
    j = 0;
    next_step = 0;
    while (index <= len_v - numbers){
        for (; j < numbers + next_step; i++, j++){
            temp_seq.push_back(v[i][j]);
            //cout << i << " " << j << " " << v[i][j] << endl;
        }
        next_step++;
        int temp_len = temp_seq.size();
        if (temp_len == numbers){
            seq.push_back(temp_seq);
            temp_seq.clear();
        }
        i = index;
        j = next_step;
        if (next_step > len - numbers){
            index++;
            next_step = 0;
            i = index;
            j = 0;
        }
    }
    index = 0;
    i = 0;
    j = len - 1;
    next_step = len - 1;
    while (index <= len_v - numbers){
        for (; j > next_step - numbers; i++, j--){
            temp_seq.push_back(v[i][j]);
            //cout << i << " " << j << " " << v[i][j] << endl;
        }
        next_step--;
        int temp_len = temp_seq.size();
        if (temp_len == numbers){
            seq.push_back(temp_seq);
            temp_seq.clear();
        }
        i = index;
        j = next_step;
        if (next_step < numbers - 1){
            index++;
            next_step = len - 1;
            i = index;
            j = len - 1;
        }
    }
    return seq;
}

int sum(vector<int> v){
    int n = 0;
    int len = v.size();
    for (int i = 0; i < len; i++){
        n = n + v[i];
    }
    return n;
}

unsigned long long product(vector<int> v){
    unsigned long long n = 1;
    int len = v.size();
    // cout << len << endl;
    for (int i = 0; i < len; i++){
        //cout << n << " * " << v[i] << " = ";
        n = n * v[i];
        //cout << n << endl;
    }
    return n;
}

void arr_slice(vector<string> &origin, int slice_count){
    int index = 0;
    for (int i = 0; i < slice_count; i++){
        for(int j = 0; j < slice_count; j++){
            int_arr[i][j] = stoi(origin[index]);
            index++;
        }
    }
}

template <class T>
void print_mass(T &mass, int count_el){
    for (int i = 0; i < count_el; i++){
        for(int j = 0; j < count_el; j++){
            cout << mass[i][j] << " "; // cout << typeid(mass[i][j]).name() << ", "; //посмотреть имя типа
        }
        cout << endl;
    }
}

void print_v(vector<vector<int>> v){
    int len = v.size();
    int len_inner = v[0].size();
    for (int i = 0; i < len; i++){
        for(int j = 0; j < len_inner; j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}


void eiler11(){
    vector<string> v = split_str(" ", s);
    vector<vector<int>> sliced_v = v_slice(v, count_el_in_list);
    //print_mass(sliced_v, count_el_in_list);
    /*arr_slice(v, count_el_in_list);
    print_mass(int_arr, count_el_in_list);*/
    /*vector<int> int_v = str_to_int(v);
    int res = sum(int_v);
    cout << res << endl;*/

    //vector<vector<int>> seq = get_seq(sliced_v, seq_num);
    get_seq_vertic(sliced_v, seq_num);
    get_seq_horizont(sliced_v, seq_num);
    get_seq_diag_left(sliced_v, seq_num);
    get_seq_diag_right(sliced_v, seq_num);
    int len = seq.size();
    //print_v(seq);
    unsigned long long result = 0;
    for (int i = 0; i < len; i++){
        unsigned long long temp = product(seq[i]);
        if (result < temp) result = temp;
    }
    cout << "#11. Result = " << result << " Len: " << len <<endl;
    // #11. Result = 70600674 Len: 1258
}
