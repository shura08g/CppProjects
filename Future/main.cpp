#include <iostream>
#include <random>
#include <set>
#include <algorithm>
#include <future>  //async

using namespace std;

set<int> make_sorted_random(const size_t num_elems){
    set<int> retval;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, num_elems - 1);

    generate_n(inserter(retval, retval.end()), num_elems, [&](){ return dis(gen); });

    return retval;
}

int main()
{
    set<int> s = make_sorted_random(100);
    cout << s.size() << '\n'
    ;

    //set<int>::iterator it;
    for (auto it = s.begin(); it != s.end(); it++){
        cout << *it << ' ';
    }

    cout << '\n';
    for (auto const &i: s){
        cout << i << ' ';
    }

    cout << '\n';
    auto f1 = async(launch::async, make_sorted_random, 10000);
    auto f2 = async(launch::async, make_sorted_random, 10000);
    auto f3 = async(launch::deferred, make_sorted_random, 10000);
    auto f4 = async(launch::deferred, make_sorted_random, 10000);
    auto f5 = async(make_sorted_random, 10000);

    const auto val1 = f1.get().size();
    const auto val2 = f2.get().size();
    const auto val3 = f3.get().size();
    const auto val4 = f4.get().size();
    const auto val5 = f5.get().size();

    cout << val1 << ' ' << val2 << ' ' << val3 << ' ' << val4 << ' ' << val5 << '\n';
    return 0;
}
