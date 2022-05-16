# Random data

| Data set size | Sorting algorithm                       | Run time |
| ------------- | --------------------------------------- | -------- |
| 10000         | In-place quick sort with good pivot     | 2        |
| 10000         | In-place quick sort with bad pivot      | 2        |
| 10000         | Not-in-place quick sort with good pivot | 42       |
| 10000         | Not-in-place quick sort with bad pivot  | 40       |
| 10000         | Merge sort                              | 31       |
| ------------- | --------------------------------------- | -------- |
| 100000        | In-place quick sort with good pivot     | 22       |
| 100000        | In-place quick sort with bad pivot      | 22       |
| 100000        | Not-in-place quick sort with good pivot | 2008     |
| 100000        | Not-in-place quick sort with bad pivot  | 2114     |
| 100000        | Merge sort                              | 335      |
| ------------- | --------------------------------------- | -------- |
| 1000000       | In-place quick sort with good pivot     | 313      |
| 1000000       | In-place quick sort with bad pivot      | 213762   |
| 1000000       | Not-in-place quick sort with good pivot | 157778   |
| 1000000       | Not-in-place quick sort with bad pivot  | 155842   |
| 1000000       | Merge sort                              | 3514     |

# Sorted data

| Data set size | Sorting algorithm                       | Run time |
| ------------- | --------------------------------------- | -------- |
| 10000         | In-place quick sort with good pivot     | 31       |
| 10000         | In-place quick sort with bad pivot      | 32       |
| 10000         | Not-in-place quick sort with good pivot | 43       |
| 10000         | Not-in-place quick sort with bad pivot  | 42       |
| 10000         | Merge sort                              | 38       |
| ------------- | --------------------------------------- | -------- |
| 100000        | In-place quick sort with good pivot     | 2322     |
| 100000        | In-place quick sort with bad pivot      | 2220     |
| 100000        | Not-in-place quick sort with good pivot | 2190     |
| 100000        | Not-in-place quick sort with bad pivot  | 2111     |
| 100000        | Merge sort                              | 321      |
| ------------- | --------------------------------------- | -------- |
| 1000000       | In-place quick sort with good pivot     | 213145   |
| 1000000       | In-place quick sort with bad pivot      | 219589   |
| 1000000       | Not-in-place quick sort with good pivot | 158931   |
| 1000000       | Not-in-place quick sort with bad pivot  | 157660   |
| 1000000       | Merge sort                              | 3682     |

# Summary
- Using a good vs bad pivot doesn't really create any significant difference in run time, with the exception of certain cases
  - A case on randomized data sets, in-place quick sort with good pivot, the run time growth rate is slower
- On randomized data sets, quick sort done in-place is noticeably faster than not-in-place
- Although quick sort usually beats merge sort on smaller data sets, the rate in which the run time grows as data set size grows is smaller with merge sort, making merge sort faster on larger data sets
- In a pre-sorted data set, run times are similar to a randomized data set, except that in-place quick sort is catching up to not-in-place