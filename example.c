#include "counterpoint.c"

void makeCounterpoint(){
    int cantusFirmus[11] = {1, 3, 2, 1, 4, 3, 5, 4, 3, 2, 1};
    step steps[10];
    for(int i = 0; i < 10; i++){
        steps[i].fromNote.pitch = cantusFirmus[i];
        steps[i].toNote.pitch = cantusFirmus[i+1];
        if(steps[i].fromNote.pitch == 1 || steps[i].fromNote.pitch == 5 || steps[i].fromNote.pitch == 8){
            steps[i].fromNote.consonance = 1;
            steps[i].fromNote.perfect = 1;
        }
        else if(steps[i].fromNote.pitch == 3 || steps[i].fromNote.pitch == 6){
            steps[i].fromNote.consonance = 1;
            steps[i].fromNote.perfect = 0;
        }
        
        if(steps[i].toNote.pitch == 1 || steps[i].toNote.pitch == 5 || steps[i].toNote.pitch == 8){
            steps[i].toNote.consonance = 1;
            steps[i].toNote.perfect = 1;
        }
        else if(steps[i].toNote.pitch == 3 || steps[i].toNote.pitch == 6){
            steps[i].toNote.consonance = 1;
            steps[i].toNote.perfect = 0;
        }

        if(cantusFirmus[i] < cantusFirmus[i+1]){
            steps[i].direction = 1;
            steps[i].interval = cantusFirmus[i+1] - cantusFirmus[i];
        }
        else{
            steps[i].direction = 0;
            steps[i].interval = cantusFirmus[i] - cantusFirmus[i+1];
        }
        
    }
    int counterPoint[11];
    counterPoint[0] = 5;
    for(int i = 1; i < 11; i++){
        if(steps[i-1].toNote.consonance && steps[i-1].toNote.perfect){
            // contrary or oblique motion only
            if(steps[i-1].direction){ // CF goes up
                if(arc4random()%2 == 0)
                    counterPoint[i] = counterPoint[i-1] - 1;  // CP goes down, contrary
                else
                    counterPoint[i] = counterPoint[i-1];      // CP stays same, oblique
            }
            if(!steps[i-1].direction){ // CF goes down
                if(arc4random()%2 == 0)
                    counterPoint[i] = counterPoint[i-1] + 1;  // CP goes up, contrary
                else
                    counterPoint[i] = counterPoint[i-1];      // CP stays same, oblique
            }
        }
        else {
            // any 3 movements permitted
            if(arc4random()%3 == 0)
                counterPoint[i] = counterPoint[i-1] + 1;  // CP goes up
            else if(arc4random()%2 == 0)
                counterPoint[i] = counterPoint[i-1] - 1;  // CP goes down
            else
                counterPoint[i] = counterPoint[i-1];      // CP stays same, oblique
        }
        
        if(steps[i].fromNote.consonance && steps[i].toNote.consonance){
            
        }
        else if(!steps[i].fromNote.consonance && steps[i].toNote.consonance){
            
        }
        else if(steps[i].fromNote.consonance && !steps[i].toNote.consonance){
            
        }
        else if(!steps[i].fromNote.consonance && !steps[i].toNote.consonance){
            
        }
    }
    printf("  ");
    for(int i = 0; i < 10; i++){
        if(steps[i].direction) printf("+");
        else                   printf("-");
        printf("%d ",steps[i].interval);
    }
    printf("\ncantus firmus:\n");
    for(int i = 0; i < 11; i++)
        printf(" %d ",cantusFirmus[i]);
    printf("\ncounterpoint:\n");
    for(int i = 0; i < 11; i++)
        printf(" %d ",counterPoint[i]);
    printf("\n\n");

}