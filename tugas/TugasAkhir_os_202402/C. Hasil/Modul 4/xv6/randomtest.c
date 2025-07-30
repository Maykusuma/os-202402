#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(void) {
  char buf[8];
  int fd = open("/dev/random", O_RDONLY);
  if (fd < 0) {
    printf(1, "cannot open /dev/random\n");
    exit();
  }

  int n = read(fd, buf, sizeof(buf));
  if (n < 0) {
    printf(1, "read failed\n");
    close(fd);
    exit();
  }

  for (int i = 0; i < n; i++) {
    printf(1, "%d ", buf[i] & 0xFF);  // 🧠 mask pakai & 0xFF biar unsigned
  }
  printf(1, "\n");

  close(fd);
  exit();
}
