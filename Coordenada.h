

#ifndef COORDENADA_H
#define COORDENADA_H

class Coordenada{
private:
    int coordenadaX;
    int coordenadaY;
    int coordenadaZ;
public:
    Coordenada();
    int getCoordenadaX() const;
    int getCoordenadaY() const;
    int getCoordenadaZ() const;

    void setCoordenadaX(int coordenadaX);
    void setCoordenadaY(int coordenadaY);
    void setCoordenadaZ(int coordenadaZ);
};


#endif //COORDENADA_H

