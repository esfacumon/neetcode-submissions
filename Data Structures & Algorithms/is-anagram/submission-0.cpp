class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        map<char, int> char_count_s{};
        map<char, int> char_count_t{};
        for (int i = 0; i < t.size(); ++i) {
            if (!char_count_t.contains(t[i])) {
                char_count_t[t[i]] = 0;
            }
            else {
                char_count_t[t[i]] = char_count_t[t[i]] + 1;
            }

            if (!char_count_s.contains(s[i])) {
                char_count_s[s[i]] = 0;
            }
            else {
                char_count_s[s[i]] = char_count_s[s[i]] + 1;
            }
        }

        for (auto const& [key, val] : char_count_s) {
            if (!char_count_t.contains(key)) return false;
            if (val != char_count_t[key]) return false;
        }

        return true;
    }
};