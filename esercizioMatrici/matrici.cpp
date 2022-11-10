#include <bits/stdc++.h>

using namespace std;

int main(){

  int righe = 10;
  int colonne = 10;

  //QUESTO PROGRAMMA RISOLVERA' AL PIU' SISTEMI LINEARI DI 100 EQUAZIONI A 100 INCOGNITE

  double m[10][10];
  double s[10]; //QUESTA LA SI PUO' VEDERE COME LA COLONNA DELLE SOLUZIONI
  
  //IMPOSTO A INT_MIN IL VALORE DI DEFAULT COME TECNICA PER COMPRENDERE IL NUMERO DI RIGHE EFFETTIVE DI UNA MATRICE
  
  //NEL CASO IN CUI AVESSI LA SFIGA DI AVERE UN VALORE DEI COEFFICIENTI ALL'INTERNO DELLA MATRICE COMPLETA AVRO' UN ERRORE NON INDIFFERENTE

  for(int i=0; i<righe; i++){
    for(int j=0; j<colonne; j++)
      m[i][j] = INT_MIN;        
  }

  //ORA MI OCCUPO DELL'INSERIMENTO DI DATI DA PARTE DELL'UTENTE TRAMITE UNA SCELTA ITERATA FINCHE' IL CHAR RESTA S OPPURE ARRIVO ALLA CENTESIMA EQUAZIONE
  //NOTARE CHE LA STESSA OPERAZIONE ANDRA' SVOLTA SULLE COLONNE 
  
  int k_r = 1; //keep rows
  int k_c = 1; //keep columns
  int c_r = 0; //count rows
  int c_c = 0; //count columns

  while(k_r == 1 && c_r < righe){
    
    cout<<"EQUAZIONE NUMERO "<< c_r + 1 <<" : "<<endl;
    
    while(k_c == 1 && c_c < colonne){

      cout<<"TERMINE X_"<< c_c + 1 <<": ";
      cin>>m[c_r][c_c];
      cout<<"ALTRO COEFFICIENTE? (1 yes other no)"<<endl;
      cin>>k_c;
      c_c++;
      
    }
    cout<<"VALORE EQUAZIONE: ";
    cin>>s[c_r];
    k_c = 1;
    c_c = 0;
    cout<<"ALTRA EQUAZIONE? (1 yes other no)"<<endl;
    cin>>k_r;
    c_r++;
    
  }

  int n_eq = c_r-1; //QUI MI SALVO IL NUMERO DI EQUAZIONI INSERITE
  
  //FUNZIONE DI STAMPA SPECIALE

  cout<<endl;
  
  for(int i=0; i<righe; i++){
    for(int j=0; j<colonne; j++){
      if(m[i][j] != INT_MIN)
        cout<<m[i][j]/*<<"x_"<<j+1*/<<" ";
    }
    if(m[i][0] != INT_MIN)
      cout<<endl;
  }

  //VADO A CERCARE QUALE E' L'INCOGNITA MAGGIORE (SE VOGLIAMO X_N IN UN SISTEMA CON N EQUAZIONI)

  int coef_max = 0;

  c_r = 0;
  c_c = 0;

  while(c_r < righe){
    while(c_c < colonne){
      if(m[c_r][c_c] != INT_MIN){
        if(coef_max < c_c)
          coef_max = c_c;
      }
      else
        c_c = 9;
      c_c++;
    }
    c_c = 0;
    c_r ++;
  }

  //cout<<"COEFFICIENTE MASSIMO: "<<coef_max<<endl;

  //ORA POSSO FINALMENTE SCRIVERE LA MATRICE DEI COEFFICENTI CON VALORI O 0 O DIVERSI DA 0
  
  for (int i=0; i<=n_eq; i++){
    for(int j=0; j<=coef_max; j++){
      if(m[i][j] == INT_MIN)
        m[i][j] = 0;
    }
  }

  //FUNZIONE DI STAMPA SPECIALE

  cout<<endl;
  
  for(int i=0; i<righe; i++){
    for(int j=0; j<colonne; j++){
      if(m[i][j] != INT_MIN)
        cout<<m[i][j]/*<<"x_"<<j+1*/<<" ";
    }
    if(m[i][0] != INT_MIN)
      cout<<endl;
  }

  //ORA DEVO TRASFORMARE IN UNA MATRISCE SCALA OGNI MATRICE

  //DEVO COLONNA PER COLONNA TROVARE LA PRIMA COLONNA CON UN VALORE DIVERSO DA ZERO (CHIARAMENTE NEI LIMITI DELLE DIMENSIONI DELLA MATRICE)
  //PER FAR CIO' L'ITERAZIONE AVVERRA' PER COLONNE E NON PER RIGA
  //AD OGNI CICLO APPENA TROVO UNA COLONNA CON VALORE DIVERSO DA ZERO AD INDICE I-ESIMO DEVO SWAPPARE LA RIGA ALL'I-ESIMA POSIZIONE (NOTA CHE SE NON TROVO NEANCHE UNA EQUAZIONE MI TIRO DIETRO L'INDICE DELLA RIGA PRECEDENTE)
  //TUTTE LE COLONNE SUCCESSIVE NEL CICLO IESIMO CON VALORE DIVERSO DA ZERO AD INDICE I-ESIMO VANNO TRASFORMATE 
  //POICHE' IL TERMINE CHE DEVE SCOMPARIRE E' IL COEFFICIENTE AD INDICE I-ESIMA, BASTA SOTTRARRE ALLA RIGA IN QUESTIONE LA RIGA I-ESIMA LECITA MOLTIPLICATA PER IL VALORE DELL'INDICE CONSIDERATO FRATTO IL VALORE LECITO DELL'INDICE I-ESIMO

  int r_i = 0; //QUESTA E' LA VARIABILE  IN CUI MANTENGO LA POSIZIONE PER SWAPPARE LE RIGHE ED ANDRA' DA 0 AD N_EQ, AUMENTA SOLO QUANDO TROVO UNA COLONNA LECITA
  c_c = 0;
  c_r = 0;

  for(int j=0; j<=coef_max; j++)  //ITERO LE COLONNE
  {
    int i = j;
    while(m[i][j] == 0 && i<=n_eq)
      i++;
    if(i<n_eq)//DEVO SWAPPARE R_I-ESIMA FILA CON I-ESIMA FILA
    {
        for(int l=0; l<=coef_max; l++){
          double t = m[r_i][l];
          m[r_i][l] = m[i][l];
          m[i][l] = t;
          t = s[r_i];
          s[r_i] = s[i];
          s[i] = t;
        } 
      r_i ++;
    }
    for(i=i; i<=n_eq; i++)
    {
      if(m[i][j] != 0){  
        //SE HO TROVATO UNA VARIABILE CHE HA VALORE DIVERSO DA ZERO IN COLONNA JESIMA ALLORA TRASFORMO L'EQUAZIONE
      double k = m[i][j] / m[r_i - 1][j]; 
      k *= -1;
        cout<<endl<<"k vale: "<<k<<endl;
        //k E' LA COSTANTE DA MOLTIPLICARE AGLI ELEMENTI DELLA RIGA I-ESIMA PER FAR SI CHE L'ELEMENTO CON VALORE DIVERSO DA ZERO ALLA RIGA IESIMA SI ANNULLI GRAZIE ALLA SOTTRAZIONE DELL'ELEMENTO LECITO IN RIGA R-IESIMA * K 
        // EG: 2 3 1 E 1 0 2 -> PER RIMUOVERE L'1 SCRIVIAMO L'EQUAZIONE 2K + 1 = 0 -> K = -1/2 (IL MENO LO METTO DIRETTAMENTE COME SOTTRAZIONE)
      for(int l=j; l<=coef_max; l++){
        cout<<"M[I][L] = "<<m[i][l]<<endl;
        cout<<"M[R_I-1][L] = "<<m[r_i]-1[l]<<endl;
        m[i][l] = m[i][l] + (m[r_i-1][l]*k);
        cout<<"M[I][L] + M[R_I-1][L]*K = "<<m[i][l]<<endl;
        s[i] = s[i] + (s[r_i] * k);  //IMPORTANTE RICORDARE PURE I RISULTATI
      }
    }
  }

  //FUNZIONE DI STAMPA SPECIALE

  cout<<"giro numero: "<<j<<endl;
  
  for(int i=0; i<righe; i++){
    for(int j=0; j<colonne; j++){
      if(m[i][j] != INT_MIN)
        cout<<m[i][j]/*<<"x_"<<j+1*/<<" ";
    }
    if(m[i][0] != INT_MIN)
      cout<<endl;
  }
  }
   //FUNZIONE DI STAMPA SPECIALE

  cout<<endl;
  for(int i=0; i<righe; i++){
    for(int j=0; j<colonne; j++){
      if(m[i][j] != INT_MIN)
        cout<<m[i][j]/*<<"x_"<<j+1*/<<" ";
    }
    if(m[i][0] != INT_MIN)
      cout<<endl;
  }

  
    
  return 0;
  
}