#include <stdio.h>

typedef enum {
    T_INT,
    T_FLOAT,
    T_CHAR,
} my_type;

typedef struct {
    my_type type;
    union {
        int a; 
        float b; 
        char c;
    } my_union;
} my_struct;

void set_overload (my_struct *whatever) 
{
    switch (whatever->type) 
    {
        case T_INT:
            whatever->my_union.a = 1;
            break;
        case T_FLOAT:
            whatever->my_union.b = 2.0;
            break;
        case T_CHAR:
            whatever->my_union.c = '3';
    }
}

void printf_overload (my_struct *whatever) {
    switch (whatever->type) 
    {
        case T_INT:
            printf("%d\n", whatever->my_union.a);
            break;
        case T_FLOAT:
            printf("%f\n", whatever->my_union.b);
            break;
        case T_CHAR:
            printf("%c\n", whatever->my_union.c);
            break;
    }

}

int main (int argc, char* argv[])
{
    my_struct s;

    s.type=T_INT;
    set_overload(&s);
    printf_overload(&s);

    s.type=T_FLOAT;
    set_overload(&s);
    printf_overload(&s);

    s.type=T_CHAR;
    set_overload(&s);
    printf_overload(&s); 
}









