#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/errno.h>  

#define BUFSIZE 1000

struct node {
    char *data;
    struct node *next;
};

// getlinefd reads a full line from fd into *lineptr. Initialize *lineptr to NULL and *n to 0.
// getlinefd will store the line into *lineptr which is is a buffer that will grow as needed.
// The buffer size is stored in *n. The line ends '\0' and with a '\n'when present.
// getlinefd returns the number of characters read, or -1 in case of error or if the end of file is reached.
ssize_t getlinefd(char **lineptr, size_t *n, int fd) {
    static char buf[10];
    static size_t len = 0;
    const size_t blen = sizeof(buf);

    if (lineptr == NULL || n == NULL) {
        errno = EINVAL;
        return -1;
    }
    if (*lineptr == NULL)
        len = 0;

    for (size_t i = 0; i < len; i++) {
        if (buf[i] == '\n') {
            i++;
            if (i+1 > *n)
                *lineptr = realloc(*lineptr, *n = i+1);
            strncpy(*lineptr, buf, i);
            (*lineptr)[i] = '\0';
            len = blen-i;
            memmove(buf, buf+i, len);
            return i;
        }
    }
    size_t l = 0;
    while (1) {
        ssize_t r = read(fd, buf+len, blen-len);
        if (r < 0)
            return -1;
        len += r;
        if (len == 0) {
            if (l != 0) {
                (*lineptr)[l] = '\0';
                return l;
            }
            if (*lineptr != NULL)
                (*lineptr)[0] = '\0';
            return -1;
        }
        for (size_t i = 0; i < len; i++) {
            if (buf[i] == '\n') {
                i++;
                if (l+i+1 > *n)
                    *lineptr = realloc(*lineptr, *n = l+i+1);
                strncpy(*lineptr+l, buf, i);
                l += i;
                (*lineptr)[l] = '\0';
                len = blen-i;
                memmove(buf, buf+i, len);
                return l;
            }
        }
        if (l+len+1 > *n)
            *lineptr = realloc(*lineptr, *n = l+len+1);
        strncpy(*lineptr+l, buf, len);
        l += len;
        len = 0;
    }
}


int main(int argc, char const *argv[]) {
    if (argc != 2) {
        printf("expected the file name as command line argument\n");
        return -1;
    }

    printf("file name: %s\n", argv[1]);    

    int fd = open(argv[1], O_RDONLY, 0644);
    if (fd < 0) {
        return -1;
    }

    // list of token is intially empty 
    struct node *head = NULL, *last = NULL;

    printf("\nREAD FROM FILE.\n");

    size_t bufLen = BUFSIZE;
    char *line = malloc(bufLen);
    // read a line from the file
    while(getlinefd(&line, &bufLen, fd) != -1)
    {
        // remove the trailing \n
        size_t len = strlen(line);
        if (len > 0 && line[len-1] == '\n')
            line[len-1] = '\0';

        // for each token in the line
        for (char *token = strtok(line, ","); token != NULL; token = strtok(NULL, ",")) {
            // append token to list
            struct node *q = malloc(sizeof(struct node));
            q->data = strdup(token);
            q->next = NULL;
            if (last == NULL)
                head = last = q;
            else
                last = last->next = q;
        }
    }

    for (struct node *p = head; p != NULL; p = p->next)
        printf("%s\n", p->data);

    return 0;
}