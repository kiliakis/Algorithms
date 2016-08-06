#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;


#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int
merge (int *a, int l, int middle, int r)
{
  int b[l+r];
  int left = 0;
  int right = middle;
  int s = 0;
  int size = l+r;
  while (s < size)
    {
      if (left >= l)
	{
	  b[s] = a[right];
	  right++;
	}
      else if (right >= middle+r)
	{
	  b[s] = a[left];
	  left++;
	}
      else if (a[left] < a[right])
	{
	  b[s] = a[left];
	  left++;
	}
      else if(a[right] < a[left])
	{
	  b[s] = a[right];
	  right++;
	}
	else{
		right++;
		size--;
		s--;
	}
      s++;
    }
  for (int i = 0; i < size; i++)
    a[i] = b[i];

  return size;
}



int
mergesort (int *a, int size)
{
  if (size < 2) return size;
  int middle = size / 2;
  int l = mergesort (a, middle); 
  int r = mergesort (&a[middle], size - middle);
  return merge (a, l, middle, r);
}


int
main ()
{

  int a[] = { 3, 5, 1, 11, 11, 45, 24, 11, 0, 0};
  int s = mergesort (a, 10);
  for (int i = 0; i < s; ++i)
    cout << a[i] << " ";
  cout << "\n";
  return 0;
}
