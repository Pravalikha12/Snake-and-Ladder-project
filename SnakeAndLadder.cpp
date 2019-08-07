#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void disp_rules();
void disp1_status(int,int);
void disp_status(int,int);
int roll_the_dice();
int jump(int);
int play(int);
int disp(int);
int disp1(int);
void admin_board();
void board_init();
void user_board_values();
void create_board();
void disp_board();
void choose_player();
void invalid_entry(char k);


int *board,turn=0,n,player1,player2,roll,snakes[10][2],ladders[10][2],s,l,rows,columns;

void disp_rules(){
    printf("\tThe rules are simple:\n");
    printf("\t1. Each player should roll one die to see who gets the highest number.\n");
    printf("\t2. Whoever rolls the highest number gets to take the first turn.\n");
    printf("\t3. If two or more people roll the same number, and it is the highest number rolled,\n\t   each of those people roll the die an additional time to see who gets to go first.\n");
    printf("\t4. Players take turns to roll a dice and move along the number of squares rolled.\n");
    printf("\t5. If a player lands on a square which has the base of a ladder upn t then he will move up to the top of the ladder.\n");
    printf("\t6. If he lands on a square which has the head of a snake upon it then he will move down to the tail of the snake.\n");
    printf("\t7. The first person to reach the highest square on the board wins\n");
}

void disp_status(int l,int r){
    int i;
    for(i=l;i>r;i--){
        if(i!=player1&&i!=player2){
            if(board[i] == i){
                printf("________");
            }
            else{
                if(i>board[i])
                    printf("_____$%d",board[i]);
                else
                    printf("_____L%d",board[i]);                    
            }
        }
        else{
            if(player1!=player2){
                if(i==player1)
                    printf("_______A");
                else
                    printf("_______B");
            }
            else{
                printf("______AB");
            }
        }
    }
}

void disp1_status(int l,int r){
    int i;
    for(i=l;i<r;i++){
        if(i!=player1&&i!=player2){
            if(board[i] == i){
                printf("________");
            }
            else{
                if(i>board[i])
                    printf("_____$%d",board[i]);
                else
                    printf("_____L%d",board[i]);                    
            }
        }
        else{
               if(player1!=player2){
                   if(i==player1)
                        printf("_______A");
                    else
                        printf("_______B");
                }
            else{
                   printf("______AB");
               }
        }
       }
}


int roll_the_dice(){
    int j = (rand()%6)+ 1 ;
    printf("You rolled %d!\n",j);
    return j;
}


int jump(int player){
    if((player+roll)<n){
        player = board[player+roll];
    }
    else{
        int temp;
        temp = (player+roll)-(n-1);
        player = board[(n-1) - temp];
    }
    return player;
}

int play(int player){
    char k;
    printf("\n______player %d 's turn______\nPress ‘y’ to roll the die: ",turn+1);
    scanf(" %c",&k);
    invalid_entry(k);
    roll = roll_the_dice();
    while(roll==6){
        printf("\nCongratulations, you get to roll again!\n");
        if(turn==0){
            player = player1 = jump(player);
            disp_board();
        }
        else{
            player = player2 = jump(player);
            disp_board();
        }
        printf("\n______player %d 's turn______\nPress ‘y’ to roll the die: ",turn+1);
        scanf(" %c",&k);
        invalid_entry(k);
        roll = roll_the_dice();        
    }
    if(roll!=6){
        if((player+roll)<n){
            player = board[player + roll];
        }
        else{
            if(turn==0){
                player = player1 = jump(player);
            }
            else{
                player = player2 = jump(player);
            }
        }
    }
    if(player == n-1){
        if(turn==0)
            player1 = n-1;
        else
            player2 =n-1;
    }
    turn = 1 - turn;
    return player;
}

void invalid_entry(char k){
    if(k!='y'){
            printf("Invalid entry!");
            exit(0);
    }
}

void board_init(){
    int i;
    n=(rows*columns)+1;
    board = (int*)malloc(n * sizeof(int));
    for(i=1;i<n;i++){
        board[i]=i;
    }
}

void user_board_values(){
    int i;
    printf("Enter the dimension of the board: ");
    scanf("%d%d",&rows,&columns);
    printf("Enter the number of snakes: ");
    scanf("%d",&s);
    printf("Enter the number of ladders: ");
    scanf("%d",&l);
    if(l!=0 && s!=0){ 
    printf("Enter the head and tail of the snakes:\n");
    for(i=0;i<s;i++){
        printf("Snake %d: ",i+1);
        scanf("%d%d",&snakes[i][0],&snakes[i][1]);
    }
    printf("Enter the top end and bottom end of the ladder:\n");
    for(i=0;i<l;i++){
        printf("Ladder %d: ",i+1);
        scanf("%d%d",&ladders[i][0],&ladders[i][1]);
    }
    }
    else{
        printf("Atleast one snake and ladder must be included\n");
        user_board_values();
    }
}

void create_board(){
    int i;
    board_init();
    for(i=0;i<s;i++){
        board[snakes[i][0]] = snakes[i][1];
    }
    for(i=0;i<l;i++){
        board[ladders[i][0]] = ladders[i][1];
    }
}

void disp_board(){
    int iter = rows*columns;
    int i;
    if(rows%2 != 0){
        while(iter>0){
            if(iter>0){
                iter =    disp(iter);                
            }
            if(iter>0){
                iter = disp1(iter);
            }
        }
    }
    else{
        while(iter>0){
            if(iter>0){
                iter =    disp1(iter);                
            }
            if(iter>0){
                iter = disp(iter);
            }
        }
    }
}

int disp(int iter){
    int i;
    disp1_status(iter-columns+1,iter+1);
    printf("\n");
    for(i= iter-columns+1;i<=iter;i++)
            printf("%8d",i);
    printf("\n");
    
    return iter-columns;
}

int disp1(int iter){
    int i;
    disp_status(iter,iter-columns);
    printf("\n");
    for(i = iter;i>=iter-columns+1;i--){
            printf("%8d",i);        
    }
    printf("\n");
    
    return i;
}

void admin_board(){
    rows=columns=10;
    board_init();
    board[4] = 14;
    board[62] = 19;
    board[21] = 42;
    board[87] = 36;
    board[28] = 84;
    board[54] = 35;
    board[51] = 67;
    board[93] = 73;
    board[72] = 91;
    board[95] = 75;
    board[80] = 99;
    board[98] = 79;
}

void choose_player(){
    char k;
    int roll1,roll2;
    turn  = 0;
    printf("\n______player %d 's turn______\nPress ‘y’ to roll the die: ",turn+1);
    scanf(" %c",&k);
    invalid_entry(k);
    roll1 = roll_the_dice();
    turn = 1-turn;
    printf("\n______player %d 's turn______\nPress ‘y’ to roll the die: ",turn+1);
    scanf(" %c",&k);
    invalid_entry(k);
    roll2 = roll_the_dice();
    turn = 1-turn;
    if(roll1>roll2){
        player1=roll1;
        turn = 1;
    }
    else if(roll2>roll1){
        player2=roll2;
        turn = 0;
    }
    else{
        choose_player();
    }
    printf("Player %d gets the first turn!\n",(1-turn)+1);
}

int main(){
    srand(time(0));
    int ch,choice;
    printf("\n_______Welcome to Snake and Ladders_______\n");
    do{
        printf("\n_______Would you like to \n\t\t1.Read the rules \n\t\t2.Play the game\n\t\t3.Exit\nEnter your choice: ");
        scanf("%d",&ch);
        if(ch==1){
            disp_rules();
        }
        else if(ch == 2){
            printf("\n1. Use Admin Board\n2. Create Your own Board\nEnter your choice: ");
            scanf("%d",&choice);
            if(choice==1){
                admin_board();
            }
            else if(choice==2){
                user_board_values();
                create_board();
            }
            else
                break;
                printf("To decide the first player to roll the die: \n");
            choose_player();
            disp_board();
            while(1){
                if(player1 < n ){
                    if(turn==0){
                        player1 = play(player1);
                        disp_board();
                        if(player1==n-1){
                            printf("Player A Won!\n");
                            break;
                        }
                    }
                }
                if(player2 < n){
                    if(turn==1){
                        player2 = play(player2);
                        disp_board();
                        if(player2==n-1){
                            printf("Player B Won!\n");
                            break;
                        }
                    }
                }
                else
                    break;
            }
            printf("______Game ends______\n");
        }
        else
            break;
    }while(ch!=3);
    return 0;
}




