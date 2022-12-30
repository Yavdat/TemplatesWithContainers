#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <utility>

using namespace std;

template <typename Collection>
string Join(const Collection& c, char d) {
    stringstream ss;
    bool first = true; // выводим первый элемент или нет
    for (const auto& i : c) {
        if (!first) {
            ss << d; // если мы выводим не первый элемент, то в наш поток мы кладем разделитель
        }
        first = false;
        ss << i;
    }
    return ss.str();
}

template <typename T>
ostream& operator<< (ostream& out, const vector<T>& vi) {
    // for (const auto& i : vi) {
    //     out << i << ',';
    // }
    // return out;
    return out << '[' << Join(vi, ',') << ']';
}

template <typename First, typename Second>
ostream& operator<< (ostream& out, const pair<First, Second>& p) {
    out << '(' << p.first << ',' << p.second << ')';
    return out;
}

template <typename Key, typename Value>
ostream& operator<< (ostream& out, const map<Key, Value>& m) {
    // for (const auto& i : m) {
    //     out << i << ',';
    // }
    // return out;
    return out << '{' << Join(m, ',') << '}';
}

// Случай когда компилятор не знает какой тип использовать
template <typename T>
T Max(T a, T b) {
    if (b < a) {
        return a;
    }
    return b;
}

int main() {
    vector<int> vi = {1, 2, 3};
    cout << vi << endl; // [1,2,3]
    vector<double> vd = {1.5, 3, 4.5};
    cout << vd << endl; // [1.5,3,4.5]
    vector<vector<int>> vv = {{1,2,3}, {3,2,1}};
    cout << vv << endl; // [[1,2,3],[3,2,1]]

    map<int, int> m = {{1, 2}, {3, 4}};
    cout << m << endl; // {(1,2),(3,4)}

    // Случай когда компилятор не знает какой тип использовать
    // cout << Max(2, 3.5) << endl; // тут естественно компилятор ругнется, так как мы используем разные типы
    // в этом случае нужно подсказать компилятору, то есть нужно явным образом указать тип
    cout << Max<int>(2, 4.7) << endl; // 4

    return 0;
}