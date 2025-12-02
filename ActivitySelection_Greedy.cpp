#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity {
    int start, finish;
};

bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    vector<Activity> act(n);
    cout << "Enter start and end times:\n";
    for (int i = 0; i < n; i++)
        cin >> act[i].start >> act[i].finish;

    sort(act.begin(), act.end(), compare);

    cout << "\nSelected Activities:\n";
    int count = 1;
    cout << "(" << act[0].start << ", " << act[0].finish << ")\n";

    int lastFinish = act[0].finish;

    for (int i = 1; i < n; i++) {
        if (act[i].start >= lastFinish) {
            cout << "(" << act[i].start << ", " << act[i].finish << ")\n";
            lastFinish = act[i].finish;
            count++;
        }
    }

    cout << "\nMax Non-overlapping Activities: " << count << endl;
    return 0;
}
