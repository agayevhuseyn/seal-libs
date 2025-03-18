#include "../src/libdef.h"
#include <stdlib.h>
#include <time.h>

static const char* libname = "random";

void _initlib() {
  srand(time(0));
}

sealobj* _rand(sealobj** args, size_t arg_size)
{
  seal_check_args(libname, "rand", NULL, 0, args, arg_size);
  sealobj* res = create_sealobj(SEAL_INT);
  res->integer.val = rand();
  return res;
}
