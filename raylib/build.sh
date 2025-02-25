#!/bin/bash

SEAL_DIR="../src/"
LIBNAME="raylib"
RAYLIB_DIR="winraylib-src"
gcc -fPIC -shared -lm -o "$LIBNAME.so" "$LIBNAME.c" "$SEAL_DIR/libdef.c" "$SEAL_DIR/ast.c" ./libraylib.a -I$SEAL_DIR
x86_64-w64-mingw32-gcc -shared -lm -o "$LIBNAME.dll" "$LIBNAME.c" "$SEAL_DIR/libdef.c" "$SEAL_DIR/ast.c" -I$SEAL_DIR -lraylib -lgdi32 -lwinmm -L $RAYLIB_DIR/lib -I $RAYLIB_DIR/include
