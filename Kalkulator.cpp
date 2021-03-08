/*
	TUGAS 2 PROGRAMMING SEKURO13
	Nama : Maharani Ayu Putri Irawan
	NIM  : 16520134
	
	Deskripsi:
	PROGRAM KALKULATOR
	--> menghitung penjumlahan, pengurangan, perkalian, pembagian, perpangkatan, dan integral tentu (Metode Riemann Trapesium)
	
	1. 	int main()
		Fungsi utama int main(). Menampilkan menu perhitungan yang dapat dilakukan program. User memasukkan pilihan. Program memanggil
		fungsi perhitungan sesuai pilihan user dan menampilkan hasil perhitungan dalam desimal dengan 2 angka di belakang koma.
		Contoh input : 1 <press enter>
		
	2. 	calculation()
		Fungsi penghitungan operasi matematika dasar dengan lebih dari 1 operator dan 2 operand secara berurutan (tidak berdasar 
		aturan operasi hitung campuran). Setiap input dipisahkan oleh enter. Hasil perhitungan dikembalikan pada fungsi utama int main()
		Contoh input : 1 <press enter> + 2 <press enter> / 2 <press enter> = <press enter>
		
	3.	singleCalculation()
		Fungsi penghitungan operasi matematika dasar dengan hanya 1 operator dan 2 operand. Program menampilkan jenis-jenis operasi
		yang dapat dilakukan. User diminta untuk memasukkan 2 buah operand dan 1 buah operator. Hasil perhitungan dikembalikan pada
		fungsi utama int main().
		Contoh input : 1 <press enter> 2 <press enter> * <press enter>
		
	4.	addition(float one, float two)
		Fungsi antara penghitungan penjumlahan angka one dan two yang bertipe data float. Hasil perhitungan dikembalikan pada fungsi 
		singleCalculation().
		
	5.	subtraction (float one, float two)
		Fungsi antara penghitungan pengurangan angka one dan two yang bertipe data float. Hasil perhitungan dikembalikan pada fungsi 
		singleCalculation().
		
	6.	multiplication (float one, float two)
		Fungsi antara penghitungan perkalian angka one dan two yang bertipe data float. Hasil perhitungan dikembalikan pada fungsi 
		singleCalculation().
	
	7.	division (float one, float two)
		Fungsi antara penghitungan pembagian angka one dan two yang bertipe data float. Hasil perhitungan dikembalikan pada fungsi 
		singleCalculation().
	
	8.	power (float one, float two)
		Fungsi antara penghitungan perpangkatan angka one dengan angka two yang bertipe data float. Hasil perhitungan dikembalikan pada 
		fungsi singleCalculation().
	
	9.	integral()
		Fungsi untuk menghitung nilai integral tentu dengan bantuan fungsi antara fs_polynomial(float x) dan fs_reciprocal(float x).
		Program memberikan pilihan 2 buah fungsi yang integralnya dapat dihitung, yakni f(x)=x^3+x+1 dan f(x)=1/(1+x^2). User menginput
		angka 1 untuk memilih fungsi f(x)=x^3+x+1 dan 2 untuk memilih fungsi f(x)=1/(1+x^2). Program juga meminta masukan user berupa
		batas atas dan bawah integral, serta jumlah interval yang diinginkan user. Hasil perhitungan dikembalikan pada fungsi int main().
		Contoh input : 1 <press enter> 1 <press enter> 20 <press enter> 20 <press enter>
		
	10.	fs_polynomial(float x)
		Fungsi untuk menghitung hasil pemetaan x pada fungsi f(x)=x^3+x+1. Hasil perhitungan dikembalikan pada fungsi integral().
	
	11. fs_reciprocal(float x)
		Fungsi untuk menghitung hasil pemetaan x pada fungsi f(x)=1/(1+x^2). Hasil perhitungan dikembalikan pada fungsi integral().
*/

// LIBRARY
#include <stdio.h>
#include <math.h>

float calculation();
float singleCalculation();
float addition(float one, float two);
float subtraction(float one, float two);
float multiplication(float one, float two);
float division(float one, float two);
float power(float base, float powers);
float integral();
float fs_polynomial(float x);
float fs_reciprocal(float x);

int main(){
	// Deklarasi variabel
	float res;
	int choice;
	int choice2;
	
	// Menampilkan menu
	printf("\tSIMPLE CALCULATOR\n- Maharani Ayu Putri Irawan -\n\n");
	printf("List of Operations Available: \n");
	printf("1. Basic Math Calculation (Addition, Subtraction, Multiplication, Division, and Power)\n");
	printf("2. Definite Integral\n");
	printf("Input your choice (1/2):\n");
	
	// meminta inputan user
	scanf("%d", &choice);
	
	// perulangan untuk meminta ulang input apabila tidak sesuai
	while ((choice!=1) && (choice!=2)){
		printf("Input valid choice (1/2):\n");
		scanf("%d", &choice);
	}
	printf("\n");
	// decision pemilihan operasi
	if (choice==1){						// memilih perhitungan matematika sederhana
		// menampilkan menu
		printf("Operations available:\n");
		printf("1. Single sign\n2. Multiple sign\n");
		printf("Input valid choice (1/2):\n");
		// meminta inputan user
		scanf("%d", &choice2);
		
		// perulangan untuk meminta ulang input apabila tidak sesuai
		while ((choice2!=1) && (choice2!=2)){
			printf("Input valid choice (1/2)\n");
			scanf("%d", &choice2);
		}
		
		// decision pemilihan operasi dan pemanggilan fungsi
		if (choice2==1)
			res = singleCalculation();
		else
			res = calculation();
	}
	else if (choice==2)					// memilih operasi integral tentu
		res = integral();
	printf("\n");
	// menampilkan hasil perhitungan
	printf("The result is %.2f\n", res);
}

float calculation(){
	// deklarasi dan inisialisasi variabel
	float input(0), total(0);
	char sign;
	bool still(true);
	
	// perintah memasukkan dan meminta masukan user
	printf("Input number and sign in different lines!\n");
	scanf("%f", &input);
	total = input;
	
	// perulangan untuk perhitungan, tidak berhenti sebelum pengguna memasukkan tanda '='
	while(still){
		// input dan validasi
		scanf("%s", &sign);
		while (sign!='+' && sign!='-' && sign!='*' && sign!='/' && sign!='^' && sign!='='){
			printf("Input valid operation (+ - * / ^): ");
			scanf("%s", &sign);
		}
		// akhir perhitungan
		if (sign=='='){
			return total;
			still = false;
		}
		else
			scanf("%f", &input);
		
		switch(sign){
			case '+' : total += input;
						break;
			case '-' : total -= input;
						break;
			case '*' : total *= input;
						break;
			case '/' : total /= input;
						break;
			case '^' : total = pow(total, input);
						break;
		}
	}
}

float singleCalculation(){
	// deklarasi variabel
	char Operator;
	float first, second;
	
	// menampilkan menu dan meminta inputan user
	printf("Available operators: + - * / ^\n");
	
	printf("Input first number  : ");
	scanf("%f", &first);
	printf("Input second number : ");
	scanf("%f", &second);
	printf("Input operation : ");
	scanf("%s", &Operator);
	
	// validasi input dan meminta input ulang jika input tidak valid
	while (Operator!='+' && Operator!='-' && Operator!='*' && Operator!='/' && Operator!='^'){
		printf("Input valid operation (+ - * / ^): ");
		scanf("%s", &Operator);
	}
	// pemanggilan fungsi perhitungan sesuai pilihan user dan mengembalikan pada fungsi utama main()
	if (Operator=='+')
		return addition(first, second);	
	else if (Operator=='-')
		return subtraction(first, second);
	else if (Operator=='*')
		return multiplication(first, second);
	else if (Operator=='/')
		return division(first, second);
	else if (Operator=='^')
		return power(first, second);
}

float addition(float one, float two){
	// fungsi perhitungan penjumlahan
	return (one + two);
}
float subtraction(float one, float two){
	// fungsi perhitungan pengurangan
	return (one - two);
}
float multiplication(float one, float two){
	// fungsi perhitungan perkalian
	return (one * two);
}
float division(float one, float two){
	// fungsi perhitungan pembagian
	return (one / two);
}
float power(float base, float powers){
	// fungsi perhitungan perpangkatan
	return pow(base, powers);
}

float fs_polynomial(float x){
	// fungsi perhitungan fungsi Polynomial f(x)=x^3+x+1
	return (pow(x,3)+x+1);
}

float fs_reciprocal(float x){
	// fungsi perhitungan fungsi Reciprocal f(x)=1/(1+x^2)
	return (1/(1+pow(x,2)));
}

float integral(){
	// deklarasi dan inisialisasi variabel
	int choice4;
	float a, b, interval, delta, x, tot(0);
	
	// menampilkan menu dan meminta inputan pilihan
	printf("Choose type of function:\n");
	printf("1. Polynomial Function f(x)=x^3+x+1\n2. Reciprocal Function f(x)=1/(1+x^2)\n");
	scanf("%d", &choice4);
	
	// validasi
	while (choice4!=1 && choice4!=2){
		printf("Input valid choice (1/2):\n");
		scanf("%d", &choice4);
	}
	
	// meminta input batas atas dan bawah serta jumlah interval
	printf("Input initial point : ");
	scanf("%f", &a);
	printf("Input final point : ");
	scanf("%f", &b);
	printf("Input number of intervals : ");
	scanf("%f", &interval);
	
	// perhitungan hasil integral dan pengembalian ke fungsi utama main()
	delta = (b-a)/interval;
	if (choice4==1){
		for(int j=1; j<interval; j++){
			x = a + (j*delta);
			tot += fs_polynomial(x);
		}
		return (fs_polynomial(a)+fs_polynomial(b)+(2*tot))*(delta/2);
	}
	else{
		for(int j=1; j<interval; j++){
			x = a + (j*delta);
			tot += fs_reciprocal(x);
		}
		return (fs_reciprocal(a)+fs_reciprocal(b)+(2*tot))*(delta/2);
	}
}
