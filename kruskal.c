#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int parent[MAX];

int find(int i) { 
    if (parent[i] == i) {
        return i;
    }
    return parent[i] = find(parent[i]); // Path compression
} 

int uni(int i, int j) {
    if(i != j) {  
        parent[j] = i; // Union the sets
        return 1; 
    } 
    return 0; 
} 

int main() {  
    int vertex_count = 0;
    int row, column;
    int cost_matrix[MAX][MAX];
    int edge_count = 0, count = 1;
    int sum_cost = 0, min_cost;
    int row_no, column_no, edge1, edge2;
    
    printf("Implementation of Kruskal's algorithm\n\n");
    printf("Total no of vertices: ");
    scanf("%d", &vertex_count);
    
    // Initialize parent array such that each vertex is its own parent
    for(int i = 1; i <= vertex_count; i++) {
        parent[i] = i;  // Initially, all vertices are their own parents
    }
    
    // Get edge weight matrix from user    
    printf("Enter the cost matrix:\n");
    for(row = 1; row <= vertex_count; row++) {
        for(column = 1; column <= vertex_count; column++) {
            scanf("%d", &cost_matrix[row][column]);
            if(cost_matrix[row][column] == 0) {
                cost_matrix[row][column] = 999; // Use a large value for no edge
            }
        }
    }
    
    // Calculate the number of edges
    edge_count = 0;
    for(row = 1; row <= vertex_count; row++) {
        for(column = row + 1; column <= vertex_count; column++) {  // Avoid double counting
            if(cost_matrix[row][column] != 999) {
                edge_count++;
            }
        }
    }
    
    while(count <= edge_count) {
        min_cost = 999; // Reset min_cost for each iteration
        for(row = 1; row <= vertex_count; row++) {
            for(column = 1; column <= vertex_count; column++) {
                if(cost_matrix[row][column] < min_cost && cost_matrix[row][column] != 999) {
                    min_cost = cost_matrix[row][column];
                    edge1 = row;
                    edge2 = column;
                    row_no = row;
                    column_no = column;
                }
            }
        }
        
        row_no = find(row_no);
        column_no = find(column_no);
        
        if(uni(row_no, column_no)) {  
            printf("\nEdge %d is (%d -> %d) with cost: %d", count++, edge1, edge2, min_cost);
            sum_cost = sum_cost + min_cost;
        }
        
        // Mark the edge as processed
        cost_matrix[edge1][edge2] = cost_matrix[edge2][edge1] = 999;  // Remove the edge from consideration
    }
    
    printf("\nMinimum cost = %d", sum_cost);  
    return 0;
}

