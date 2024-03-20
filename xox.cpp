#include <iostream>
using namespace std;
    

int main(){
    int table[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    bool game_finished = false;
    char input;
    bool invalid = false;
    bool turn = true; //true X false O
    int drawCheck = 0; // if = 9 => draw
    bool gameWon = false;
    int winCheck = 1;
    while (!game_finished){
        //printing the tables
        for (int i = 0; i < 3; i++){
            cout << "-------    -------" << endl;
            cout << "|";
            for (int j = 0; j < 3; j++){
                if (table[i][j] == 1){
                    cout << "X";
                }else if (table[i][j] == 2){
                    cout << "O";
                }else{
                    cout << " ";
                }
                cout << "|";
            }
            cout << "    " ;
            cout << "|";
            for (int j = 0; j < 3; j++){
                
                cout << j + 3*i+1;
                cout << "|";
            }
            cout << endl;
        }
        cout << "-------    -------" << endl;   
        //print end
        cout << "Turn of : " ;
        if (turn){ //turn => true X false
            cout << "X";
            winCheck = 1;
        }else{
            cout << "O";
            winCheck = 2;
        }
        cout << endl;
        
        cout << "Type the position: " ;
        cin >> input;


        

        switch (input){ //turn => true X false O X => 1 O => 2
        case '1':
            if (table[0][0] != 0){
                cout << "Already taken!" << endl;
                invalid = true;
                break;
            }
            if (turn){
                table[0][0] = 1;
            }else{
                table[0][0] = 2;
            }
            /*
                T11
                32O
                3O2
            */
            if ((table[0][1] == winCheck && table[0][2] == winCheck) || //condition marked with 1
                (table[1][1] == winCheck && table[2][2] == winCheck) || //cmw 2
                (table[1][0] == winCheck && table[2][0] == winCheck)){  //cmw 3
                gameWon = true;
            }
            
            break;
        case '2':
            if (table[0][1] != 0){
                cout << "Already taken!" << endl;
                invalid = true;
                break;

            }
            if (turn){
                table[0][1] = 1;
            }else{
                table[0][1] = 2;
            }
            /*
                1T1
                O2O
                O2O
            */
            if ((table[0][0] == winCheck && table[0][2] == winCheck) || //condition marked with 1
                (table[1][1] == winCheck && table[2][1] == winCheck)){  //cmw 2
                gameWon = true;
            }
            break;
        case '3':
            if (table[0][2] != 0){
                cout << "Already taken!" << endl;
                invalid = true;
                break;
            }
            if (turn){
                table[0][2] = 1;
            }else{
                table[0][2] = 2;
            }
            /*
                11T
                O23
                2O3
            */
            if ((table[0][0] == winCheck && table[0][1] == winCheck) || //condition marked with 1
                (table[1][1] == winCheck && table[2][0] == winCheck) || //cmw 2
                (table[1][2] == winCheck && table[2][2] == winCheck)){  //cmw 3
                gameWon = true;
            }         
            break;
        case '4':
            if (table[1][0] != 0){
                cout << "Already taken!" << endl;
                invalid = true;
                break;
            }
            if (turn){
                table[1][0] = 1;
            }else{
                table[1][0] = 2;
            }
            /*
                1OO 
                T22
                1OO
            */
            if ((table[0][0] == winCheck && table[2][0] == winCheck) || //condition marked with 1
                (table[1][1] == winCheck && table[1][2] == winCheck)){  //cmw 2
                gameWon = true;
            }     
            break;
        case '5':
            if (table[1][1] != 0){
                cout << "Already taken!" << endl;
                invalid = true;
                break;
            }
            if (turn){
                table[1][1] = 1;
            }else{
                table[1][1] = 2;
            }     
            /*
                123
                4T4
                321
            */
            if ((table[0][0] == winCheck && table[2][2] == winCheck) || //condition marked with 1
                (table[0][1] == winCheck && table[2][1] == winCheck) || //cmw 2
                (table[0][2] == winCheck && table[2][0] == winCheck) || //cmw 3
                (table[1][0] == winCheck && table[1][2] == winCheck)){  //cmw 4
                gameWon = true;
            }                          
            break;
        case '6':
            if (table[1][2] != 0){
                cout << "Already taken!" << endl;
                invalid = true;
                break;
            }
            if (turn){
                table[1][2] = 1;
            }else{
                table[1][2] = 2;
            } 
            /*
                OO1 
                22T
                OO1
            */
            if ((table[0][2] == winCheck && table[2][2] == winCheck) || //condition marked with 1
                (table[1][0] == winCheck && table[1][1] == winCheck)){  //cmw 2
                gameWon = true;
            }                    
            break;
        case '7':
            if (table[2][0] != 0){
                cout << "Already taken!" << endl;
                invalid = true;
                break;
            }
            if (turn){
                table[2][0] = 1;
            }else{
                table[2][0] = 2;
            }                  
            /*
                1O3 
                13O
                T22
            */
            if ((table[0][0] == winCheck && table[1][0] == winCheck) || //condition marked with 1
                (table[1][1] == winCheck && table[0][2] == winCheck) || //cmw 3
                (table[2][1] == winCheck && table[2][2] == winCheck)){  //cmw 2
                gameWon = true;
            } 
            break; 
        case '8':
            if (table[2][1] != 0){
                cout << "Already taken!" << endl;
                invalid = true;
                break;
            }
            if (turn){
                table[2][1] = 1;
            }else{
                table[2][1] = 2;
            }
            /*
                O1O 
                O1O
                2T2
            */
            if ((table[0][1] == winCheck && table[1][1] == winCheck) || //condition marked with 1
                (table[2][0] == winCheck && table[2][2] == winCheck)){  //cmw 2
                gameWon = true;
            }                 
            break;
        case '9':
            if (table[2][2] != 0){
                cout << "Already taken!" << endl;
                invalid = true;
                break;
            }
            if (turn){
                table[2][2] = 1;
            }else{
                table[2][2] = 2;
            }
            /*
                3O1 
                O31
                22T
            */
            if ((table[0][2] == winCheck && table[1][2] == winCheck) || //condition marked with 1
                (table[2][0] == winCheck && table[2][1] == winCheck) || //cmw 2
                (table[0][0] == winCheck && table[1][1] == winCheck)){  //cmw 3
                gameWon = true;
            }                               
            break;
        default:
            cout << "Invalid output!" << endl;
            invalid = true;
            break;
        }

        //check for invalid input
        if (!invalid && !gameWon){
            turn = !turn;
            drawCheck++;            
        }else{
            invalid = !invalid;
        }

        if (gameWon){
            game_finished = true;
            for (int i = 0; i < 3; i++){
            cout << "-------" << endl;
            cout << "|";
                for (int j = 0; j < 3; j++){
                    if (table[i][j] == 1){
                        cout << "X";
                    }else if (table[i][j] == 2){
                        cout << "O";
                    }else{
                        cout << " ";
                    }
                    cout << "|";
                }            
                cout << endl;
            }
            cout << "-------" << endl;
            if (turn){
                cout << "X wins!";
            }else{
                cout << "O wins!";
            }

        }else if (drawCheck == 9){ //check for draw
            game_finished = true;
            for (int i = 0; i < 3; i++){
            cout << "-------" << endl;
            cout << "|";
                for (int j = 0; j < 3; j++){
                    if (table[i][j] == 1){
                        cout << "X";
                    }else if (table[i][j] == 2){
                        cout << "O";
                    }else{
                        cout << " ";
                    }
                    cout << "|";
                }            
                cout << endl;
            }
            cout << "-------" << endl;
            cout << "Draw!" << endl;
        }
        
    }
    
    
    return 0;
}
