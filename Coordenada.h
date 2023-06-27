

#ifndef COORDENADA_H
#define COORDENADA_H

class Coordenada{
private:
    int coordenadaX;
    int coordenadaY;
    int coordenadaZ;
public:
    Coordenada();

    Coordenada( int x, int y , int z );
    Coordenada( Coordenada const & );
    ~Coordenada();


    int getCoordenadaX() const;
    int getCoordenadaY() const;
    int getCoordenadaZ() const;

    void setCoordenadaX(int coordenadaX);
    void setCoordenadaY(int coordenadaY);
    void setCoordenadaZ(int coordenadaZ);
};


#endif //COORDENADA_H

