class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        unordered_map<string, vector<string>> g;
        unordered_map<string, int> indegree;

        for (int i = 0; i < recipes.size(); i++) {
            indegree[recipes[i]] = ingredients[i].size();
            for (auto &x : ingredients[i])
                g[x].push_back(recipes[i]);
        }

        queue<string> q;
        for (auto &x : supplies) q.push(x);

        vector<string> ans;

        while (!q.empty()) {
            string cur = q.front();
            q.pop();

            for (auto &r : g[cur]) {
                if (--indegree[r] == 0) {
                    ans.push_back(r);
                    q.push(r);
                }
            }
        }

        return ans;
    }
};