#ifndef PRENOTAZIONE_H
#define PRENOTAZIONE_H

class Prenotazione {
public:
    
    Prenotazione(Sala, int, int, int);
    virtual ~Prenotazione();
    int fila;
    int poltrona;
    int codice_controllo;
    void stampa();
    
protected:
        
    Sala sala;
    void acquistaBiglietto();
    
private:
    
    bool stato_prenotazione;
};

#endif /* PRENOTAZIONE_H */
