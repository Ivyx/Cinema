#ifndef BIGLIETTERIA_H
#define BIGLIETTERIA_H

class Cinema {
public:
    
    static int N_FILE = 10;
    static int N_POLTRONE = 20;
    static int N_SALE = 4;
    static int N_POSTI = N_FILE * N_POLTRONE;
    static int N_PRENOTAZIONI = N_POSTI * N_SALE;
    static int MAX_COD_PRENOTAZIONE = 1000;
    static int MIN_COD_PRENOTAZIONE = 0;
    Cinema();
    virtual ~Cinema();
    void static printMenu();
    void stampaPosti();
    bool prenotaBiglietto(char);
    bool cancellaPrenotazione(int);
    bool acquistaPrenotazione(int);
    
private:
    
    Sala* sale;
    Prenotazione* prenotazioni;
    int getNextCodice();
    bool isPrenotazione(int);
    Sala getSala(char);
    int getIndexPrenotazione(int);
    
};

#endif /* BIGLIETTERIA_H */
