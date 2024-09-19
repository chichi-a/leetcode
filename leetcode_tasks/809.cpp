class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int answer = 0;
        
        for (int k = 0; k < words.size(); k++) {
            string a = words[k];
            int i = 0, j = 0;
            bool check = true;
            
            while (i < s.size() && j < a.size()) {
                if (s[i] != a[j]) {
                    check = false;
                    break;
                }

               
                int len_s = 0;
                char current_s = s[i];
                while (i < s.size() && s[i] == current_s) {
                    len_s++;
                    i++;
                }

              
                int len_a = 0;
                char current_a = a[j];
                while (j < a.size() && a[j] == current_a) {
                    len_a++;
                    j++;
                }

               
                if (len_s < len_a || (len_s < 3 && len_s != len_a)) {
                    check = false;
                    break;
                }
            }
            
           
            if (check && i == s.size() && j == a.size()) {
                answer++;
            }
        }

        return answer;
    }
};