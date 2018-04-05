#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Album{
public:
  void CompraSobre(int n_en_sobre);
  void Status(void);
  void quitar_repetida(int n);
  void poner_cambio(int n);
  bool esta_lleno();
  int dar_sobres_comprados();
  int * dar_repetidas();
  int * dar_album();
  int dar_n_repetidas();
  int dar_total();
  Album(int n);
  
private:
  int n_total;
  int n_repetidas;
  int n_en_album;
  int n_sobres_comprados;
  
  int *album;
  int *repetidas;
};

void Album::quitar_repetida(int n)
{
  repetidas[n]--;
}

void Album::poner_cambio(int n)
{
  album[n]++;
}

int Album::dar_total()
{
  return n_total;
}

int Album::dar_sobres_comprados()
{
  return n_sobres_comprados;
}

int * Album::dar_album()
{
  return album;
}

int * Album::dar_repetidas()
{
  return repetidas;
}


int Album::dar_n_repetidas()
{
  return n_repetidas;
}

  
void Album::Status(void){
  cout << n_en_album << " "<<n_repetidas << endl;
}

bool Album::esta_lleno()
{
  if (n_total == n_en_album)
    {
      return true;
    }
  else
    {
      return false;
    }

}


void Album::CompraSobre(int n_en_sobre){
  int lamina;
  n_sobres_comprados++;
  for(int i=0;i<n_en_sobre;i++){
    lamina = rand()%n_total;
    if(album[lamina]==0){
      album[lamina] = 1;
      n_en_album++;
    }else{
      repetidas[lamina] +=1;
      n_repetidas++;
    }
  }
}

Album::Album(int n){
  album = new int[n];
  repetidas = new int[n];
  n_total = n;
  n_repetidas = 0;
  n_en_album = 0 ;
  n_sobres_comprados = 0 ;
  for (int i=0;i<n_total;i++){
    album[i] = 0;
    repetidas[i] = 0;
  }
}

void cambio(Album a, Album b)
{
  int * rA = a.dar_repetidas();

  int * rB = b.dar_repetidas();

  int * pA = a.dar_album();

  int * pB = b.dar_album();

  int total = a.dar_total();

  int i;

  int k;

  int max;

  int min;

  if(a.dar_n_repetidas() < b.dar_n_repetidas())
    {
      max = a.dar_n_repetidas();
      min = b.dar_n_repetidas();
    }

  else
    {
      max = b.dar_n_repetidas();
      min = a.dar_n_repetidas();
    }
      

  for (i = 0; i < max; i++)
    {
      if( (rA[i] && !pB[i]) )
	{
	  for (k = 0; k < min; k++)
	    {
	      if(rB[k] && !pA[k])
		{
		  a.quitar_repetida(i);
		  b.poner_cambio(i);

		  b.quitar_repetida(k);
		  a.poner_cambio(k);
		}

	    }
	}
    }

}
 
		  
	      
	  

int main(){
  srand(time(0));
  Album A(660);
  Album B(660);
  // for(int i=0;i<160;i++){
  //A.CompraSobre(5);
  // A.Status();
  while(!A.esta_lleno())
    {
      A.CompraSobre(5);
      cambio(A, B);
      
    }
  cout << "Fueron necesarios " << A.dar_sobres_comprados() << " cuando se realizaron cambios" << endl;
  
  

  return 0;
}
