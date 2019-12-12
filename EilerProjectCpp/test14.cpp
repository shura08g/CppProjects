#include <iostream>
#include <vector>
#include <map>
using namespace std;
/*
https://euler.stephan-brumme.com/
Задача 14
Самая длинная последовательность Коллатца

Следующая повторяющаяся последовательность определена для множества
натуральных чисел:

n → n/2 (n - четное)
n → 3n + 1 (n - нечетное)

Используя описанное выше правило и начиная с 13, сгенерируется следующая
последовательность:

13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
Получившаяся последовательность (начиная с 13 и заканчивая 1)
содержит10 элементов. Хотя это до сих пор и не доказано (проблема Коллатца
(Collatz)), предполагается, что все сгенерированные таким образом
последовательности оканчиваются на 1.

Какой начальный элемент меньше миллиона генерирует самую длинную
последовательность?

Примечание: Следующие за первым элементы последовательности могут быть
больше миллиона.

The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
It can be seen that this sequence (starting at 13 and finishing at 1)
contains 10 terms. Although it has not been proved yet (Collatz Problem),
it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
*/

void print_v(vector<unsigned long> v){
    int len = v.size();
    cout << "<";
    for (int i = 0; i < len; i++){
        if (i == len - 1) cout << v[i];
        else cout << v[i] << ", ";
    }
    cout << ">" << endl;
}

void eiler14_my(){
    unsigned long limit = 1000000;
    vector<unsigned long> result;
    vector<unsigned long> temp;
    //for (int i = limit / 2; i <= limit; i++){
    for (unsigned long i = limit / 2; i <= limit ; i++){
        unsigned long num = i;
        temp.clear();
        temp.push_back(num);
        while (num != 1){
            if (num % 2 == 0) num = num / 2;
            else num = 3 * num + 1;
            temp.push_back(num);
            if (temp.size() > result.size()) result = temp;
        }
    }
    // print_v(result);
    cout << "#14. " << result[0] << " produces " << result.size() << " elements " << endl;
    // #14. 837799 produces 525 elements execution time : 1.587 s
}

// memoize all paths length for n up to 5000000
const size_t MaxN = 5000000 + 2;
// we could change MaxN at will:
// it just affects performance, not the result

// identify chain lengths we haven't computed so far
const int Unknown = -1;
// store chain lengths
vector<short> cache(MaxN, Unknown);

// recursively count steps of Collatz sequence
unsigned short steps(unsigned long x){
    // finished recursion ?
    if (x == 1) return 1;

    // try to use cached result
    if (x < cache.size() && cache[x] != Unknown) return cache[x];

    // next step
    unsigned long next;
    if (x % 2 == 0) next = x / 2;
    else next = 3 * x + 1;

    // deeper recursion
    auto result = 1 + steps(next);
    if (x < cache.size()) cache[x] = result;

  return result;
}

void eiler14(){
    // [smallest number] => [chain length]
    map<unsigned long , unsigned long > longest;
    // highest number analyzed so far
    unsigned long maxTested = 1;
    longest[maxTested] = 1; // obvious case
    unsigned long limit = 1000000;
    unsigned long x = limit;
    while (limit--){
        // compute remaining chain lengths
        for (; maxTested <= x; maxTested++) {
          // get chain length
          auto length = steps(maxTested);
          // at least as long as anything we have seen before ?
          if (length >= longest.rbegin()->second)
            longest[maxTested] = length;
        }
    }
    // find next longest chain for numbers bigger than x
    auto best = longest.upper_bound(x);
    // and go one step back
    best--;
    cout << "#14. " << best->first << endl;
    // #14. 837799
}

