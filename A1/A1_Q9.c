#include <stdio.h>
#include <math.h>

int main() {
    float m1, m2, c1, c2;
    int result;

    // Input slopes and intercepts for the two lines
    printf("Enter the slope (m1) and intercept (c1) of the first line: ");
    scanf("%f %f", &m1, &c1);

    printf("Enter the slope (m2) and intercept (c2) of the second line: ");
    scanf("%f %f", &m2, &c2);

    // Determine the relationship between the lines
    if (m1 == m2) {
        if (c1 == c2) {
            result = 1;  // Lines are coincident
        } else {
            result = 2;  // Lines are parallel
        }
    } else if (m1 * m2 == -1) {
        result = 3;  // Lines are perpendicular
    } else {
        result = 4;  // Lines intersect with an angle θ ≠ 90°
    }

    // Output the result using switch-case
    switch (result) {
        case 1:
            printf("The lines are coincident.\n");
            break;
        case 2:
            printf("The lines are parallel.\n");
            break;
        case 3:
            printf("The lines are perpendicular.\n");
            break;
        case 4:
            printf("The lines intersect with an angle θ ≠ 90°.\n");
            break;
        default:
            printf("Error in determining the relationship between the lines.\n");
            break;
    }

    return 0;
}
