#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <utility>

using namespace std;

template <typename T>
ostream& operator<< (ostream& out, const vector<T>& vi) {
    for (const auto& i : vi) {
        out << i << ' ';
    }
    return out;
}

template <typename First, typename Second>
ostream& operator<< (ostream& out, const pair<First, Second>& p) {
    out << p.first << ',' << p.second;
    return out;
}

template <typename Key, typename Value>
ostream& operator<< (ostream& out, const map<Key, Value>& vi) {
    for (const auto& i : vi) {
        out << i << ' ';
    }
    return out;
}

int main() {
    vector<int> vi = {1, 2, 3};
    cout << vi << endl;
    vector<double> vd = {1.5, 3, 4.5};
    cout << vd << endl;

    map<int, int> m = {{1, 2}, {3, 4}};
    cout << m << endl;
    return 0;
}