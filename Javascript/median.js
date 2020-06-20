// Find the median of 2 sorted arrays in javascript

var findMedianSortedArrays = function(nums1, nums2) {
  var nums3 = [...nums1, ...nums2].sort((a, b) => a - b)
  if (nums3.length % 2 !== 0) {
      return nums3[(nums3.length-1)/2]
  } else {
      return (nums3[(nums3.length/2) - 1] + nums3[(nums3.length/2)]) / 2
  }
};
