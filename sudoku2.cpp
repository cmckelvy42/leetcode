bool checkBox(int startX, int startY, vector<vector<char>> grid)
{
    set<char> digits;
    
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            char c = grid[startY + i][startX + j];
            if (digits.find(c) != digits.end()) return false;
            if(c != '.')
                digits.insert(c);
        }
    }
    return true;
}

bool sudoku2(std::vector<std::vector<char>> grid) {
    set<string> col;
    set<string> row;
    
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (grid[i][j] != '.')
            {
                if (row.insert(to_string(i) + grid[i][j]).second == false)
                    { cout << "1";
                   return false;}
                if (col.insert(to_string(j) + grid[i][j]).second == false)
                    { cout << "2";
                    return false;}
                if (checkBox(j / 3 * 3, i / 3 * 3, grid) == false)
                   { cout << "3";
                    return false;}
            }
        }
    }
    return true;
}


/*
Sudoku is a number-placement puzzle. The objective is to fill a 9 × 9 grid with numbers in such a way
that each column, each row, and each of the nine 3 × 3 sub-grids that compose the grid all contain all
of the numbers from 1 to 9 one time.

Implement an algorithm that will check whether the given grid of numbers represents a valid Sudoku puzzle
according to the layout rules described above. Note that the puzzle represented by grid does not have to be solvable.

INPUT:
A 9 × 9 array of characters, in which each character is either a digit from '1' to '9' or a period '.'.
*/