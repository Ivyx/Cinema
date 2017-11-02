#include "Prenotazione.h"

Prenotazione::Prenotazione(Sala sala, int fila, int poltrona, int codiceControllo)  {
    this.sala = sala;
    this.fila = fila;
    this.poltrona = poltrona;
    this.codice_controllo = codiceControllo;
    this.stato_prenotazione = false;
}

Prenotazione::~Prenotazione() {
}

    /**
     * Cambia lo stato di prenotazione da NON ACQUISTATO  ad ACQUISTATO
     * @throws Exception Se la prenotazione risulta già acquistata
     */
     
void Prenotazione::acquistaBiglietto()throws Exception 
{
        if(!stato_prenotazione)
            stato_prenotazione = true;
        else
            throw new Exception("Prenotazione già acquistata");
}
    
void Prenotazione::stampa()  
{
    System.out.println("Posto prenotato\nSala \""+ sala.codice +  "\", [fila: " + (fila + 1) + ", poltrona: " + (poltrona + 1) + "]" );
    System.out.println("codice controllo :[" + (codice_controllo) + "]" );
    System.out.println("stato prenotazione :[" + (stato_prenotazione ? "ACQUISTATO" : "NON ACQUISTATO") + "]" );
}
