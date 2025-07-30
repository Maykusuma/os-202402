#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

char *argv[] = { "audit", 0 };  // Ganti sh jadi audit

int
main(void)
{
  if(open("console", O_RDWR) < 0){
    mknod("console", 1, 1);
    open("console", O_RDWR);
  }
  dup(0);  // stdout
  dup(0);  // stderr

  // LANGSUNG exec audit, TANPA fork()
  exec("audit", argv);
  printf(1, "init: exec audit failed\n");
  exit();
}
