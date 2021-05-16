//bfs
class Solution {
public:
    vector<int> rightSideView(TreeNode* root)
    {
        if (!root) {
            return {};
        }
        vector<int> view;
        queue<TreeNode*> todo;
        todo.push(root);

        while (!todo.empty()) {
            int n = todo.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = todo.front();
                todo.pop();
                if (i == n - 1) {
                    view.push_back(node->val);
                }
                if (node->left) {
                    todo.push(node->left);
                }
                if (node->right) {
                    todo.push(node->right);
                }
            }
        }
        return view;
    }
};

class Solution {
public:
    // h is the current level of the node, maxh is the maximum level reached at any given point of time.
    void traverse(TreeNode* root, int h, int& maxh, vector<int>& ans)
    {
        if (!root)
            return;
        // if level is greater than maximum level then it will be seen at the right side. Try to visualize it.
        if (h > maxh) {
            ans.push_back(root->val);
            maxh = h;
        }
        // first visiting the right side for right view.
        traverse(root->right, h + 1, maxh, ans);

        traverse(root->left, h + 1, maxh, ans);
    }
    vector<int> rightSideView(TreeNode* root)
    {
        if (!root)
            return {};
        vector<int> ans;
        int maxh = 0;
        ans.push_back(root->val);
        traverse(root, 0, maxh, ans);
        return ans;
    }
};

class Solution {
public:
    int minKnightMoves(int x, int y)
    {
        if (!x && !y)
            return 0;
        vector<pair<int, int>> dir = { { -1, -2 }, { -2, -1 }, { -2, 1 }, { -1, 2 }, { 1, -2 },
            { 2, -1 }, { 2, 1 }, { 1, 2 } };
        queue<pair<int, int>> q;
        unordered_set<string> s;
        q.push({ 0, 0 });
        double val = sqrt(x * x + y * y);
        int res = 0;
        while (!q.empty()) {
            int size = q.size();
            res++;
            for (int i = 0; i < size; i++) {
                auto cur = q.front();
                q.pop();
                for (auto d : dir) {
                    int X = d.first + cur.first;
                    int Y = d.second + cur.second;
                    if (X == x && Y == y)
                        return res;
                    string str = to_string(X) + ',' + to_string(Y);
                    double val2 = sqrt((X - x) * (X - x) + (Y - y) * (Y - y));
                    if (!s.count(str) && (val2 < val || val < 2)) {
                        val = val2;
                        q.push({ X, Y });
                        s.insert(str);
                    }
                }
            }
        }
        return res;
    }
};

//Debug, type gdb filename  not filename.out or cpp
//b - main b stands for break
//r - run
//l - Stands for list that will debug for
//f - Defines where the debugger right now
//n - Step over (Does't step into functions)
//s - Step into
//p - Print variable
//bt- Print a stack trace
//c - Continues running the program until the next breakpoint or error
//r - Runs the program until a breakpoint or error

#include <bits/stdc++.h>

using namespace std;

int main()
{

    vector<int> colors { 1, 1, 2, 1, 3, 2, 2, 3, 3 };
    vector<pair<int, int>> queries { { 1, 3 }, { 2, 2 }, { 6, 1 } };
    unordered_map<int, int> mp(3);

    for (int i = 0; i < (int)colors.size(); i++) {
        mp[colors[i]].push_back(i);
    }
    for (auto& [key, val] : mp) {

        cout << key << "--->" << val << "\n";
    }

    vector<int> ans(3);

    for (auto [target_idx, target_col] : queries) {
        //cout << colors[target_idx]
        //if(colors[target_idx] != target_col){
        //short_dist = get_shortest();
    }

    return 0;
}
