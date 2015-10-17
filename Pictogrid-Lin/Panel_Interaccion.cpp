// Panel_Interaccion.cpp: implementation of the Panel_Interaccion class.
//
//////////////////////////////////////////////////////////////////////

#include "Panel_Interaccion.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Panel_Interaccion::~Panel_Interaccion()
{

}

void Panel_Interaccion::MoverFilaDcha(int k)
{
	int x=0,i=0,n=0;//Contadores
	Casilla aux;//Objeto Casilla para realizar el intercambio

	do{
		if(casilla[(fila-1)-n][k]->GetColorR()==255)//Comprobacion de fichas rojas en el final
			{										//de la fila
			i++;
			n++;
			}

		else
			{
			x=n;//devuelve el indice de la casilla hasta la que debe haber desplazamiento
			i=0;
			}
			
	}while(i!=0&&n<fila);//mientras sean rojas y queden fichas por comprobar

	for(x;x<=(fila-2);x++)//Bucle para intercambiar las casillas de la fila
		{
		aux.SetColor(casilla[(fila-1)-x][k]->GetColorR(),
		casilla[(fila-1)-x][k]->GetColorV(),
		casilla[(fila-1)-x][k]->GetColorA());

		if(aux.GetColorA()!=255)//Si no es una casilla azul...
			{
			if(casilla[(fila-2)-x][k]->GetColorA()!=255)//y si la siguiente tampoco es azul
				{
				casilla[(fila-1)-x][k]->SetColor(casilla[(fila-2)-x][k]->GetColorR(),//intercambia sus colores
										casilla[(fila-2)-x][k]->GetColorV(),
										casilla[(fila-2)-x][k]->GetColorA());

				casilla[(fila-2)-x][k]->SetColor(aux.GetColorR(),
									   aux.GetColorV(),
									   aux.GetColorA());
				}
			}
		else if(x==fila-2){}//si es una casilla azul y es la penultima no hay movimiento tras ella
							
		else	//si no...
			{
			n=x+1;//examina a partir de la casilla azul
			do{
				if(casilla[(fila-1)-n][k]->GetColorR()==255)//Comprobacion de fichas rojas en el final
					{										//de la fila(en este caso el final es la casilla azul)
					i++;
					n++;
					}
				else
					{
					x=n;//devuelve el indice de la casilla hasta la que debe haber desplazamiento
					i=0;
					}
			
				}while(i!=0&&n<fila);

			if(x<=(fila-2))//mientras esa casilla no sea la ultima
				{
				aux.SetColor(casilla[(fila-1)-x][k]->GetColorR(),//intercambia sus colores
				casilla[(fila-1)-x][k]->GetColorV(),
				casilla[(fila-1)-x][k]->GetColorA());

				if(aux.GetColorA()!=255&&casilla[(fila-2)-x][k]->GetColorA()!=255){//intercambia siempre que no modifiques atributos de casillas azules

				casilla[(fila-1)-x][k]->SetColor(casilla[(fila-2)-x][k]->GetColorR(),
										casilla[(fila-2)-x][k]->GetColorV(),
										casilla[(fila-2)-x][k]->GetColorA());

				casilla[(fila-2)-x][k]->SetColor(aux.GetColorR(),
									   aux.GetColorV(),
									   aux.GetColorA());
				}
				}
			}
		}
}

void Panel_Interaccion::MoverFilaIzq(int k)
{
		
		int x=0,i=0,n=0;
		Casilla aux;

		do{
				if(casilla[n][k]->GetColorR()==255)
					{
					i++;
					n++;
					}
				else
					{
					x=i;
					i=0;
					}
			
		}while(i!=0&&n<fila);
		

		for(x;x<(fila-1);x++)
			{
			aux.SetColor(casilla[x][k]->GetColorR(),
				casilla[x][k]->GetColorV(),
						 casilla[x][k]->GetColorA());

			if(aux.GetColorA()!=255)
				{
					if(casilla[x+1][k]->GetColorA()!=255)
					{

					casilla[x][k]->SetColor(casilla[x+1][k]->GetColorR(),
											casilla[x+1][k]->GetColorV(),
											casilla[x+1][k]->GetColorA());

					casilla[x+1][k]->SetColor(aux.GetColorR(),
										   aux.GetColorV(),
										   aux.GetColorA());
					}		
				}
			else if(x==fila-2){}
				else{
				n=x+1;
				do{
					if(casilla[n][k]->GetColorR()==255)
						{
						i++;
						n++;
						}
					else
						{
						x=n;
						i=0;
						}
			
					}while(i!=0&&n<fila);

				if(x<=(fila-2))
					{
						aux.SetColor(casilla[x][k]->GetColorR(),
						casilla[x][k]->GetColorV(),
						casilla[x][k]->GetColorA());

						if(aux.GetColorA()!=255&&casilla[x+1][k]->GetColorA()!=255){

					casilla[x][k]->SetColor(casilla[x+1][k]->GetColorR(),
											casilla[x+1][k]->GetColorV(),
											casilla[x+1][k]->GetColorA());

					casilla[x+1][k]->SetColor(aux.GetColorR(),
										   aux.GetColorV(),
										   aux.GetColorA());
						}
					}

			}
		}
}

void Panel_Interaccion::MoverColumnaArriba(int k)
{
		int x=0,i=0,n=0;
		Casilla aux;

		do{
				if(casilla[k][(columna-1)-n]->GetColorR()==255)
					{
					i++;
					n++;
					}
				else
					{
					x=i;
					i=0;
					}
			
		}while(i!=0&&n<=columna-1);
			
		if(x!=columna-1)
		{
		for(x;x<columna-1;x++)
			{
			aux.SetColor(casilla[k][(columna-1)-x]->GetColorR(),
						 casilla[k][(columna-1)-x]->GetColorV(),
						 casilla[k][(columna-1)-x]->GetColorA());

		if(aux.GetColorA()!=255)
			{
			if(casilla[k][(columna-2)-x]->GetColorA()!=255)
				{
			casilla[k][(columna-1)-x]->SetColor(casilla[k][(columna-1)-x-1]->GetColorR(),
									casilla[k][(columna-1)-x-1]->GetColorV(),
									casilla[k][(columna-1)-x-1]->GetColorA());

			casilla[k][(columna-1)-x-1]->SetColor(aux.GetColorR(),
								   aux.GetColorV(),
								   aux.GetColorA());
				}
			}
		else
			{
			

			n=x+1;
			do{
				if(casilla[k][(columna-1)-n]->GetColorR()==255)
					{										
					i++;
					n++;
					}
				else
					{
					x=n;
					i=0;
					}
			
			}while(i!=0&&n<fila);

			if(x<=(columna-2))
				{
				aux.SetColor(casilla[k][(columna-1)-x]->GetColorR(),
				casilla[k][(columna-1)-x]->GetColorV(),
				casilla[k][(columna-1)-x]->GetColorA());

				if(aux.GetColorA()!=255&&casilla[k][(columna-2)-x]->GetColorA()!=255){

				casilla[k][(columna-1)-x]->SetColor(casilla[k][(columna-2)-x]->GetColorR(),
										casilla[k][(columna-2)-x]->GetColorV(),
										casilla[k][(columna-2)-x]->GetColorA());

				casilla[k][(columna-2)-x]->SetColor(aux.GetColorR(),
									   aux.GetColorV(),
									   aux.GetColorA());
					}
				}

		}

			}
		}

}

void Panel_Interaccion::MoverColumnaAbajo (int k)
{
			int x=0,i=0,n=0;
		Casilla aux;

		do{
				if(casilla[k][n]->GetColorR()==255)
					{
					i++;
					n++;
					}
				else
					{
					x=i;
					i=0;
					}
			
		}while(i!=0&&n<=columna-1);
			
		if(x!=columna-1)
		{
		for(x;x<columna-1;x++)
			{
			aux.SetColor(casilla[k][x]->GetColorR(),
						 casilla[k][x]->GetColorV(),
						 casilla[k][x]->GetColorA());

			if(aux.GetColorA()!=255)
				{
					if(casilla[k][x+1]->GetColorA()!=255)
					{
			casilla[k][x]->SetColor(casilla[k][x+1]->GetColorR(),
									casilla[k][x+1]->GetColorV(),
									casilla[k][x+1]->GetColorA());

			casilla[k][x+1]->SetColor(aux.GetColorR(),
								   aux.GetColorV(),
								   aux.GetColorA());
					}
				}

			else if(x==fila-2){}
			else{
				n=x+1;
				do{
					if(casilla[k][n]->GetColorR()==255)
						{
						i++;
						n++;
						}
					else
						{
						x=n;
						i=0;
						}
			
					}while(i!=0&&n<fila);

				if(x<=(fila-2))
					{
						aux.SetColor(casilla[k][x]->GetColorR(),
						casilla[k][x]->GetColorV(),
						casilla[k][x]->GetColorA());

						if(aux.GetColorA()!=255&&casilla[k][x+1]->GetColorA()!=255){

					casilla[k][x]->SetColor(casilla[k][x+1]->GetColorR(),
											casilla[k][x+1]->GetColorV(),
											casilla[k][x+1]->GetColorA());

					casilla[k][x+1]->SetColor(aux.GetColorR(),
										   aux.GetColorV(),
										   aux.GetColorA());
						}
					}

			}


			}
		}

}

