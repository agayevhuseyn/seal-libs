#include "../src/libdef.h"
#include <raylib.h>

// libname
static const char* libname = "raylib";

// global constant field names
static const char* vec2_mnames[] = {"x", "y"};

// singleton
void _initlib()
{
  create_const_seal_objects();
}

sealobj* _color(sealobj** args, size_t arg_size)
{
  static const char* color_mnames[] =   {"r", "g", "b", "a"};

  seal_type expected_types[] = { SEAL_INT, SEAL_INT, SEAL_INT, SEAL_INT };
  seal_check_args(libname, "color", expected_types, 4, args, arg_size);
  return seal_create_object(color_mnames, args, arg_size);
}

sealobj* _vec2(sealobj** args, size_t arg_size)
{
  seal_type expected_types[] = { SEAL_NUMBER, SEAL_NUMBER };
  seal_check_args(libname, "vec2", expected_types, 2, args, arg_size);
  return seal_create_object(vec2_mnames, args, arg_size);
}

sealobj* _load_texture(sealobj** args, size_t arg_size)
{
  static const char* texture_mnames[] = {"id",
                                         "width",
                                         "height",
                                         "mipmaps",
                                         "format"};

  seal_type expected_types[] = { SEAL_STRING };
  seal_check_args(libname, "load_texture", expected_types, 1, args, arg_size);


  Texture2D tex = LoadTexture(args[0]->string.val);
  if (tex.id == 0) {
    printf("FAILED TO LOAD TEXTURE: %s\n", args[0]->string.val);
    exit(1);
  }

  size_t field_size = 5;
  sealobj* field_vals[field_size];
  for (int i = 0; i < field_size; i++) {
    field_vals[i] = create_sealobj(SEAL_INT);
  }

  field_vals[0]->integer.val = tex.id;
  field_vals[1]->integer.val = tex.width;
  field_vals[2]->integer.val = tex.height;
  field_vals[3]->integer.val = tex.mipmaps;
  field_vals[4]->integer.val = tex.format;

  return seal_create_object(texture_mnames, field_vals, field_size);
}

sealobj* _init_window(sealobj** args, size_t arg_size)
{
  SetTraceLogLevel(LOG_ERROR);
  seal_type expected_types[] = { SEAL_INT, SEAL_INT, SEAL_STRING };
  seal_check_args(libname, "init_window", expected_types, 3, args, arg_size);
  InitWindow(args[0]->integer.val, args[1]->integer.val, args[2]->string.val);
  return seal_null();
}

sealobj* _window_should_close(sealobj** args, size_t arg_size)
{
  seal_check_args(libname, "window_should_close", NULL, 0, args, arg_size);
  return WindowShouldClose() ? seal_true() : seal_false();
}

sealobj* _clear_background(sealobj** args, size_t arg_size)
{
  static const char* func_name = "clear_background";
  seal_type expected_types[] = { SEAL_OBJECT };
  seal_check_args(libname, func_name, expected_types, sizeof(expected_types) / sizeof(expected_types[0]), args, arg_size);
  ClearBackground((Color){ seal_get_obj_mem(args[0], "r", SEAL_INT, libname, func_name)->integer.val,
                           seal_get_obj_mem(args[0], "g", SEAL_INT, libname, func_name)->integer.val,
                           seal_get_obj_mem(args[0], "b", SEAL_INT, libname, func_name)->integer.val,
                           seal_get_obj_mem(args[0], "a", SEAL_INT, libname, func_name)->integer.val }
                 );

  return seal_null();
}

sealobj* _begin_drawing(sealobj** args, size_t arg_size)
{
  seal_check_args(libname, "begin_drawing", NULL, 0, args, arg_size);
  BeginDrawing();
  return seal_null();
}

sealobj* _end_drawing(sealobj** args, size_t arg_size)
{
  seal_check_args(libname, "end_drawing", NULL, 0, args, arg_size);
  EndDrawing();
  return seal_null();
}

sealobj* _close_window(sealobj** args, size_t arg_size)
{
  seal_check_args(libname, "close_drawing", NULL, 0, args, arg_size);
  CloseWindow();
  return seal_null();
}

sealobj* _set_fps(sealobj** args, size_t arg_size)
{
  seal_type expected_types[] = { SEAL_INT };
  seal_check_args(libname, "set_fps", expected_types, 1, args, arg_size);
  SetTargetFPS(args[0]->integer.val);
  return seal_null();
}

sealobj* _get_fps(sealobj** args, size_t arg_size)
{
  seal_check_args(libname, "get_fps", NULL, 0, args, arg_size);
  sealobj* sobj = create_sealobj(SEAL_INT);
  sobj->integer.val = GetFPS();
  return sobj;
}

sealobj* _delta_time(sealobj** args, size_t arg_size)
{
  seal_check_args(libname, "delta_time", NULL, 0, args, arg_size);
  sealobj* sobj = create_sealobj(SEAL_FLOAT);
  sobj->floating.val = GetFrameTime();
  return sobj;
}

sealobj* _draw_line(sealobj** args, size_t arg_size)
{
  static const char* func_name = "draw_line";
  seal_type expected_types[] = { SEAL_NUMBER, SEAL_NUMBER, SEAL_NUMBER, SEAL_NUMBER, SEAL_OBJECT};
  seal_check_args(libname, func_name, expected_types, 5, args, arg_size);
  DrawLine(args[0]->type == SEAL_INT ? args[0]->integer.val : args[0]->floating.val,
           args[1]->type == SEAL_INT ? args[1]->integer.val : args[1]->floating.val,
           args[2]->type == SEAL_INT ? args[2]->integer.val : args[2]->floating.val,
           args[3]->type == SEAL_INT ? args[3]->integer.val : args[3]->floating.val,
           (Color){ seal_get_obj_mem(args[4], "r", SEAL_INT, libname, func_name)->integer.val,
                    seal_get_obj_mem(args[4], "g", SEAL_INT, libname, func_name)->integer.val,
                    seal_get_obj_mem(args[4], "b", SEAL_INT, libname, func_name)->integer.val,
                    seal_get_obj_mem(args[4], "a", SEAL_INT, libname, func_name)->integer.val }
          );
  return seal_null();
}

sealobj* _draw_line_ex(sealobj** args, size_t arg_size)
{
  static const char* func_name = "draw_line_ex";
  seal_type expected_types[] = { SEAL_OBJECT, SEAL_OBJECT, SEAL_NUMBER, SEAL_OBJECT};
  seal_check_args(libname, func_name, expected_types, sizeof(expected_types) / sizeof(expected_types[0]), args, arg_size);
  sealobj* start_x = seal_get_obj_mem(args[0], "x", SEAL_NUMBER, libname, func_name),
         * start_y = seal_get_obj_mem(args[0], "y", SEAL_NUMBER, libname, func_name),
         * end_x   = seal_get_obj_mem(args[1], "x", SEAL_NUMBER, libname, func_name),
         * end_y   = seal_get_obj_mem(args[1], "y", SEAL_NUMBER, libname, func_name);
  DrawLineEx(// start pos vec2
             (Vector2) { .x = IS_SEAL_INT(start_x) ? start_x->integer.val : start_x->floating.val,
                         .y = IS_SEAL_INT(start_y) ? start_y->integer.val : start_y->floating.val },
             // end pos vec2
             (Vector2) { .x = IS_SEAL_INT(end_x) ? end_x->integer.val : end_x->floating.val,
                         .y = IS_SEAL_INT(end_y) ? end_y->integer.val : end_y->floating.val },
             // thickness
             IS_SEAL_INT(args[2]) ? args[2]->integer.val : args[2]->floating.val,
             // color
             (Color){ seal_get_obj_mem(args[3], "r", SEAL_INT, libname, func_name)->integer.val,
                      seal_get_obj_mem(args[3], "g", SEAL_INT, libname, func_name)->integer.val,
                      seal_get_obj_mem(args[3], "b", SEAL_INT, libname, func_name)->integer.val,
                      seal_get_obj_mem(args[3], "a", SEAL_INT, libname, func_name)->integer.val }
            );
  return seal_null();
}

sealobj* _draw_rectangle(sealobj** args, size_t arg_size)
{
  static const char* func_name = "draw_rectangle";
  seal_type expected_types[] = { SEAL_NUMBER, SEAL_NUMBER, SEAL_NUMBER, SEAL_NUMBER, SEAL_OBJECT};
  seal_check_args(libname, "draw_rectangle", expected_types, 5, args, arg_size);
  DrawRectangle(IS_SEAL_INT(args[0]) ? args[0]->integer.val : args[0]->floating.val,
                IS_SEAL_INT(args[1]) ? args[1]->integer.val : args[1]->floating.val,
                IS_SEAL_INT(args[2]) ? args[2]->integer.val : args[2]->floating.val,
                IS_SEAL_INT(args[3]) ? args[3]->integer.val : args[3]->floating.val,
                (Color){ seal_get_obj_mem(args[4], "r", SEAL_INT, libname, func_name)->integer.val,
                         seal_get_obj_mem(args[4], "g", SEAL_INT, libname, func_name)->integer.val,
                         seal_get_obj_mem(args[4], "b", SEAL_INT, libname, func_name)->integer.val,
                         seal_get_obj_mem(args[4], "a", SEAL_INT, libname, func_name)->integer.val }
               );
  return seal_null();
}

sealobj* _draw_circle(sealobj** args, size_t arg_size)
{
  static const char* func_name = "draw_circle";
  seal_type expected_types[] = { SEAL_NUMBER, SEAL_NUMBER, SEAL_NUMBER, SEAL_OBJECT};
  seal_check_args(libname, func_name, expected_types, sizeof(expected_types) / sizeof(expected_types[0]), args, arg_size);
  DrawCircle(IS_SEAL_INT(args[0]) ? args[0]->integer.val : args[0]->floating.val,
             IS_SEAL_INT(args[1]) ? args[1]->integer.val : args[1]->floating.val,
             IS_SEAL_INT(args[2]) ? args[2]->integer.val : args[2]->floating.val,
             (Color){ seal_get_obj_mem(args[3], "r", SEAL_INT, libname, func_name)->integer.val,
                      seal_get_obj_mem(args[3], "g", SEAL_INT, libname, func_name)->integer.val,
                      seal_get_obj_mem(args[3], "b", SEAL_INT, libname, func_name)->integer.val,
                      seal_get_obj_mem(args[3], "a", SEAL_INT, libname, func_name)->integer.val }
            );
  return seal_null();
}

sealobj* _draw_texture(sealobj** args, size_t arg_size)
{
  static const char* func_name = "draw_texture";

  seal_type expected_types[] = { SEAL_OBJECT, SEAL_NUMBER, SEAL_NUMBER, SEAL_OBJECT};
  seal_check_args(libname, func_name, expected_types, 4, args, arg_size);
  DrawTexture((Texture2D) { seal_get_obj_mem(args[0], "id", SEAL_INT, libname, func_name)->integer.val,
                            seal_get_obj_mem(args[0], "width", SEAL_INT, libname, func_name)->integer.val,
                            seal_get_obj_mem(args[0], "height", SEAL_INT, libname, func_name)->integer.val,
                            seal_get_obj_mem(args[0], "mipmaps", SEAL_INT, libname, func_name)->integer.val,
                            seal_get_obj_mem(args[0], "format", SEAL_INT, libname, func_name)->integer.val},
              IS_SEAL_INT(args[1]) ? args[1]->integer.val : args[1]->floating.val,
              IS_SEAL_INT(args[2]) ? args[2]->integer.val : args[2]->floating.val,
              (Color){ seal_get_obj_mem(args[3], "r", SEAL_INT, libname, func_name)->integer.val,
                       seal_get_obj_mem(args[3], "g", SEAL_INT, libname, func_name)->integer.val,
                       seal_get_obj_mem(args[3], "b", SEAL_INT, libname, func_name)->integer.val,
                       seal_get_obj_mem(args[3], "a", SEAL_INT, libname, func_name)->integer.val }
             );
  return seal_null();
}

sealobj* _draw_texture_v(sealobj** args, size_t arg_size)
{
  static const char* func_name = "draw_texture_v";

  seal_type expected_types[] = { SEAL_OBJECT, SEAL_OBJECT, SEAL_OBJECT};
  seal_check_args(libname, func_name, expected_types, 3, args, arg_size);
  
  sealobj* x = seal_get_obj_mem(args[1], "x", SEAL_NUMBER, libname, func_name),
         * y = seal_get_obj_mem(args[1], "y", SEAL_NUMBER, libname, func_name);

  DrawTextureV((Texture2D) { seal_get_obj_mem(args[0], "id", SEAL_INT, libname, func_name)->integer.val,
                            seal_get_obj_mem(args[0], "width", SEAL_INT, libname, func_name)->integer.val,
                            seal_get_obj_mem(args[0], "height", SEAL_INT, libname, func_name)->integer.val,
                            seal_get_obj_mem(args[0], "mipmaps", SEAL_INT, libname, func_name)->integer.val,
                            seal_get_obj_mem(args[0], "format", SEAL_INT, libname, func_name)->integer.val},
               (Vector2) { IS_SEAL_INT(x) ? x->integer.val : x->floating.val,
                           IS_SEAL_INT(y) ? y->integer.val : y->floating.val, },
               (Color){ seal_get_obj_mem(args[2], "r", SEAL_INT, libname, func_name)->integer.val,
                        seal_get_obj_mem(args[2], "g", SEAL_INT, libname, func_name)->integer.val,
                        seal_get_obj_mem(args[2], "b", SEAL_INT, libname, func_name)->integer.val,
                        seal_get_obj_mem(args[2], "a", SEAL_INT, libname, func_name)->integer.val }
              );
  return seal_null();
}

sealobj* _draw_texture_ex(sealobj** args, size_t arg_size)
{
  static const char* func_name = "draw_texture_ex";

  seal_type expected_types[] = { SEAL_OBJECT, SEAL_OBJECT, SEAL_NUMBER, SEAL_NUMBER, SEAL_OBJECT};
  seal_check_args(libname, func_name, expected_types, 5, args, arg_size);
  
  sealobj* x = seal_get_obj_mem(args[1], "x", SEAL_NUMBER, libname, func_name),
         * y = seal_get_obj_mem(args[1], "y", SEAL_NUMBER, libname, func_name);

  DrawTextureEx((Texture2D) { seal_get_obj_mem(args[0], "id", SEAL_INT, libname, func_name)->integer.val,
                              seal_get_obj_mem(args[0], "width", SEAL_INT, libname, func_name)->integer.val,
                              seal_get_obj_mem(args[0], "height", SEAL_INT, libname, func_name)->integer.val,
                              seal_get_obj_mem(args[0], "mipmaps", SEAL_INT, libname, func_name)->integer.val,
                              seal_get_obj_mem(args[0], "format", SEAL_INT, libname, func_name)->integer.val},
                (Vector2) { IS_SEAL_INT(x) ? x->integer.val : x->floating.val,
                            IS_SEAL_INT(y) ? y->integer.val : y->floating.val, },
                IS_SEAL_INT(args[2]) ? args[2]->integer.val : args[2]->floating.val,
                IS_SEAL_INT(args[3]) ? args[3]->integer.val : args[3]->floating.val,
                (Color){ seal_get_obj_mem(args[4], "r", SEAL_INT, libname, func_name)->integer.val,
                         seal_get_obj_mem(args[4], "g", SEAL_INT, libname, func_name)->integer.val,
                         seal_get_obj_mem(args[4], "b", SEAL_INT, libname, func_name)->integer.val,
                         seal_get_obj_mem(args[4], "a", SEAL_INT, libname, func_name)->integer.val }
               );
  return seal_null();
}

sealobj* _is_key_down(sealobj** args, size_t arg_size)
{
  seal_type expected_types[] = { SEAL_INT };
  seal_check_args(libname, "is_key_down", expected_types, 1, args, arg_size);
  return IsKeyDown(args[0]->integer.val) ? seal_true() : seal_false();
}

sealobj* _is_key_pressed(sealobj** args, size_t arg_size)
{
  seal_type expected_types[] = { SEAL_INT };
  seal_check_args(libname, "is_key_pressed", expected_types, 1, args, arg_size);
  return IsKeyPressed(args[0]->integer.val) ? seal_true() : seal_false();
}

sealobj* _is_key_pressed_repeat(sealobj** args, size_t arg_size)
{
  seal_type expected_types[] = { SEAL_INT };
  seal_check_args(libname, "is_key_pressed_repeat", expected_types, 1, args, arg_size);
  return IsKeyPressedRepeat(args[0]->integer.val) ? seal_true() : seal_false();
}

sealobj* _is_key_released(sealobj** args, size_t arg_size)
{
  seal_type expected_types[] = { SEAL_INT };
  seal_check_args(libname, "is_key_released", expected_types, 1, args, arg_size);
  return IsKeyReleased(args[0]->integer.val) ? seal_true() : seal_false();
}

sealobj* _is_key_up(sealobj** args, size_t arg_size)
{
  seal_type expected_types[] = { SEAL_INT };
  seal_check_args(libname, "is_key_up", expected_types, 1, args, arg_size);
  return IsKeyUp(args[0]->integer.val) ? seal_true() : seal_false();
}

sealobj* _set_exit_key(sealobj** args, size_t arg_size)
{
  seal_type expected_types[] = { SEAL_INT };
  seal_check_args(libname, "set_exit_key", expected_types, 1, args, arg_size);
  SetExitKey(args[0]->integer.val);
  return seal_null();
}

sealobj* _show_cursor(sealobj** args, size_t arg_size)
{
  seal_check_args(libname, "show_cursor", NULL, 0, args, arg_size);
  ShowCursor();
  return seal_null();
}

sealobj* _hide_cursor(sealobj** args, size_t arg_size)
{
  seal_check_args(libname, "hide_cursor", NULL, 0, args, arg_size);
  HideCursor();
  return seal_null();
}

sealobj* _is_cursor_hidden(sealobj** args, size_t arg_size)
{
  seal_check_args(libname, "is_cursor_hidden", NULL, 0, args, arg_size);
  return IsCursorHidden() ? seal_true() : seal_false();
}

sealobj* _enable_cursor(sealobj** args, size_t arg_size)
{
  seal_check_args(libname, "enable_cursor", NULL, 0, args, arg_size);
  EnableCursor();
  return seal_null();
}

sealobj* _disable_cursor(sealobj** args, size_t arg_size)
{
  seal_check_args(libname, "disable_cursor", NULL, 0, args, arg_size);
  DisableCursor();
  return seal_null();
}

sealobj* _is_cursor_on_screen(sealobj** args, size_t arg_size)
{
  seal_check_args(libname, "is_cursor_on_screen", NULL, 0, args, arg_size);
  return IsCursorOnScreen() ? seal_true() : seal_false();
}

sealobj* _is_mouse_down(sealobj** args, size_t arg_size)
{
  seal_type expected_types[] = { SEAL_INT };
  seal_check_args(libname, "is_mouse_down", expected_types, 1, args, arg_size);
  return IsMouseButtonDown(args[0]->integer.val) ? seal_true() : seal_false();
}

sealobj* _is_mouse_pressed(sealobj** args, size_t arg_size)
{
  seal_type expected_types[] = { SEAL_INT };
  seal_check_args(libname, "is_mouse_pressed", expected_types, 1, args, arg_size);
  return IsMouseButtonPressed(args[0]->integer.val) ? seal_true() : seal_false();
}

sealobj* _is_mouse_released(sealobj** args, size_t arg_size)
{
  seal_type expected_types[] = { SEAL_INT };
  seal_check_args(libname, "is_mouse_released", expected_types, 1, args, arg_size);
  return IsMouseButtonReleased(args[0]->integer.val) ? seal_true() : seal_false();
}

sealobj* _is_mouse_up(sealobj** args, size_t arg_size)
{
  seal_type expected_types[] = { SEAL_INT };
  seal_check_args(libname, "is_mouse_up", expected_types, 1, args, arg_size);
  return IsMouseButtonUp(args[0]->integer.val) ? seal_true() : seal_false();
}

sealobj* _mouse_x(sealobj** args, size_t arg_size)
{
  seal_check_args(libname, "mouse_x", NULL, 0, args, arg_size);
  sealobj* sobj = create_sealobj(SEAL_INT);
  sobj->integer.val = GetMouseX();
  return sobj;
}

sealobj* _mouse_y(sealobj** args, size_t arg_size)
{
  seal_check_args(libname, "mouse_y", NULL, 0, args, arg_size);
  sealobj* sobj = create_sealobj(SEAL_INT);
  sobj->integer.val = GetMouseY();
  return sobj;
}

sealobj* _mouse_pos(sealobj** args, size_t arg_size)
{
  seal_check_args(libname, "mouse_pos", NULL, 0, args, arg_size);

  Vector2 mouse_pos = GetMousePosition();

  sealobj* mem_x = create_sealobj(SEAL_INT); mem_x->integer.val = mouse_pos.x;
  sealobj* mem_y = create_sealobj(SEAL_INT); mem_y->integer.val = mouse_pos.y;

  sealobj* mems[2];
  mems[0] = mem_x;
  mems[1] = mem_y;

  return seal_create_object(vec2_mnames, mems, 2);
}

sealobj* _draw_text(sealobj** args, size_t arg_size)
{
  static const char* func_name = "draw_text";

  seal_type expected_types[] = { SEAL_STRING, SEAL_NUMBER, SEAL_NUMBER, SEAL_NUMBER, SEAL_OBJECT};
  seal_check_args(libname, func_name, expected_types, 5, args, arg_size);
  DrawText(args[0]->string.val,
           IS_SEAL_INT(args[1]) ? args[1]->integer.val : args[1]->floating.val,
           IS_SEAL_INT(args[2]) ? args[2]->integer.val : args[2]->floating.val,
           IS_SEAL_INT(args[3]) ? args[3]->integer.val : args[3]->floating.val,
           (Color){ seal_get_obj_mem(args[4], "r", SEAL_INT, libname, func_name)->integer.val,
                    seal_get_obj_mem(args[4], "g", SEAL_INT, libname, func_name)->integer.val,
                    seal_get_obj_mem(args[4], "b", SEAL_INT, libname, func_name)->integer.val,
                    seal_get_obj_mem(args[4], "a", SEAL_INT, libname, func_name)->integer.val }
          );
  return seal_null();
}

sealobj* _measure_text(sealobj** args, size_t arg_size)
{
  static const char* func_name = "measure_text";

  seal_type expected_types[] = { SEAL_STRING, SEAL_NUMBER };
  seal_check_args(libname, func_name, expected_types, 2, args, arg_size);
  sealobj* text_width = create_sealobj(SEAL_INT);
  text_width->integer.val =
    MeasureText(
      args[0]->string.val,
      IS_SEAL_INT(args[1]) ? args[1]->integer.val : args[1]->floating.val
    );
  return text_width;
}

sealobj* _load_font(sealobj** args, size_t arg_size)
{
  static const char* func_name = "load_font";

  seal_type expected_types[] = { SEAL_STRING, SEAL_INT };
  seal_check_args(libname, func_name, expected_types, 2, args, arg_size);

  Font font = LoadFontEx(args[0]->string.val, args[1]->integer.val, NULL, 0);
  if (font.baseSize == 0) return ast_null();

  Font* fontp = SEAL_CALLOC(1, sizeof(Font));

  fontp->recs = font.recs;
  fontp->glyphs= font.glyphs;
  fontp->texture = font.texture;
  fontp->baseSize = font.baseSize;
  fontp->glyphCount = font.glyphCount;
  fontp->glyphPadding = font.glyphPadding;

  sealobj* font_ptr = create_sealobj(SEAL_INT);
  font_ptr->integer.val = (Seal_int) fontp;
  return font_ptr;
}

sealobj* _draw_text_ex(sealobj** args, size_t arg_size)
{
  static const char* func_name = "draw_text_ex";

  seal_type expected_types[] = { SEAL_INT, SEAL_STRING, SEAL_OBJECT, SEAL_NUMBER, SEAL_NUMBER, SEAL_OBJECT};
  seal_check_args(libname, func_name, expected_types, 6, args, arg_size);
  //DrawTextEx(Font font, const char *text, Vector2 position, float fontSize, float spacing, Color tint);
  //
  sealobj* x = seal_get_obj_mem(args[2], "x", SEAL_NUMBER, libname, func_name),
         * y = seal_get_obj_mem(args[2], "y", SEAL_NUMBER, libname, func_name);

  DrawTextEx(*((Font*) args[0]->integer.val),
             args[1]->string.val,
             (Vector2) { IS_SEAL_INT(x) ? x->integer.val : x->floating.val,
                         IS_SEAL_INT(y) ? y->integer.val : y->floating.val },
             IS_SEAL_INT(args[3]) ? args[3]->integer.val : args[3]->floating.val,
             IS_SEAL_INT(args[4]) ? args[4]->integer.val : args[4]->floating.val,
             (Color){ seal_get_obj_mem(args[5], "r", SEAL_INT, libname, func_name)->integer.val,
                      seal_get_obj_mem(args[5], "g", SEAL_INT, libname, func_name)->integer.val,
                      seal_get_obj_mem(args[5], "b", SEAL_INT, libname, func_name)->integer.val,
                      seal_get_obj_mem(args[5], "a", SEAL_INT, libname, func_name)->integer.val }
            );
  return seal_null();
}

sealobj* _get_key_pressed(sealobj** args, size_t arg_size)
{
  static const char* func_name = "get_key_pressed";

  seal_check_args(libname, func_name, NULL, 0, args, arg_size);
  sealobj* key = create_sealobj(SEAL_INT);
  key->integer.val = GetKeyPressed();
  return key;
}

sealobj* _get_char_pressed(sealobj** args, size_t arg_size)
{
  static const char* func_name = "get_char_pressed";

  seal_check_args(libname, func_name, NULL, 0, args, arg_size);
  sealobj* key = create_sealobj(SEAL_INT);
  key->integer.val = GetCharPressed();
  return key;
}

sealobj* _set_config_flags(sealobj** args, size_t arg_size)
{
  static const char* func_name = "set_config_flags";

  seal_type expected_types[] = { SEAL_INT };
  seal_check_args(libname, func_name, expected_types, 1, args, arg_size);

  SetConfigFlags(args[0]->integer.val);

  return ast_null();
}

sealobj* _get_screen_width(sealobj** args, size_t arg_size)
{
  static const char* func_name = "get_screen_width";

  seal_check_args(libname, func_name, NULL, 0, args, arg_size);
  sealobj* width = create_sealobj(SEAL_INT);
  width->integer.val = GetScreenWidth();
  return width;
}

sealobj* _get_screen_height(sealobj** args, size_t arg_size)
{
  static const char* func_name = "get_screen_height";

  seal_check_args(libname, func_name, NULL, 0, args, arg_size);
  sealobj* height = create_sealobj(SEAL_INT);
  height->integer.val = GetScreenHeight();
  return height;
}

sealobj* _init_audio_device(sealobj** args, size_t arg_size)
{
  seal_check_args(libname, "init_audio_device", NULL, 0, args, arg_size);
  InitAudioDevice();
  return seal_null();
}

sealobj* _close_audio_device(sealobj** args, size_t arg_size)
{
  seal_check_args(libname, "close_audio_device", NULL, 0, args, arg_size);
  CloseAudioDevice();
  return seal_null();
}

sealobj* _is_audio_device_ready(sealobj** args, size_t arg_size)
{
  seal_check_args(libname, "is_audio_device_ready", NULL, 0, args, arg_size);
  return IsAudioDeviceReady() ? seal_true() : seal_false();
}

sealobj* _load_sound(sealobj** args, size_t arg_size)
{
  static const char* func_name = "load_sound";

  seal_type expected_types[] = { SEAL_STRING };
  seal_check_args(libname, func_name, expected_types, 1, args, arg_size);

  Sound sound = LoadSound(args[0]->string.val);
  if (sound.frameCount == 0) return ast_null();

  Sound* soundp = SEAL_CALLOC(1, sizeof(Sound));

  *soundp = sound;

  sealobj* sound_ptr = create_sealobj(SEAL_INT);
  sound_ptr->integer.val = (Seal_int) soundp;
  return sound_ptr;
}

sealobj* _play_sound(sealobj** args, size_t arg_size)
{
  static const char* func_name = "play_sound";

  seal_type expected_types[] = { SEAL_INT };
  seal_check_args(libname, func_name, expected_types, 1, args, arg_size);

  PlaySound(*(Sound*) args[0]->integer.val);

  return seal_null();
}

sealobj* _stop_sound(sealobj** args, size_t arg_size)
{
  static const char* func_name = "stop_sound";

  seal_type expected_types[] = { SEAL_INT };
  seal_check_args(libname, func_name, expected_types, 1, args, arg_size);

  StopSound(*(Sound*) args[0]->integer.val);

  return seal_null();
}

sealobj* _pause_sound(sealobj** args, size_t arg_size)
{
  static const char* func_name = "pause_sound";

  seal_type expected_types[] = { SEAL_INT };
  seal_check_args(libname, func_name, expected_types, 1, args, arg_size);

  PauseSound(*(Sound*) args[0]->integer.val);

  return seal_null();
}

sealobj* _resume_sound(sealobj** args, size_t arg_size)
{
  static const char* func_name = "resume_sound";

  seal_type expected_types[] = { SEAL_INT };
  seal_check_args(libname, func_name, expected_types, 1, args, arg_size);

  ResumeSound(*(Sound*) args[0]->integer.val);

  return seal_null();
}

sealobj* _is_sound_playing(sealobj** args, size_t arg_size)
{
  static const char* func_name = "is_sound_playing";

  seal_type expected_types[] = { SEAL_INT };
  seal_check_args(libname, func_name, expected_types, 1, args, arg_size);

  return IsSoundPlaying(*(Sound*) args[0]->integer.val) ? seal_true() : seal_false();
}
