#include "QuickSort.hh"

/*--------------------------------------| Podzial tablic |----------------------------*/

int PodzielTablice( Tablica& array, const unsigned int& PoczatekPodzialu, const unsigned int& KoniecPodzialu) {


	int wartoscPodzialu = array.OdczytajElement(PoczatekPodzialu);
	int i = PoczatekPodzialu - 1;
	int k = KoniecPodzialu + 1 ;


   while ( true ) {

	 do { --k; } while( array.OdczytajElement(k) > wartoscPodzialu );
	 do { ++i; } while( array.OdczytajElement(i) < wartoscPodzialu ); 
		 
		 if ( i < k ) {
		
			 ZamienElementy(array,i,k);
		
		 } else return k;
	 }	 
} 


int PodzielTabliceLosowo( Tablica& array, const unsigned int& PoczatekPodzialu, const unsigned int& KoniecPodzialu) {

	int wartoscPodzialu;
	unsigned int indeksPodzialu;
	int i = PoczatekPodzialu - 1;
	int k = KoniecPodzialu + 1 ;

	// Losowanie pivota
	indeksPodzialu =  Losuj(PoczatekPodzialu, KoniecPodzialu);

	ZamienElementy(array, PoczatekPodzialu, indeksPodzialu);
	wartoscPodzialu = array.OdczytajElement(PoczatekPodzialu);


   while ( true ) {

	 do { --k; } while( array.OdczytajElement(k) > wartoscPodzialu );
	 do { ++i; } while( array.OdczytajElement(i) < wartoscPodzialu ); 
		 
		 if ( i < k ) {
			 
			 ZamienElementy(array,i,k);
		
		 } else return k;
	 }	 

} 

int PodzielTabliceMedianaZTrzech( Tablica& array, const unsigned int& PoczatekPodzialu, const unsigned int& KoniecPodzialu) {

	int wartoscPodzialu;
	unsigned int indeksPodzialu;
	int i = PoczatekPodzialu - 1;
	int k = KoniecPodzialu + 1 ;

	// Losowanie pivota
	indeksPodzialu =  Losuj2(PoczatekPodzialu, KoniecPodzialu);

	ZamienElementy(array, PoczatekPodzialu, indeksPodzialu);
	wartoscPodzialu = array.OdczytajElement(PoczatekPodzialu);


   while ( true ) {

	 do { --k; } while( array.OdczytajElement(k) > wartoscPodzialu );
	 do { ++i; } while( array.OdczytajElement(i) < wartoscPodzialu ); 
		 
		 if ( i < k ) {
			 
			 ZamienElementy(array,i,k);
		
		 } else return k;
	 }	 

} 

/*---------------------------------| End |----------------------------*/



/*---------------------------------| QuickSort |----------------------------*/


void QuickSort( Tablica& array, const unsigned int& tryb ) {

	switch(tryb) {
		case 1: 
			QuickSort(array, 0, array.Size()-1);
			break;
		case 2: 
			QuickSortLosowy(array, 0, array.Size()-1);
			break;
		case 3: 
			QuickSortMedianaZTrzech(array, 0, array.Size()-1);
			break;
		default:
			std::string wyjatek = "\nZły tryb";
			throw wyjatek;
			break;
	}
}

void  QuickSort( Tablica& array, const unsigned int & PoczatekPodzialu, const unsigned int & KoniecPodzialu) {

	if (PoczatekPodzialu < KoniecPodzialu){
		int q = PodzielTablice(array,  PoczatekPodzialu, KoniecPodzialu);
			QuickSort(array,  PoczatekPodzialu, q);
			QuickSort(array,  q+1, KoniecPodzialu);

	}
}

void  QuickSortLosowy( Tablica& array, const unsigned int & PoczatekPodzialu, const unsigned int & KoniecPodzialu) {

	if (PoczatekPodzialu < KoniecPodzialu){
		int q = PodzielTabliceLosowo(array,  PoczatekPodzialu, KoniecPodzialu);
			QuickSortLosowy(array,  PoczatekPodzialu, q);
			QuickSortLosowy(array,  q+1, KoniecPodzialu);

	}
}


void QuickSortMedianaZTrzech( Tablica& array, const unsigned int & PoczatekPodzialu, const unsigned int & KoniecPodzialu) {

	if (PoczatekPodzialu < KoniecPodzialu){
		int q = PodzielTabliceMedianaZTrzech(array,  PoczatekPodzialu, KoniecPodzialu);
			QuickSortMedianaZTrzech(array,  PoczatekPodzialu, q);
			QuickSortMedianaZTrzech(array,  q+1, KoniecPodzialu);

	}
}


/*---------------------------------| End |----------------------------*/


void ZamienElementy( Tablica& array, const unsigned int& Poz1, const unsigned int& Poz2 ) {

	int tmp =  array.OdczytajElement(Poz2);
	array.ZmienElement(Poz2) =  array.OdczytajElement(Poz1);
	array.ZmienElement(Poz1) =  tmp;


}

int Losuj(const unsigned int& PoczatekPodzialu,const unsigned int& KoniecPodzialu) {
	srand(time(NULL));
	return ( (rand() % (KoniecPodzialu - PoczatekPodzialu + 1)) + PoczatekPodzialu ) ;

}

const unsigned int& Porownaj( const unsigned int& liczba1, const unsigned int& liczba2 ) {
	return (liczba1>liczba2) ? liczba1 : liczba2 ;
}

const unsigned int& Losuj2(const unsigned int& PoczatekPodzialu,const unsigned int& KoniecPodzialu) {
	srand(time(NULL));

	int tmp1 = (rand() % (KoniecPodzialu - PoczatekPodzialu + 1)) + PoczatekPodzialu;
	int tmp2 = (rand() % (KoniecPodzialu - PoczatekPodzialu + 1)) + PoczatekPodzialu;
	int tmp3 = (rand() % (KoniecPodzialu - PoczatekPodzialu + 1)) + PoczatekPodzialu;

	return Porownaj( Porownaj(tmp1,tmp2), tmp3);
}



