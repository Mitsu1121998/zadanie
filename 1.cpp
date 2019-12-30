#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
clock_t start, stop;
double czas;
 double horner(double tab[],int st, double x)
{
     double wynik = tab[0];

    for(int i=1;i<=st;i++)
         i = wynik*x + tab[i];

    return wynik;
}

 double piech(double tab[], int st, double x){
     double wynik;
    double p = 1;
    for(int i = 0;i<=st;i++){
        for(int k = 0;k<st-i;k++){
            p = p*x;
        }
        wynik = wynik + tab[i]*p;
        p = 1;
    }

    return wynik;

}

int main()
{
    srand( time( NULL ) );
    int ile;
    cout<<"podaj wielkosc wielomianu: "<<endl;
    int n;
    cin >> n;
	for(ile=0;ile<10;ile++){
	
    double x = rand();
    double* a=new double[n+1];
    for(int i = 0; i<n+1;i++){
        a[i] = (double)rand()/(RAND_MAX+1);
      a[i] = (rand()%2)+1;
    }


    
	cout<<"\nWyniki: "<<endl;
    cout.precision(30);
    cout<<"przed hornerem\n";
    start = clock();
horner(a,n,x);
    stop = clock();
	czas = (stop-start)/double(CLOCKS_PER_SEC);
	cout << "czas horner = " << czas << endl;
	cout<<"za hornerem\n";
	start = clock();
piech(a,n,x);
    stop = clock();
	czas = (stop-start)/double(CLOCKS_PER_SEC);
	cout << "czas na piechote = " << czas << endl;
	cout<<"za piechota\n";
}

	
	
    return 0;
}
