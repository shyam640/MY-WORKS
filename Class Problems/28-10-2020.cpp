#include <cstdio>

int main() {
    int p;
    printf("Enter the number of nodes :");
    scanf("%d",&p);
    switch (p) {
        case 0:
            printf("Geometry");
            break;
        case 1:
            printf("Point");
            break;
        case 2:
            printf("Line");
            break;
        case 3:
            printf("Triangle");
            break;
        case 4:
            printf("Rectangle");
            break;
        default:
            printf("Polygon");
            break;
    }
    return 0;
}
