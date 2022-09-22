//This is lab assignment 1, Muhammad Ibrahim Siddiqui, 1001753339
// Implementing merge sort.

// Compilation command on omega
// ssh mxs3339@omega.uta.edu
// gcc Assignment1.c
// ./a.out < textfile.txt
#include <stdio.h>
#include <stdlib.h>


int merge(int Array[], int link[], int start, int count)
{
	int i,j;
	if(Array[start] <= Array[count])
	{
 	  	i = start,j=start;
  	  	start = link[start];
	}

    else
    {
    	i = count,j=count;
    	count = link[count];
	}

	while(start != -1 && count != -1)
	{
    	if(Array[start] <= Array[count])
    	{
       		 link[j] = count;
       		 j = count;
       		 count = link[count];
    	}
    	else
    	{
       		link[j] = count;
       	 	j = count;
       		count = link[count];
    	}
	}

	if(start == -1)
	{
    	link[j] = count;
	}

    else
	{
  		  link[j] = start;
	}

	return i;
}


int mymergesort(int Array[], int link[], int start,int count)
{
	
	int nleft,nright,i,j;
    // Checker whether or not this is the last reccursion for the merge in order to set negative 1 values in the link array.
	if (count<2)
	{
    // initializing each link array position -1 
		link[start] = -1;

		return start;
	}
  // find the middle and break the array into sub arrays
	nleft=count/2; nright=count-nleft;

  //use recurssion to call mergesort and merge

	i = mymergesort(Array, link, start,nleft);
	j = mymergesort(Array, link, start+nleft,nright); // pointer arithmetic
	return (merge(Array, link, i, j));
	
}

int main(int argc, char const *argv[])
{

    int i = 0, Lowest = 0, k = 0, size =0, count = 0;
    scanf("%d",&size); // Reading the size of the array
    int Highest = size;
    int Array[size],LinkerArray[size] ;
    
    for(i = 0; i < size; i++)
    {
    	LinkerArray[i] = i;
        scanf("%d",&Array[i]); //reading from the file and storing the values in an array
    }
    printf("First element is at subscript %d\n",mymergesort(Array, LinkerArray, Lowest, Highest));

    for(count = 0; count < size; count++)
    {
    	printf("%d\t  %d\t  %d\n",count,Array[count], LinkerArray[count]); // Printing my sorted index array
    }
    
    return 0;
    
}
