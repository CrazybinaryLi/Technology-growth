//×Ö·û´®Ä£Äâ
class Solution {
    // 4:1211
    // 5: 111221
    // 6: 312211
public:
    string countAndSay(int n) {
        string str = "1";
        for(int i = 2; i <= n; i++) {
            string temp = "";
            char previous = str[0];
            int counter = 1;
            for(int j = 1; j <= str.length(); j++) {
                if (previous == str[j]) {
                    counter++;
                } else {
                    temp += to_string(counter) + previous;
                    previous = str[j];
                    counter = 1;
                }
            }
            str = temp;
        }
        return str;
    }
};
