void printA(int a){
printf("Hello world from printA : %d\n",a);
}

void printB(const char *buff){
printf("Hello world from printB : %s\n",buff);
}

#define Max_ITEMS() 6, 5, 4, 3, 2, 1, 0 
#define __VA_ARG_N(_1, _2, _3, _4, _5, _6, N, ...) N
#define _Num_ARGS_(...) __VA_ARG_N(__VA_ARGS__) 
#define NUM_ARGS(...) (_Num_ARGS_(_0, ## __VA_ARGS__, Max_ITEMS()) - 1) 
#define CHECK_ARGS_MAX_LIMIT(t) if(NUM_ARGS(args)>t)
#define CHECK_ARGS_MIN_LIMIT(t) if(NUM_ARGS(args) 
#define print(x , args ...) \
CHECK_ARGS_MIN_LIMIT(1) printf("error");fflush(stdout); \
CHECK_ARGS_MAX_LIMIT(4) printf("error");fflush(stdout); \
({ \
if (__builtin_types_compatible_p (typeof (x), int)) \
printA(x, ##args); \
else \
printB (x,##args); \
})

int main(int argc, char** argv) {
    int a=0;
    print(a);
    print("hello");
    return (EXIT_SUCCESS);
}