#include <stdio.h>
#include <stdlib.h>

int main()
{
    int u, v=45;
    int *pu, *pv = &v;
    *pv = v + 1;
    u = *pv + 1;
    pu = &u;

    printf("-- %d\n", &v);  // endereco de v
    printf("-- %d\n", pv);  // endereco de v
    printf("-- %d\n", *pv); // 46
    printf("-- %d\n", u);   // 47
    printf("-- %d\n", &u);  // endereco de u
    printf("-- %d\n", pu);  // endereco de u
    printf("-- %d\n", *pu); // 47

}
