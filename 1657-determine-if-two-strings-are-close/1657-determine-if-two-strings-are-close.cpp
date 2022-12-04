class Solution
{
    public:

        unordered_map<char, int> makeFrequencyMapOfStringChars(string s)
        {
            unordered_map<char, int> m;
            for (auto c: s)
            {
                m[c]++;
            }
            return m;
        }

    multiset<int> frequenciesMapToSet(unordered_map<char, int> m)
    {
        multiset<int> set;
        for (auto x: m)
        {
            set.insert(x.second);
            set.insert(-x.first);
        }
        return set;
    }

    bool closeStrings(string word1, string word2)
    {
        if (word1.size() != word2.size()) return false;

        unordered_map<char, int> m1 = makeFrequencyMapOfStringChars(word1);
        unordered_map<char, int> m2 = makeFrequencyMapOfStringChars(word2);

        multiset<int> s1 = frequenciesMapToSet(m1);
        multiset<int> s2 = frequenciesMapToSet(m2);

        multiset<int>::iterator it1 = s1.begin();
        multiset<int>::iterator it2 = s2.begin();

        while (it1 != s1.end())
        {
            if (*it1 != *it2) return false;
            it1++;
            it2++;
        }
        return true;
    }
};
