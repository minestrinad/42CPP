# FORD-JOHNSON MERGE-SORT ALGORITHM

Merge-insertion sort performs the following steps, on an input `X` of `n` elements:[6]

Let's devide the algorithm in two similar recursion `Predecessor` and `Binary`

## predecessor

The first recursion will sort pair of `groups` by theire last(highest) element where each pair start with an odd index and `groups` size is recursively doubled starting from `1` 

When we can't complete groups or are the number of groups is odd the last group is not considered in the comparisons and leaved there
eg.
  7 5 6 3 2 0 4 9 1 8
- at the first recursion at `depth` 1
  we will consider as `idx*` the singles numbers `*` 
  we have to check if `idx0` < `idx1`, is not swap them, than check if `idx3 < idx4` and so on
  at the end of the first recursion we have
  5 7 3 6 0 2 4 9 1 8
- in `depth` 2 our group size will be `2` so we consider as `idx*` couples of elements `* *`
  3 6 5 7 0 2 4 9 1 8
- in `depth` 3 groups size is `4` so `idx*` are quartet of elements `* * * *`
  in this case we have just two groups that ends wiht `7` and `9` that are sorted so we leave.

## binary

The second recursion is a bit more tricky we can first explain the base and than how to implement the jacobsther sequence.
We still consider `groups` and indexes the same way as before but we go backward from group with size 2^`depth` where depth is the recursion level we've reached before, but this time instea of
just checking pair to pair we will binary search the correct position (always considering the last element of the group as 'rouler')

- here is where the hard work made in the predecessor part give his gifts: at each depth we can just reorder the odd groups because the even groups at every depth are just sorted
- 
