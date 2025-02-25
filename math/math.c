#include "../src/libdef.h"
#include <math.h>

static const char* libname = "math";

void _initlib() {}

sealobj* _sin(sealobj** args, size_t arg_size)
{
  seal_check_args(libname, "sin", (seal_type[]){SEAL_NUMBER}, 1, args, arg_size);
  sealobj* res = create_ast(AST_FLOAT);
  sealobj* arg = args[0];
  res->floating.val = sin(IS_SEAL_INT(arg) ? arg->integer.val : arg->floating.val);
  return res;
}

sealobj* _cos(sealobj** args, size_t arg_size)
{
  seal_check_args(libname, "cos", (seal_type[]){SEAL_NUMBER}, 1, args, arg_size);
  sealobj* res = create_ast(AST_FLOAT);
  sealobj* arg = args[0];
  res->floating.val = cos(IS_SEAL_INT(arg) ? arg->integer.val : arg->floating.val);
  return res;
}

sealobj* _tan(sealobj** args, size_t arg_size)
{
  seal_check_args(libname, "tan", (seal_type[]){SEAL_NUMBER}, 1, args, arg_size);
  sealobj* res = create_ast(AST_FLOAT);
  sealobj* arg = args[0];
  res->floating.val = tan(IS_SEAL_INT(arg) ? arg->integer.val : arg->floating.val);
  return res;
}

sealobj* _sqrt(sealobj** args, size_t arg_size)
{
  seal_check_args(libname, "sqrt", (seal_type[]){SEAL_NUMBER}, 1, args, arg_size);
  sealobj* res = create_ast(AST_FLOAT);
  sealobj* arg = args[0];
  res->floating.val = sqrt(IS_SEAL_INT(arg) ? arg->integer.val : arg->floating.val);
  return res;
}

sealobj* _cbrt(sealobj** args, size_t arg_size)
{
  seal_check_args(libname, "cbrt", (seal_type[]){SEAL_NUMBER}, 1, args, arg_size);
  sealobj* res = create_ast(AST_FLOAT);
  sealobj* arg = args[0];
  res->floating.val = cbrt(IS_SEAL_INT(arg) ? arg->integer.val : arg->floating.val);
  return res;
}

sealobj* _atan2(sealobj** args, size_t arg_size)
{
  seal_check_args(libname, "atan2", (seal_type[]){SEAL_NUMBER, SEAL_NUMBER}, 2, args, arg_size);
  sealobj* res = create_ast(AST_FLOAT);
  res->floating.val = atan2(IS_SEAL_INT(args[0]) ? args[0]->integer.val : args[0]->floating.val,
                            IS_SEAL_INT(args[1]) ? args[1]->integer.val : args[1]->floating.val);
  return res;
}
