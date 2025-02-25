#include "../src/libdef.h"
#include <raylib.h>

// libname
static const char* libname = "raylib";

// constant field names
static const char* color_mnames[] =   {"r", "g", "b", "a"};
static const char* vec2_mnames[] =    {"x", "y"};
static const char* texture_mnames[] = {"id",
                                       "width",
                                       "height",
                                       "mipmaps",
                                       "format"};

// singleton
static sealobj* keys;
void _initlib()
{
  create_const_asts();

  // keys
  keys = create_sealobj(SEAL_OBJECT);
  keys->ref_counter = 1;
  keys->object.is_lit = true;
  size_t key_field_size = 110;
  keys->object.field_size = key_field_size;
  keys->object.field_vals = SEAL_CALLOC(key_field_size, sizeof(sealobj*));
  for (int i = 0; i < key_field_size; i++) {
    keys->object.field_vals[i] = create_sealobj(SEAL_INT);
    keys->object.field_vals[i]->ref_counter = 1;
  }
  keys->object.field_names = SEAL_CALLOC(key_field_size, sizeof(char*));

  keys->object.field_names[0] = "KEY_NULL";
  keys->object.field_names[1] = "KEY_APOSTROPHE";
  keys->object.field_names[2] = "KEY_COMMA";
  keys->object.field_names[3] = "KEY_MINUS";
  keys->object.field_names[4] = "KEY_DOT";
  keys->object.field_names[5] = "KEY_SLASH";
  keys->object.field_names[6] = "KEY_ZERO";
  keys->object.field_names[7] = "KEY_ONE";
  keys->object.field_names[8] = "KEY_TWO";
  keys->object.field_names[9] = "KEY_THREE";
  keys->object.field_names[10] = "KEY_FOUR";
  keys->object.field_names[11] = "KEY_FIVE";
  keys->object.field_names[12] = "KEY_SIX";
  keys->object.field_names[13] = "KEY_SEVEN";
  keys->object.field_names[14] = "KEY_EIGHT";
  keys->object.field_names[15] = "KEY_NINE";
  keys->object.field_names[16] = "KEY_SEMICOLON";
  keys->object.field_names[17] = "KEY_EQUAL";


  keys->object.field_names[18] = "KEY_A";
  keys->object.field_names[19] = "KEY_B";
  keys->object.field_names[20] = "KEY_C";
  keys->object.field_names[21] = "KEY_D";
  keys->object.field_names[22] = "KEY_E";
  keys->object.field_names[23] = "KEY_F";
  keys->object.field_names[24] = "KEY_G";
  keys->object.field_names[25] = "KEY_H";
  keys->object.field_names[26] = "KEY_I";
  keys->object.field_names[27] = "KEY_J";
  keys->object.field_names[28] = "KEY_K";
  keys->object.field_names[29] = "KEY_L";
  keys->object.field_names[30] = "KEY_M";
  keys->object.field_names[31] = "KEY_N";
  keys->object.field_names[32] = "KEY_O";
  keys->object.field_names[33] = "KEY_P";
  keys->object.field_names[34] = "KEY_Q";
  keys->object.field_names[35] = "KEY_R";
  keys->object.field_names[36] = "KEY_S";
  keys->object.field_names[37] = "KEY_T";
  keys->object.field_names[38] = "KEY_U";
  keys->object.field_names[39] = "KEY_V";
  keys->object.field_names[40] = "KEY_W";
  keys->object.field_names[41] = "KEY_X";
  keys->object.field_names[42] = "KEY_Y";
  keys->object.field_names[43] = "KEY_Z";

  keys->object.field_names[44] = "KEY_LEFT_BRACKET";
  keys->object.field_names[45] = "KEY_BACKSLASH";
  keys->object.field_names[46] = "KEY_RIGHT_BRACKET";
  keys->object.field_names[47] = "KEY_GRAVE";

  // function keys
  keys->object.field_names[48] = "KEY_SPACE";
  keys->object.field_names[49] = "KEY_ESCAPE";
  keys->object.field_names[50] = "KEY_ENTER";
  keys->object.field_names[51] = "KEY_TAB";
  keys->object.field_names[52] = "KEY_BACKSPACE";
  keys->object.field_names[53] = "KEY_INSERT";
  keys->object.field_names[54] = "KEY_DELETE";
  keys->object.field_names[55] = "KEY_RIGHT";
  keys->object.field_names[56] = "KEY_LEFT";
  keys->object.field_names[57] = "KEY_DOWN";
  keys->object.field_names[58] = "KEY_UP";
  keys->object.field_names[59] = "KEY_PAGE_UP";
  keys->object.field_names[60] = "KEY_PAGE_DOWN";
  keys->object.field_names[61] = "KEY_HOME";
  keys->object.field_names[62] = "KEY_END";
  keys->object.field_names[63] = "KEY_CAPS_LOCK";
  keys->object.field_names[64] = "KEY_SCROLL_LOCK";
  keys->object.field_names[65] = "KEY_NUM_LOCK";
  keys->object.field_names[66] = "KEY_PRINT_SCREEN";
  keys->object.field_names[67] = "KEY_PAUSE";

  // F
  keys->object.field_names[68] = "KEY_F1";
  keys->object.field_names[69] = "KEY_F2";
  keys->object.field_names[70] = "KEY_F3";
  keys->object.field_names[71] = "KEY_F4";
  keys->object.field_names[72] = "KEY_F5";
  keys->object.field_names[73] = "KEY_F6";
  keys->object.field_names[74] = "KEY_F7";
  keys->object.field_names[75] = "KEY_F8";
  keys->object.field_names[76] = "KEY_F9";
  keys->object.field_names[77] = "KEY_F10";
  keys->object.field_names[78] = "KEY_F11";
  keys->object.field_names[79] = "KEY_F12";


  // control
  keys->object.field_names[80] = "KEY_LEFT_SHIFT";
  keys->object.field_names[81] = "KEY_LEFT_CONTROL";
  keys->object.field_names[82] = "KEY_LEFT_ALT";
  keys->object.field_names[83] = "KEY_LEFT_SUPER";
  keys->object.field_names[84] = "KEY_RIGHT_SHIFT";
  keys->object.field_names[85] = "KEY_RIGHT_CONTROL";
  keys->object.field_names[86] = "KEY_RIGHT_ALT";
  keys->object.field_names[87] = "KEY_RIGHT_SUPER";
  keys->object.field_names[88] = "KEY_KB_MENU";

  // keypad keys
  keys->object.field_names[89] = "KEY_KP_0";
  keys->object.field_names[90] = "KEY_KP_1";
  keys->object.field_names[91] = "KEY_KP_2";
  keys->object.field_names[92] = "KEY_KP_3";
  keys->object.field_names[93] = "KEY_KP_4";
  keys->object.field_names[94] = "KEY_KP_5";
  keys->object.field_names[95] = "KEY_KP_6";
  keys->object.field_names[96] = "KEY_KP_7";
  keys->object.field_names[97] = "KEY_KP_8";
  keys->object.field_names[98] = "KEY_KP_9";
  keys->object.field_names[99] = "KEY_KP_DECIMAL";
  keys->object.field_names[100] = "KEY_KP_DIVIDE";
  keys->object.field_names[101] = "KEY_KP_MULTIPLY";
  keys->object.field_names[102] = "KEY_KP_SUBTRACT";
  keys->object.field_names[103] = "KEY_KP_ADD";
  keys->object.field_names[104] = "KEY_KP_ENTER";
  keys->object.field_names[105] = "KEY_KP_EQUAL";

  // android
  keys->object.field_names[106] = "KEY_BACK";
  keys->object.field_names[107] = "KEY_MENU";
  keys->object.field_names[108] = "KEY_VOLUME_UP";
  keys->object.field_names[109] = "KEY_VOLUME_DOWN";
  //------------------

  keys->object.field_vals[0]->integer.val = 0; // = "KEY_NULL";
  keys->object.field_vals[1]->integer.val = 39; // = "KEY_APOSTROPHE";
  keys->object.field_vals[2]->integer.val = 44; // = "KEY_COMMA";
  keys->object.field_vals[3]->integer.val = 45; // = "KEY_MINUS";
  keys->object.field_vals[4]->integer.val = 46; // = "KEY_DOT";
  keys->object.field_vals[5]->integer.val = 47; // = "KEY_SLASH";
  keys->object.field_vals[6]->integer.val = 48; // = "KEY_ZERO";
  keys->object.field_vals[7]->integer.val = 49; //  = "KEY_ONE";
  keys->object.field_vals[8]->integer.val = 50; // = "KEY_TWO";
  keys->object.field_vals[9]->integer.val = 51; // = "KEY_THREE";
  keys->object.field_vals[10]->integer.val = 52; //  = "KEY_FOUR";
  keys->object.field_vals[11]->integer.val = 53; // = "KEY_FIVE";
  keys->object.field_vals[12]->integer.val = 54; // = "KEY_SIX";
  keys->object.field_vals[13]->integer.val = 55; // = "KEY_SEVEN";
  keys->object.field_vals[14]->integer.val = 56; // = "KEY_EIGHT";
  keys->object.field_vals[15]->integer.val = 57; // = "KEY_NINE";
  keys->object.field_vals[16]->integer.val = 59; // = "KEY_SEMICOLON";
  keys->object.field_vals[17]->integer.val = 61; // = "KEY_EQUAL";


  keys->object.field_vals[18]->integer.val = 65; // = "KEY_A";
  keys->object.field_vals[19]->integer.val = 66; // = "KEY_B";
  keys->object.field_vals[20]->integer.val = 67; // = "KEY_C";
  keys->object.field_vals[21]->integer.val = 68; // = "KEY_D";
  keys->object.field_vals[22]->integer.val = 69; // = "KEY_E";
  keys->object.field_vals[23]->integer.val = 70; // = "KEY_F";
  keys->object.field_vals[24]->integer.val = 71; // = "KEY_G";
  keys->object.field_vals[25]->integer.val = 72; // = "KEY_H";
  keys->object.field_vals[26]->integer.val = 73; // = "KEY_I";
  keys->object.field_vals[27]->integer.val = 74; // = "KEY_J";
  keys->object.field_vals[28]->integer.val = 75; // = "KEY_K";
  keys->object.field_vals[29]->integer.val = 76; // = "KEY_L";
  keys->object.field_vals[30]->integer.val = 77; // = "KEY_M";
  keys->object.field_vals[31]->integer.val = 78; // = "KEY_N";
  keys->object.field_vals[32]->integer.val = 79; // = "KEY_O";
  keys->object.field_vals[33]->integer.val = 80; // = "KEY_P";
  keys->object.field_vals[34]->integer.val = 81; // = "KEY_Q";
  keys->object.field_vals[35]->integer.val = 82; // = "KEY_R";
  keys->object.field_vals[36]->integer.val = 83; // = "KEY_S";
  keys->object.field_vals[37]->integer.val = 84; // = "KEY_T";
  keys->object.field_vals[38]->integer.val = 85; // = "KEY_U";
  keys->object.field_vals[39]->integer.val = 86; // = "KEY_V";
  keys->object.field_vals[40]->integer.val = 87; // = "KEY_W";
  keys->object.field_vals[41]->integer.val = 88; // = "KEY_X";
  keys->object.field_vals[42]->integer.val = 89; // = "KEY_Y";
  keys->object.field_vals[43]->integer.val = 90; // = "KEY_Z";

  keys->object.field_vals[44]->integer.val = 91; // = "KEY_LEFT_BRACKET";
  keys->object.field_vals[45]->integer.val = 92; // = "KEY_BACKSLASH";
  keys->object.field_vals[46]->integer.val = 93; // = "KEY_RIGHT_BRACKET";
  keys->object.field_vals[47]->integer.val = 96; // = "KEY_GRAVE";

  // function keys
  keys->object.field_vals[48]->integer.val = 32; // = "KEY_SPACE";
  keys->object.field_vals[49]->integer.val = 256; // = "KEY_ESCAPE";
  keys->object.field_vals[50]->integer.val = 257; // = "KEY_ENTER";
  keys->object.field_vals[51]->integer.val = 258; // = "KEY_TAB";
  keys->object.field_vals[52]->integer.val = 259; // = "KEY_BACKSPACE";
  keys->object.field_vals[53]->integer.val = 260; // = "KEY_INSERT";
  keys->object.field_vals[54]->integer.val = 261; // = "KEY_DELETE";
  keys->object.field_vals[55]->integer.val = 262; // = "KEY_RIGHT";
  keys->object.field_vals[56]->integer.val = 263; // = "KEY_LEFT";
  keys->object.field_vals[57]->integer.val = 264; // = "KEY_DOWN";
  keys->object.field_vals[58]->integer.val = 265; // = "KEY_UP";
  keys->object.field_vals[59]->integer.val = 266; // = "KEY_PAGE_UP";
  keys->object.field_vals[60]->integer.val = 267; // = "KEY_PAGE_DOWN";
  keys->object.field_vals[61]->integer.val = 268; // = "KEY_HOME";
  keys->object.field_vals[62]->integer.val = 269; // = "KEY_END";
  keys->object.field_vals[63]->integer.val = 280; // = "KEY_CAPS_LOCK";
  keys->object.field_vals[64]->integer.val = 281; // = "KEY_SCROLL_LOCK";
  keys->object.field_vals[65]->integer.val = 282; // = "KEY_NUM_LOCK";
  keys->object.field_vals[66]->integer.val = 283; // = "KEY_PRINT_SCREEN";
  keys->object.field_vals[67]->integer.val = 284; // = "KEY_PAUSE";

  // F
  keys->object.field_vals[68]->integer.val = 290; // = "KEY_F1";
  keys->object.field_vals[69]->integer.val = 291; // = "KEY_F2";
  keys->object.field_vals[70]->integer.val = 292; // = "KEY_F3";
  keys->object.field_vals[71]->integer.val = 293; // = "KEY_F4";
  keys->object.field_vals[72]->integer.val = 294; // = "KEY_F5";
  keys->object.field_vals[73]->integer.val = 295; // = "KEY_F6";
  keys->object.field_vals[74]->integer.val = 295; // = "KEY_F7";
  keys->object.field_vals[75]->integer.val = 296; // = "KEY_F8";
  keys->object.field_vals[76]->integer.val = 298; // = "KEY_F9";
  keys->object.field_vals[77]->integer.val = 299; // = "KEY_F10";
  keys->object.field_vals[78]->integer.val = 300; // = "KEY_F11";
  keys->object.field_vals[79]->integer.val = 301; // = "KEY_F12";


  // control
  keys->object.field_vals[80]->integer.val = 340; // = "KEY_LEFT_SHIFT";
  keys->object.field_vals[81]->integer.val = 341; // = "KEY_LEFT_CONTROL";
  keys->object.field_vals[82]->integer.val = 342; // = "KEY_LEFT_ALT";
  keys->object.field_vals[83]->integer.val = 343; // = "KEY_LEFT_SUPER";
  keys->object.field_vals[84]->integer.val = 344; // = "KEY_RIGHT_SHIFT";
  keys->object.field_vals[85]->integer.val = 345; // = "KEY_RIGHT_CONTROL";
  keys->object.field_vals[86]->integer.val = 346; // = "KEY_RIGHT_ALT";
  keys->object.field_vals[87]->integer.val = 347; // = "KEY_RIGHT_SUPER";
  keys->object.field_vals[88]->integer.val = 348; // = "KEY_KB_MENU";

  // keypad keys
  keys->object.field_vals[89]->integer.val = 320; // = "KEY_KP_0";
  keys->object.field_vals[90]->integer.val = 321; // = "KEY_KP_1";
  keys->object.field_vals[91]->integer.val = 322; // = "KEY_KP_2";
  keys->object.field_vals[92]->integer.val = 323; // = "KEY_KP_3";
  keys->object.field_vals[93]->integer.val = 324; // = "KEY_KP_4";
  keys->object.field_vals[94]->integer.val = 325; // = "KEY_KP_5";
  keys->object.field_vals[95]->integer.val = 326; // = "KEY_KP_6";
  keys->object.field_vals[96]->integer.val = 327; // = "KEY_KP_7";
  keys->object.field_vals[97]->integer.val = 328; // = "KEY_KP_8";
  keys->object.field_vals[98]->integer.val = 329; // = "KEY_KP_9";
  keys->object.field_vals[99]->integer.val = 330; // = "KEY_KP_DECIMAL";
  keys->object.field_vals[100]->integer.val = 331; // = "KEY_KP_DIVIDE";
  keys->object.field_vals[101]->integer.val = 332; // = "KEY_KP_MULTIPLY";
  keys->object.field_vals[102]->integer.val = 333; // = "KEY_KP_SUBTRACT";
  keys->object.field_vals[103]->integer.val = 334; // = "KEY_KP_ADD";
  keys->object.field_vals[104]->integer.val = 335; // = "KEY_KP_ENTER";
  keys->object.field_vals[105]->integer.val = 336; // = "KEY_KP_EQUAL";

  // android
  keys->object.field_vals[106]->integer.val = 4; // = "KEY_BACK";
  keys->object.field_vals[107]->integer.val = 82; // = "KEY_MENU";
  keys->object.field_vals[108]->integer.val = 24; // = "KEY_VOLUME_UP";
  keys->object.field_vals[109]->integer.val = 25; // = "KEY_VOLUME_DOWN";
}

sealobj* _color(sealobj** args, size_t arg_size)
{
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

sealobj* _keys(sealobj** args, size_t arg_size)
{
  seal_check_args(libname, "keys", NULL, 0, args, arg_size);
  return keys;
}

sealobj* _load_texture(sealobj** args, size_t arg_size)
{
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
  sealobj* sobj = create_sealobj(AST_FLOAT);
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
  static const char* func_name = "draw_line";
  seal_type expected_types[] = { SEAL_OBJECT, SEAL_OBJECT, SEAL_NUMBER, SEAL_OBJECT};
  seal_check_args(libname, func_name, expected_types, sizeof(expected_types) / sizeof(expected_types[0]), args, arg_size);
  sealobj* start_x = seal_get_obj_mem(args[0], "x", SEAL_NUMBER, libname, func_name),
          *start_y = seal_get_obj_mem(args[0], "y", SEAL_NUMBER, libname, func_name),
          *end_x   = seal_get_obj_mem(args[1], "x", SEAL_NUMBER, libname, func_name),
          *end_y   = seal_get_obj_mem(args[1], "y", SEAL_NUMBER, libname, func_name);
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
  return ast_null();
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
