#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
 
typedef struct file_data
{
    char ** token;
 
 
    unsigned token_amount;
 
 
    struct file_data * next;
 
 
} file_data;
 
 
void print_data( file_data * head )
{
    unsigned token;
 
 
    file_data * node = head;
 
 
    for ( ; node; node = node->next )
        for ( token = 0; token <= node->token_amount; token++ )
            printf( "Token %d : %s\n", token, node->token[token] );
 
 
    return;
}
 
 
void free_data( file_data * head )
{
    unsigned token = 0;
 
 
    void * temp = NULL;
    file_data * node = head;
 
 
    while ( node )
    {
        for ( ; token <= node->token_amount; token++ )
            free( node->token[token] );
        free( node->token );
 
 
        temp = node;
        node = node->next;
        free( temp );
    }
 
 
    return;
}
 
 
file_data * create( )
{
    void * temp = NULL;
 
 
    if ( !( temp = malloc( sizeof( file_data ) ) ) )
        exit( 1 );
 
 
    return temp;
}
 
 
void set_token( file_data * node, const char * token, unsigned offset )
{
    void * temp = NULL;
 
 
    if ( !offset )
    {
        if ( !( temp = malloc( ( node->token_amount * sizeof( char * ) ) ) ) )
        {
            perror( "malloc" );
            exit( 1 );
        }
    } else if ( !( temp = realloc( node->token, ( node->token_amount * sizeof( char * ) ) ) ) )
    {
        perror( "realloc" );
        exit( 1 );
    }
 
 
    node->token = temp;
 
 
    if ( !( temp = malloc( strlen( token ) + 1 ) ) )
        exit( 1 );
 
 
    node->token[offset] = temp;
    node->token[offset] = strcpy( node->token[0], token );
 
 
    return;
}
 
 
void add_tokens( char * line, file_data * head, char * delimiter )
{
    unsigned offset;
    char * token = NULL;
 
 
    token = strtok( line, delimiter );
 
 
    for ( offset = 0; token != NULL; ++offset )
    {
        head->token_amount = offset + 1;
        set_token( head, token, offset );
        token = strtok( NULL, delimiter );
    }
 
 
    head->token_amount = offset - 1;
}
 
 
file_data * append( file_data * head, char * line, char * delimiter )
{
    file_data * temp = NULL;
 
 
    if ( !head )
        head = create( );
    else
    {
        temp = create( );
        temp->next = head;
        head = temp;
    }
 
 
    add_tokens( line, head, delimiter );
 
 
    return head;
}
 
 
FILE * open_file( const char * file_name )
{
    FILE * file = NULL;
 
 
    if ( !( file = fopen( file_name, "r" ) ) )
    {
        perror( "fopen" );
        exit( 1 );
    }
 
 
    return file;
}
 
 
char * get_file_line( FILE * file )
{
    char buffer[BUFSIZ] = {0};
    char * line = NULL;
    char * newline;
 
 
    if ( fgets( buffer, BUFSIZ, file ) == NULL )
        return NULL;
 
 
    line = malloc( strlen( buffer ) );
 
 
    if ( !line )
    {
        perror( "malloc" );
        exit( 1 );
    }
 
 
    line = strcpy( line, buffer );
 
 
    if ( ( newline = strchr( line, '\n') ) != NULL )
        *newline = '\0';
 
 
    return line;
}
 
 
file_data * parse_file( const char * file_name )
{
    FILE * file = NULL;
    file_data * head = NULL;
 
 
    char * line;
 
 
    file = open_file( file_name );
 
 
    for ( line = NULL; ( line = get_file_line( file ) ); free( line ), line = NULL )
        head = append( head, line, ";" );
 
 
    fclose( file );
 
 
    return head;
}
 
 
void check_command_line_paramters( int argc, const char * file_name )
{
    if ( argc < 2 )
    {
        printf( "Usage : <%s> <file_name>\n", file_name );
        exit( 1 );
    }
 
 
    return;
}
 
 
int main( int argc, char * argv[] )
{
    file_data * head = NULL;
 
 
    check_command_line_paramters( argc, argv[0] );
    head = parse_file( argv[1] );
    print_data( head );
    free_data( head );
 
 
    printf( "Program exited normally!" );
 
 
    return 0;
}