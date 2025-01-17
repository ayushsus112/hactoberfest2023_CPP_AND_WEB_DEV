// C++ program for bubble sort 
// using stack 
#include <bits/stdc++.h>
using namespace std;

// Function for bubble sort using Stack 
void bubbleSortStack(int a[], int n)
{
	stack<int> s1;
	
	// Push all elements of array in 1st stack
	for(int i = 0; i < n; i++) 
	{
		s1.push(a[i]);
	}

	stack<int> s2;

	for(int i = 0; i < n; i++)
	{
		if (i % 2 == 0) 
		{
			while (!s1.empty())
			{
				int t = s1.top();
				s1.pop();

				if (s2.empty()) 
				{
					s2.push(t);
				}

				else
				{
					// Swapping
					if (s2.top() > t)
					{
						int temp = s2.top();
						s2.pop();
						s2.push(t);
						s2.push(temp);
					}
					else
					{
						s2.push(t);
					}
				}
			}
			
			// Tricky step
			a[n - 1 - i] = s2.top();
			s2.pop();
		}

		else
		{
			while (!s2.empty()) 
			{
				int t = s2.top();
				s2.pop();

				if (s1.empty()) 
				{
					s1.push(t);
				}

				else
				{
					if (s1.top() > t) 
					{
						int temp = s1.top();
						s1.pop();

						s1.push(t);
						s1.push(temp);
					}

					else
					{
						s1.push(t);
					}
				}
			}
			
			// Tricky step
			a[n - 1 - i] = s1.top();
			s1.pop();
		}
	}
	
	cout << "[";
	for(int i = 0; i < n; i++)
	{
		cout << a[i] << ", ";
	}
	cout << "]";
}

// Driver code
int main()
{
	int a[] = { 15, 12, 44, 2, 5, 10 };
	int n = sizeof(a) / sizeof(a[0]);

	bubbleSortStack(a, n);

	return 0;
}

// This code is contributed by pawki
