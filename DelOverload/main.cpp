#include <iostream>
#include <utility>

struct S{
    S() = default;
    S(S &&) = default;
    S(const S &) = default;
    S(const S &&) = delete;
    S &operator=(const S &) = default;
    S &operator=(S &&) = default;
    S &operator=(const S &&) = delete;

    template<typename T>
    constexpr void do_something(T) const noexcept {}

    void do_something(double) const noexcept = delete;
    void do_something(char) const noexcept = delete;
};

int main()
{
    S s1;
    S s2;
    s2 = std::move(s1);

    s2.do_something(1);
    //s2.do_something('c'); // char double deleted
    s2.do_something((int)'c');
    //s2.do_something(2.0); // error double deleted
    s2.do_something(2.0f);

    return 0;
}
