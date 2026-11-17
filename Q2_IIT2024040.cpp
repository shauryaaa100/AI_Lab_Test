#include <bits/stdc++.h>
using namespace std;

int main() {
    // Given facts
    set<string> students = {"Ravi", "Anu"};
    set<string> courses = {"AI", "ML"};
    set<pair<string, string>> studies = {
        {"Ravi", "AI"}, {"Anu", "ML"}
    };
    set<pair<string, string>> passed = {
        {"Ravi", "AI"}
    };
    set<string> professors = {"DrSharma"};
    set<pair<string, string>> supervises = {
        {"DrSharma", "Ravi"}
    };

    set<string> qualified, researcher, eligible;

    // Rule 1: Student studies at least one course
    cout << "Checking students studying courses:\n";
    for (auto s : students) {
        for (auto c : courses) {
            if (studies.count({s, c}))
                cout << s << " studies " << c << endl;
        }
    }

    // Rule 2: Student studies and passes same course
    for (auto s : students) {
        for (auto c : courses) {
            if (studies.count({s, c}) &&
                passed.count({s, c})) {
                qualified.insert(s);
                cout << "\nQualified(" << s << ")\n";
            }
        }
    }

    // Rule 3: Qualified student supervised by professor
    for (auto s : qualified) {
        for (auto p : professors) {
            if (supervises.count({p, s})) {
                researcher.insert(s);
                cout << "Researcher(" << s << ")\n";
            }
        }
    }

    // Rule 4: Every researcher is eligible
    for (auto s : researcher) {
        eligible.insert(s);
        cout << "Eligible(" << s << ")\n";
    }

    // Final result
    cout << "\nFinal Result:\n";

    if (eligible.count("Ravi"))
        cout << "Ravi is eligible for research fellowship.\n";
    else
        cout << "Ravi is not eligible.\n";

    return 0;
}
