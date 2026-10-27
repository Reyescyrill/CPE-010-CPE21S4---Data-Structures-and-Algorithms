
#include <iostream>
#include <string>
#include <vector>
#include <thread>
using namespace std;

void print(int n, const string &str) {
    string msg = to_string(n) + " : " + str;
    cout << msg << endl;
}

int main() {
    vector<string> s = {
        "T.I.P.",
        "Competent",
        "Computer",
        "Engineers"
    };

    vector<thread> threads;

    for (int i = 0; i < s.size(); i++) {
        threads.push_back(thread(print, i, s[i]));
    }

    for (auto &th : threads) {
        th.join();
    }

    return 0;
}
