#include <stdio.h>
#include <string.h>
 
/*  Below structure1 and structure2 are same. 
    They differ only in member's allignment */
 
struct structure1 
{
       int id1;
       int id2;
       char name;
       char c;
       float percentage;
};
 
struct structure2 
{
       int id1;
       char name;
       int id2;
       char c;
       float percentage;                      
};
 
int main() 
{
    struct structure1 a;
    struct structure2 b;
 
    printf("size of structure1 in bytes : %Zu\n", 
            sizeof(a));
    printf ( "\n   Address of id1        = %p", &a.id1 );
    printf ( "\n   Address of id2        = %p", &a.id2 );
    printf ( "\n   Address of name       = %p", &a.name );
    printf ( "\n   Address of c          = %p", &a.c );
    printf ( "\n   Address of percentage = %p\n",
                   &a.percentage );
 
    printf("   \n\nsize of structure2 in bytes : %Zu\n",
                   sizeof(b));
    printf ( "\n   Address of id1        = %p", &b.id1 );
    printf ( "\n   Address of name       = %p", &b.name );
    printf ( "\n   Address of id2        = %p", &b.id2 );
    printf ( "\n   Address of c          = %p", &b.c );
    printf ( "\n   Address of percentage = %p\n",
                   &b.percentage );
    getchar();
    return 0;
}
