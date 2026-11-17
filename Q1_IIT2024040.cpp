#include <bits/stdc++.h>
using namespace std;

int main() {
    // Initial state
    set<string> onTable = {"A", "B", "C", "D"};
    set<string> clear = {"A", "B", "C", "D"};
    set<pair<string, string>> on;

    bool armEmpty = true;

    cout << "Initial State: All blocks are on the table.\n";

    // Goal 1: Place A on C
    if (onTable.count("A") && clear.count("A") && armEmpty) {
        cout << "\n1. PICKUP(A)\n";
        onTable.erase("A");
        clear.erase("A");
        armEmpty = false;

        cout << "2. STACK(A,C)\n";
        on.insert({"A", "C"});
        clear.erase("C");
        clear.insert("A");
        armEmpty = true;
    }

    // Goal 2: Place D on B
    if (onTable.count("D") && clear.count("D") && armEmpty) {
        cout << "3. PICKUP(D)\n";
        onTable.erase("D");
        clear.erase("D");
        armEmpty = false;

        cout << "4. STACK(D,B)\n";
        on.insert({"D", "B"});
        clear.erase("B");
        clear.insert("D");
        armEmpty = true;
    }

    cout << "\nFinal State:\n";
    for (auto p : on)
        cout << "ON(" << p.first << "," << p.second << ")\n";

    cout << "Goal Achieved!\n";

    return 0;
}
