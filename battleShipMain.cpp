//
// Created by infan_000 on 10/28/2017.
//

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
char userBoard[10][10];
char aiBorad[10][10];
int randIncr = 0;
int playerShipPosition[5][2];
char playerShipOrientation[2];
void updatePlayArea() {
    system("CLS");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << userBoard[i][j] << " ";
        }
        cout << "\n";
    }
}
bool checkConflictsUser(int x, int y, int shipLength,char o = 'v', char lastShipOrientation = ' '){
    int vald = 0;
    int bruh = 0;
    switch(shipLength){
        case 3:
            bruh = 3;
            break;
        case 5:
            bruh = 4;
            break;
        default:
            bruh = 1 + randIncr;
    }
    if(o == 'v'){
        for(int i = 0; i < shipLength; i++){
            for(int j = 0; j < bruh; j++) {
                if(x == playerShipPosition[j][0] && y+i == playerShipPosition[j][1]){
                    vald = 1;
                    break;
                }
                if(shipLength == 5 && j<3){
                    if(lastShipOrientation == 'h'){
                        if(x == playerShipPosition[3][0]+j && y+i == playerShipPosition[3][1]){
                            vald = 1;
                            break;
                        }
                    }else if(lastShipOrientation == 'v'){
                        if(x == playerShipPosition[3][0] && y+i == playerShipPosition[3][1] + j){
                            vald = 1;
                            break;
                        }
                    }
                }
            }
            if(vald == 1){
                break;
            }
        }
        if(vald == 1){
            return true;
        }else{
            return false;
        }
    }else if(o == 'h'){
        for(int i = 0; i < shipLength; i++){
            for(int j = 0; j < bruh; j++) {
                if(x+i == playerShipPosition[j][0] && y == playerShipPosition[j][1]){
                    vald = 1;
                    break;
                }
                if(shipLength == 5 && j<3){
                    if(lastShipOrientation == 'h'){
                        if(x+i == playerShipPosition[3][0]+j && y == playerShipPosition[3][1]){
                            vald = 1;
                            break;
                        }
                    }else if(lastShipOrientation == 'v'){
                        if(x+i == playerShipPosition[3][0] && y == playerShipPosition[3][1] + j){
                            vald = 1;
                            break;
                        }
                    }
                }
            }
            if(vald == 1) {
                break;
            }
        }
        if(vald == 1){
            return true;
        }else{
            return false;
        }
    }
}

void inputPlayerShip(){
    string orient3("");
    string orient5("");
    cout<<"Enter ship starting coordinate for ship with 1 value: ";
    cin>>playerShipPosition[0][0]>>playerShipPosition[0][1];
    do {
        cout << "Enter ship starting coordinate for ship with 1 value: ";
        cin >> playerShipPosition[1][0] >> playerShipPosition[1][1];
    }while(checkConflictsUser(playerShipPosition[1][0], playerShipPosition[1][1], 1));
    randIncr++;
    do {
        cout << "Enter ship starting coordinate for ship with 1 value: ";
        cin >> playerShipPosition[2][0] >> playerShipPosition[2][1];
    }while(checkConflictsUser(playerShipPosition[2][0], playerShipPosition[2][1], 1));
    randIncr == 0;
    do {
        cout << "Enter ship starting coordinate for ship with 3 value: ";
        cin >> playerShipPosition[3][0] >> playerShipPosition[3][1];
        cout << "Enter orientation: ";
        cin >> orient3;
        if (orient3 == "vert") {
            playerShipOrientation[0] = 'v';
        } else if (orient3 == "hor") {
            playerShipOrientation[0] = 'h';
        }
    }while(checkConflictsUser(playerShipPosition[3][0], playerShipPosition[3][1], 3, playerShipOrientation[0]));
    do {
        bool valid = true;
        cout << "Enter ship starting coordinate for ship with 5 value: ";
        cin >> playerShipPosition[4][0] >> playerShipPosition[4][1];
        cout << "Enter orientation: ";
        cin >> orient5;
        if (orient5 == "vert") {
            playerShipOrientation[1] = 'v';
        } else if (orient5 == "hor") {
            playerShipOrientation[1] = 'h';
        }else{
            valid = false;
        }
        
    }while(checkConflictsUser(playerShipPosition[4][0], playerShipPosition[4][1], 5, playerShipOrientation[1], playerShipOrientation[0]) && valid == true);
}
void setPlayerShip(){
    system("CLS");
    userBoard[playerShipPosition[0][1] - 1][playerShipPosition[0][0] - 1] = 'l';
    userBoard[playerShipPosition[1][1] -1][playerShipPosition[1][0] - 1] = 'l';
    userBoard[playerShipPosition[2][1] - 1][playerShipPosition[2][0] - 1] = 'l';
    if(playerShipOrientation[0] == 'v'){
        userBoard[playerShipPosition[3][1] - 1][playerShipPosition[3][0] - 1] = 'l';
        userBoard[playerShipPosition[3][1]][playerShipPosition[3][0] - 1] = 'l';
        userBoard[playerShipPosition[3][1] + 1][playerShipPosition[3][0] - 1] = 'l';
    }else if(playerShipOrientation[0] == 'h'){
        userBoard[playerShipPosition[3][1] - 1][playerShipPosition[3][0] - 1] = 'l';
        userBoard[playerShipPosition[3][1] - 1][playerShipPosition[3][0]] = 'l';
        userBoard[playerShipPosition[3][1] - 1][playerShipPosition[3][0] + 1] = 'l';
    }
    if(playerShipOrientation[1] == 'v'){
        userBoard[playerShipPosition[4][1] - 1][playerShipPosition[4][0] - 1] = 'l';
        userBoard[playerShipPosition[4][1]][playerShipPosition[4][0] - 1] = 'l';
        userBoard[playerShipPosition[4][1] + 1][playerShipPosition[4][0] - 1] = 'l';
        userBoard[playerShipPosition[4][1] + 2][playerShipPosition[4][0] - 1] = 'l';
        userBoard[playerShipPosition[4][1] + 3][playerShipPosition[4][0] - 1]= 'l';
    }else if(playerShipOrientation[1] == 'h'){
        userBoard[playerShipPosition[4][1] - 1] [playerShipPosition[4][0] - 1]= 'l';
        userBoard[playerShipPosition[4][1] - 1] [playerShipPosition[4][0]]= 'l';
        userBoard[playerShipPosition[4][1] - 1] [playerShipPosition[4][0] + 1]= 'l';
        userBoard[playerShipPosition[4][1] - 1] [playerShipPosition[4][0] + 2]= 'l';
        userBoard[playerShipPosition[4][1] - 1] [playerShipPosition[4][0] + 3]= 'l';
    }
}
void createUserBoard(){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j<10; j++){
            userBoard[i][j] = 'o';
        }
    }
}
void createAiBoard(){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            aiBorad[i][j] = 'o';
        }
    }
}
int main(){

    createUserBoard();
    createAiBoard();
    inputPlayerShip();
    setPlayerShip();
    updatePlayArea();
    return 0;
}