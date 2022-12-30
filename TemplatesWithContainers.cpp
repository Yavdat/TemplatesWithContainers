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

int main() {
    vector<int> vi = {1, 2, 3};
    cout << vi << endl;
    vector<double> vd = {1.5, 3, 4.5};
    cout << vd << endl;
    vector<vector<int>> vv = {{1,2,3}, {3,2,1}};
    cout << vv << endl;

    map<int, int> m = {{1, 2}, {3, 4}};
    cout << m << endl;
    return 0;
}