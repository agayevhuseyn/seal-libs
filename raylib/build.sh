#!/bin/bash

SEAL_DIR="../src/"
LIBNAME="raylib"
VER="-5.0"
RAYLIB_DIR="winraylib-src$VER"
gcc -fPIC -shared -o "$LIBNAME.so" "$LIBNAME.c" "$SEAL_DIR/libdef.c" "$SEAL_DIR/ast.c" ./libraylib.a -lm -I$SEAL_DIR
x86_64-w64-mingw32-gcc -shared -o "$LIBNAME.dll" "$LIBNAME.c" "$SEAL_DIR/libdef.c" "$SEAL_DIR/ast.c" -I$SEAL_DIR -lm -lraylib -lgdi32 -lwinmm -L $RAYLIB_DIR/lib -I $RAYLIB_DIR/include
