std::vector<std::vector<int>> rotateImage(std::vector<std::vector<int>> a) {
    int n = a.size() - 1;
    for (int i = 0; i <= n; ++i)
    {
        for (int j = i; j < n - i; ++j)
        {
            swap(a[i][j], a[j][n - i]);
            swap(a[i][j], a[n - i][n - j]);
            swap(a[i][j], a[n - j][i]);
        }
    }
    return a;
}

/*
You are given an n x n 2D matrix that represents an image. Rotate the image by 90 degrees (clockwise).
Guaranteed constraints:
1 ≤ a.length ≤ 100,
a[i].length = a.length,
1 ≤ a[i][j] ≤ 104.
*/