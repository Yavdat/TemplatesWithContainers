#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <utility>

using namespace std;

ostream& operator<< (ostream& out, const vector<int>& vi) {
    for (const auto& i : vi) {
        out << i << ' ';
    }
    return out;
}

int main() {
    vector<int> vi = {1, 2, 3};
    cout << vi << endl;
    return 0;
}