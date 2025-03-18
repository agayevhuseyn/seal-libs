#!/bin/bash

SEAL_DIR="../src/"
LIBNAME="time"
gcc -fPIC -shared -o "$LIBNAME.so" "$LIBNAME.c" "$SEAL_DIR/libdef.c" "$SEAL_DIR/ast.c" -I$SEAL_DIR
x86_64-w64-mingw32-gcc -shared -o "$LIBNAME.dll" "$LIBNAME.c" "$SEAL_DIR/libdef.c" "$SEAL_DIR/ast.c" -I$SEAL_DIR 
