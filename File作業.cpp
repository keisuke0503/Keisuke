#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
using namespace std;

int **Arr(int r , int c) {
	int i , j , s ;
	int **arr = new int *[r] ;
	srand( time(NULL) );
	for(i=0 ; i<r ; i++){
		arr[i] = new int [c]; 
	}
	for(i=0 ; i<r ; i++){
		for(j=0 ;j<c ;j++){
			s=rand()%10 ;
			arr[i][j]=s ;
		}
		return arr ;
	}
}


void writeToFile (int **arr , int r , int c , char *way ){
	int i , j ;
	FILE *homework ;  //開一個File的指標 
	homework = fopen(way, "w") ;   //  w是寫入並覆蓋  r是讀取  a是在尾端寫入
	fprintf(homework , "2D array\n ");
	fprintf(homework , "size of indexes : %d * %d \n", r , c);  // 使用%d代表告訴系統這裡要用變數
	for (i=0 ; i<r ; i++){
		for(j=0 ; j<c ; j++){
			fprintf(homework, "%-11d", arr[i][j]);
		}
		fprintf(homework,"\n");
	} 
	int fr = fclose(homework) ;
	cout << "New array is written to" << way << endl ; 
}

void PrintMatrix (int **arr , int r , int c){
	int i , j ;
	cout <<"the new array is" <<"\n" ;
	cout << "the size of array is" << r << "*" << c << endl 
		 << "the contents of array is " <<"\n" ;
		for(i=0; i<r ;i++){
			for(j=0 ; j<c ; j++){ 
			cout << setw(3) <<arr[i][j] << "  " ;
			} 
			cout<< endl ;  //endl = end line =換行 
		}
}



void ReadFile(char *way){
	FILE *book ;
	book = fopen (way , "r");
	char c ;
	if (book){
		while ((c= fgetc(book))!=EOF) //EOF=End Of File  Fgetc= File get character
			cout << c ;
	}
	else{
		cout << "File not found or permission denied ! " <<"\n" ;  //
		return ;
	}
	fclose(book) ;
} 


void file1(){
	cout << "Generate 2D array and write a file" << "\n" ;
	cout << "please input 2 indexes for array" << "\n" ;
	int row , col ;
	cin >> row >> col ;
	int **arr = Arr(row,col) ;
	PrintMatrix(arr,row ,col);
	char way[100]={'\0'};
	cout << "enter name for the file to new array" <<"\n" ;
	cin >> way ;
	writeToFile(arr , row ,col ,way); 
}
	
	
void file2(){
	cout << "Read from file and show the array" << "\n" ;
	char way[100]={'\0'}; //裡面是字元 不能用0替代 
	cout << "enter name of file " <<"\n" ;
	cin >> way ;
	ReadFile(way) ;
}	


int main (){
	int s ;
	cout << "1 : Generate a 2D array and write a file" << "\n" 
		 << "2 : Read from file and show the array" << endl ;
			while(true){
		 	cout << "choose a number for specific function" << "\n" ;
		 	cin >> s ;
		 switch (s)	{
		 case 1 :
		 	file1() ;
			break ;
		 
		 case 2 :
		 	file2();
			 break ;
		
		 default :
		 	cout << "Invalid inout" << "\n" ;
			 break ;	 		 	
		 }
	} 
}

