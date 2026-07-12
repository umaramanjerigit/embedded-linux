
1. Bit Manipulation Programs 
----------------------------
These are extremely common because firmware engineers frequently manipulate 
device registers. [geeksforgeeks.org], [wecreateproblems.com] 
============================
Swap Numbers Without Temp 
-------------------------
   a ^= b; 
   b ^= a; 
   a ^= b; 
============================
Find Odd/Even 
--------------
if(n & 1) 
    printf("Odd"); 
else 
    printf("Even"); 
============================
Count Set Bits without using library functions ( Brian Kernighan Method )
-------------------------------------------------------------------------
int countBits(unsigned int n) 
{ 
    int count = 0; 
 
    while(n) 
    { 
        n = n & (n - 1); 
        count++; 
    } 
  
    return count; 
} 
Example: 
13 -> 1101 
 
1101 
1100 
 
1100 
1011 
 
1000 
0111 
  
0000 
Count = 3
============================
1. Check if Number is Power of 2 
--------------------------------
int isPowerOfTwo(unsigned int n)

{ 
    return n && !(n & (n - 1)); 
} 

Why? 
8 = 1000 
7 = 0111 
 
1000 & 
0111 = 0 
============================
• Reverse bits of a 32-bit integer 
----------------------------------
unsigned int reverseBits(unsigned int n) 
{ 
    unsigned int rev = 0; 
 
    for(int i = 0; i < 32; i++) 
    { 
        rev <<= 1; 
        rev |= (n & 1); 
 
         n >>= 1; 
    } 
  
    return rev; 
} 

#include <stdio.h>
#include <stdlib.h>
int main ()
/*{ // THis logic is not reversing bits in a Variable its simply printing the last bits
    int x = 0xA5;
    for (int i = 0; (i<8); i++)
    {
        printf("%d \t", (x>>i)&1 );
    }
    printf("\n");
    return 0;
}*/
{
    int x = 0xA5, rev = 0;
    for (int K=0; K<8; K++)
    {
        //x = x >> 1; shiffting before extracting the number is wrong
        rev = (rev<<1) | (x&1);
        x = x >> 1; //Extracting 0th bit in previous line and then shifting is good
    }
    printf("rev = %x \n", rev);
    return 0;
}

============================
• Swap odd and even bits 
============================
• Detect endianness 
-------------------
int isLittleEndian() 
{ 
    int x = 1; 
 
    return *((char *)&x); 
} 
Output: 
1 -> Little Endian 
0 -> Big Endian 
============================
• Set/Clear/Toggle specific bit
-------------------------------
x = x &  (1 << k); : Check whether kth bit is SET or CLEAR
n ^= (1 << pos);   : Toggle nth Bit
Set nth Bit	   : n |= (1 << pos); 
Clear nth Bit  : n &= ~(1 << pos); 

Example: 
10 = 1010 
 
Toggle bit 1 
 
1010 
0010 
---- 
1000 
============================
• Find first set bit 
• Find missing number using XOR 
============================
• Count trailing zeros 
• Implement bit-field extraction macro 
• Rotate bits left/right 
• Parity calculation 

* Swap odd-even bits

* Find missing number using XOR
* Find unique element
* Find two unique numbers
* Set nth bit
* Clear nth bit
* Toggle nth bit
* Check nth bit
* Find rightmost set bit
* Find leftmost set bit
* Rotate bits
* Bit mask operations
* Bitmap implementation

Catalina Interview Question
---------------------------

#include <stdio.h>

#define SIZE 10   // 10 integers => 320 bits

void setGivenBitPos(int arr[], int bitPos)
{
    int index  = bitPos / 32;   // which integer
    int offset = bitPos % 32;   // which bit inside that integer

    if (index >= 0 && index < SIZE)
    {
        arr[index] |= (1U << offset);
    }
}

int main()
{
    int arr[SIZE] = {0};

    int k = 169;
    setGivenBitPos(arr, k);

    printf("Bit %d set in arr[%d], value = %u\n", k, k/32, arr[k/32]);

    return 0;
}

============================

