#include "types.h"
#include "defs.h"

static uint seed = 123456789;

int
randomread(struct inode *ip, char *dst, int n)
{
  for (int i = 0; i < n; i++) {
    seed ^= seed << 13;
    seed ^= seed >> 17;
    seed ^= seed << 5;
    dst[i] = seed & 0xFF;
  }
  return n;
}

