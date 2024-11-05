#include <assert.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdio.h>

#include "clingo/clingo.h"
#include "cmdscreen/term.h"
#include "cmdscreen/csScreen.h"
#include "termbox.h"

struct Key {
    unsigned char x;
    unsigned char y;
    char const* str;
};
typedef struct Key Key;

SLICES_C_(
   Key,
   Keys,
   varKeys
)

#define keys_( ... ) slice_c_( Key, __VA_ARGS__ )

Key K_ESC = {1,1,"ESC"};
Key K_F1 = {6,1,"F1"};
Key K_F2 = {9,1,"F2"};
Key K_F3 = {12,1,"F3"};
Key K_F4 = {15,1,"F4"};
Key K_F5 = {19,1,"F5"};
Key K_F6 = {22,1,"F6"};
Key K_F7 = {25,1,"F7"};
Key K_F8 = {28,1,"F8"};
Key K_F9 = {33,1,"F9"};
Key K_F10 = {36,1,"F10"};
Key K_F11 = {40,1,"F11"};
Key K_F12 = {44,1,"F12"};
Key K_PRN = {50,1,"PRN"};
Key K_SCR = {54,1,"SCR"};
Key K_BRK = {58,1,"BRK"};
Key K_LED1 = {66,1,"-"};
Key K_LED2 = {70,1,"-"};
Key K_LED3 = {74,1,"-"};

Key K_TILDE = {1,4,"`"};
Key K_TILDE_SHIFT = {1,4,"~"};
Key K_1 = {4,4,"1"};
Key K_1_SHIFT = {4,4,"!"};
Key K_2 = {7,4,"2"};
Key K_2_SHIFT = {7,4,"@"};
Key K_3 = {10,4,"3"};
Key K_3_SHIFT = {10,4,"#"};
Key K_4 = {13,4,"4"};
Key K_4_SHIFT = {13,4,"$"};
Key K_5 = {16,4,"5"};
Key K_5_SHIFT = {16,4,"%"};
Key K_6 = {19,4,"6"};
Key K_6_SHIFT = {19,4,"^"};
Key K_7 = {22,4,"7"};
Key K_7_SHIFT = {22,4,"&"};
Key K_8 = {25,4,"8"};
Key K_8_SHIFT = {25,4,"*"};
Key K_9 = {28,4,"9"};
Key K_9_SHIFT = {28,4,"("};
Key K_0 = {31,4,"0"};
Key K_0_SHIFT = {31,4,")"};
Key K_MINUS = {34,4,"-"};
Key K_MINUS_SHIFT = {34,4,"_"};
Key K_EQUALS = {37,4,"="};
Key K_EQUALS_SHIFT = {37,4,"+"};
Key K_BACKSLASH = {40,4,"\\"};
Key K_BACKSLASH_SHIFT = {40,4,"|"};
Key K_BACKSPACE = {44,4,"←──"};
Key K_INS = {50,4,"INS"};
Key K_HOM = {54,4,"HOM"};
Key K_PGU = {58,4,"PGU"};
Key K_K_NUMLOCK = {65,4,"N"};
Key K_K_SLASH = {68,4,"/"};
Key K_K_STAR = {71,4,"*"};
Key K_K_MINUS = {74,4,"-"};

Key K_TAB = {1,6,"TAB"};
Key K_q = {6,6,"q"};
Key K_Q = {6,6,"Q"};
Key K_w = {9,6,"w"};
Key K_W = {9,6,"W"};
Key K_e = {12,6,"e"};
Key K_E = {12,6,"E"};
Key K_r = {15,6,"r"};
Key K_R = {15,6,"R"};
Key K_t = {18,6,"t"};
Key K_T = {18,6,"T"};
Key K_y = {21,6,"y"};
Key K_Y = {21,6,"Y"};
Key K_u = {24,6,"u"};
Key K_U = {24,6,"U"};
Key K_i = {27,6,"i"};
Key K_I = {27,6,"I"};
Key K_o = {30,6,"o"};
Key K_O = {30,6,"O"};
Key K_p = {33,6,"p"};
Key K_P = {33,6,"P"};
Key K_LSQB = {36,6,"["};
Key K_LCUB = {36,6,"{"};
Key K_RSQB = {39,6,"]"};
Key K_RCUB = {39,6,"}"};
Key K_ENTER = {41,8,"░░↵░"};
Key K_DEL = {50,6,"DEL"};
Key K_END = {54,6,"END"};
Key K_PGD = {58,6,"PGD"};
Key K_K_7 = {65,6,"7"};
Key K_K_8 = {68,6,"8"};
Key K_K_9 = {71,6,"9"};
Key K_K_PLUS = {74,7,"+"};

Key K_CAPS = {1,8,"CAPS"};
Key K_a = {7,8,"a"};
Key K_A = {7,8,"A"};
Key K_s = {10,8,"s"};
Key K_S = {10,8,"S"};
Key K_d = {13,8,"d"};
Key K_D = {13,8,"D"};
Key K_f = {16,8,"f"};
Key K_F = {16,8,"F"};
Key K_g = {19,8,"g"};
Key K_G = {19,8,"G"};
Key K_h = {22,8,"h"};
Key K_H = {22,8,"H"};
Key K_j = {25,8,"j"};
Key K_J = {25,8,"J"};
Key K_k = {28,8,"k"};
Key K_K = {28,8,"K"};
Key K_l = {31,8,"l"};
Key K_L = {31,8,"L"};
Key K_SEMICOLON = {34,8,";"};
Key K_PARENTHESIS = {34,8,":"};
Key K_QUOTE = {37,8,"\'"};
Key K_DOUBLEQUOTE = {37,8,"\""};
Key K_K_4 = {65,8,"4"};
Key K_K_5 = {68,8,"5"};
Key K_K_6 = {71,8,"6"};

Key K_LSHIFT = {1,10,"SHIFT"};
Key K_z = {9,10,"z"};
Key K_Z = {9,10,"Z"};
Key K_x = {12,10,"x"};
Key K_X = {12,10,"X"};
Key K_c = {15,10,"c"};
Key K_C = {15,10,"C"};
Key K_v = {18,10,"v"};
Key K_V = {18,10,"V"};
Key K_b = {21,10,"b"};
Key K_B = {21,10,"B"};
Key K_n = {24,10,"n"};
Key K_N = {24,10,"N"};
Key K_m = {27,10,"m"};
Key K_M = {27,10,"M"};
Key K_COMMA = {30,10,","};
Key K_LANB = {30,10,"<"};
Key K_PERIOD = {33,10,"."};
Key K_RANB = {33,10,">"};
Key K_SLASH = {36,10,"/"};
Key K_QUESTION = {36,10,"?"};
Key K_RSHIFT = {42,10,"SHIFT"};
Key K_ARROW_UP = {54,10,"(↑)"};
Key K_K_1 = {65,10,"1"};
Key K_K_2 = {68,10,"2"};
Key K_K_3 = {71,10,"3"};
Key K_K_ENTER = {74,11,"░"};

Key K_LCTRL = {1,12,"CTRL"};
Key K_LWIN = {6,12,"WIN"};
Key K_LALT = {10,12,"ALT"};
Key K_SPACE = {14,12,"     SPACE     "};
Key K_RALT = {30,12,"ALT"};
Key K_RWIN = {34,12,"WIN"};
Key K_RPROP = {38,12,"PROP"};
Key K_RCTRL = {43,12,"CTRL"};
Key K_ARROW_LEFT = {50,12,"(←)"};
Key K_ARROW_DOWN = {54,12,"(↓)"};
Key K_ARROW_RIGHT = {58,12,"(→)"};
Key K_K_0 = {65,12," 0  "};
Key K_K_PERIOD = {71,12,"."};

csStyle cyanStyle( void )
{  return base_style_cs( rgb24_c_( 0, 255, 255 ), rgb24_c_( 0, 0, 0 ) );
}
csStyle greenStyle( void )
{  return base_style_cs( rgb24_c_( 0, 255, 0 ), rgb24_c_( 0, 0, 0 ) );
}
csStyle magentaStyle( void )
{  return base_style_cs( rgb24_c_( 255, 0, 255 ), rgb24_c_( 0, 0, 0 ) );
}
csStyle redStyle( void )
{  return base_style_cs( rgb24_c_( 255, 0, 0 ), rgb24_c_( 0, 0, 0 ) );
}
csStyle whiteStyle( void )
{  return base_style_cs( rgb24_c_( 255, 255, 255 ), rgb24_c_( 0, 0, 0 ) );
}
csStyle yellowStyle( void )
{  return base_style_cs( rgb24_c_( 255, 255, 0 ), rgb24_c_( 0, 0, 0 ) );
}

void printf_tb(int x, int y, csStyle style, const char *fmt, ...)
{
    char buf[4096];
    va_list vl;
    va_start(vl, fmt);
    vsnprintf(buf, sizeof(buf), fmt, vl);
    va_end(vl);
    set_htext_cs( point_ui( x, y ), c_c( buf ), style );
}

void draw_key(Key k, csStyle style )
{
   uiPoint cord = point_ui( k.x+2, k.y+4 );
   set_htext_cs( cord, c_c( k.str ), style );
}

void draw_keyboard(void)
{
   int i;
   set_cell_cs( point_ui( 0, 0 ), rune_c( "┌" ), whiteStyle() );
   set_cell_cs( point_ui( 79, 0 ), rune_c( "┐" ), whiteStyle() );
   set_cell_cs( point_ui( 0, 23 ), rune_c( "└" ), whiteStyle() );
   set_cell_cs( point_ui( 79, 23 ), rune_c( "┘" ), whiteStyle() );

    for (i = 1; i < 79; ++i) {
      set_cell_cs( point_ui( i, 0 ), rune_c( "─" ), whiteStyle() );
      set_cell_cs( point_ui( i, 23 ), rune_c( "─" ), whiteStyle() );
      set_cell_cs( point_ui( i, 17 ), rune_c( "─" ), whiteStyle() );
      set_cell_cs( point_ui( i, 4 ), rune_c( "─" ), whiteStyle() );
    }
    for (i = 1; i < 23; ++i) {
      set_cell_cs( point_ui( 0, i ), rune_c( "│" ), whiteStyle() );
      set_cell_cs( point_ui( 79, i ), rune_c( "│" ), whiteStyle() );
    }
    set_cell_cs( point_ui( 0, 17 ), rune_c( "├" ), whiteStyle() );
    set_cell_cs( point_ui( 79, 17 ), rune_c( "┤" ), whiteStyle() );
    set_cell_cs( point_ui( 0, 4 ), rune_c( "├" ), whiteStyle() );
    set_cell_cs( point_ui( 79, 4 ), rune_c( "┤" ), whiteStyle() );

    for (i = 5; i < 17; ++i) {
      set_cell_cs( point_ui( 1, i ), rune_c( "█" ), yellowStyle() );
      set_cell_cs( point_ui( 78, i ), rune_c( "█" ), yellowStyle() );
    }

   csStyle keyStyle = base_style_cs( rgb24_c_( 255, 255, 255 ), rgb24_c_( 0, 0, 255 ) );

   Keys keys = keys_(
      K_ESC,
      K_F1, K_F2, K_F3, K_F4, K_F5, K_F6, K_F7, K_F8, K_F9, K_F10, K_F11, K_F12,
      K_PRN, K_SCR, K_BRK, K_LED1, K_LED2, K_LED3,

      K_TILDE, K_1, K_2, K_3, K_4, K_5, K_6, K_7, K_8, K_9, K_0,
      K_MINUS, K_EQUALS, K_BACKSLASH, K_BACKSPACE,
      K_INS, K_HOM, K_PGU, K_K_NUMLOCK, K_K_SLASH, K_K_STAR, K_K_MINUS,

      K_TAB, K_q, K_w, K_e, K_r, K_t, K_y, K_u, K_i, K_o, K_p, K_LSQB, K_RSQB, K_ENTER,
      K_DEL, K_END, K_PGD, K_K_7, K_K_8, K_K_9, K_K_PLUS,

      K_CAPS, K_a, K_s, K_d, K_f, K_g, K_h, K_j, K_k, K_l, K_SEMICOLON, K_QUOTE,
      K_K_4, K_K_5, K_K_6,

      K_LSHIFT, K_z, K_x, K_c, K_v, K_b, K_n, K_m, K_COMMA, K_PERIOD, K_SLASH, K_RSHIFT,
      K_ARROW_UP, K_K_1, K_K_2, K_K_3, K_K_ENTER,

      K_LCTRL, K_LWIN, K_LALT, K_SPACE, K_RALT, K_RWIN, K_RPROP, K_RCTRL,
      K_ARROW_LEFT, K_ARROW_DOWN, K_ARROW_RIGHT, K_K_0, K_K_PERIOD,
   );
    each_c_( Key const*, k, keys )
    {
       draw_key( *k, keyStyle );
    }


    printf_tb(33, 1, magentaStyle(), "Keyboard demo!");
    printf_tb(21, 2, magentaStyle(), "(press CTRL+X and then CTRL+Q to exit)");
    printf_tb(15, 3, magentaStyle(), "(press CTRL+X and then CTRL+C to change input mode)");

    int inputmode = tb_set_input_mode(0);
    char inputmode_str[64];

    if (inputmode & TB_INPUT_ESC)
        sprintf(inputmode_str, "TB_INPUT_ESC");
    if (inputmode & TB_INPUT_ALT)
        sprintf(inputmode_str, "TB_INPUT_ALT");
    if (inputmode & TB_INPUT_MOUSE)
        sprintf(inputmode_str + 12, " | TB_INPUT_MOUSE");

    printf_tb(3, 18, whiteStyle(), "Input mode: %s", inputmode_str);
}

const char *funckeymap(int k)
{
    static const char *fcmap[] = {
        "CTRL+2, CTRL+~",
        "CTRL+A",
        "CTRL+B",
        "CTRL+C",
        "CTRL+D",
        "CTRL+E",
        "CTRL+F",
        "CTRL+G",
        "CTRL+H, BACKSPACE",
        "CTRL+I, TAB",
        "CTRL+J",
        "CTRL+K",
        "CTRL+L",
        "CTRL+M, ENTER",
        "CTRL+N",
        "CTRL+O",
        "CTRL+P",
        "CTRL+Q",
        "CTRL+R",
        "CTRL+S",
        "CTRL+T",
        "CTRL+U",
        "CTRL+V",
        "CTRL+W",
        "CTRL+X",
        "CTRL+Y",
        "CTRL+Z",
        "CTRL+3, ESC, CTRL+[",
        "CTRL+4, CTRL+\\",
        "CTRL+5, CTRL+]",
        "CTRL+6",
        "CTRL+7, CTRL+/, CTRL+_",
        "SPACE"
    };
    static const char *fkmap[] = {
        "F1",
        "F2",
        "F3",
        "F4",
        "F5",
        "F6",
        "F7",
        "F8",
        "F9",
        "F10",
        "F11",
        "F12",
        "INSERT",
        "DELETE",
        "HOME",
        "END",
        "PGUP",
        "PGDN",
        "ARROW UP",
        "ARROW DOWN",
        "ARROW LEFT",
        "ARROW RIGHT"
    };

    if (k == TB_KEY_CTRL_8)
        return "CTRL+8, BACKSPACE 2"; /* 0x7F */
    else if (k >= TB_KEY_ARROW_RIGHT && k <= 0xFFFF)
        return fkmap[0xFFFF-k];
    else if (k <= TB_KEY_SPACE)
        return fcmap[k];
    return "UNKNOWN";
}

void pretty_print_press(struct tb_event *ev)
{
    char buf[7];
    buf[tb_utf8_unicode_to_char(buf, ev->ch)] = '\0';
    printf_tb(3, 19, whiteStyle(), "Key: ");
    printf_tb(8, 19, yellowStyle(), "decimal: %d", ev->key);
    printf_tb(8, 20, greenStyle(), "hex:     0x%X", ev->key);
    printf_tb(8, 21, cyanStyle(), "octal:   0%o", ev->key);
    printf_tb(8, 22, redStyle(), "string:  %s", funckeymap(ev->key));

    printf_tb(54, 19, whiteStyle(), "Char: ");
    printf_tb(60, 19, yellowStyle(), "decimal: %d", ev->ch);
    printf_tb(60, 20, greenStyle(), "hex:     0x%X", ev->ch);
    printf_tb(60, 21, cyanStyle(), "octal:   0%o", ev->ch);
    printf_tb(60, 22, redStyle(), "string:  %s", buf);

    printf_tb(54, 18, whiteStyle(), "Modifier: %c%c%c%c",
            (ev->mod & TB_MOD_CTRL)   ? 'C' : ' ',
            (ev->mod & TB_MOD_ALT)    ? 'A' : ' ',
            (ev->mod & TB_MOD_SHIFT)  ? 'S' : ' ',
            (ev->mod & TB_MOD_MOTION) ? 'M' : ' ');

}

void pretty_print_resize(struct tb_event *ev)
{
    printf_tb(3, 19, whiteStyle(), "Resize event: %d x %d", ev->w, ev->h);
}

int counter = 0;

void pretty_print_mouse(struct tb_event *ev) {
    printf_tb(3, 19, whiteStyle(), "Mouse event: %d x %d %c", ev->x, ev->y, (ev->mod & TB_MOD_MOTION) ? '*' : ' ');
    char *btn = "";
    switch (ev->key) {
    case TB_KEY_MOUSE_LEFT:
        btn = "MouseLeft: %d";
        break;
    case TB_KEY_MOUSE_MIDDLE:
        btn = "MouseMiddle: %d";
        break;
    case TB_KEY_MOUSE_RIGHT:
        btn = "MouseRight: %d";
        break;
    case TB_KEY_MOUSE_WHEEL_UP:
        btn = "MouseWheelUp: %d";
        break;
    case TB_KEY_MOUSE_WHEEL_DOWN:
        btn = "MouseWheelDown: %d";
        break;
    case TB_KEY_MOUSE_RELEASE:
        btn = "MouseRelease: %d";
    }
    counter++;
    printf_tb(43, 19, whiteStyle(), "Key: ");
    printf_tb(48, 19, yellowStyle(), btn, counter);
}

void dispatch_press(struct tb_event *ev)
{
   Keys combos[] = {
      keys_( K_TILDE, K_2, K_LCTRL, K_RCTRL ),
      keys_( K_A, K_LCTRL, K_RCTRL ),
      keys_( K_B, K_LCTRL, K_RCTRL ),
      keys_( K_C, K_LCTRL, K_RCTRL ),
      keys_( K_D, K_LCTRL, K_RCTRL ),
      keys_( K_E, K_LCTRL, K_RCTRL ),
      keys_( K_F, K_LCTRL, K_RCTRL ),
      keys_( K_G, K_LCTRL, K_RCTRL ),
      keys_( K_H, K_BACKSPACE, K_LCTRL, K_RCTRL ),
      keys_( K_I, K_TAB, K_LCTRL, K_RCTRL ),
      keys_( K_J, K_LCTRL, K_RCTRL ),
      keys_( K_K, K_LCTRL, K_RCTRL ),
      keys_( K_L, K_LCTRL, K_RCTRL ),
      keys_( K_M, K_ENTER, K_K_ENTER, K_LCTRL, K_RCTRL ),
      keys_( K_N, K_LCTRL, K_RCTRL ),
      keys_( K_O, K_LCTRL, K_RCTRL ),
      keys_( K_P, K_LCTRL, K_RCTRL ),
      keys_( K_Q, K_LCTRL, K_RCTRL ),
      keys_( K_R, K_LCTRL, K_RCTRL ),
      keys_( K_S, K_LCTRL, K_RCTRL ),
      keys_( K_T, K_LCTRL, K_RCTRL ),
      keys_( K_U, K_LCTRL, K_RCTRL ),
      keys_( K_V, K_LCTRL, K_RCTRL ),
      keys_( K_W, K_LCTRL, K_RCTRL ),
      keys_( K_X, K_LCTRL, K_RCTRL ),
      keys_( K_Y, K_LCTRL, K_RCTRL ),
      keys_( K_Z, K_LCTRL, K_RCTRL ),
      keys_( K_LSQB, K_ESC, K_3, K_LCTRL, K_RCTRL ),
      keys_( K_4, K_BACKSLASH, K_LCTRL, K_RCTRL ),
      keys_( K_RSQB, K_5, K_LCTRL, K_RCTRL ),
      keys_( K_6, K_LCTRL, K_RCTRL ),
      keys_( K_7, K_SLASH, K_MINUS_SHIFT, K_LCTRL, K_RCTRL ),
      keys_( K_SPACE ),
      keys_( K_1_SHIFT,K_LSHIFT,K_RSHIFT ),
      keys_( K_DOUBLEQUOTE,K_LSHIFT,K_RSHIFT ),
      keys_( K_3_SHIFT,K_LSHIFT,K_RSHIFT ),
      keys_( K_4_SHIFT,K_LSHIFT,K_RSHIFT ),
      keys_( K_5_SHIFT,K_LSHIFT,K_RSHIFT ),
      keys_( K_7_SHIFT,K_LSHIFT,K_RSHIFT ),
      keys_( K_QUOTE ),
      keys_( K_9_SHIFT,K_LSHIFT,K_RSHIFT ),
      keys_( K_0_SHIFT,K_LSHIFT,K_RSHIFT ),
      keys_( K_8_SHIFT,K_K_STAR,K_LSHIFT,K_RSHIFT ),
      keys_( K_EQUALS_SHIFT,K_K_PLUS,K_LSHIFT,K_RSHIFT ),
      keys_( K_COMMA ),
      keys_( K_MINUS,K_K_MINUS ),
      keys_( K_PERIOD,K_K_PERIOD ),
      keys_( K_SLASH,K_K_SLASH ),
      keys_( K_0,K_K_0 ),
      keys_( K_1,K_K_1 ),
      keys_( K_2,K_K_2 ),
      keys_( K_3,K_K_3 ),
      keys_( K_4,K_K_4 ),
      keys_( K_5,K_K_5 ),
      keys_( K_6,K_K_6 ),
      keys_( K_7,K_K_7 ),
      keys_( K_8,K_K_8 ),
      keys_( K_9,K_K_9 ),
      keys_( K_PARENTHESIS,K_LSHIFT,K_RSHIFT ),
      keys_( K_SEMICOLON ),
      keys_( K_LANB,K_LSHIFT,K_RSHIFT ),
      keys_( K_EQUALS ),
      keys_( K_RANB,K_LSHIFT,K_RSHIFT ),
      keys_( K_QUESTION,K_LSHIFT,K_RSHIFT ),
      keys_( K_2_SHIFT,K_LSHIFT,K_RSHIFT ),
      keys_( K_A,K_LSHIFT,K_RSHIFT ),
      keys_( K_B,K_LSHIFT,K_RSHIFT ),
      keys_( K_C,K_LSHIFT,K_RSHIFT ),
      keys_( K_D,K_LSHIFT,K_RSHIFT ),
      keys_( K_E,K_LSHIFT,K_RSHIFT ),
      keys_( K_F,K_LSHIFT,K_RSHIFT ),
      keys_( K_G,K_LSHIFT,K_RSHIFT ),
      keys_( K_H,K_LSHIFT,K_RSHIFT ),
      keys_( K_I,K_LSHIFT,K_RSHIFT ),
      keys_( K_J,K_LSHIFT,K_RSHIFT ),
      keys_( K_K,K_LSHIFT,K_RSHIFT ),
      keys_( K_L,K_LSHIFT,K_RSHIFT ),
      keys_( K_M,K_LSHIFT,K_RSHIFT ),
      keys_( K_N,K_LSHIFT,K_RSHIFT ),
      keys_( K_O,K_LSHIFT,K_RSHIFT ),
      keys_( K_P,K_LSHIFT,K_RSHIFT ),
      keys_( K_Q,K_LSHIFT,K_RSHIFT ),
      keys_( K_R,K_LSHIFT,K_RSHIFT ),
      keys_( K_S,K_LSHIFT,K_RSHIFT ),
      keys_( K_T,K_LSHIFT,K_RSHIFT ),
      keys_( K_U,K_LSHIFT,K_RSHIFT ),
      keys_( K_V,K_LSHIFT,K_RSHIFT ),
      keys_( K_W,K_LSHIFT,K_RSHIFT ),
      keys_( K_X,K_LSHIFT,K_RSHIFT ),
      keys_( K_Y,K_LSHIFT,K_RSHIFT ),
      keys_( K_Z,K_LSHIFT,K_RSHIFT ),
      keys_( K_LSQB ),
      keys_( K_BACKSLASH ),
      keys_( K_RSQB ),
      keys_( K_6_SHIFT,K_LSHIFT,K_RSHIFT ),
      keys_( K_MINUS_SHIFT,K_LSHIFT,K_RSHIFT ),
      keys_( K_TILDE ),
      keys_( K_a ),
      keys_( K_b ),
      keys_( K_c ),
      keys_( K_d ),
      keys_( K_e ),
      keys_( K_f ),
      keys_( K_g ),
      keys_( K_h ),
      keys_( K_i ),
      keys_( K_j ),
      keys_( K_k ),
      keys_( K_l ),
      keys_( K_m ),
      keys_( K_n ),
      keys_( K_o ),
      keys_( K_p ),
      keys_( K_q ),
      keys_( K_r ),
      keys_( K_s ),
      keys_( K_t ),
      keys_( K_u ),
      keys_( K_v ),
      keys_( K_w ),
      keys_( K_x ),
      keys_( K_y ),
      keys_( K_z ),
      keys_( K_LCUB,K_LSHIFT,K_RSHIFT ),
      keys_( K_BACKSLASH_SHIFT,K_LSHIFT,K_RSHIFT ),
      keys_( K_RCUB,K_LSHIFT,K_RSHIFT ),
      keys_( K_TILDE_SHIFT,K_LSHIFT,K_RSHIFT ),
      keys_( K_8, K_BACKSPACE, K_LCTRL, K_RCTRL )
   };

   Keys func_combos[] = {
      keys_( K_F1 ),
      keys_( K_F2 ),
      keys_( K_F3 ),
      keys_( K_F4 ),
      keys_( K_F5 ),
      keys_( K_F6 ),
      keys_( K_F7 ),
      keys_( K_F8 ),
      keys_( K_F9 ),
      keys_( K_F10 ),
      keys_( K_F11 ),
      keys_( K_F12 ),
      keys_( K_INS ),
      keys_( K_DEL ),
      keys_( K_HOM ),
      keys_( K_END ),
      keys_( K_PGU ),
      keys_( K_PGD ),
      keys_( K_ARROW_UP ),
      keys_( K_ARROW_DOWN ),
      keys_( K_ARROW_LEFT ),
      keys_( K_ARROW_RIGHT )
   };

    csStyle pressedStyle = base_style_cs( rgb24_c_( 255, 255, 255 ), rgb24_c_( 255, 0, 0 ) );
    if (ev->mod & TB_MOD_ALT) {
        draw_key(K_LALT, pressedStyle);
        draw_key(K_RALT, pressedStyle);
    }
    if (ev->mod & TB_MOD_CTRL) {
        draw_key(K_LCTRL, pressedStyle);
        draw_key(K_RCTRL, pressedStyle);
    }
    if (ev->mod & TB_MOD_SHIFT) {
        draw_key(K_LSHIFT, pressedStyle);
        draw_key(K_RSHIFT, pressedStyle);
    }

    Keys *combo = 0;
    if (ev->key >= TB_KEY_ARROW_RIGHT)
        combo = &func_combos[0xFFFF-ev->key];
    else if (ev->ch < 128) {
        if (ev->ch == 0 && ev->key < 128)
            combo = &combos[ev->key];
        else
            combo = &combos[ev->ch];
    }
    if (!combo)
        return;

    each_c_( Key const*, key, *combo )
    {
       draw_key( *key, pressedStyle );
    }
}

int main(int argc, char **argv)
{
    (void) argc; (void) argv;
    int ret;
    print_locale_c();
    set_locale_c( LC_ALL, "en_US.UTF-8" );
    char const* locale = get_locale_c( LC_ALL, var_chars_c_( 128 ) );
    println_c_( "locale: {s:q}", locale );

    cmdscreen_cs();
    tb_set_output_mode( TB_OUTPUT_TRUECOLOR );

    tb_set_input_mode(TB_INPUT_ESC | TB_INPUT_MOUSE);
    struct tb_event ev;

    clear_cs();
    draw_keyboard();
    refresh_cs();
    int inputmode = 0;
    int ctrlxpressed = 0;

    while (1) {
        int ret = tb_poll_event(&ev);

        if (ret != TB_OK) {
            if (ret == TB_ERR_POLL && tb_last_errno() == EINTR) {
                /* poll was interrupted, maybe by a SIGWINCH; try again */
                continue;
            }
            /* some other error occurred; bail */
            break;
        }

        switch (ev.type) {
        case TB_EVENT_KEY:
            if (ev.key == TB_KEY_CTRL_A && ctrlxpressed) {
                cleanup_cmdscreen_cs();
                return 0;
            }
            if (ev.key == TB_KEY_CTRL_C && ctrlxpressed) {
                static int chmap[] = {
                    TB_INPUT_ESC | TB_INPUT_MOUSE, /* 101 */
                    TB_INPUT_ALT | TB_INPUT_MOUSE, /* 110 */
                    TB_INPUT_ESC,                  /* 001 */
                    TB_INPUT_ALT,                  /* 010 */
                };
                inputmode++;
                if (inputmode >= 4) {
                    inputmode = 0;
                }
                tb_set_input_mode(chmap[inputmode]);
            }
            if (ev.key == TB_KEY_CTRL_X)
                ctrlxpressed = 1;
            else
                ctrlxpressed = 0;

            clear_cs();
            draw_keyboard();
            dispatch_press(&ev);
            pretty_print_press(&ev);
            break;
        case TB_EVENT_RESIZE:
            clear_cs();
            draw_keyboard();
            pretty_print_resize(&ev);
            break;
        case TB_EVENT_MOUSE:
            clear_cs();
            draw_keyboard();
            pretty_print_mouse(&ev);
            break;
        default:
            break;
        }
      refresh_cs();
    }
    cleanup_cmdscreen_cs();
    return 0;
}
