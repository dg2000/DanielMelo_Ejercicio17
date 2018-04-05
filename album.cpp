#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Album{
public:
  void CompraSobre(int n_en_sobre);
  void Status(void);
  bool esta_lleno();
  int dar_sobres_comprados();
  Album(int n);
  
private:
  int n_total;
  int n_repetidas;
  int n_en_album;
  int n_sobres_comprados;
  
  int *album;
  int *repetidas;
};

int Album::dar_sobres_comprados()
{
  return n_sobres_comprados;
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

int main(){
  srand(time(0));
  Album A(660);
  // for(int i=0;i<160;i++){
  //A.CompraSobre(5);
  // A.Status();
  while(!A.esta_lleno())
    {
      A.CompraSobre(5);
    }
  cout << "Fueron necesarios " << A.dar_sobres_comprados() << endl;
  
  

  return 0;
}
