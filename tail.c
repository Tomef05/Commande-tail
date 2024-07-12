#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"

FILE* init_fic(char* fichier, char* mode);
int count_line(char* fichier);
void display(char* fichier,int nb_ligne,int nb_arg,char* args[]);

int main(int nb_arg, char* args[]) {
    FILE* f = init_fic(args[1], args[2]);
    char line[256];
    int nb_ligne = count_line(args[1]);
    
    display(args[1],nb_ligne,nb_arg,args);


    fclose(f);
    return 0;
}

FILE* init_fic(char* fichier, char* mode) {
    FILE* f = fopen(fichier,mode);
    if(f == NULL) {
        printf("Erreur\n");
        return NULL;
    }
}

int count_line(char* fichier) {
    int compt;
    char line[256];
    FILE* fic = init_fic(fichier,"r");

    for(compt = 1; feof(fic) != 1; compt++) {
        fgets(line,255,fic);
    }

    fclose(fic);
    return(compt - 1);
}

void display(char* fichier,int nb_ligne,int nb_arg,char* args[]) {
    int compt;
    char line[256];
    FILE* fic = init_fic(fichier,"r");

    if(nb_arg != 3) {
        for(compt = 1; compt < count_line(fichier); compt++) {
        
        if(compt == (count_line(fichier) - atoi(args[3]))) {
            for(compt = compt; compt < count_line(fichier); compt++) {
                fgets(line,255,fic);
                printf("%s",line);
            }
        }

        fgets(line,255,fic);
        }
        fclose(fic);
    } else {
        for(compt = 1; compt < count_line(fichier); compt++) {
        
        if(compt == (count_line(fichier) - 10)) {
            for(compt = compt; compt < count_line(fichier); compt++) {
                fgets(line,255,fic);
                printf("%s",line);
            }
        }

        fgets(line,255,fic);
    }
    fclose(fic);
    }
}
