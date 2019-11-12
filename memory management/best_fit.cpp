/* ================SOMETHING WORTH A READ=============
Is Best-Fit really best?
Although, best fit minimizes the wastage space, it consumes a lot of processor time for searching the block which is close to required size. Also, Best-fit may perform poorer than other algorithms in some cases. For example, see below exercise.

Example: Consider the requests from processes in given order 300K, 25K, 125K and 50K. Let there be two blocks of memory available of size 150K followed by a block size 350K.

Best Fit:
300K is allocated from block of size 350K. 50 is left in the block.
25K is allocated from the remaining 50K block. 25K is left in the block.
125K is allocated from 150 K block. 25K is left in this block also.
50K can’t be allocated even if there is 25K + 25K space available.

First Fit:
300K request is allocated from 350K block, 50K is left out.
25K is be allocated from 150K block, 125K is left out.
Then 125K and 50K are allocated to remaining left out partitions.
So, first fit can handle requests.

*/

// C++ implementation of Best - Fit algorithm 
#include<bits/stdc++.h> 
using namespace std; 

// Function to allocate memory to blocks as per Best fit 
// algorithm 
void bestFit(int blockSize[], int m, int processSize[], int n) 
{ 
	// Stores block id of the block allocated to a 
	// process 
	int allocation[n]; 

	// Initially no block is assigned to any process 
	memset(allocation, -1, sizeof(allocation)); 

	// pick each process and find suitable blocks 
	// according to its size ad assign to it 
	for (int i=0; i<n; i++) 
	{ 
		// Find the best fit block for current process 
		int bestIdx = -1; 
		for (int j=0; j<m; j++) 
		{ 
			if (blockSize[j] >= processSize[i]) 
			{ 
				if (bestIdx == -1) 
					bestIdx = j; 
				else if (blockSize[bestIdx] > blockSize[j]) 
					bestIdx = j; 
			} 
		} 

		// If we could find a block for current process 
		if (bestIdx != -1) 
		{ 
			// allocate block j to p[i] process 
			allocation[i] = bestIdx; 

			// Reduce available memory in this block. 
			blockSize[bestIdx] -= processSize[i]; 
		} 
	} 

	cout << "\nProcess No.\tProcess Size\tBlock no.\n"; 
	for (int i = 0; i < n; i++) 
	{ 
		cout << " " << i+1 << "\t\t" << processSize[i] << "\t\t"; 
		if (allocation[i] != -1) 
			cout << allocation[i] + 1; 
		else
			cout << "Not Allocated"; 
		cout << endl; 
	} 
} 

// Driver code 
int main() 
{ 
	int blockSize[] = {100, 500, 200, 300, 600}; 
	int processSize[] = {212, 417, 112, 426}; 
	int m = sizeof(blockSize)/sizeof(blockSize[0]); 
	int n = sizeof(processSize)/sizeof(processSize[0]); 

	bestFit(blockSize, m, processSize, n); 

	return 0 ; 
} 
