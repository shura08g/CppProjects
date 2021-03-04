//¬ычисл€ем e с точностью 600 знаков после зап€той

#include <iostream>
#include <vector>

constexpr long long factorial(int n) {
    return (n == 0) ? 1 : n * factorial(n- 1);
}

constexpr double series(double v, int n, int max) {
    return 1.0 / factorial(n) + (max == n ? 0 : series(v, n + 1, max));
}

constexpr double exp_number(double v, int accuracy) {
    return series(v, 0, accuracy);
}

//--------------------------------//

void print(std::vector<int>& v) {
    for (auto i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void get_exponent(std::vector<int>& a, std::vector<int>& b, std::vector<int>& e) {
    if (a.size() != e.size() || b.size() != e.size()) {
        return;
    }

    int c;
    int p;

    e[0] = 1;
    b[0] = 1;

    for (int n = 1; n < e.size(); ++n) {
        // Saving old member of the series in vector "a": vector "a" = vector "b"
        for (int i = 0; i < e.size(); ++i) {
            a[i] = b[i];
            //c = a[0];
        }
        c = a[0];
        // Calculation new member of the series: vector "b" = vector "a" / n
        for (int i = 0; i < e.size() - 1; ++i) {
            b[i] = c / n;
            c = (c - n * b [i]) * 10 + a[i + 1];
        }
        p = 0;
        //print(b);
        //print(e);
        // Addition last member of the series to e: vector "e" += vector "b"
        for (int i = e.size(); i >= 0; --i) {
            c = e[i] + b[i] + p;
            p = 0;
            if (c < 10) {
                e[i] = c;
            } else {
                e[i] = c - 10;
                p = 1;
            }
        }
    }
}

void test11() {
    std::cout << '\n';
    constexpr int signs = 20;
    constexpr double e = exp_number(1, signs);
    std::cout.precision(signs);
    std::cout << e << '\n';  // 2.7182818284590450908

    const int signs2 = 600;
    std::vector<int> a(signs2, 0);
    std::vector<int> b(signs2, 0);
    std::vector<int> e2(signs2, 0);

    get_exponent(a, b, e2);

    std::cout << "e = " << e2[0] << ".";
    for (int i = 1; i < e2.size() - 9; i++) {
        std::cout << e2[i];
        if (i % 6 == 0) {
            std::cout << "\t ";
        }
    }
    std::cout << "\n";
}
