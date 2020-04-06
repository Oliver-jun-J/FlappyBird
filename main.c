#include "Header"

void draw(int way[20][100]){
    printf("------------------------------------------------------------------------------------------------\n");
    for(int i=1;i<=20;i++){
        for(int j=1;j<=100;j++){
            if(way[i-1][j-1]==1){
                printf("*");
            }
            if(way[i-1][j-1]==0){
                printf(" ");
            }
            if(j==100){
                printf("\n");
            }
        }
        if(i==20){
            printf("------------------------------------------------------------------------------------------------\n");
        }
    }
}

void ini(int way[20][100]){
    for(int i=1;i<=20;i++){
        for(int j=1;j<=100;j++){
            way[i-1][j-1]=0;
        }
    }
}

int pipe(int bor[20][100]){
    int a=time(NULL);
    int b=0;
    int end=0;
    srand(a);
    b=rand()%10;
    for(int i=1;i<=b;i++){
        bor[i][99]=1;
    }
    for(int i=b+9;i<=19;i++){
        bor[i][99]=1;
    }
    return b;
}

void move(int way[20][100]){
    for(int i=1;i<=20;i++){
        for(int j=1;j<=99;j++){
            way[i-1][j-1]=way[i-1][j];
        }
    }
    for(int i=1;i<=20;i++){
        way[i-1][99]=way[i-1][98];
    }
}

void emove(int way[20][100]){
    for(int i=1;i<=20;i++){
        for(int j=1;j<=99;j++){
            way[i-1][j-1]=way[i-1][j];
        }
    }
    for(int i=1;i<=20;i++){
        way[i-1][99]=0;
    }
}

void fly(int bor[20][100]){
    int end=0;
    int count=0;
    int floor=6;
    int t=100;
    int ch;
    double timef;
    int round=0;
    int backg[20][100];
    int score=0;
    int add=0;


    while(end==0){
        move(backg);
        for(int i=8;i<=11;i++){
            for(int j=floor;j<=floor+2;j++){
                bor[j][i]=1;
            }
        }
        if(round>=11){
            for(int i=1;i<=20;i++){
                backg[i-1][99]=0;
            }
            pipe(backg);
            round=0;
        }
        if(round>=2&&round<11){
            emove(backg);
        }
        if(round<2){
            move(backg);
        }

        draw(bor);
        printf("Your Score is: %d\n",score);
        for(int i=floor;i<=floor+2;i++){
            for(int j=8;j<=11;j++){
                if(bor[i][j]==backg[i][j]&&bor[i][j]==1){
                    end=1;
                }
            }
        }
        for(int i=1;i<=20;i++){
            for(int j=1;j<=100;j++){
                bor[i-1][j-1]=backg[i-1][j-1];
            }
        }
        floor=floor+1;
        count=count+1;
        round=round+1;
        if(bor[0][10]==1&&bor[0][11]==0){
            score=score+1;
            add=1;
        }
        if(add==0&&bor[19][10]==1&&bor[19][11]==0){
            score=score+1;
        }
        add=0;
        timef=sqrt(count)-sqrt(count-1);
        Sleep(timef*t);
        system("cls");
        if(_kbhit()){
            ch=getch();
            if(ch==32){
                floor=floor-2;
                count=0;
            }
        }
        if(floor>=17||floor<=0){
            end=1;
        }

    }
    Sleep(150);
    printf("Game Over, Your Fianl Score is: %d. Try again next time!!\nPress 0 to exit.\n",score);

}

int main() {
    int board[20][100];
    int exit;
    fly(board);
    exit=getch();
    if(exit==0){
        return 0;
    }

}