#include <iostream>
#include <vector>
#include <time.h>
#include <unistd.h>
#include <cstdlib>
#include <sys/time.h>
#include <math.h>
#include <cassert>

std::vector<int> msort(std::vector<int> v)
{
}

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

int main()
{
   /* int size = 102000;
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
   a = ssort(a);
   print_vector(a); */

   std::vector<int> v1 = {3, 5, 8, 12, 13, 17};
   std::vector<int> v2 = {2, 6, 7, 14, 19, 26};

   std::vector<int> s = {2, 3, 5, 6, 7, 8, 12, 13, 14, 17, 19, 26};

   assert(merge(v1, v2) == s);

   return 0;
}