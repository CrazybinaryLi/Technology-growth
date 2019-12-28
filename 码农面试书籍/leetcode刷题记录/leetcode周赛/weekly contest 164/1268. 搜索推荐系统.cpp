class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin() , products.end());
        vector< vector<string> > res;
        string s = "";
        for( const char& c : searchWord){
            s += c;
            int len = s.size();
            vector<string>::iterator it = lower_bound(products.begin() , products.end() , s);
            vector<string> cur;
            for(int i = 0 ;i < 3; ++i){
                if(it == products.end())
                    break;
                if( (*it).size() < len || s != (*it).substr(0,len))
                    break;
                cur.push_back(*it);
                ++it;
            }
            res.push_back(cur);
        }
        return res;
    }

};
