/*
Run
>> g++ -std=c++11 merge_sorted_array.cpp
>> ./a.out
*/
#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i1 = m - 1; //size_t
		int i2 = n - 1;

		if (n == 0)
			return ;
		for (int i = nums1.size() - 1; i >= 0; i--) {
			if (i1 < 0)
				nums1[i] = nums2[i2--];
			else if (i2 < 0)
				nums1[i] = nums1[i1--];
			else {
				if (nums1[i1] > nums2[i2])
					nums1[i] = nums1[i1--];
				else
					nums1[i] = nums2[i2--];
			}
		}
	}
};

void printVector(const std::vector<int>& v) {
	std::cout << "[";
	for (size_t i = 0; i < v.size(); i++) {
		std::cout << v[i];
		if (i + 1 < v.size()) std::cout << ", ";
	}
	std::cout << "]\n";
}

int main(void) {
	Solution solution;
	std::vector<int> nums1; // {1, 2, 3, 0, 0, 0}
	nums1.push_back(1);
	nums1.push_back(2);
	nums1.push_back(3);
	nums1.push_back(0);
	nums1.push_back(0);
	nums1.push_back(0);
	std::vector<int> nums2 = {2, 5, 6};
	printVector(nums1);
	printVector(nums2);
	solution.merge(nums1, 3, nums2, 3);
	printVector(nums1);
	return (0);
}