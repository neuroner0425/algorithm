#include <bits/stdc++.h>

using namespace std;

long long largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    long long maxArea = 0;
    int n = heights.size();

    for (int i = 0; i <= n; i++) {
        while (!st.empty() && (i == n || heights[st.top()] > heights[i])) {
            int height = heights[st.top()];
            st.pop();

            int width = (st.empty()) ? i : (i - st.top() - 1);
            maxArea = max(maxArea, (long long)height * width);
        }
        st.push(i);
    }

    return maxArea;
}

int main() {
    while (true) {
        int n;
        cin >> n;

        if (n == 0) break;

        vector<int> heights(n);
        for (int i = 0; i < n; i++) {
            cin >> heights[i];
        }

        long long maxArea = largestRectangleArea(heights);
        cout << maxArea << endl;
    }

    return 0;
}
