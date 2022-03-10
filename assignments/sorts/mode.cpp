#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

int count(std::vector<int> v, int value);
int largest(std::vector<int> v);
int mode(std::vector<int> v);

/**
 * Counts the number of times a value appears in a vector
 *
 * @param v  Vector to count in
 * @param value  Value to count
 * @returns  The number of times `value` appears in `v`
 * */
int count(std::vector<int> v, int value)
{
   int counter = 0;

   for (int i = 0; i < v.size(); i++)
   {
      if (v[i] == value)
      {
         counter++;
      }
   }

   return counter;
}

/**
 * Get the largest value from the vector
 *
 * @param v  The vector to look in
 * @returns  The largest value in `v`
 * */
int largest(std::vector<int> v)
{
   int largest = v[0];

   for (int i = 1; i < v.size(); i++)
   {
      if (v[i] > largest)
      {
         largest = v[i];
      }
   }

   return largest;
}

/**
 * Get the mode of a vector
 *
 * @param v  The vector to get the mode of
 * @returns  The mode of `v`
 * */
int mode(std::vector<int> v)
{
   int mode;
   int mode_count = 0;

   for (int i = 0; i < v.size(); i++)
   {
      int freq = count(v, v[i]);

      if (freq > mode_count)
      {
         mode_count = freq;
         mode = v[i];
      }
   }

   return mode;
}

int main()
{
   srand(time(NULL));
   std::vector<int> v;

   for (int i = 0; i < 10; i++)
   {
      int random = rand() % 11;
      v.push_back(random);
      std::cout << random << ", ";
   }

   std::cout << std::endl;

   std::cout << "Count of " << v[0] << ": " << count(v, v[0]) << std::endl;
   std::cout << "Largest: " << largest(v) << std::endl;
   std::cout << "Mode: " << mode(v) << std::endl;

   return 0;
}