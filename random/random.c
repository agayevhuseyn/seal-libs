#include "../src/libdef.h"
#include <stdlib.h>
#include <time.h>

static const char* libname = "random";

void _initlib() {
  create_const_seal_objects();
}

sealobj* _srand(sealobj** args, size_t arg_size)
{
  seal_check_args(libname, "srand", (seal_type[]){SEAL_INT}, 1, args, arg_size);
  srand(args[0]->integer.val);
  return seal_null();
}

sealobj* _rand(sealobj** args, size_t arg_size)
{
  seal_check_args(libname, "rand", NULL, 0, args, arg_size);
  sealobj* res = create_sealobj(SEAL_INT);
  res->integer.val = rand();
  return res;
}
