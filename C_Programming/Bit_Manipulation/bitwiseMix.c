Bit Manipulation Programs 
----------------------------
These are extremely common because firmware engineers frequently manipulate 
device registers. [geeksforgeeks.org], [wecreateproblems.com] 
===========================================================
|-------------------------------|
| X << 1  | Multiply by 2       |
|---------|---------------------|
| X >> 1  | Divide by 2         |
|-------------------------------|

To check sign of a number
if (X >> 31) // MSB
  printf("MSB is set, so number is negative\n");

uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/1_bitwiseOperators$ cat leftShiftRightShiftOp.c 
// 2. Demonstrate Left Shift and Right Shift Operations
#include <stdio.h>
int main() {
	int num, shifts;
	printf("Enter the number: ");
	scanf("%d", &num);
	printf("Enter the shifts: ");
	scanf("%d", &shifts);
	int rs = num>>shifts;
	int ls = num<<shifts;
	printf("After %d >> %d, we get: %d\n", num, shifts, rs);
	printf("After %d << %d, we get: %d\n", num, shifts, ls);
}
/*
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ ./a.out
Enter the number: 56
Enter the shifts: 4
After 56 >> 4, we get: 3
After 56 << 4, we get: 896
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ ./a.out
Enter the number: 46
Enter the shifts: 2
After 46 >> 2, we get: 11
After 46 << 2, we get: 184
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ ./a.out
Enter the number: 12
Enter the shifts: 3
After 12 >> 3, we get: 1
After 12 << 3, we get: 96
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ 
*/
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/1_bitwiseOperators$ 
===========================================================
==================================================
Swap odd/even bits Nvidia

uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/1_bitwiseOperators$ cat swapEvenOddBitPositions.c
#include <stdio.h>

unsigned int swap_even_odd_bits( unsigned int x)
{   
    unsigned int result = 0;
    unsigned int even = x & 0xAAAAAAAA; // mask even bits
    unsigned int odd = x & 0x55555555;  // mask odd bits

    even = even >> 1;                   //A -> 1010 -> move odd bit at 1st position to 0th position. So right shift from 1 to 0th position
    odd = odd << 1; 

    result = even | odd; 
    
    return result;
}          
           
int main ()
{
    unsigned int x = 23; // 00010111
    printf("Result: %u \n", swap_even_odd_bits(x));
    return 0; 
}
/*
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ ./a.out
Result: 43 
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ 
*/
==================================================
Reverse bits using masking
==================================================
Set/Clear/Toggle specific bit
-------------------------------
|-----------------------------------------|---------------------|
| Header 1                                | Header 2            |
|-----------------------------------------|---------------------|
| Check whether kth bit is SET or CLEAR   | n = n & (1 << k);   |
|-----------------------------------------|---------------------|
| Set nth Bit                             | n = n | (1 << k);   |
|-----------------------------------------|---------------------|
| Clear nth Bit                           | n = n & ~(1 << k);  |
|-----------------------------------------|---------------------|
| Toggle nth Bit                          | n = n ^ (1 << k);   |
|-----------------------------------------|---------------------|
===========================================================
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/1_bitwiseOperators$ cat setClearNbitsLSB.c 
// 4. Set, Clear, and Get N Bits from LSB

#include <stdio.h>

int main() {
	unsigned int num;
	int n;
	
	// accept the Hexadecimal number
	printf("Enter the Hexadecimal number : ");
	scanf("%x", &num);
	printf("Enter the number of bits n: ");
	scanf("%d", &n);
	
	//perform the set, clear, get n bits from lsb operation
	unsigned int mask = (1 << n) - 1;
	unsigned int setbit = num | mask;
	unsigned int clearbit = num & ~(mask);
	unsigned int getnbit = num & mask;

	printf("After setting %d bits in decimal: %x\n",n, setbit);
	printf("After clearing %d bits in decimal: %x\n",n, clearbit);
	printf("After getting %d bits in decimal: %x\n", n, getnbit);

	return 0;
}
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/1_bitwiseOperators$ 
=======================================

|-------------------------------------------|---------------------|
| Header 1                                  | Header 2            |
|-------------------------------------------|---------------------|
| Get the value of the nth bit as 0 or 1.   | (num >> n) & 1U     |
|-------------------------------------------|---------------------|

Example: 
10 = 1010 
 
Toggle bit 1 

1010 
0010 
---- 
1000 

|------------------------------------------------------------|--------------------------------------------------|
| Header 1                                                   | Header 2                                         |
|------------------------------------------------------------|--------------------------------------------------|
|Get n bits starting from position p                         | (num >> p) & ((1U << n) - 1)                     |
|Extracts n bits starting from position p (LSB = position 0) |                                                  |
|------------------------------------------------------------|--------------------------------------------------|
| Set/Put n bis of val into position p.                      | num |  (((val) & ((1U << n) - 1)) << p)          |
|------------------------------------------------------------|--------------------------------------------------|
| Clear n bits starting from position p                      | num & ~(((1U << n) - 1) << p)                    |
|------------------------------------------------------------|--------------------------------------------------|

|-------------------------------|
| X << 1  | Multiply by 2       |
|---------|---------------------|
| X >> 1  | Divide by 2         |
|-------------------------------|

|-------------------------------------------|--------------------------------------------------|
| Replace selected bits using a mask.       | (num & ~mask) | (val & mask)                     |
|-------------------------------------------|--------------------------------------------------|

|-------------------------------------------|--------------------------------------------------|
| Circular Shiting (Rotate)                 | w can be 8, 16, 32, 64                           |                                       |
|-------------------------------------------|--------------------------------------------------|
| Circular left shift by k on a w-bit value | ((num << k) | (num >> (w - k)))                  |
|-------------------------------------------|--------------------------------------------------|
| Circular left shift by k on a w-bit value | ((num >> k) | (num << (w - k)))                  |
|-------------------------------------------|--------------------------------------------------|
=============================================================
“Given a 32-bit unsigned integer, perform circular left shift by k.”


🔹 Version 3 (with values)

“Rotate 8-bit number 179 left by 3 positions.”


🧪 Example (they may give this)
num = 179 → 10110011k = 3w = 8

✅ Solution
(num << k) | (num >> (w - k))

🔍 Step-by-step
Step 1: Left shift
10110011 << 3 = 10011000

Step 2: Wrap bits
10110011 >> 5 = 00000101

Step 3: Combine
1001100000000101--------10011101 → 157

🏆 What You Should Say

“I shift left and bring back the overflow bits using right shift and OR.”

=============================================================
/*

🏆 Interview Tip

If interviewer asks: “Explain bit extraction”

Say: “Shift the required bits to LSB and mask using (1 << n) - 1.”

👉 This extracts n bits starting from position p (LSB = position 0)

(num >> p) & ((1U << n) - 1)    Get n bits starting from position p.
Get 3 bits starting from position 3.
num = 29 -> 11101
n = 3
p = 3

Step 2 : Creates mask with n ones 

Mask:   (1 << 3) - 1 = 111

(29 >> 3) & 7
29 -> 11101
29 >> 3 -> 00011 -> 3

 00011
&00111
------
 00011 -> 3
------
*/
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

very integer in binary ends with:

0 → even
1 → odd

| Number | Binary | Last     |
| ------ | ------ | -------- |
| 4      | 100    | 0 → even |
| 5      | 101    | 1 → odd  |
==================================================
Check power of 2
x && !(x & (x - 1))
==================================================
Remove lowest set bit
x & (x - 1)
==================================================
Isolate lowest set bit
x & -x
x & ~(x - 1)
==================================================
Keeps/Retails only the rightmost set bit i.e 1
Find right most set bit
Except right most set bit all other bits will be turned to zero
Retain rightmost set bit and turn all other bits into 0

|----------------------|
|Isolate lowest set bit|
|----------------------|
| X & -X               |
| X & ~(X - 1)         |
|----------------------|
| 1100 -> 0100         |
| X & ~ (X - 1)        |
|----------------------|
For Example : -

result = X & -X
n = 12 -> 1100
   -12 -> 0011 + 1 -> 0100
result = 0100

8 & ~(8 - 1) 
8 & ~7
1000 & ~0111
1000 & 1000
1000 -> Right most set bit in digit 8 is retained as it is

uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/1_bitwiseOperators$ cat extractLowestSetBit.c 
#include <stdio.h>
int main() {
	int n;
	printf("Enter the number\n");
	scanf("%d", &n);
	int x = n & -n;
	
	printf("x = %d\n", x);
	return 0;
}
============================
|--------------|------------------------------------|
| X & (X + 1)  | Turn off right most contiguous 1s  |
|              | Clear trailing 1's                 |
|              | Remove consecutive 1's   at end    |
|              | Example :                          |
|              | n = 0110 1111 -> 0110 0000         |
|--------------|------------------------------------|
| X | (X + 1)  | Turn on right most zero into 1     |
|              | Set Lowest Zero bit                |
|              | n = 1001   n+1 = 1010              |
|              | n | (n+ 1)        1011             |
|---------------------------------------------------|
| X ^ (X + 1)  | Flip all bits after rightmost 0    |
|              | Example 1 :                        |
|              | n    = 0110 1111                   |
|              | n+1  = 0111 0000                   |
|              | XOR  = 0001 1111                   |
|              | Example 2 :                        |
|              | n         => 10 => 1010            |
|              | n+1       =>       1011            |
|              | XOR 1010  =>       0001            |
|---------------------------------------------------|
============================
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/1_bitwiseOperators$ cat extractLowestSetBit.c 
#include <stdio.h>
int main() {
	int n;
	printf("Enter the number\n");
	scanf("%d", &n);
	int x = n & -n;
	
	printf("x = %d\n", x);
	return 0;
}
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/1_bitwiseOperators$ 
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

while (x)
{
    x = x & (x - 1);
    count++;
}
input x = 7;
for 7 & 6 = 6; count = 1;
for 6 & 5 = 4; count = 2;
for 4 & 3 = 0; count = 3; while(0) stops

============================

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
    unsigned int x = 0xA5, rev = 0;
    for (int K=0; K<8; K++)
    {
        //x = x >> 1; shiffting before extracting the number is wrong
        rev = (rev << 1) | (x & 1);
             x = x >> 1; // Extracting 0th bit in previous line and then shifting is good
    }
    printf("rev = %x \n", rev);
    return 0;
}
============================
==================================================
(x       & 0x0F)    -> Extract lower nibble 
(x >> 4) & 0xF0     -> Extract Upper nibble
(x >> 8) & 0xFF     -> Extract byte from integer
(x >> 4) & 0x0F     -> Extract bits 4-7 -> Extract bit fields
==================================================
(1 << n) -1         -> Create mask of n bits    
(1 << 5) -1 -> (100000 - 1) -> (32 - 1) -> 31 -> 11111 -> This creates a mask with lower 5 bits set to 1
| n | Expression     | Binary Result |
| - | -------------- | ------------- |
| 3 | `(1 << 3) - 1` | `00000111`    |
| 5 | `(1 << 5) - 1` | `00011111`    |
| 8 | `(1 << 8) - 1` | `11111111`    |
==================================================
Create contiguous mask between bit positions
Example: bits 3-7
((1 << 5) - 1) << 3
((31) - 1) << 3
(31) << 3
11111
--------------------------------------------------
Why 5 bits? Because: 7 - 3 + 1 = 5 -> We need 5 consecutive bits.
( ( (1<<(7-3+1) ) -1 ) << start
( ( 1 << 5 ) -1 ) << 3
General Formula: ((1 << (end - start + 1)) - 1) << start
Example: start = 3 and end = 7
(end - start + 1) => +1 bcz representation starts from 0
7 - 3 = 4 but 76543 is 5 bits
So add 1 to 4 to make it 5
==================================================

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

🧠 What is “Reverse Bytes”?

👉 Reverse the order of "bytes" in a number (not bits)

Example (32-bit):

0x12345678
→ 0x78563412
🧠 Why this matters (Endianness)
Little Endian (e.g., x86)
78 56 34 12   (LSB stored first)
Big Endian
12 34 56 78   (MSB stored first)

👉 Reversing bytes = converting between these representations

🧠 What is Endianness?
Little Endian → LSB at lowest address
Big Endian → MSB at lowest address

Example:

0x12345678

Little Endian (memory):
78 56 34 12

Big Endian:
12 34 56 78
===================================================
🔁 Swap Bytes (16-bit)
uint16_t swap16(uint16_t x) {
    return (x >> 8) | (x << 8); 
}

🧠 Mental model:

Right shift → brings MSB down
Left shift → pushes LSB up
🔁 Swap Bytes (32-bit)
uint32_t swap32(uint32_t x) {
    return ((x >> 24) & 0x000000FF) |
           ((x >> 8)  & 0x0000FF00) |
           ((x << 8)  & 0x00FF0000) |
           ((x << 24) & 0xFF000000);
}

🧠 Think in chunks:

[A][B][C][D]  →  [D][C][B][A]
🔁 Swap Words (32-bit)

Swap two 16-bit halves:

uint32_t swap_words(uint32_t x) {
    return (x >> 16) | (x << 16);
}
=================================================
🔥 Method 1: Bit Masking (INTERVIEW STANDARD)
#include <stdio.h>
#include <stdint.h>

uint32_t reverseBytes(uint32_t x)
{
    return ((x & 0x000000FF) << 24) |
           ((x & 0x0000FF00) << 8)  |
           ((x & 0x00FF0000) >> 8)  |
           ((x & 0xFF000000) >> 24);
}

int main()
{
    uint32_t x = 0x12345678;
    printf("Reversed = 0x%X\n", reverseBytes(x));
    return 0;
}
============================
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
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/1_bitwiseOperators$ cat binaryRepresentation.c 
#include <stdio.h>

/*
// Method 1: Using Bit Shifting (Most Common)
void printBinary(unsigned int num)
{
    
    for (int i = 31; i >= 0; i--)
    {
        printf("%d", (num>>i) & 1);
    }
    printf("\n");
}
*/

/*
// Method 2: Without Leading Zeros (Cleaner Output)
void printBinary(unsigned int n)
{
    int started = 0;

    for (int i = 31; i >= 0; i--)
    {
        int bit = (n >> i) & 1;

        if (bit == 1)
            started = 1;

        if (started)
            printf("%d", bit);
    }

    if (!started) // for n = 0
        printf("0");

    printf("\n");
}
*/

/*
// Method 3: Recursive (Elegant)
void printBinary(unsigned int n)
{
    if (n > 1)
        printBinary(n / 2);

    printf("%d", n % 2);
}
*/

int main()
{
    unsigned int num;
    printf("Enter number: ");
    scanf("%u", &num);

    printBinary(num);
    printf("\n");
    return 0;
}

/*
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ ./a.out
Enter number: 5
00000000000000000000000000000101

Explanation :-
-----------
5 -> 101
(5 >> 31) & 1			<- make sure loop runs from 31 down to 0, so that all bits are covered and last bit is right shifted by 0 position' 
and doesn't start from 32 and ends at 1, which will miss the last shift by 0.

uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ cc binaryRepresentation.c
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ ./a.out
Enter number: 5
101
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ cc binaryRepresentation.c
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ ./a.out
Enter number: 5
101
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ 


Bonus: Print Only N Bits (e.g., 8-bit view)
for (int i = 7; i >= 0; i--)
{
    printf("%d", (n >> i) & 1);
}

// Method 3: Recursive (Elegant)
void printBinary(unsigned int n)
{
    if (n > 1)
        printBinary(n / 2);

    printf("%d", n % 2);
}

Recursive method :-
----------------
pB(6)			pB(3)			pB(1)
(6>1)			(3>1)			(1>1)
	pB(6/2)			pB(3/3)			
									(1%2) is 1
		(6%2) is 0		   (3%2) is 1

result is 110
*/
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/1_bitwiseOperators$ 
============================
🔥 SECTION 1: Register Programming (VERY COMMON)
1️⃣ Set specific bits in a hardware register

👉 Problem
Enable bits 3, 5, 7 in a 32-bit register reg without affecting others.

Solution
Set bits 3, 5, 7
reg |= (1U << 3) | (1U << 5) | (1U << 7);

why OR ? anything OR with 1 is 1
===========================================================
2️⃣ Clear interrupt status bits

👉 Problem
Clear bits 0–3 in reg (interrupt status register).

Solution
0-3 means 3210 bits in a number. So to clear & 0 or use ~
reg = reg & ~0xF;
============================================================
3️⃣ Toggle feature flags

👉 Problem
Toggle bits 8 and 9 in a control register.

Solution
EXOR table is best for toggle a bit/bits
-----------
0   0   0
-----------
0   1   1 exor of 1 with 0 is 1, which toggles 0 to 1
-----------
1   0   1
-----------
1   1   0 exor of 1 with 1 is 0, which toggles 1 to 0
-----------
=======================================
🔹 What is ~(1 << k) ?

👉 Two steps:

Create (1 << k) → single bit = 1

Apply ~ → invert all bits
🔍 Example (k = 3)

Step 1:
1 << 3 = 00001000

Step 2 (NOT operator ~):
~(00001000) = 11110111

👉 All bits flipped

🎯 Meaning

“Everything is 1 except bit k”

🔥 Why this matters
✅ Clear a bit (IMPORTANT)
n = n & ~(1 << k);



4️⃣ Extract field from register

👉 Problem
Bits [15:8] represent a queue ID. Extract it.

=======================================
5️⃣ Update field safely (classic kernel pattern)

#define BYTE_MASK 0xFF
#define SHIFT     16

reg = (reg & ~(BYTE_MASK << SHIFT)) |
      ((val & BYTE_MASK) << SHIFT);

👉 Problem
Set bits [23:16] to value val without disturbing other bits.
Solution
Clears (sets to 0) 8 bits starting at bit position 16

reg = (reg & ~(0xFF << 16)) | ((val & 0xFF) << 16);
---------------------------------------
>>>>>>1st bracket<<<<<
((val & 0xFF) << 16)    <== 👉 Mask only the lowest 8 bits (1 byte) of val
val = 0x7766;
val & 0xFF = 0x66;
((val & 0xFF) << 16) = 0110 0110 0000 0000 0000 0000

---------------------------------------
>>>>>2nd bracket<<<<<
reg & ~(0xFF << 16)

👉 AND rules:

bit & 1 → unchanged
bit & 0 → becomes 0

So:

Bits [23:16] → cleared (forced to 0)
Other bits   → unchanged


🧪 Example
reg = 0x12345678

Binary:
00010010 00110100 01010110 01111000

Mask:

~(0xFF << 16) = 11111111 00000000 11111111 11111111

Apply AND:

 (0xFF << 16)      00010010 00110100 01010110 01111000
~(0xFF << 16)     &11111111 00000000 11111111 11111111
                   -----------------------------------
                   00010010 00000000 01010110 01111000
                   -----------------------------------
reg & step2 | step1
((val & 0xFF) << 16) =      01100110 00000000 00000000
                 | 00010010 00000000 01010110 01111000
                   -----------------------------------
                   00010010 01100110 01010110 01111000
                   -----------------------------------
👉 Result: 0x12005678
---------------------------------------
=======================================
Swap nibbles
(x & 0x0F) << 4 | (x & 0xF0) >> 4;


AND  (&) → Extract / Clear
OR   (|) → Set
XOR  (^) → Toggle
SHIFT     → Move bits
=======================================

🔥 SECTION 2: Endianness + Packet Parsing
6️⃣ Parse Ethernet header

👉 Problem
Extract EtherType from raw packet buffer:

uint8_t *pkt;
7️⃣ Convert network to host order

👉 Problem
You read a 32-bit value from NIC → convert to CPU format.

8️⃣ Detect little vs big endian at runtime

👉 Problem
Write a function to check endianness.

9️⃣ Swap bytes of DMA descriptor

👉 Problem
Hardware gives big-endian descriptor → CPU is little-endian.

🔟 Extract IP header version

👉 Problem
From first byte:

0x45

Extract version and IHL.

🔥 SECTION 3: Bit Tricks (Driver Logic)
1️⃣1️⃣ Check if descriptor is owned by hardware

👉 Problem
Bit 31 = ownership bit.
Return true if HW owns it.

1️⃣2️⃣ Set ring buffer wrap bit

👉 Problem
Set last descriptor’s wrap bit (bit 15).


1️⃣3️⃣ Count active queues

👉 Problem
Given bitmask of queues:

0b10110110

Count active ones.

1️⃣4️⃣ Find first available queue

👉 Problem
Find first zero bit in mask.

1️⃣5️⃣ Align address to 64 bytes

👉 Problem
Align addr to next 64-byte boundary.

🔥 SECTION 4: Advanced Masking (VERY IMPORTANT)
1️⃣6️⃣ Build GENMASK macro manually

👉 Problem
Implement:

GENMASK(h, l)
1️⃣7️⃣ Extract arbitrary bitfield

👉 Problem
Extract bits [27:13] from a 32-bit value.

1️⃣8️⃣ Replace bitfield safely

👉 Problem
Replace bits [10:5] with new value.

1️⃣9️⃣ Check power-of-two buffer size

👉 Problem
Validate ring size is power of 2.

2️⃣0️⃣ Circular buffer index wrap

👉 Problem
Efficiently wrap index using bit trick (no %).

🔥 BONUS (INTERVIEW KILLER)
2️⃣1️⃣ Memory-mapped IO bug

👉 Problem
Why is this dangerous?

reg |= (1 << 5);

👉 Expected answer:

Missing readl/writel
Race condition
Needs atomic / barrier
2️⃣2️⃣ Volatile vs non-volatile

👉 Problem
Why must hardware registers be volatile?


Why volatile ?
Prevents compiler from
-> caching register
-> reordering accesses
=======================================
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/1_bitwiseOperators$ cat reverseBits.c 
#include <stdio.h>
#include <stdint.h> //'uint32_t’ is defined in header ‘<stdint.h>’; did you forget to ‘#include <stdint.h>

int main ()
{
	unsigned int n = 6;
	unsigned int bit = 0;
	uint32_t res = 0, num = 0;

	while (n>0)
	{
		res = (res << 1) | (n & 1) ;
		n = n >> 1;
		printf("res=%d \t", res);
	}
	printf("\n");
	//printf("res=%d \n", res);
	//printf("res=%u \n", res);

	num = res;
    for (int i = 31; i >= 0; i--)
    {
        printf("%d", (num >> i) & 1);

        // optional: space every 8 bits for readability
        if (i % 8 == 0) printf(" ");
    }
    printf("\n");

	return res;
}
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/1_bitwiseOperators$ 
===========================================
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/1_bitwiseOperators$ cat swapEvenOddBitPositions.c 
#include <stdio.h>

unsigned int swap_even_odd_bits( unsigned int x)
{
	unsigned int result = 0;
	unsigned int even = x & 0xAAAAAAAA; // mask even bits
	unsigned int odd = x & 0x55555555;	// mask odd bits

	even = even >> 1; 					//A -> 1010 -> move odd bit at 1st position to 0th position. So right shift from 1 to 0th position
	odd = odd << 1;

	result = even | odd;
	
	return result;
}

int main ()
{
	unsigned int x = 23; // 00010111
	printf("Result: %u \n", swap_even_odd_bits(x));
	return 0;
}

/*
a-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ vi setevenOddBits.c
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ cc setevenOddBits.c
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ ./a.out
Result: 43 
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ 
*/
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/1_bitwiseOperators$ 
===========================================
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/1_bitwiseOperators$ cat swapUsingXOR.c 
#include <stdio.h>

int main()
{
	int a=12, b=89;

	a ^= b;
	b ^= a;
	a ^= b;

	printf("a=%d, b=%d\n", a, b);
	return 0;
}
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/1_bitwiseOperators$ 
===========================================
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/1_bitwiseOperators$ cat swapWithoutTemp.c 
#include <stdio.h>

int main () {
	int a, b;

	printf("Enter the 2 diff numbers to be swaped \n");
	scanf("%d %d", &a, &b);
    /*
	scanf("%d, %d", &a, &b);   <--- ❌ format specifier with , in between

This format expects input like:

2, 3

But you entered:

2

So:

a = 2 ✅
b is NOT assigned ❌ (remains garbage → 32764)

👉 That’s why output is wrong:

a = 32764, b = 2

	uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ ./a.out
	Enter the 2 diff numbers to be swaped 
	2
	The 2 diff numbers after performing swap are a = 32764, b = 2 
	uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$

THIS WORKS FOR ❌ format specifier with , in between
----------------------------------------------------
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ ./a.out
Enter the 2 diff numbers to be swaped 
333333, 45678
The 2 diff numbers after performing swap are a = 45678, b = 333333 
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$
	*/

	a ^= b;
	b ^= a;
	a ^= b;
	printf ("The 2 diff numbers after performing swap are a = %d, b = %d \n", a, b);

	return 0;
}

/*
OUTPUT

uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ ./a.out
Enter the 2 diff numbers to be swaped 
12345      6789
The 2 diff numbers after performing swap are a = 6789, b = 12345 
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ ./a.out
Enter the 2 diff numbers to be swaped 
678910                                     12345
The 2 diff numbers after performing swap are a = 12345, b = 678910 
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ 
*/
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/1_bitwiseOperators$ 
===========================================
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/1_bitwiseOperators$ cat swapNibbles.c 
#include <stdio.h>

int main ()
{
	int x = 0xF0;
	int lowernb = x & 0x0F;
	int highernb = x & 0xF0;
	int swappednb = (lowernb << 4) | (highernb >> 4);

	printf("%x \n", swappednb);

	return 0;
}

/*
Variation: Swap nibbles in 32-bit integer
unsigned int x = 0x12345678;

unsigned int result =
    ((x & 0x0F0F0F0F) << 4) |
    ((x & 0xF0F0F0F0) >> 4);
*/
===========================================

===========================================

===========================================
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/1_bitwiseOperators$ cat CountSetBits_BrianKernighans.c 
// 8. Count Set Bits using Brian Kernighan's Algorithm

#include <stdio.h>

int main() {
	unsigned int num = 0;
	int count = 0;
	
	printf("Enter the hexadecimal input: ");
	scanf("%x", &num);

	while(num) {
		num = num & (num-1);
		count++;
		printf("num = %x, count = %d \n", num, count);
	}
	printf("There are tottaly %d number of setbits \n", count);
	return 0;
}

/*
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ ./a.out
Enter the hexadecimal input: FFF
num = 4094, count = 1 
num = 4092, count = 2 
num = 4088, count = 3 
num = 4080, count = 4 
num = 4064, count = 5 
num = 4032, count = 6 
num = 3968, count = 7 
num = 3840, count = 8 
num = 3584, count = 9 
num = 3072, count = 10 
num = 2048, count = 11 
num = 0, count = 12 
There are tottaly 12 number of setbits 
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ vi CountSetBits_BrianKernighans.c
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ cc CountSetBits_BrianKernighans.c
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ ./a.out
Enter the hexadecimal input: FFFF
num = fffe, count = 1 
num = fffc, count = 2 
num = fff8, count = 3 
num = fff0, count = 4 
num = ffe0, count = 5 
num = ffc0, count = 6 
num = ff80, count = 7 
num = ff00, count = 8 
num = fe00, count = 9 
num = fc00, count = 10 
num = f800, count = 11 
num = f000, count = 12 
num = e000, count = 13 
num = c000, count = 14 
num = 8000, count = 15 
num = 0, count = 16 
There are tottaly 16 number of setbits 
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ ./a.out
Enter the hexadecimal input: FFF
num = ffe, count = 1 
num = ffc, count = 2 
num = ff8, count = 3 
num = ff0, count = 4 
num = fe0, count = 5 
num = fc0, count = 6 
num = f80, count = 7 
num = f00, count = 8 
num = e00, count = 9 
num = c00, count = 10 
num = 800, count = 11 
num = 0, count = 12 
There are tottaly 12 number of setbits 
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ 

*/
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/1_bitwiseOperators$ 
#include <stdio.h>
int countSetBits(unsigned int num)
{
    int count = 0;
    while (num)
    {
        if(num & 1)
        {
             count++;
        }
        num = num >> 1; // as you keep right shifting the number by 1 in every loop, finally number becomes zero and the loop will stop.
        printf("num=%d \n", num);
    }
    return count;
}
int main ()
{
    unsigned int n ;
    printf("%s : Enter the number n ", __func__);
    //scanf("%d", &n);
    scanf("%x", &n);
    int result = countSetBits(n);
    printf ("There are totally %d number of setbits \n", result);

    return 0;
}

/*

uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ ./a.out
main : Enter the number n 10
result = 2 
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ ./a.out
main : Enter the number n 15
result = 4 
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ ./a.out
main : Enter the number n F
result = 17 

-----------------
scanf("%d", &n);
-----------------

%d expects decimal input

%d expects decimal input
F0 is hexadecimal
So scanf fails → n gets garbage value

That’s why you see:

num=1200926408 ...


-----------------
scanf("%x", &n);
-----------------
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ ./a.out
main : Enter the number n 55
num=42 
num=21 
num=10 
num=5 
num=2 
num=1 
num=0 
There are totally 4 number of setbits 
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ ./a.out
main : Enter the number n F0
num=120 
num=60 
num=30 
num=15 
num=7 
num=3 
num=1 
num=0 
There are totally 4 number of setbits 
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ ./a.out
main : Enter the number n 01
num=0 
There are totally 1 number of setbits 
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ 
*/
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/1_bitwiseOperators$
=========================================
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/1_bitwiseOperators$ cat reverseBitsMaskingMethod.c
/*
 * Reverse bits of a 32-bit unsigned integer
 * Efficient Divide-and-Conquer (Mask + Shift) Method
 *
 * Used in:
 *   - Network drivers
 *   - Endianness conversion
 *   - Bitstream processing
 *   - Hardware protocols
 *   - CRC / crypto / DSP
 */

#include <stdio.h>
#include <stdint.h>

/* Function to reverse all 32 bits */
uint32_t reverse_bits(uint32_t n)
{
    /* Swap odd and even bits */
    n = ((n >> 1) & 0x55555555) | ((n << 1) & 0xAAAAAAAA);

    /* Swap consecutive 2-bit groups */
    n = ((n >> 2) & 0x33333333) | ((n << 2) & 0xCCCCCCCC);

    /* Swap nibbles (4 bits) */
    n = ((n >> 4) & 0x0F0F0F0F) | ((n << 4) & 0xF0F0F0F0);

    /* Swap bytes (8 bits) */
    n = ((n >> 8) & 0x00FF00FF) | ((n << 8) & 0xFF00FF00);

    /* Swap 16-bit halves */
    n = (n >> 16) | (n << 16);

    return n;
}

/* Print binary representation */
void print_binary(uint32_t n)
{
    int i;

    for (i = 31; i >= 0; i--)
    {
        printf("%u", (n >> i) & 1);

        /* spacing every 4 bits */
        if (i % 4 == 0)
            printf(" ");
    }

    printf("\n");
}

int main()
{
    uint32_t num = 0x12345678;
    uint32_t reversed;

    printf("Original Number : 0x%08X\n", num);
    print_binary(num);

    reversed = reverse_bits(num);

    printf("\nReversed Number : 0x%08X\n", reversed);
    print_binary(reversed);

    return 0;
}
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/1_bitwiseOperators$ 
===========================================
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/1_bitwiseOperators$ cat generateAllSubSetsUsingBits.c 
#include <stdio.h>

void generateSubsets(int arr[], int n)
{
    int total = 1 << n;  // 2^n   i.e 1000 i.e 8
	printf("%d \n", total);

    for (int i = 0; i < total; i++)
    {
        printf("{ ");

        for (int j = 0; j < n; j++)
        {
            // Check if j-th bit is set
            if ( i & (1 << j) )
            {
                printf("%d ", arr[j]);
            }
        }

        printf("}\n");
    }
}

int main()
{
    int arr[] = {1, 2, 3};
    int n = 3;

    generateSubsets(arr, n);

    return 0;
}

/*

Output
{ }
{ 1 }
{ 2 }
{ 1 2 }
{ 3 }
{ 1 3 }
{ 2 3 }
{ 1 2 3 }

🧠 Core Logic

Each number i represents a subset in binary form

Example: n = 3 → elements = {A, B, C}
i (decimal)	Binary	Subset
0	000	{}
1	001	{A}
2	010	{B}
3	011	{A, B}
4	100	{C}
5	101	{A, C}
6	110	{B, C}
7	111	{A, B, C}
*/
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/1_bitwiseOperators$ 
===========================================
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/1_bitwiseOperators$ cat compareSignedUnsignedShift.c
// 3. Compare Signed and Unsigned Right Shift Bahaviour
#include <stdio.h>

int main() {
    unsigned int usd;
    int sd;
    int shift;

    printf("Enter the unsigned number: ");
    printf("Enter the unsigned number: ");
    scanf("%d", &usd);
    printf("Enter the signed number: ");
    scanf("%d", &sd);
    printf("Enter the shifts to perform: ");
    scanf("%d", &shift);

    int bit = usd >> shift;
    printf("\nAfter performing the unsigned right shifts: %d\n", bit);

    bit = sd >> shift;
    printf("\nAfter performing the signed right shifts: %d\n", bit);
}

/*
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ ./a.out
Enter the unsigned number: 16
Enter the signed number: 16
Enter the shifts to perform: 2

After performing the unsigned right shifts: 4

After performing the signed right shifts: 4
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ ./a.out
Enter the unsigned number: 16
Enter the signed number: -16
Enter the shifts to perform: 2

After performing the unsigned right shifts: 4

After performing the signed right shifts: -4
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ ./a.out
Enter the unsigned number: 255
Enter the signed number: -1
Enter the shifts to perform: 1

After performing the unsigned right shifts: 127

After performing the signed right shifts: -1
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ 
*/
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/1_bitwiseOperators$
==================================================================
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/1_bitwiseOperators$ cat binaryRepresentation.c
#include <stdio.h>

/*
// Method 1: Using Bit Shifting (Most Common)
void printBinary(unsigned int num)
{
    
    for (int i = 31; i >= 0; i--)
    {
        printf("%d", (num>>i) & 1);
    }
    printf("\n");
}
*/

/*
// Method 2: Without Leading Zeros (Cleaner Output)
void printBinary(unsigned int n)
{
    int started = 0;

    for (int i = 31; i >= 0; i--)
    {
        int bit = (n >> i) & 1;

        if (bit == 1)
            started = 1;

        if (started)
            printf("%d", bit);
    }

    if (!started) // for n = 0
        printf("0");

    printf("\n");
}
*/

/*
// Method 3: Recursive (Elegant)
void printBinary(unsigned int n)
{
    if (n > 1)
        printBinary(n / 2);

    printf("%d", n % 2);
}
*/

int main()
{
    unsigned int num;
    printf("Enter number: ");
    scanf("%u", &num);

    printBinary(num);
    printf("\n");
    return 0;
}

/*
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ ./a.out
Enter number: 5
00000000000000000000000000000101

Explanation :-
-----------
5 -> 101
(5 >> 31) & 1           <- make sure loop runs from 31 down to 0, so that all bits are covered and last bit is right shifted by 0 position' 
and doesn't start from 32 and ends at 1, which will miss the last shift by 0.

uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ cc binaryRepresentation.c

uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ ./a.out
Enter number: 5
101
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ cc binaryRepresentation.c
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ ./a.out
Enter number: 5
101
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ 


Bonus: Print Only N Bits (e.g., 8-bit view)
for (int i = 7; i >= 0; i--)
{
    printf("%d", (n >> i) & 1);
}

// Method 3: Recursive (Elegant)
void printBinary(unsigned int n)
{
    if (n > 1)
        printBinary(n / 2);

    printf("%d", n % 2);
}

Recursive method :-
----------------
pB(6)           pB(3)           pB(1)
(6>1)           (3>1)           (1>1)
    pB(6/2)         pB(3/3)         
                                    (1%2) is 1
        (6%2) is 0         (3%2) is 1

result is 110
*/
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/1_bitwiseOperators$

===========================================
int extractLowestBits(int num, int n)
{
    return num & ((1 << n) - 1);
}

int main()
{
    int num = 29;
    int n = 3;

    int result = extractLowestBits(num, n);

    printf("Lowest %d bits of %d = %d\n", n, num, result);

    return 0;
}

/*
👉 Keeps only the lowest n bits
num & mask

Example 1

num = 29 → 11101
n = 3

Mask:   (1 << 3) - 1 = 111
(1 << 3) = 10000 = 8
8-1 = 7 = 111

AND:
 11101
&00111
------
 00101 → 5
------

Example 2

num = 59 -> 101011
n = 3

AND:
 101011
&000111
-------
 000011 -> 3
-------
*/
===========================================
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/1_bitwiseOperators$ cat findMissingNumberInArray.c 
/*
🔥 Key XOR Properties
x ^ x = 0
x ^ 0 = x

Find Missing Number using XOR
📌 Problem

You are given:

An array of size n-1
Numbers are from 1 to n
One number is missing

👉 Find the missing number

👉 Why this works?

All numbers cancel out except the missing one.
*/

#include <stdio.h>
#include <string.h>

int findMissing(int arr[], int n)
{
    int xor_full = 0;   // XOR from 1 to n
    int xor_input_arr  = 0;   // XOR of array elements

    // XOR all numbers from 1 to n. i bcz first element in the array is 1.
    // generally forloop starts from 0. But in this case we want to xor elements of the array only
    // starting from the first element. 
	// Here first element in the array is 1. So use 1 so that the sum of xor of all elements starts from 1
	// and not 0

    // Step 1: XOR all elements including missing number
    for (int i = 1; i <=n; i++)
    {
        xor_full ^= i;
    }

    // Step 2: XOR all elements in input array (size n-1)
    for (int i = 0; i < (n-1); i++)
    {
		printf("%d \t", arr[i]);

        xor_input_arr ^= arr[i];
    }
	printf("\n");

    // Missing number
    return xor_full ^ xor_input_arr;
}

int main()
{
    int arr[] = {1, 2, 4, 5};	// missing 3
    int n = 5;

    int missing = findMissing(arr, n);

    printf("Missing number = %d\n", missing);

    return 0;
}

/*
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ ./a.out
1 	2 	4 	5 	
Missing number = 3
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ 
*/
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/1_bitwiseOperators$ 
===========================================
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/1_bitwiseOperators$ cat findTwoUniqueNumbers.c 
#include <stdio.h>

void findTwoUnique(int arr[], int n)
{
    int xor = 0;

    // Step 1: XOR all elements
    for (int i = 0; i < n; i++)
        xor ^= arr[i];

    // Step 2: Get rightmost set bit
    int setBit = xor & (-xor);

    int x = 0, y = 0;

    // Step 3: Divide and XOR
    for (int i = 0; i < n; i++) {
        if (arr[i] & setBit)
            x ^= arr[i];
        else
            y ^= arr[i];
    }

    printf("Unique numbers: %d and %d\n", x, y);
}

int main()
{
    int arr[] = {1, 1, 225, 228, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    findTwoUnique(arr, n);

    return 0;
}

/*
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ ./a.out
Unique numbers: 225 and 228
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$

🎯 Problem

Find two unique numbers where every other number appears twice

Example:
{1, 1, 225, 228, 3, 3}

👉 Unique numbers = 225 and 228

🧠 Step 1: XOR All Elements
           ----------------
xor = 1 ^ 1 ^ 225 ^ 228 ^ 3 ^ 3

Cancel duplicates:
----------------
1 ^ 1 = 0
3 ^ 3 = 0

So:

xor = 225 ^ 228 = 5
🔎 Step 2: Find a Differentiating Bit

We need a bit where 225 and 228 differ

Use:

setBit = xor & (-xor);

👉 This isolates the rightmost set bit

Example:
xor = 5 → 00000101
-xor     → 11111011  (2’s complement)
-------------------
setBit = 00000001

👉 This bit differs between the two numbers

🔀 Step 3: Divide into Two Groups

Split numbers based on this bit:

Group 1 (bit = 1):
225 → included
1   → included
1   → included
Group 2 (bit = 0):
228 → included
3   → included
3   → included
⚙️ Step 4: XOR Each Group
Group 1:
1 ^ 1 ^ 225 = 225
Group 2:
3 ^ 3 ^ 228 = 228
✅ Final Answer
Unique numbers = 225 and 228
*/
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/1_bitwiseOperators$ 
===========================================
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/1_bitwiseOperators$ cat findMissingNumberInJumbelledArray.c
#include <stdio.h>
int single(int arr[], int n);

int main () {

    int arr[5] = { 1, 1, 225, 3, 3 };
    //int arr[6] = { 1, 1, 225, 228, 3, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);   // I compute array size using sizeof to avoid hardcoding and prevent out-of-bounds errors or garbage errors
    int res = single (arr, n);
    printf("res=%d \n", res);

    return 0;
}

int single(int arr[], int n) {
//int single(int* arr, int n) {
    int res = 0;
    for (int i = 0; i < n; i++)
        res ^= arr[i];
    return res;
}

/*
int res = single (arr, 6);
Here we are passing 6 instead of 4 or 5. =4 or <5

 so the answer is wrong
Pass correct sizeof array like this
int n = = sizeof(arr) / sizeoff(arr[0]);
*/


/*
    //int arr[5] = { 1, 1, 225, 3, 3 };

uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ ./a.out
res=2
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ vi findSingleNumber.c 
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ ./a.out
res=5
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ vi findSingleNumber.c 
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ cc findSingleNumber.c 
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ ./a.out
res=225 
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ cat findSingleNumber.c 

Explanation :-
-----------

uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ cc findSingleNumber.c 
findSingleNumber.c: In function ‘main’:
findSingleNumber.c:6:43: warning: excess elements in array initializer
    6 |         int arr[5] = { 1, 1, 225, 228, 3, 3 };
      |                                           ^
findSingleNumber.c:6:43: note: (near initialization for ‘arr’)
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ ./a.out
res=6 
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ vi findSingleNumber.c 
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ cc findSingleNumber.c 
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ ./a.out
res=5 
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/chatGPT/bitwiseOperators$ 

*/
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/1_bitwiseOperators$ 
===========================================
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/1_bitwiseOperators$ cat reverseBitsMaskingMethod.c
/*
 * Reverse bits of a 32-bit unsigned integer
 * Efficient Divide-and-Conquer (Mask + Shift) Method
 *
 * Used in:
 *   - Network drivers
 *   - Endianness conversion
 *   - Bitstream processing
 *   - Hardware protocols
 *   - CRC / crypto / DSP
 */

#include <stdio.h>
#include <stdint.h>

/* Function to reverse all 32 bits */
uint32_t reverse_bits(uint32_t n)
{
    /* Swap odd and even bits */
    n = ((n >> 1) & 0x55555555) | ((n << 1) & 0xAAAAAAAA);

    /* Swap consecutive 2-bit groups */
    n = ((n >> 2) & 0x33333333) | ((n << 2) & 0xCCCCCCCC);

    /* Swap nibbles (4 bits) */
    n = ((n >> 4) & 0x0F0F0F0F) | ((n << 4) & 0xF0F0F0F0);

    /* Swap bytes (8 bits) */
    n = ((n >> 8) & 0x00FF00FF) | ((n << 8) & 0xFF00FF00);

    /* Swap 16-bit halves */
    n = (n >> 16) | (n << 16);

    return n;
}

/* Print binary representation */
void print_binary(uint32_t n)
{
    int i;

    for (i = 31; i >= 0; i--)
    {
        printf("%u", (n >> i) & 1);

        /* spacing every 4 bits */
        if (i % 4 == 0)
            printf(" ");
    }

    printf("\n");
}

int main()
{
    uint32_t num = 0x12345678;
    uint32_t reversed;

    printf("Original Number : 0x%08X\n", num);
    print_binary(num);

    reversed = reverse_bits(num);

    printf("\nReversed Number : 0x%08X\n", reversed);
    print_binary(reversed);

    return 0;
}
uma-shankar@uma-shankar-HP-Laptop-15-bs1xx:~/my_cProgram/1_bitwiseOperators$
===========================================



