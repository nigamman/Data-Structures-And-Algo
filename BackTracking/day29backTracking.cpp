#include <iostream>
#include <vector>
#include <string>
using namespace std;

// void printPermutations(string &str, int index) {

//     //base case
//     if(index >= str.length()) {
//         cout << str << " " << endl;
//         return;
//     }
//     for (int j = index; j < str.length(); j++) {

//         swap(str[index] , str[j]);

//         //call recursion 
//         printPermutations(str, index+1);
//         //backtracking
//         swap(str[index] , str[j]);
//     }
// }
// int main () {
//     string str = "abc";
//     int index = 0;
//     printPermutations(str,index);
// }
//this fxn that will hanndle all the below cases
//if path closed
//it out of bound
//check is position is already visited 
bool isSafe(int srcX, int srcY, int newX, int newY, int maze[][4], int row, int col, vector<vector<bool > > &visited) {
   if (
        (newX >=0 && newX < row) &&
        (newY >=0 && newY < col) &&
        maze[newX][newY] == 1 &&
        visited[newX][newY] == false
        ) {
    return true;
   }
    else {
        return false;
    }
}

void printAllPath(int maze[][4], int row, int col, int srcX, int srcY, string &output, vector<vector<bool > > &visited) {
    //base case
    //destination coordinates are [row-1] , [col-1]

    if(srcX == row-1 && srcY == col-1) {
        cout << output << endl;    //destination reached
        return;
    }
    //one case you solved then recursion will handle the all

    // for UP Case
    int newX = srcX - 1;
    int newY = srcY;
    if(isSafe(srcX, srcY, newX, newY,maze,row,col,visited)) {
        visited[newX][newY] = true; //mark visited;
        output.push_back('U'); //append U to output string
        printAllPath(maze,row,col,newX,newY,output,visited); // call recursion
        output.pop_back();  //BACKTRACKING
        visited[newX][newY] = false;    //unmark visited
    }
    // for RIGHT Case
    newX = srcX;
    newY = srcY+1;
    if(isSafe(srcX, srcY, newX, newY,maze,row,col,visited)) {
        visited[newX][newY] = true; //mark visited;
        output.push_back('R');  //append R to output string
        printAllPath(maze,row,col,newX,newY,output,visited);  //Call RECURSION
        output.pop_back();  //BACKTRACKING
        visited[newX][newY] = false; //unmark visited
    }
    // for LEFT Case
    newX = srcX;
    newY = srcY - 1;
    if(isSafe(srcX, srcY, newX, newY,maze,row,col,visited)) {
        visited[newX][newY] = true; //mark visited;
        output.push_back('L');  //append U to output string
        printAllPath(maze,row,col,newX,newY,output,visited);    //Call RECURSION
        output.pop_back(); //BACKTRACKING
        visited[newX][newY] = false;    //unmark visited
    }
    // for DOWN Case
    newX = srcX+1;
    newY = srcY;
    if(isSafe(srcX, srcY, newX, newY,maze,row,col,visited)) {
        visited[newX][newY] = true; //mark visited;
        output.push_back('D');  //append U to output string
        printAllPath(maze,row,col,newX,newY,output,visited);    //Call RECURSION
        output.pop_back();  //BACKTRACKING
        visited[newX][newY] = false;    //unmark visited
    }
}

int main () {
    int maze[4][4] = {
        {1,0,0,0},
        {1,1,0,0},
        {1,1,1,0},
        {1,1,1,1}
    };
    int row = 4;
    int col = 4;

    int srcX = 0;
    int srcY = 0;
    string output = "";

    //create a visited 2d array
    vector<vector<bool> > visited(row, vector<bool>(col, false));

    if(maze[0][0] == 0) {
        //source position is closec so the rat can not move
        cout << "No paths existed" << endl;   
    }
    else{
        visited [srcX][srcY] = true;
        printAllPath(maze, row, col, srcX, srcY, output, visited);
    }

}