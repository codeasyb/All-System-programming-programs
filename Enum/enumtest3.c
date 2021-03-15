// we need `size_t`
#include <stddef.h>

// argument types to accept
enum sum_arg_types { SUM_LONG, SUM_ULONG, SUM_DOUBLE };

// a structure to hold an argument
struct sum_arg
{
    enum sum_arg_types type;
    union
    {
        long as_long;
        unsigned long as_ulong;
        double as_double;
    } value;
};

// determine an array's size
#define count(ARRAY) ((sizeof (ARRAY))/(sizeof *(ARRAY)))

// this is how our function will be called
#define sum(...) _sum(count(sum_args(__VA_ARGS__)), sum_args(__VA_ARGS__))

// create an array of `struct sum_arg`
#define sum_args(...) ((struct sum_arg []){ __VA_ARGS__ })

// create initializers for the arguments
#define sum_long(VALUE) { SUM_LONG, { .as_long = (VALUE) } }
#define sum_ulong(VALUE) { SUM_ULONG, { .as_ulong = (VALUE) } }
#define sum_double(VALUE) { SUM_DOUBLE, { .as_double = (VALUE) } }

// our polymorphic function
long double _sum(size_t count, struct sum_arg * args)
{
    long double value = 0;

    for(size_t i = 0; i < count; ++i)
    {
        switch(args[i].type)
        {
            case SUM_LONG:
            value += args[i].value.as_long;
            break;

            case SUM_ULONG:
            value += args[i].value.as_ulong;
            break;

            case SUM_DOUBLE:
            value += args[i].value.as_double;
            break;
        }
    }

    return value;
}

// let's see if it works

#include <stdio.h>

int main()
{
    unsigned long foo = -1;
    long double value = sum(sum_long(42), sum_ulong(foo), sum_double(1e10));
    printf("%Le\n", value);
    return 0;
}