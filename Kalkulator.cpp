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
		yang dapat dilakukan. User diminta untuk memasukkan 2 buah operand (diasumsikan benar) dan 1 buah operator. Hasil perhitungan 
		dikembalikan pada fungsi utama int main().
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
		Fungsi antara penghitungan perpangkatan angka one dengan angka two yang bertipe data float. Variabel two telah dipastikan berupa bilangan
		bulat sehingga hasil perpangkatan dapat ditampilkan tanpa menggunakan library math.h. Hasil perhitungan dikembalikan pada fungsi singleCalculation().
	
	9.	integral()
		Fungsi untuk menghitung nilai integral tentu dengan bantuan fungsi antara fs_polynomial(float x). Program dapat menghitung integral 
		dari fungsi yang bentuk umumnya adalah f(x)= ax^n + bx^o + cx^p + dx^q +.... User menginput jumlah suku dari fungsi tersebut yang 
		hendak dihitung, koefisien (a, b, c,..), dan pangkatnya (n, o, q, ...). Program juga meminta masukan user berupa batas atas dan 
		bawah integral, serta jumlah interval yang diinginkan user. Hasil perhitungan dikembalikan pada fungsi int main().
		Contoh input : 5 <press enter> 1 2 <press enter> 2 3 <press enter> 3 4 <press enter> 4 5 <press enter> 5 6 <press enter> 1 <press enter>
		20 <press enter> 20 <press enter>
		
	10.	fs_polynomial(float x)
		Fungsi untuk menghitung hasil pemetaan x pada fungsi f(x)=x^3+x+1. Hasil perhitungan dikembalikan pada fungsi integral().
	
	11.	isInteger(float s)
		Fungsi untuk mengecek apakah suatu bilangan merupakan bilangan bulat (sebagai syarat penghitungan pangkat dalam fungsi power().
		Menghasilkan true apabila merupakan bilangan bulat dan false jika sebaliknya
*/

// LIBRARY
#include <stdio.h>

float calculation();
float singleCalculation();
float addition(float one, float two);
float subtraction(float one, float two);
float multiplication(float one, float two);
float division(float one, float two);
float power(float base, float powers);
float integral();
float fs_polynomial(float x, int n, float coeff[], int powers[]);
bool isInteger(float s);

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
	int input_power;
	
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
		else{
			scanf("%f", &input);
			if (sign=='^'){
				while (isInteger(input)==false){
					printf("Input integer number for power\n");
					scanf("%f", &input);
				}
			}
		}
		// decision dan operasi perhitungan
		switch(sign){
			case '+' : total += input;
						break;
			case '-' : total -= input;
						break;
			case '*' : total *= input;
						break;
			case '/' : total /= input;
						break;
			case '^' : total = power(total, input);
						break;
		}
	}
}

bool isInteger(float s){
	// mengecek apakah s merupakan integer (bilangan bulat)
    if (s<1 && s>0)
    	return false;
    else if (s==0)
    	return true;
    else
    	return isInteger(s-1);
}

float singleCalculation(){
	// deklarasi variabel
	char Operator;
	float first, second;
	int second_power;
	
	// menampilkan menu dan meminta inputan user
	printf("Available operators: + - * / ^\n");
	
	printf("Input first number  : ");
	scanf("%f", &first);
	printf("Input operation : ");
	scanf("%s", &Operator);
	
	// validasi input dan meminta input ulang jika input tidak valid
	while (Operator!='+' && Operator!='-' && Operator!='*' && Operator!='/' && Operator!='^'){
		printf("Input valid operation (+ - * / ^): ");
		scanf("%s", &Operator);
	}
	
	printf("Input second number : ");
	scanf("%f", &second);
	if(Operator=='^'){
		while (isInteger(second)==false){
			printf("Input integer number for power!\n");
			scanf("%f", &second);
		}
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
	if (powers==0)
		return 1;
	else
		return (base * power(base, powers-1));
}

float fs_polynomial(float x, int n, float coeff[], float powers[]){
	// fungsi perhitungan fungsi Polynomial f(x)= ax^n + bx^o + cx^p + dx^q +...
	float total(0);
	for (int j=1; j<=n; j++){
		total += coeff[j]*power(x, powers[j]);
	}
	return total;
}

float integral(){
	// deklarasi dan inisialisasi variabel
	int choice4;
	float a, b, interval, delta, x, tot(0), temp;
	
	// menampilkan fungsi dengan n suku yang akan diminta user
	printf("The function is polynomial f(x)= ax^n + bx^o + cx^p + dx^q +... with n x terms\n"); 
	
	// meminta masukkan jumlah suku yang diinginkan, masukkan koefisien dan pangkat
	printf("Input number of x algebraic terms : ");
	scanf("%d", &choice4);
	
	float coeff[choice4+1]; // array for storing each coefficient
	float powers[choice4+1]; // array for storing powers to each corresponding coefficient
	
	// input koefisien dan pangkat suku-suku aljabar sebanyak choice4
	printf("For all %d x terms, input the coefficient (float) and power (integer) :\n", choice4);
	for (int j=1; j<=choice4; j++){
		scanf("%f \t %f", &coeff[j], &powers[j]);
		// validasi input
		while (isInteger(powers[j])==false){
			printf("Input integer number for power!\n");
			scanf("%f", &powers[j]);
		}
	}
	
	// meminta input batas atas dan bawah serta jumlah interval
	printf("Input initial point : ");
	scanf("%f", &a);
	printf("Input final point : ");
	scanf("%f", &b);
	printf("Input number of intervals : ");
	scanf("%f", &interval);
	
	// perhitungan hasil integral melalui fungsi antara dan pengembalian hasil ke fungsi utama main()
	delta = (b-a)/interval;
	
	for(int j=1; j<interval; j++){
		x = a + (j*delta);
		tot += fs_polynomial(x, choice4, coeff, powers);
	}
	return (fs_polynomial(a, choice4, coeff, powers)+fs_polynomial(b, choice4, coeff, powers)+(2*tot))*(delta/2);
}
