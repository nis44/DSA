class Solution {
public:
    int minimumOperations(vector<vector<int>>& v){
        int c=0;
        
        for(int i=0;i<v[0].size();i++){
            for(int j=1;j<v.size();j++){

                if(v[j][i]<v[j-1][i]){
                    c+=v[j-1][i]-v[j][i]+1;
                    v[j][i]+=v[j-1][i]-v[j][i]+1;
                }

                else if(v[j][i]==v[j-1][i]){
                    c++;
                    v[j][i]=v[j][i]+1;
                }
            }
        }

        return c;
    }
};