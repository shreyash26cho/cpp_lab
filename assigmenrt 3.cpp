#include<iostream>
#include<string.h>
using namespace std;

class Book
{
    private:
       char *title;
	  char *author;
	  int pgcnt;
	  bool format;
	  float *chpages;
	  int chnumbers;
     
	public:
		// 1.default constructor 
	   Book(){
	    title='\0';
	    author='\0';
	    pgcnt=0;
	    format=0;
	    chpages='\0';
	    chnumbers=0;
	   }
	   // 1 default constructor	
	   Book(char *nm,char *at,int pcnt,bool ft,float *chpg,int chno)
	   {
	   	title=new char[(strlen(nm)+1)];
          strcpy(title,nm);
    	   	author=new char[strlen(at)+1];
	   	strcpy(author,at);
	   	pgcnt=pcnt;
	   	format=ft;
	   	chpages=new float[chno];
	   	for(int i=0;i<chno;i++){
	   		chpages[i]=chpg[i];
		   }
	   	chnumbers=chno;
	   }
        // display th einformatio about book
	   void display(){
	   	cout<<"Book name :"<<title<<endl;
	   	cout<<"Book author name : "<<author<<endl;
	   	cout<<"Book page count :"<<pgcnt<<endl;
	   	cout<<"format : "<<format<<endl;
	   	cout<<"chapter pages :";
	   	for(int i=0;i<chnumbers;i++){
	   		cout<<chpages[i]<<" ";
		   }
		cout<<"\nchapter numbers  :"<<chnumbers<<endl;
	   }	  
	   
	    Book(const Book &abc){
	    	//shallow copy
	    	// it copy CONSTRUCTION 
         title=abc.title;
		author=abc.author;
		pgcnt=abc.pgcnt;
	     format=abc.format;
		chpages=abc.chpages;
		chnumbers=abc.chnumbers;
	    }
	    // 
	   ~Book(){
	   	delete [] title;
	   	delete [] author;
	   	delete [] chpages;
	   	cout<<"Distructer is called";
	   }
};
int main(){
	float chpages[]={10,20,30,40,50};
	Book b1("Your name ","makoto shinkai",100,1,chpages,5);
	b1.display();
	cout<<"\n 2nd book information :\n ";
	Book b2=b1;
	b2.display();

}
