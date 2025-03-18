#include "../src/libdef.h"
#include <time.h>

static const char* libname = "time";

void _initlib() {}

sealobj* _time(sealobj** args, size_t arg_size)
{
  seal_check_args(libname, "time", NULL, 0, args, arg_size);
  sealobj* res = create_sealobj(SEAL_INT);
  res->integer.val = time(NULL);
  return res;
}

sealobj* _date(sealobj** args, size_t arg_size)
{
  seal_check_args(libname, "date", (seal_type[]) {SEAL_INT}, 1, args, arg_size);
  sealobj* res = create_sealobj(SEAL_STRING);
  char* date = ctime((time_t*)&args[0]->integer.val);
  res->string.val = calloc(strlen(date) + 1, sizeof(char));
  strncpy(res->string.val, date, strlen(date) - 1);
  return res;
}
