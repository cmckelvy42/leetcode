
int  decrypt(string crypt, map<char, char> solution)
{
    for (int i = 0; i < crypt.length(); ++i)
        crypt[i] = solution[crypt[i]];
    return stol(crypt);
}
bool isCryptSolution(std::vector<std::string> crypt, std::vector<std::vector<char>> solution) {
    map<char, char>stuff;
    int crypt1;
    int crypt2;
    int crypt3;
    for (int i = 0; i < solution.size(); i++)
        stuff.insert(pair<char, int>(solution[i][0], solution[i][1]));
    for (int i = 0; i < 3; ++i)    
        if (crypt[i].length() > 1 && stuff[crypt[i][0]] == '0') 
        //check for leading zeroes in every string, the only time the first character can be '0' is if it's 1 char long
            return false;
       crypt1 = decrypt(crypt[0], stuff);
       crypt2 = decrypt(crypt[1], stuff);
       crypt3 = decrypt(crypt[2], stuff);
    return (crypt1 + crypt2 == crypt3);
}

/*
A cryptarithm is a mathematical puzzle for which the goal is to find the correspondence between letters and digits,
such that the given arithmetic equation consisting of letters holds true when the letters are converted to digits.

You have an array of strings crypt, the cryptarithm, and an an array containing the mapping of letters and digits, solution.
The array crypt will contain three non-empty strings that follow the structure: [word1, word2, word3], which should be interpreted
as the word1 + word2 = word3 cryptarithm.

If crypt, when it is decoded by replacing all of the letters in the cryptarithm with digits using the mapping in solution,
becomes a valid arithmetic equation containing no numbers with leading zeroes, the answer is true.
If it does not become a valid arithmetic solution, the answer is false.

Note that number 0 doesn't contain leading zeroes (while for example 00 or 0123 do).

Guaranteed constraints:
crypt.length = 3,
1 ≤ crypt[i].length ≤ 14.

solution[i].length = 2,
'A' ≤ solution[i][0] ≤ 'Z',
'0' ≤ solution[i][1] ≤ '9',
solution[i][0] ≠ solution[j][0], i ≠ j,
solution[i][1] ≠ solution[j][1], i ≠ j.