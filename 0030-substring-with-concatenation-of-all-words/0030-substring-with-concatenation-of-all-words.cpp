class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if(s.empty()|| words.empty())
        return result;

        int num_words=words.size();
        int word_len=words[0].size();
        int total_len=word_len*num_words;
        int n=s.size();

        if(n<total_len)
        return result;

        unordered_map<string, int> word_freq;
        for (const string& w : words) {
            word_freq[w]++;
        }

for(int offset=0;offset<word_len;offset++){
    int left=offset;
    int words_matched=0;
unordered_map<string, int> win_freq;

for(int right=offset;right+word_len<=n;right+=word_len){
    string word = s.substr(right, word_len);
    if(word_freq[word]){
        win_freq[word]++;
        words_matched++;
        while(win_freq[word]>word_freq[word]){
            string left_word= s.substr(left, word_len);
            win_freq[left_word]--;
            words_matched--;
            left+=word_len;

        }
        if (words_matched == num_words) {
                        result.push_back(left);
                    }

    }
    else {
                    // Encountered a word not in 'words': reset the whole window
                    win_freq.clear();
                    words_matched = 0;
                    left = right + word_len;
                }

}

}
return result;


    }
};