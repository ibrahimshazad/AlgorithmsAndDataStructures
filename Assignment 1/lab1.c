//This is lab assignment 1, Muhammad Ibrahim Siddiqui, 1001753339
// Implementing merge sort.

#include <stdio.h>
#include <stdlib.h>


int merge(int value[], int link[], int start, int count)
{
	int j;
	int i;
	if(value[start] <= value[count])
	{
 	  	i = start;
  	  	j = start;
  	  	start = link[start];
	}

    else
    {
    	i = count;
    	j = count;
    	count = link[count];
	}

	while(start != -1 && count != -1)
	{
    	if(value[start] <= value[count])
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
	
	int nleft,nright,i;
    // Checker whether or not this is the last reccursion for the merge in order to set negative 1 values in the link array.
	if (count<2)
	{
		link[start] = -1;

		return start;
	}

	nleft=count/2; nright=count-nleft;
    
	int a = mymergesort(Array, link, start,nleft);
	int b = mymergesort(Array, link, start+nleft,nright); // pointer arithmetic
	return (merge(Array, link, a, b));
	
}

int main(int argc, char const *argv[])
{

    int i = 0, Lowest = 0, k = 0, size =0, count = 0;
    scanf("%d",&size);
    int Highest = size;
    int Array[size],LinkerArray[size] ;
    
    for(i = 0; i < size; i++)
    {
    	LinkerArray[i] = i;
        scanf("%d",&Array[i]);
    }
    printf("First element is at subscript %d\n",mymergesort(Array, LinkerArray, Lowest, Highest));

    for(count = 0; count < size; count++)
    {
    	printf("%d Array Element is %d\t linker Array %d\n",count,Array[count], LinkerArray[count]);
    }
    
    return 0;
    
}
