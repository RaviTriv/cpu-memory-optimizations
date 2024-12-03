# cpu-memory-optimizations
Today CPU cores are very fast in comparision to memory access. This can be a bottleneck. Below are a few techniques that can be used to optimize performance.

### Write Combining

### Bypassing Cache
By default nothing is directly written to memory. Everything goes through cache, if our cache space is full we replace older cache lines. In some situations we may have data that will not be accessed again anytime soon or frequently, making it a waste to use cache space. In these situations we can bypass cache and write directly to memory.

![Non Temporal Store](./images/nonTemporalStore.png)

A simple example is we intialize two matrixs, matA and matB. We write values to matA and then write values to matB. After writing values to matB, we want to read from matA. In this case since we will not be reading values of matB anytime soon we can make use of intel's non temporal stores to write matB directly to memory. The simple example is roughly 3 times faster.

### Fitting into Cache Lines
Reading from cache is significantly faster than reading from memory. Therefore its important to fit as much data into cache as possible. CPU cache is a collection of  cache lines, in this case each cache line is 64 bytes long and read in `words`, a fixed size of bytes. We want to optimize the way we put data into `words` such that their are minimal holes.

```
struct hole
{
  int a;
  double b[6];
  short c;
  short d;
  int e;
  int f;
};
```
In the `struct` above we use 4 bytes and then 8 bytes, for a consecutive total of 12 bytes. Unforunately this cannot fit into a `word` of 8 bytes, so we are left with a `hole`.
```
/* size: 72, cachelines: 2, members: 6 */
```

![Memory Hole](./images/cacheline.png)

If we organize our struct so that 2 shorts follow the int this can close the holes.

```
struct noHole
{
  int a;
  short b;
  short c;
  double d[6];
  int e;
  int f;
};
```

This simple change allows us to make better use of the available space.

```
/* size: 64, cachelines: 1, members: 6 */
```

*Note: CPU cache line and word size can differ by hardware.

### notes
out of order execution


optimizing cache access 

fitting into cache line
-> // need to rearrange to make compatabile with word size of cpu
// 64 bits = 8 bytes cpu breaks into word size therefore giving us hole of 4

reduce code footprint
-> make program smaller such that it can fit in cache

Optimizing TLB usage
-> reduce number of pages, simply can result in less TLB misses
-> make lookup cheaper, reduce the number of higher level directory tables

review TLB miss vs page fault

ASLR, turn off ASLR

Prefetching
use when lots of misses occur
_mm_prefetch intrinsic

Direct Cache Access
