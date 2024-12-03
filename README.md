# cpu-memory-optimizations
Today CPU cores are very fast in comparision to memory access. This can be a bottleneck. Below are a few techniques that can be used to optimize performance.

### Write Combining

### Bypassing Cache

### Fitting into Cache Lines
Reading from cache is significantly faster than reading from memory. Therefore its important to fit as much data into cache as possible. CPU cache is a collection of  cache lines, in this case each cache line is 64 bytes long and read in `words`, a fixed size of bytes. We want to optimize the way we put data into `words` such that their is minimal holes.

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

out of order execution


bypassing cache

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
