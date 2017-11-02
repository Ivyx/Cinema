#ifndef SALA_H
#define SALA_H

class Sala {
public:
    
    Sala();
    virtual ~Sala();
    char codice;
    int countPostiDisponibili();
    Posto occupaPosto(); //posto era un enum
    void liberaPosto(int,int);
    
private:

    bool[][]disponibilita_posti;
};

#endif /* SALA_H */
