#include <stdio.h>
#include <stdlib.h>
int ruleset();
int second_rules();

int main(int argc, char **argv){
    int cells, i,generations, wolfram, * cell_count, *second,rule;
    for (i=1;i<4;i++){
        if(atoi(argv[i])==1){
            return 1;
        }
    }
    cells = strtol(argv[1],NULL,10);
    generations = strtol(argv[2],NULL,10);
    wolfram = strtol(argv[3],NULL,10);
    
    cell_count = calloc(cells, sizeof(int));
    second = calloc(cells, sizeof(int));

    if (argc != 4){
        return 1;
    }
        

    if (cells <= 0.0 || generations <= 0.0 || wolfram <= 0.0 || wolfram > 255){
        return 1;
    }
        
   
    rule = cells/2;
    cell_count[rule] = 1;
    second_rules(wolfram,cell_count,second,generations,cells);
    free(cell_count);
    free(second);    

    return 0;
}

int second_rules(int wolfram,int * cell_count, int * second,int generations,int cells ){
    int i,xloop,x,y,z,final;
    for (i=0; i<generations; i++){        
        for (xloop=0; xloop<cells; xloop++){
            if (cell_count[xloop]==0)
                printf(" ");
            if (cell_count[xloop]==1)
                printf("*");
        }
        for (xloop=0; xloop<cells; xloop++){
            if (xloop==0){
                x = cell_count[cells-1];
                y = cell_count[xloop];
                z = cell_count[xloop+1];
            }
            if (xloop==cells-1){
                x = cell_count[xloop-1];
                y = cell_count[xloop];
                z = cell_count[0];
            }
            if (xloop!=cells-1 && xloop != 0){
                x = cell_count[xloop-1];
                y = cell_count[xloop];
                z = cell_count[xloop+1];                
            }   

            final = ruleset(wolfram,x,y,z);
            second[xloop] = final;
                        
        }
        for (xloop=0; xloop<cells; xloop++)    
            cell_count[xloop] = second[xloop];
        
        printf("\n");
    }
    return 0;
}


int ruleset(int wolfram,int x,int y,int z){
    int i, binary[8],count,value;
    count = 0;
    value = 0;
    for(i=0; wolfram>0 ; i++){    
        binary[i] = wolfram%2;    
        wolfram=wolfram/2;    
        count++;
        value++;
    };

    
    for (i=0;i<(8-count);i++){
        binary[value] = 0;
        value++;

    }

    if (x==1 && y == 1 && z==1){
        return(binary[7]);
    }

    if (x==1 && y == 1 && z==0){
        return(binary[6]);
    }

    if (x==1 && y == 0 && z==1){
        return(binary[5]);
    }

    if (x==1 && y == 0 && z==0){
        return(binary[4]);
    }

    if (x==0 && y == 1 && z==1){
        return(binary[3]);
    }

    if (x==0 && y == 1 && z==0){
        return(binary[2]);
    }

    if (x==0 && y == 0 && z==1){
        return(binary[1]);
    }

    if (x==0 && y == 0 && z==0){
        return(binary[0]);
    }
    return(2000);

}

