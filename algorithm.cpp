
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <vector>


#define clrscr(){ system("@cls||clear"); }

//https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm#:~:text=Bresenham's%20line%20algorithm%20is%20a,straight%20line%20between%20two%20points.
void setVectorPositions(std::vector<int*>* vec, int* pos1, int* pos2) {
    // positions
    int x1 = pos1[0], y1 = pos1[1];
    int x2 = pos2[0], y2 = pos2[1];
    
    //distance
    int dx = abs(x2 - x1), dy = abs(y2 - y1);

    //direction 
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    int err = dx - dy;

    // sub x1 and y1 until they equal to startPositions
    while (x1 != x2 || y1 != y2) {
        //add value
        int* posN = (int*)malloc(sizeof(int) * 2);
        posN[0] = x1;
        posN[1] = y1;
        vec->push_back(posN);

        //set value
        int e2 = 2 * err;
        // a * dy < dx when a is odd
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        //a * dx < dy when a in odd
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}


int main(){
    clrscr();
    //line
    std::vector<int*> pos;
    int pos1[2] = {20, 10}; int pos2[2] = {12, 13};
    int pos3[2] = {12, 20}; int pos4[2] = {23, 13};
    setVectorPositions(&pos, pos1, pos3);


    int i = 20;
    while(true){//play frames
        i++;
        if (i > 100) i = 0;


        printf("\x1b[H");
        printf("\n\n%d\n\n", i);
        //screan
        for (int y = 0; y < 20; y++){
            for (int x = 0; x < 40; x++){
                //positions
                bool b = false; 
                for (int i = 0; i < pos.size(); i++){
                    if(pos[i][0] == x && pos[i][1] == y) b = true;
                }
                if(b) printf(" ");
                else printf("0");
            }
            printf("\n");
        }
        
        usleep(1000 * 1000 * 1);
    }
    return 0;
}