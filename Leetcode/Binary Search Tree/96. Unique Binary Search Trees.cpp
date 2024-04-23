/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int numTrees(int n) {
        ///generating Catalan numbers

        vector <int> numerators, denominators;

        for(int i = n+2; i <= 2*n; i++) numerators.push_back(i);
        for(int i = 2; i <= n; i++) denominators.push_back(i);

        for(auto &n: numerators) {
            for(auto &d: denominators) {
                int gcd = __gcd(n, d);
                n /= gcd, d /= gcd;
            }
        }

        int p1 = 1, p2 = 1;
        for(auto n: numerators) p1 *= n;
        for(auto d: denominators) p2 *= d;

        return p1 / p2;

//        return solve(n, 0, 0, n-1);
    }

    int set1(int x, int pos) {
        return (x | (1 << pos));
    }

    int solve(int n, int msk, int st, int en) {
        if(msk == (1<<n)-1 or st > en) return 1;
        int res = 0;

        for(int i = st; i <= en; i++) {
            int newMsk = msk;
            newMsk = set1(newMsk, i);

            res += solve(n, newMsk, st, i-1) * solve(n, newMsk, i+1, en);
        }

        return res;
    }
};

/**
Outputs:
1
2
5
14
42
132
429
1430
*/
