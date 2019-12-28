class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        vector<vector<string>> res;
        string prefix="";
        for(int i=0;i<searchWord.size();i++){
            prefix+=searchWord[i];
            vector<string> tmp;
            int begin=f(products,prefix);
            for(int j=begin;j<products.size();j++){
                if(tmp.size()>=3||products[j].substr(0,prefix.size())>prefix) break;
                else if(products[j].substr(0,prefix.size())==prefix) tmp.push_back(products[j]);
            }
            res.push_back(tmp);
        }
        return res;
    }

private:
    int f(vector<string>& products,string& prefix){
        int left=0;
        int right=products.size()-1;
        int mid;
        while(left<=right){
            mid=(left+right)/2;
            if(products[mid]==prefix) return mid;
            else if(products[mid]<prefix) left=mid+1;
            else right=mid-1;
        }
        return right+1;
    }
};
