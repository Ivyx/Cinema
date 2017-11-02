#include "Cinema.h"
#include "Prenotazione.h"

using namespace std;

Cinema::Cinema() 
{
        sale = new Sala[N_SALE];
        //Creo e istanzio le 4 sale del cinema
        sale[0] = new Sala('A');
        sale[1] = new Sala('B');
        sale[2] = new Sala('C');
        sale[3] = new Sala('D');
        
        prenotazioni = new Prenotazione[N_PRENOTAZIONI];
}

Cinema::~Cinema() {
}

void static Cinema::printMenu()
    {
        cout << "\n\n" << endl;
        cout << "\t1: stampa disponibilità posti"<< endl;
        cout << "\t2: nuova prenotazione"<< endl;
        cout << "\t3: cancella prenotazione"<< endl;
        cout << "\t4: stampa prenotazione"<< endl;
        cout << "\t\t0: esci"<< endl;
    }

int Cinema::getNextCodice()
{
    double numb;
       do
       {
           numb = Math.floor((MAX_COD_PRENOTAZIONE - MIN_COD_PRENOTAZIONE + 1) * Math.random() ) + MIN_COD_PRENOTAZIONE;
       }
       while(isPrenotazione((int)numb));

       return (int)numb;
}

bool Cinema::isPrenotazione(int codice)
{
    int i = 0;
    
    while(prenotazioni[i] != null && i < N_PRENOTAZIONI)
    {
        if(prenotazioni[i].codice_controllo == codice)
           {
               return true;
           }
           i++;
    }
    return false;
}

Sala Cinema::getSala(char codice)
{
    int i = 0;
    
    while(sale[i] != null && i < N_SALE)
    {
        if(sale[i].codice == codice)
        {
            return sale[i];
        }
        i++;
    }
    return null;
}

void Cinema::stampaPosti()
{
    for(Sala s : sale)
        {
            System.out.println("Sala [" + s.codice + "] posti disponibili: " + 
                    s.CountPostiDisponibili() + "/" + Cinema.N_POSTI);
        }
}

bool Cinema::prenotaBiglietto(char codice_sala)
{
    Sala sala = getSala(codice_sala);
        if(sala == null)
            throw new Exception("Codice sala errato.");
        
        Sala.Posto newPosto = sala.occupaPosto();
        if(newPosto == null)
        {
            return false;
        }
        else
        {
            int newCodiceControllo = getNextCodice();
            int i = 0;
            while(prenotazioni[i] != null && i < N_PRENOTAZIONI)
                i++;
            prenotazioni[i] = new Prenotazione(sala, newPosto.fila, newPosto.poltrona, newCodiceControllo);
            prenotazioni[i].stampa();
        }
        return true;
    }
    
int Cinema::getIndexPrenotazione(int codice) throws Exception
    {
        int i = 0;
        while(prenotazioni[i] != null && i < N_PRENOTAZIONI)
        {
            if(prenotazioni[i].codice_controllo == codice)
            {
                return i;
            }
            i++;
        }
        throw new Exception("Prenotazione con codice " + codice + " inesistente.");
    }
    
bool Cinema::cancellaPrenotazione(int codice)
    {
        try 
        {
            int index = getIndexPrenotazione(codice);
            prenotazioni[index].sala.liberaPosto(prenotazioni[index].fila, prenotazioni[index].poltrona);
            prenotazioni[index] = null;
            return true;
        } 
        catch (Exception ex) {
            return false;
        }
}

bool Cinema::acquistaPrenotazione(int codice)
{
    try 
    {
        int index = getIndexPrenotazione(codice);
        prenotazioni[index].acquistaBiglietto();
        prenotazioni[index].stampa();
        return true;
    } 
    catch (Exception ex) {
        return false;
    }
}
