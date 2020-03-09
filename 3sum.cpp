#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
   	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> retVal;
		sort(nums.begin(), nums.end()); //makes life so much easier
		for (size_t i = 0; i < nums.size(); ++i)
        {
			if (nums[i] > 0)
				break; //by the time we get past 0, there's no way to make any new 0 sums due to the sort
			if (i > 0 && nums[i] == nums[i - 1]) // avoid duplicates
				continue;

			size_t j = i + 1;
			size_t k = nums.size() - 1;
			while (j < k)
			{
				int tmp = nums[i] + nums[j] + nums[k];
				if (tmp == 0)
					retVal.push_back(vector<int>{nums[i], nums[j], nums[k]});

				if (tmp <= 0)
                {
					while (++j < k && nums[j] == nums[j - 1]);
						continue;
                }
				else
                {
					while (j < --k && nums[k] == nums[k + 1]);
						continue;
                }
			}
		}
		if (retVal.size() > 0)
            return (retVal);
        throw "no solution";
	}
};