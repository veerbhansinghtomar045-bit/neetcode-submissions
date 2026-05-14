class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> scores;

        for (string op : ops) {
            if (op == "C") {
                scores.pop_back();
            }
            else if (op == "D") {
                scores.push_back(scores.back() * 2);
            }
            else if (op == "+") {
                int n = scores.size();
                scores.push_back(scores[n - 1] + scores[n - 2]);
            }
            else {
                scores.push_back(stoi(op));
            }
        }

        int ans = 0;
        for (int x : scores) {
            ans += x;
        }

        return ans;
    }
};