#include <iostream.h>

class Casilla
{
private:

	float x;
	float y;

	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;

public:

	Casilla(int px=0,int py=0);
	~Casilla();

	void Dibuja ();
	void Mueve(float a,float b,unsigned char tecla);

	void SetPos(float px,float py);
	void SetColor (unsigned char r,unsigned char v,unsigned char a);

	unsigned char GetColorR(){return rojo;};
	unsigned char GetColorV(){return verde;};
	unsigned char GetColorA(){return azul;};

};
