#include <iostream>
#include <vector>
#include <time.h>
#include <unistd.h>
#include <cstdlib>
#include <sys/time.h>
#include <math.h>

void print_vector(std::vector<int> a)
{
   for (auto i : a)
   {
      std::cout << i << ", ";
   }
   std::cout << "\n";
}

int find_min_index(std::vector<int> a,
                   int start_index,
                   int stop_index)
{
   int min_index = start_index;
   int i;
   for (i = start_index; i < stop_index; i++)
   {
      if (a[i] < a[min_index])
      {
         min_index = i;
      }
   }
   return min_index;
}

std::vector<int> ssort(std::vector<int> a)
{
   int i, min_index, j, tmp;
   int len = a.size();
   // loop through the vector from 0 to end
   for (i = 0; i < len; i++)
   {
      // find the smallest value from i to the end
      min_index = find_min_index(a, i, len);

      // swap it into position i
      tmp = a[i];
      a[i] = a[min_index];
      a[min_index] = tmp;
   }
   return a;
}

/*
  left and right are already sorted

  merged should be a new vector with all the
  elements in left and right, and result
  should be sorted
*/
std::vector<int> merge(std::vector<int> left,
                       std::vector<int> right)
{
   std::vector<int> merged;

   // your code here

   int leftIndex = 0;
   int rightIndex = 0;

   while (leftIndex < left.size() || rightIndex < right.size())
   {
      if (leftIndex >= left.size())
      {
         merged.push_back(right[rightIndex]);
         rightIndex++;
      }
      else if (rightIndex >= right.size())
      {
         merged.push_back(left[leftIndex]);

         leftIndex++;
      }
      else if (left[leftIndex] < right[rightIndex])
      {
         merged.push_back(left[leftIndex]);
         leftIndex++;
      }
      else
      {
         merged.push_back(right[rightIndex]);
         rightIndex++;
      }
   }

   // remember merged.push_back(n)
   // appends value n to the vector merged

   return merged;
}

std::vector<int> msort(std::vector<int> v)
{
   if (v.size() <= 1)
      return v;

   std::vector<int> half1, half2;

   for (int i = 0; i < v.size() / 2; i++)
   {
      half1.push_back(v[i]);
   }

   for (int i = v.size() / 2; i < v.size(); i++)
   {
      half2.push_back(v[i]);
   }

   std::vector<int> sorted_half1 = msort(half1);
   std::vector<int> sorted_half2 = msort(half2);

   return merge(sorted_half1, sorted_half2);
}

std::vector<int> qsort(std::vector<int> list)
{

   // base case
   if (list.size() <= 1)
   {
      return list;
   }

   // select a pivot value.
   // for now, just pick list[0]
   int pivot = list[0];

   // make 2 new vectors
   std::vector<int> lower, higher;

   // copy all the values < pivot value to lower

   // copy all the values >= pivot value to higher;

   for (int i = 1; i < list.size(); i++)
   {
      if (list[i] < pivot)
      {
         lower.push_back(list[i]);
      }
      else
      {
         higher.push_back(list[i]);
      }
   }

   lower = qsort(lower);
   higher = qsort(higher);

   // copy everything back into list

   for (int i = 0; i < lower.size(); i++)
   {
      list[i] = lower[i];
   }
   list[lower.size()] = pivot;
   for (int i = 0; i < higher.size(); i++)
   {
      list[i + lower.size() + 1] = higher[i];
   }

   // return the sorted list
   return list;
}

int main()
{
   int size = 25;
   int max_val = 1000;

   srand(time(nullptr));
   std::vector<int> a(size);
   int i;
   for (i = 0; i < size; i++)
   {
      a[i] = rand() % max_val;
   }
   print_vector(a);
   std::cout << "\n";
   a = msort(a);
   print_vector(a);

   return 0;
}
