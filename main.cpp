#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

class solution {
  public:
    std::vector<std::string> summaryRanges(const std::vector<int> & nums) {
        std::vector<std::string> ranges;
        int begin = 0, end = begin;
        while (begin < nums.size()) {
            while (end < nums.size() && nums[begin]-begin == nums[end]-end)
                end++;
            std::string temp;
            temp += std::to_string(nums[begin]);
            if (begin != end-1) {
                temp += "->";
                temp += std::to_string(nums[end-1]);
            }
            ranges.push_back(temp);
            begin = end;
        }
        return ranges;
    }
};

int main() {
    std::vector<int> nums{0,1,2,4,5,7};

    solution soln;
    auto ranges = soln.summaryRanges(nums);
    std::copy(ranges.begin(), ranges.end(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;
}
