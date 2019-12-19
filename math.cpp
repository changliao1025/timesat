#include "math.h"
///=====================================================================
///calcualte the mean value of an array
//=====================================================================
double calculate_mean(std::vector<double> data)
{
  double mean = 0.0;
  double total = 0.0;

  long count = 0;
  std::vector<long>::size_type index;
  for (index = 0; index != data.size(); index++)
    {

      total = total + data[index];
      count = count + 1;

    }
  //get mean
  if (count > 0)
    {
      mean = total / count;
    }
  else
    {
      mean = missing_value;
    }
  return mean;
}

///=====================================================================
///calcualte the mean value of an array, excluding the missing value
///=====================================================================
double calculate_mean(std::vector<double> data, double missing_value)
{
  double mean = 0.0;
  double total = 0.0;
  long count = 0;
  std::vector<long>::size_type index;
  for (index = 0; index != data.size(); index++)
    {
      if (data[index] != missing_value)
        {
          total = total + data[index];
          count = count + 1;
        }
    }
  //get mean
  if (count > 0)
    {
      mean = total / count;
    }
  else
    {
      mean = missing_value;
    }
  return mean;
}
///======================================================================
///calcualte the mean value of an array in range min and max
///=====================================================================
double calculate_mean(std::vector<double> data, double max_value, double min_value)
{
  double mean = 0.0;
  double total = 0.0;
  double dummy;
  long count = 0;


  std::vector<double>::iterator iIterator;
  for (iIterator = data.begin(); iIterator != data.end(); iIterator++)
    {
      dummy = *iIterator;
      if (dummy >= min_value && dummy <= max_value)
        {
          total = total + dummy;
          count = count + 1;
        }
    }

  //get mean
  if (count > 0)
    {
      mean = total / count;
    }
  else
    {
      mean = missing_value;
    }
  return mean;
}

void tridia(int n,
            std::vector<double>& a,
            std::vector<double>& b,
             std::vector<double>& c,
             std::vector<double>& r,
             std::vector<double>& u)
// ------------------------ notes ----------------------------------
// solve for u given the set of equations f * u = r, where u is a
// vector of length n, r is a vector of length n, and f is an n x n
// tridiagonal matrix defined by the vectors a, b, c [each of length n].
// a(1) and c(n) are undefined and are not referenced by the subroutine.

//    |b(1) c(1)   0  ...                     |   |u(1  )|   |r(1  )|
//    |a(2) b(2) c(2) ...                     |   |u(2  )|   |r(2  )|
//    |               ...                     | * | ...  | = | ...  |
//    |               ... a(n-1) b(n-1) c(n-1)|   |u(n-1)|   |r(n-1)|
//    |               ...   0    a(n  ) b(n  )|   |u(n  )|   |r(n  )|

{
   std::vector<double> gam(n);
  double bet;
  int j;

  bet = b[0];
  u[0] = r[0] / bet;

  for (j = 1; j < n; j++)
    {
      gam[j] = c[j - 1] / bet;
      bet = b[j] - a[j] * gam[j];
      u[j] = (r[j] - a[j] * u[j - 1]) / bet;
    }

  for (j = n - 2; j >= 0; j--)
    {
      u[j] = u[j] - gam[j + 1] * u[j + 1];
    }

  return;
}

