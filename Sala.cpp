#include "Sala.h"

Sala::Sala(char cod) 
{
    codice = cod;
    disponibilita_posti = new boolean[Cinema.N_FILE][Cinema.N_POLTRONE];
    for(int i = 0; i < Cinema.N_FILE; i++)
    {
        for(int j = 0; j < Cinema.N_POLTRONE; j++)
        {
            disponibilita_posti[i][j] = true;
        }
    }
}

Sala::~Sala() {
}
       
int Sala::CountPostiDisponibili()
{
    int count = 0;
    for(int i = 0; i < Cinema.N_FILE; i++)
    {
        for(int j = 0; j < Cinema.N_POLTRONE; j++)
        {
            count += disponibilita_posti[i][j] ? 1 : 0;
        }
    }
    return count;
}
    
Posto Sala::occupaPosto()  
{
    for(int i = 0; i < Cinema.N_FILE; i++)
    {
        for(int j = 0; j < Cinema.N_POLTRONE; j++)
        {
            if(disponibilita_posti[i][j]) 
            {
                disponibilita_posti[i][j] = false;
                Posto posto = new Posto();
                posto.fila = i;
                posto.poltrona = j;
                return posto;
            }
        }
    }
    return null;
}
    
void Sala::liberaPosto(int fila, int poltrona)
{
    disponibilita_posti[fila][poltrona] = true; 
}
