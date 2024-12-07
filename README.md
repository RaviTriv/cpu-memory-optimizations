# CPU Memory Optimizations
Today CPU cores are very fast in comparision to memory access. Below are a few techniques that can be used to reduce memory access time.
### Write Combining
When we attempt to write past L1 cache we write to a line buffer before the next cache level. Depending on the hardware there are a limited number of buffers that can be written to. Each of these buffers correspond to unqiue addresses and can combine data written to the same address. This is known as write combining. We want to fill these buffers as much as possible to reduce the amount of writes we perform.

![Write Combine Buffer](./images/WCB.png)
In the example above we have 6 buffers. Illustrated is the difference between writing to 6 unqiue addresses vs 7 or more. Once a new memory location is introduced we will be forced to write to cache before we can fill the buffers to the max.

`NOT TAKING FULL ADVATAGE OF WRITE COMBINING TIME TAKEN: 0.927197` <br>
`WRITE COMBINING TIME TAKEN: 0.253306` <br>

We can observe a rough 3x performance improvement by better utilizing write combining in our simple example.

### Bypassing Cache
By default nothing is directly written to memory. Everything goes through cache, if our cache space is full we replace older cache lines. In some situations we may have data that will not be accessed again anytime soon or frequently, making it a waste to use cache space. In these situations we can bypass cache and write directly to memory.

![Non Temporal Store](./images/nonTemporalStore.png)

A simple example is we intialize two matrices, matA and matB. We write values to matA and then write values to matB. After writing values to matB, we want to read from matA. In this case since we will not be reading values of matB anytime soon we can make use of non temporal stores to write matB directly to memory. 

`NO CACHE BYPASS TIME TAKEN: 50.825197`<br>
`CACHE BYPASS TIME TAKEN: 15.427559`<br>

The simple example is roughly 3 times faster.

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
