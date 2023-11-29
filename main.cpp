#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define inf 999
#define N 4 //number of cities

void shortest_path(int connections[N][N], int start, int dest){
    int dist[N][N]; // make a copy of input matrix, dist is going to display the 
                    // smallest value from i to j which is the city index 
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            dist[i][j] = connections[i][j];
        }
    }
    
    for(int k=0; k<N; k++){  // fill in the shortest distance into matrix 
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                
                if (dist[i][j] > dist[i][k]+dist[k][j]){
                    dist[i][j] = dist[i][k]+dist[k][j];
                }
                
            }
        }
    }
    

    cout<<"\nshortest path between desired two cities is \n"<<dist[start][dest];
}



void shortest_path_key (int connections[N][N], int start, int dest, int key){
    int dist[N][N]; // make a copy of input matrix, dist is going to display the 
                    // smallest value from i to j which is the city index 
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            dist[i][j] = connections[i][j];
        }
    }
    
    for(int k=0; k<N; k++){  // fill in the shortest distance into matrix 
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                
                if (dist[i][j] > dist[i][k]+dist[k][j]){
                    dist[i][j] = dist[i][k]+dist[k][j];
                }
                
            }
        }
    }
    
    int length = 3;
    int stored_path[length]={0};
    stored_path[0]=dist[start][key]+dist[key][dest];
    stored_path[1]=dist[key][start]+dist[start][key];
    stored_path[2]=dist[start][dest]+dist[dest][key]; 
    
    //now sort the array and return leftmost elements
    int temp;
    int counter;
    for(int j=1; j<length; j++){
        temp = stored_path[j];
        counter = j-1;
        while(counter>0 && stored_path[counter]>temp){
            stored_path[counter+1]=stored_path[counter];
            counter--;
        }
        stored_path[counter+1] = temp;
    }
    
    cout<<"\nThe shortest path include key city is:\n"<<stored_path[0];
    
}



int main()
{
    int connections[N][N] = {
        {0, 2, 4, inf},
        {2, 0, 3, 1},
        {4, 3, 0, 2},
        {inf, 1, 2, 0}
    };
    
    int start = 0; //start city i
    int dest = 3;  // end city j
    
    int uni_con[N][N] = {
        {0, 2, 4, inf},
        {3, 0, 5, 6},
        {1, 7, 0, 3},
        {inf, 4, 5, 0}
    };
    
    int keyCity = 1;
    
    cout<<"\nThe answer for first condition:\n";
    shortest_path(connections, start, dest);
    
    cout<<"\n\nThe answer for second condition:\n";
    shortest_path(uni_con, start, dest);
    
    cout<<"\n\nThe answer for third condition:\n";
    shortest_path_key(uni_con, start, dest, keyCity);
}


