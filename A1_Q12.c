#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void unionSets(int A[], int n, int B[], int m);
void intersectionSets(int A[], int n, int B[], int m);
void differenceSets(int A[], int n, int B[], int m);
void symmetricDifference(int A[], int n, int B[], int m);
void printSet(int set[], int size);

int main() {
    int n,m;
    printf("Enter size of set A:- ");
    scanf("%d",&n);
    printf("Enter size of set B:- ");
    scanf("%d",&m);

    int A[n],B[n];

    printf("Enter elements of set A:- ");
    for(int i=0;i<n;i++)
    {        
        scanf("%d",&A[i]);
    }

    printf("Enter elements of set B:- ");
    for(int i=0;i<m;i++)
    {
        
        scanf("%d",&B[i]);
    }
    
    printf("Union of A and B:\n");
    unionSets(A, n, B, m);

    printf("\nIntersection of A and B:\n");
    intersectionSets(A, n, B, m);

    printf("\nDifference of A and B (A \\ B and B \\ A):\n");
    differenceSets(A, n, B, m);

    printf("\nSymmetric Difference of A and B:\n");
    symmetricDifference(A, n, B, m);

    return 0;
}

// Function to find the union of two sets A and B
void unionSets(int A[], int n, int B[], int m) {
    int unionSet[2000]; // Enough space to hold union of A and B
    int size = 0;

    // Add all elements of A to the union set
    for (int i = 0; i < n; i++) {
        unionSet[size++] = A[i];
    }

    // Add elements of B to the union set if they are not already present
    for (int i = 0; i < m; i++) {
        int found = 0;
        for (int j = 0; j < n; j++) {
            if (B[i] == A[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            unionSet[size++] = B[i];
        }
    }

    printSet(unionSet, size);
}

// Function to find the intersection of two sets A and B
void intersectionSets(int A[], int n, int B[], int m) {
    int intersectionSet[1000];
    int size = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i] == B[j]) {
                intersectionSet[size++] = A[i];
                break;
            }
        }
    }

    printSet(intersectionSet, size);
}

// Function to find the difference of two sets A \ B and B \ A
void differenceSets(int A[], int n, int B[], int m) {
    int differenceSetA[1000], differenceSetB[1000];
    int sizeA = 0, sizeB = 0;

    // A \ B
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < m; j++) {
            if (A[i] == B[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            differenceSetA[sizeA++] = A[i];
        }
    }

    // B \ A
    for (int i = 0; i < m; i++) {
        int found = 0;
        for (int j = 0; j < n; j++) {
            if (B[i] == A[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            differenceSetB[sizeB++] = B[i];
        }
    }

    printf("A \\ B: ");
    printSet(differenceSetA, sizeA);

    printf("B \\ A: ");
    printSet(differenceSetB, sizeB);
}

// Function to find the symmetric difference of two sets A and B
void symmetricDifference(int A[], int n, int B[], int m) {
    int symmetricDifferenceSet[2000];
    int size = 0;

    // Add A \ B
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < m; j++) {
            if (A[i] == B[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            symmetricDifferenceSet[size++] = A[i];
        }
    }

    // Add B \ A
    for (int i = 0; i < m; i++) {
        int found = 0;
        for (int j = 0; j < n; j++) {
            if (B[i] == A[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            symmetricDifferenceSet[size++] = B[i];
        }
    }

    printSet(symmetricDifferenceSet, size);
}

// Function to print the elements of a set
void printSet(int set[], int size) {
    printf("{ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", set[i]);
    }
    printf("}\n");
}
