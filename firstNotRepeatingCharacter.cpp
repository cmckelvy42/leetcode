char firstNotRepeatingCharacter(string s) {
    int count[26] = {0};
    int order[26] = {-1};
    int i = 0;
    
    for (char c : s)
        if (!count[c - 'a']++)
            order[i++] = c;
    for (int j = 0; j < 26; ++j)
        if (count[order[j] - 'a'] == 1)
            return order[j];
    return '_';
}

/*
Given a string s consisting of small English letters,
find and return the first instance of a non-repeating character in it.
If there is no such character, return '_'.

A string that contains only lowercase English letters.

Guaranteed constraints:
1 ≤ s.length ≤ 105.
*/