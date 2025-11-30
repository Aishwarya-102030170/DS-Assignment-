#include <iostream>
#include <queue>
using namespace std;

void findFirstNonRepeating() {
    cout << "Finding first non-repeating character in string\n";
    cout << "Enter string: ";
    string s;
    getline(cin, s);

    queue<char> q;
    int alphabets = 26;
    int count[26] = {0};

    string result;

    for (char ch : s) {
        if (ch == ' ') continue;
        int idx = ch - 'a';
        if (idx < 0 || idx >= alphabets) continue;

        count[idx]++;
        q.push(ch);

        while (!q.empty() && count[q.front() - 'a'] > 1) {
            q.pop();
        }

        if (q.empty()) {
            result.push_back('#');
        } else {
            result.push_back(q.front());
        }
    }

    cout << "Result: " << result << endl;
}

int main() {
    findFirstNonRepeating();
    return 0;
}
