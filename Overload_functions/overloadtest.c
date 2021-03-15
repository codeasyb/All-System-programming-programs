/*
 * demo.c
 *
 *  Created on: 2017-09-14
 *      Author: sboehler
 */

#include <stdio.h>

void foo_void(void)
{
    puts("void");
}
void foo_int(int c)
{
    printf("int: %d\n", c);
}
void foo_char(char c)
{
    printf("char: %c\n", c);
}
void foo_double(double c)
{
    printf("double: %.2f\n", c);
}
void foo_double_int(double c, int d)
{
    printf("double: %.2f, int: %d\n", c, d);
}

#define foo(...) SELECT(__VA_ARGS__)(__VA_ARGS__)

#define SELECT(...) CONCAT(SELECT_, NARG(__VA_ARGS__))(__VA_ARGS__)
#define CONCAT(X, Y) CONCAT_(X, Y)
#define CONCAT_(X, Y) X ## Y

#define SELECT_0() foo_void
#define SELECT_1(_1) _Generic ((_1), \
        int: foo_int,                \
        char: foo_char,              \
        double: foo_double           \
)
#define SELECT_2(_1, _2) _Generic((_1), \
        double: _Generic((_2),          \
                int: foo_double_int     \
        )                               \
)

#define ARGN(...) ARGN_(__VA_ARGS__)
#define ARGN_(_0, _1, _2, N, ...) N

#define NARG(...) ARGN(__VA_ARGS__ COMMA(__VA_ARGS__) 3, 2, 1, 0)
#define HAS_COMMA(...) ARGN(__VA_ARGS__, 1, 1, 0)

#define SET_COMMA(...) ,

#define COMMA(...) SELECT_COMMA             \
(                                           \
        HAS_COMMA(__VA_ARGS__),             \
        HAS_COMMA(__VA_ARGS__ ()),          \
        HAS_COMMA(SET_COMMA __VA_ARGS__),   \
        HAS_COMMA(SET_COMMA __VA_ARGS__ ()) \
)

#define SELECT_COMMA(_0, _1, _2, _3) SELECT_COMMA_(_0, _1, _2, _3)
#define SELECT_COMMA_(_0, _1, _2, _3) COMMA_ ## _0 ## _1 ## _2 ## _3

#define COMMA_0000 ,
#define COMMA_0001 ,
#define COMMA_0010 ,
#define COMMA_0011 ,
#define COMMA_0100 ,
#define COMMA_0101 ,
#define COMMA_0110 ,
#define COMMA_0111 ,
#define COMMA_1000 ,
#define COMMA_1001 ,
#define COMMA_1010 ,
#define COMMA_1011 ,
#define COMMA_1100 ,
#define COMMA_1101 ,
#define COMMA_1110 ,
#define COMMA_1111 ,

int main(int argc, char** argv)
{
    foo();
    foo(7);
    foo(10.12);
    foo(12.10, 7);
    foo((char)'s');

    return 0;
}