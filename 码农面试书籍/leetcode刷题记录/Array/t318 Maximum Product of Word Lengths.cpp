class Solution {
public:
    int maxProduct(vector<string>& words) {
    	int res=0;
    	vector<int> mask(words.size(),0);
		for(int i=0;i<words.size();i++){
			for(char c:words[i]){
				//ºËÐÄÒ»²½
				mask[i] |=1<<(c-'a');
			}
			for(int j=0;j<i;j++){
				if(!(mask[j]&mask[i])){
					res = max(res, int(words[i].size() * words[j].size()));
				}
			}
		}
		return res;
    }
};
