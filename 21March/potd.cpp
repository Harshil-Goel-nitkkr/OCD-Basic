class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
            // make map(recepie,idx)
            unordered_map<string,int> mp;
            for(int i=0; i<recipes.size(); i++)mp[recipes[i]] = i;
    
            // make a set of the available ingredients;
            unordered_set<string> available;
            for(auto el : supplies) available.insert(el);
    
            // find whether the dependencies are resolvable
            // make a graph
            vector<vector<int>> graph(recipes.size(),vector<int>());
            vector<int> dependencies(recipes.size(),0);
            for(int i=0; i<ingredients.size(); i++){
                for(auto el : ingredients[i]){
                    if(available.find(el) != available.end()) continue;
                    if(mp.find(el) !=mp.end()) graph[mp[el]].push_back(i);
                    dependencies[i]++;
                }
            }
            queue<int>q;
            for(int i=0; i<dependencies.size(); i++)if(!dependencies[i]) q.push(i);
            vector<string>ans;
            while(q.size()){
                auto temp = q.front();
                q.pop();
                ans.push_back(recipes[temp]);
                for(auto el : graph[temp]){
                    if(--dependencies[el]==0) q.push(el);
                }
            }
            return ans;
        }
    };