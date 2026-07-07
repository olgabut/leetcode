/*
Run
>> node mega_sorted_array.js
*/

/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function(nums1, m, nums2, n) {
	let i1 = m - 1;
	let i2 = n - 1;
	let i = m + n - 1;
	while (i2 >= 0) {
		if (i1 >= 0 && nums1[i1] > nums2[i2]) {
			nums1[i] = nums1[i1];
			i1--;
		} else {
			nums1[i] = nums2[i2];
			i2--;
		}
		i--;
	}
};

let nums1 = [1, 2, 3, 0, 0, 0];
let nums2 = [2, 5, 6];
console.log(nums1);
console.log(nums2);
merge(nums1, 3, nums2, 3);
console.log(nums1);