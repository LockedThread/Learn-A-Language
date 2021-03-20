#include <stdio.h>

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size);

double median(int *nums, int numsSize);

int main() {
    printf("Hello, World!\n");

    int nums1[] = {1};
    int nums2[] = {2};

    double median = findMedianSortedArrays(nums1, 1, nums2, 1);

    printf("\nMedian: %f", median);

    return 0;
}

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size) {
    double median1 = median(nums1, nums1Size);
    double median2 = median(nums2, nums2Size);
    printf("\nmedian1=%f", median1);
    printf("\nmedian2=%f", median2);
    if (nums1Size == 0) {
        return median2;
    } else if (nums2Size == 0) {
        return median1;
    } else {
        return (median1 + median2) / 2;
    }
}

double median(int *nums, int numsSize) {
    int index1 = (numsSize - 1) / 2;
    if (numsSize % 2 == 0) {
        int index2 = index1 + 1;
        double sum = nums[index1] + nums[index2];
        return sum / 2;
    }
    return nums[index1];
}