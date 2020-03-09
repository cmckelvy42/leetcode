#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
	{
		map<int, int> hmap;

		for (size_t i = 0; i < nums.size(); i++)
		{
			int complement = target - nums.at(i);
			auto compit = hmap.find(complement);
			if (compit != hmap.end())
			{
				vector<int> ret;
				ret.push_back(compit->second);
				ret.push_back(i);
				return (ret);
			}
			hmap.insert(pair<int, int>(nums[i], i));
		}
		throw "No two sum solution";
    }
};