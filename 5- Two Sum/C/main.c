#include <stdio.h>
#include <malloc.h>
#include "hashtable.h"

/*
 * https://leetcode.com/problems/two-sum/
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * You can return the answer in any order.
 */

int *bruteForceTwoSum(const int *nums, int numsSize, int target, int *returnSize);

int *hashTableTwoSum(const int *nums, int numsSize, int target, int *returnSize);

int main() {
    int *nums = malloc(sizeof(int) * 4);
    nums[0] = 5;
    nums[1] = 9;
    nums[2] = 32;
    nums[3] = 4;

    int returnSize;

    int *arr;
    arr = bruteForceTwoSum(nums, 4, 9, &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("\n%d", arr[i]);
    }
    free(arr);

    arr = hashTableTwoSum(nums, 4, 9, &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("\n%d", arr[i]);
    }

    return 0;
}

int *bruteForceTwoSum(const int *nums, int numsSize, int target, int *returnSize) {
    *returnSize = 0;
    for (int i = 0; i < numsSize; ++i) {
        for (int j = i; j < numsSize; ++j) {
            if (nums[i] + nums[j] == target) {
                int *arr = (int *) malloc(sizeof(int) * 2);
                if (arr == NULL) {
                    return NULL;
                }
                arr[0] = i;
                arr[1] = j;
                *returnSize = 2;
                return arr;
            }
        }
    }
    return NULL;
}

int *hashTableTwoSum(const int *nums, int numsSize, int target, int *returnSize) {
    hashtable *table = hashtable_create(numsSize);
    for (int i = 0; i < numsSize; ++i) {
        int sub = target - nums[i];
        hashtable_item *item = hashtable_get(table, sub);
        if (item != NULL && *item->value != i) {
            int *arr = (int *) malloc(sizeof(int) * 2);
            hashtable_free(table);
            if (arr == NULL) {
                break;
            }
            arr[0] = i;
            arr[1] = *item->value;
            *returnSize = 2;
            return arr;
        }
        hashtable_insert(table, nums[i], i);
    }
    return NULL;
}