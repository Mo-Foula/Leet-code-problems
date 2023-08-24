class Solution
{
    public:
        vector<string> fullJustify(vector<string> &words, int maxWidth)
        {
            vector<string> justifiedStrings;
            int index = 0;

            while (index < words.size())
            {
                string newWord = words[index++];
                int wordsLengths = newWord.size(), wordsCount = 1;

                while (index < words.size() && newWord.size() + 1 + words[index].size() <= maxWidth)
                {
                    wordsLengths += words[index].length();
                    ++wordsCount;
                    newWord += "~" + words[index++];
                }

                string newWordWithSpaces = "";

               	// Needs justification

                int spaces = maxWidth - wordsLengths;
                int evenlySplitSpaces = 1;
                int nonEvenlySplitSpaces = 0;
                int spacesAtTheEnd = 0;

                if (index > words.size() - 1 || wordsCount == 1)
                {
                   	// Last sentence, left justified
                    spacesAtTheEnd = spaces - wordsCount + 1;
                }
                else
                {
                    evenlySplitSpaces = spaces / (wordsCount > 1 ? (wordsCount - 1) : 1);
                    nonEvenlySplitSpaces = spaces % (wordsCount > 1 ? (wordsCount - 1) : 1);
                }

                string tempWord = "";
                bool firstInsert = true;

               	// For complexity
                for (int i = 0; i < newWord.length(); ++i)
                {
                    if (newWord[i] != '~')
                    {
                        tempWord += newWord[i];
                        continue;
                    }
                   	// Found separator

                    if (firstInsert)
                    {
                        firstInsert = false;
                        newWordWithSpaces += tempWord;
                    }
                    else
                    {
                        newWordWithSpaces.append(evenlySplitSpaces + (nonEvenlySplitSpaces-- > 0 ? 1 : 0), ' ');
                        newWordWithSpaces += tempWord;
                    }
                    tempWord = "";
                }

                if (firstInsert)
                {
                    firstInsert = false;
                    newWordWithSpaces += tempWord;
                }
                else
                {
                    newWordWithSpaces.append(evenlySplitSpaces + (nonEvenlySplitSpaces-- > 0 ? 1 : 0), ' ');
                newWordWithSpaces += tempWord;
            }
            tempWord = "";

            newWordWithSpaces.append(spacesAtTheEnd, ' ');

            justifiedStrings.push_back(newWordWithSpaces);
        }
    return justifiedStrings;
}
};