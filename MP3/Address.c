#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[])
{
    const int VIRTUAL_ADDRESS = 32;
    if (argc != 3)
    {
        printf("Invalid arguments");
    }
    int pageSize = (atoi)(argv[1]);
	int address = (atoi)(argv[2]);
	
	if(pageSize < 1024 || pageSize > 16384) {
            printf("Page size is not within the range of 1024 - 16384");
        }
		
	if((pageSize & (pageSize - 1)) != 0) {
            printf("Page size is not a power of 2");
        }
		
	double virtualAddressSize = pow(2, VIRTUAL_ADDRESS);	
	double pages = virtualAddressSize / pageSize;
	int pageBits = (int)(log(pages)/log(2)); 
	int otherBits = VIRTUAL_ADDRESS - pageBits;
	
	int pageNumber = (address >> otherBits);
	int offset = (address & (pageSize - 1)); 
	printf("The address %d contains:", address);
    printf("\npage number = %d", pageNumber);
    printf("\noffset = %d", offset);
	
    return 0;
}
