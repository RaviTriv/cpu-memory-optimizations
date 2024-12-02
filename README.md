# cpu-memory-optimizations
cpu cores fast, memory bottleneck

out of order execution

write combining

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