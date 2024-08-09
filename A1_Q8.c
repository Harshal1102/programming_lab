#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int isColinear(double x1, double x2, double x3, double y1, double y2, double y3){
    if(((x1 == x2) && (x1 == x3) && (x2 == x3)) || ((y1 == y2) && (y1 == y3) && (y2 == y3))){
        return 0;
    }
    else
        return 1;
}

double findLength(double x1, double x2, double y1, double y2){
    double length = sqrt(pow((x2-x1),2) + (pow((y2-y1),2)));
    return length;
}

int isTriangle(double length1, double length2, double length3){
    if((length1 + length2 > length3) && (length1 + length3 > length2) && (length2 + length3 > length1)){
        return 0;
    }
    else
        return 1;
}

int isEquilateral(double length1, double length2, double length3){
    if((length1 == length2) && (length1 == length3) && (length2 == length3)){
        return 0;
    }
    else
        return 1;
}

int isIsoceles(double length1, double length2, double length3){
    if((length1 == length2) || (length1 == length3) || (length2 == length3)){
        return 0;
    }
    else
        return 1;
}

int isScalene(double length1, double length2, double length3){
    if(length1 != length2 && length1 != length3 && length2 != length3){
        return 0;
    }
    else
        return 1;
}

int main(){
    
    double x1;
    double x2;
    double x3;
    double y1;
    double y2;
    double y3;
    
    
    printf("Enter x1:");
    scanf("%lf", &x1);
    
    printf("Enter y1:");
    scanf("%lf", &y1);

    printf("Enter x2:");
    scanf("%lf", &x2);

    printf("Enter y2:");
    scanf("%lf", &y2);

    printf("Enter x3:");
    scanf("%lf", &x3);

    printf("Enter y3:");
    scanf("%lf", &y3);
    
    double length1 = findLength(x1,x2,y1,y2);
    double length2 = findLength(x1,x3,y1,y3);
    double length3 = findLength(x2,x3,y2,y3);
    
    if(isColinear(x1,x2,x3,y1,y2,y3) == 0){
        printf("Points are colinear");
        return 0;
    }
    
    else if(isTriangle(length1, length2, length3) == 0)
    {
        if(isEquilateral(length1, length2, length3) == 0){
            printf("Equilateral Triangle");
            return 0;
        }
    
        else if(isIsoceles(length1, length2, length3) == 0){
            printf("Isoceles Triangle");
            return 0;
        }
    
        else if(isScalene(length1, length2, length3) == 0){
            printf("Scalene Triangle");
            return 0;
        }
    }
    
    else{
        printf("Not a triangle");
        return 0;
    }
}