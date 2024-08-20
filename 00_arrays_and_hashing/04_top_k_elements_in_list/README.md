# Top K Frequent Elements
## Description
Given an integer array `nums` and an integer `k`, *return* the `k` *most frequent elements*. You may return the answer in **any order**.

## Notes
Basic idea: 
1. build a map where the `num` is the key, and its count the entry.
2. build a dynamic array of num-count pairs from the map
3. sort the array based on count
4. append the top `k` frequent num from sorted array into solution

