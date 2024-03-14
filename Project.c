#include <stdio.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <unistd.h>

void cash();
void card();


int flag=0;


float gst=0, gtotal=0;
int biryani_price = 200;
int total = 0;
int quantity1, quantity2, quantity3, quantity4, quantity5;
int userorder = 0;
int nihari_price = 200;
int pulao_price = 200;
int karahi_price = 300;
int haleem_price = 400;



struct cust_info{
	char fname[15];
	char lname[15];
};

struct cust_info cust;

void basic_info(){
	printf("\nEnter your first name: ");
	scanf("%s",cust.fname);
	printf("\n\nEnter your second name: ");
	scanf("%s",cust.lname);
	strcat(cust.fname," ");
	strcat(cust.fname,cust.lname);
}

void gotoxy (int x, int y)
 {
	COORD c;
	c.X=x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void load_screen() {
	system("cls");
	gotoxy(50, 7);
	printf("\x1b[33m Loading ...");
	gotoxy(50, 8);
	for (int i=1; i<=20;i++) {
		for (int j=0; j<=10000000; j++);
		printf("%c", 219);
	}
	system("cls");
}

 static int seats[5][10];  

//static int seats[5][10] = 1;

void saveSeating()
 {
    FILE *file = fopen("seating.dat", "wb");  // Change "w" to "a"
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    fwrite(seats,sizeof(seats[0][0]), sizeof(seats)/sizeof(seats[0][0]), file);

    fclose(file);
}


void loadSeating() {

    FILE *file = fopen("seating.dat", "rb");
    
    fread(seats,sizeof(seats[0][0]), sizeof(seats)/sizeof(seats[0][0]), file);


    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 10; y++) {
            printf(" %d ", seats[x][y]);
        }
        printf("\n");
    }
    

    fclose(file);
}

void seating() {

    loadSeating();
    int n, row, col;
    int x = 0, y = 0;
    // initializing seats

    printf("\n\nEnter the amount of seats you want (n): ");
    scanf("%d", &n);

    for (y = 0; y < n; y++) {
        printf("Enter the row and column number you want to reserve (x)(y): ");
        scanf("%d%d", &row, &col);
        seats[row - 1][col - 1] = 0;
        
		//1 meaning seat available
        //0 meaning seat taken
        
    }
	
    saveSeating(); // Save seating arrangement after taking new orders
    
}
    



void printMenu(){
	printf("\x1B[0m");
   
    printf("\n\n\n\t\t\tWelcome to FAST canteen.\n\n");
    printf("\t\t\tThe following is our menu: \n");
    printf("\n\t-------------------------------------------------------------------------------------\n");
    printf("\n\n\t\tDescription \t\t|\t Price\t\t|\tItem Number\n\n");
    printf("\n\t-------------------------------------------------------------------------------------\n");
    printf("\n\t\tBiryani \t\t|\t %d\t\t|\t\t1", biryani_price);
    printf("\n\n\t\tPulao \t\t\t|\t %d\t\t|\t\t2", pulao_price);
    printf("\n\n\t\tKarahi \t\t\t|\t %d\t\t|\t\t3", karahi_price);
    printf("\n\n\t\tNihari \t\t\t|\t %d\t\t|\t\t4", nihari_price);
    printf("\n\n\t\tHaleem \t\t\t|\t %d\t\t|\t\t5\n", haleem_price);
    printf("\n\t------------------------------------------------------------------------------------\n");
    printf("\n\n");
}


void stocks(int x,int q){
	static int biryani=10 ;
	static int pulao=10 ;
	static int karahi=10 ;
	static int nihari=10 ;
	static int haleem=10 ;
	
	if(x==1){
	if(biryani-q<0){
		printf("This quantity of biryani is out of stock\n auto-ordered for new stock! ");
		biryani = 10;
	}
		

	else{
		biryani = biryani-q;
	
		printf("\n\nThis quantity of biryani is available\n");

		printf("\n\nBiryani left in stock: %d",biryani);
	}
	if(biryani<2){
		printf("\nbiryani is low on stock auto-ordered for new stock!");
		biryani=10;
	}
}
	
	if(x==2){
	if(pulao-q<0){
		printf("This quantity of pulao is out of stock\n auto-ordered for new stock! ");
		pulao = 10;
		}
	else{
		pulao = pulao-q;
		printf("this quantity of pulao is available\n");
		printf("pulao left in stock: %d",pulao);
	}
	if(pulao<2){
		printf("\nkarahi is low on stock auto-ordered for new stock!");
		pulao=10;
	}
	}
	
	if(x==3){
	if(karahi-q<0){
		printf("This quantity of karahi is out of stock\n auto-ordered for new stock! ");
		karahi = 10;
		
		
	}
	else{
		karahi = karahi-q;
		printf("this quantity of karahi is available\n");
		printf("karahi left in stock: %d",karahi);
	}
	if(karahi<2){
		printf("\nkarahi is low on stock auto-ordered for new stock!");
		karahi=10;
	}
	}
	
	if(x==4){
	if(nihari-q<0){
		printf("This quantity of nihari is out of stock\n auto-ordered for new stock! ");
		nihari = 10;
		
		
	}
	else{
		nihari = nihari-q;
		printf("this quantity of nihari is available\n");
		printf("biryani left in stock: %d",nihari);
	}
	if(nihari<2){
		printf("\nnihari is low on stock auto-ordered for new stock!");
		nihari=10;
	}
	}
	
	if(x==5){
	if(haleem-q<0){
		printf("This quantity of haleem is out of stock\n auto-ordered for new stock! ");
		haleem = 10;
		
		
	}
	else{
		haleem = haleem-q;
		printf("this quantity of haleem is available\n");
		printf("haleem left in stock: %d",haleem);
	}
	if(haleem<2){
		printf("\nhaleem is low on stock auto-ordered for new stock!");
		haleem=10;
	}
	}
	
	FILE *fp;
	fp = fopen("stock.txt", "w");
	
	fprintf(fp, "Biryani: %d\n",  biryani);
	fprintf(fp, "Pulao: %d\n", pulao);
	fprintf(fp, "Karahi: %d\n",  karahi);
	fprintf(fp, "Nihari: %d\n",  nihari);
	fprintf(fp, "Haleem: %d\n",  haleem);
	
	fclose(fp);
	
}


void getorder() {
    char confirmation;

	system("cls");
    printMenu();

    while (userorder != 6) {
        printf("\n\nEnter item number of the dish you want to order: ");
        scanf("%d", &userorder);
        switch (userorder) {
            case 1:
                printf("\n\nYou have chosen Biryani, please specify your quantity: ");
                scanf("%d", &quantity1);
                stocks(userorder,quantity1);
                printf("\n\nYou can keep ordering or can enter '6' to finish order. ");
                total += biryani_price * quantity1;
                break;
            case 2:
                printf("\n\nYou have chosen Pulao, please specify your quantity: ");
                scanf("%d", &quantity2);
                stocks(userorder,quantity2);
                printf("\n\nYou can keep ordering or can enter '6' to finish order. ");
                total += pulao_price * quantity2;
                break;
            case 3:
                printf("\n\nYou have chosen Karahi, please specify your quantity: ");
                scanf("%d", &quantity3);
                stocks(userorder,quantity3);
                printf("\n\nYou can keep ordering or can enter '6' to finish order. ");
                total += karahi_price * quantity3;
                break;
            case 4:
                printf("\n\nYou have chosen Nihari, please specify your quantity: ");
                scanf("%d", &quantity4);
                stocks(userorder,quantity4);
                printf("\n\nYou can keep ordering or can enter '6' to finish order. ");
                total += nihari_price * quantity4;
                break;
            case 5:
                printf("\n\nYou have chosen Haleem, please specify your quantity: ");
                scanf("%d", &quantity5);
                stocks(userorder,quantity5);
                printf("\n\nYou can keep ordering or can enter '6' to finish order. ");
                total += haleem_price * quantity5;
                break;
            case 6:
                printf("\n\nOrder finished. Do you want to confirm and proceed with the order (y) or cancel and re-order (n): ");
                scanf(" %c", &confirmation);
                if (confirmation == 'y') {
                    saveSeating(); // Save seating arrangement before exiting
                    break;
                } else if(confirmation == 'n') {
                    printf("\n\nOrder cancelled\n");
                    userorder = 0;
					getorder(); // Recursion
                }
                
                break; // Added break here to exit the loop after case 6
            default:
                printf("\nInvalid choice. Please enter a valid item number.\n");
        }

        
    }
    cust_choice();
}


void payment_method(){
	int paychoice;
	printf("\nEnter 1 for payment with cash or enter 2 for payment with credit/debit card: ");
	scanf("%d",&paychoice);
	
	switch(paychoice){
		case 1:
			cash();
			break;
		
		case 2:
			card();
			break;
	}
}


void card(){
	int valid=0,count=0;
	char card_num[13];
	char cardpin[6];
	displaybill();
//checking card number
	do{
	if (count != 0){
		printf("\n\n\nRe-enter your 12 digit card number: ");
		scanf("%s",card_num);
	}
	if (count == 0){
		printf("\n\n\nEnter your 12 digit card number: ");
		scanf("%s",card_num);}
	if (strlen(card_num) == 12){
		valid =1;
	}
	count += 1;
	}while(valid != 1);
	
	valid =0;
	count = 0;
	
	char name[30];
	printf("\n\nEnter the cardholder's name: ");
	scanf("%s",name);
	
	char expdate[6];
	
	do{
		printf("\n\nEnter the expiry date(MM/YY) of the card: ");
		scanf("%s",expdate);
		if (strlen(expdate) == 5 ){
			valid = 1;
		}
	}while(valid != 1);
	
	valid = 0; 
	count = 0;
//checking card pin	
	do{
		if (count ==0){
		printf("\n\nEnter your 3-4 digit card pin: ");
		scanf("%s",cardpin);}
		
		if (count != 0){
			printf("\n\nCorrectly re-enter your 3-4 digit card pin: ");
			scanf("%s",cardpin);
		}
		if (strlen(cardpin) == 3 || strlen(cardpin) == 4 ){
			valid = 1;
		}
		count += 1;
	}while(valid != 1);
	
	printf("\n\n\t\tPayment with card has been successful. ");
	
	time_t currentTime;
    struct tm *localTime;

    time(&currentTime);
    localTime = localtime(&currentTime);




    printf("\n\nCustomer: %s, your bill was printed at: %sby cashier: Zohaib Hyderabadi.\n\n",cust.fname,asctime(localTime));

	printf("Thank you for choosing FAST canteen :-))");
	
    
	sleep(5);
		
}
    
  
void cash() {
    int cash;
    float change;
    
    displaybill();
    
    do {
        
        printf("\n\nEnter the cash amount you are paying Rs.");
        scanf("%d", &cash);

        if (cash < gtotal) {
            change = gtotal - cash ;
			printf("\n\nInsufficient cash. You are short by %.2f",change);
        }
    } while (cash < gtotal);

    change = gtotal - cash;
    printf("\n\nPayment successful! Change: Rs%.2f\n\n", change);
    
   time_t currentTime;
    struct tm *localTime;

    time(&currentTime);
    localTime = localtime(&currentTime);




    printf("\n\nCustomer: %s, your bill was printed at: %sby cashier: Zohaib Hyderabadi.\n\n",cust.fname,asctime(localTime));

	printf("Thank you for choosing FAST canteen :-))");
	
   
    sleep(5);
}
    

void displaybill(){
	
	gst = 0.16 * total;
	gtotal = gst + total;
	system("cls"); 			// clearing the screen
	printf("\nThe following is your bill: ");
	printf("\nItem Total: \t\t|\t%d", total);
    printf("\n\n\nG.S.T: \t\t\t|\t%.1f", gst);
    printf("\n\n----------------------------------------------\n");
    printf("\n\nGrand Total: \t\t|\t%.1f", gtotal);

    
    
}

	
void cust_choice(){
	int choice;
	int valid=0;
	do{
	
	printf("\n\nEnter 1 for dining in, 2 for take away, 3 for home delivery: ");
	scanf("%d",&choice);
	if (choice == 1 | choice == 2 | choice == 3 ){
		valid = 1;
	}
	
	}while(valid != 1);

	switch(choice){
		case 1:
			system("cls");
			seating();
			break;
		case 2:
			system("cls");
			flag = 1;
			take_away();
			break;
		case 3:
			system("cls");
			flag = 1;
			delivery();
			break;
	}
	
}


void take_away(){
	int count;
	char str_count[10];
	FILE *fp1;
	fp1 = fopen("queue.txt","r");
	fscanf(fp1,"%s %d",str_count,&count);
	fclose(fp1);
	
	fp1 = fopen("queue.txt","w");
	printf("\n\nYou have %d people in the queue. You can take your order accordingly.",count);
	
	count += 1;
	
	fprintf(fp1,"%s %d",str_count,count);
	
	sleep(5);
	
	fclose(fp1);
}

void delivery(){
	char address[30];
	int valid=0;
	
	do{
		printf("\n\nEnter your address: ");
		scanf("%s",address);
		printf("\n\nYour location is: %s",address);
		printf("\n\nConfirm your location by entering 1 or 2 to re-enter location: ");
		scanf("%d",&valid);
	}while(valid != 1);
	printf("\n\nYour order will be delivered to: %s ",address);
	
	sleep(3);
}

int main() {
	int day=1;    

	load_screen();
	while (day != 0 ){
		
		
		
	
    FILE *file = fopen("seating.dat", "rb");
    
		
    if (file == NULL) {
        // File doesn't exist, initialize the seats array
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 10; j++) {
                seats[i][j] = 1;
            }
        }
    }
	else {
        // File exists, load the seating arrangement
        fclose(file);
        loadSeating();
        
        
    }
    
    	
    	basic_info();
		getorder();
		system("cls");
    	
		if (flag == 0){
			seating();
		}
		
    	payment_method();
    	displaybill();
    
    	
    	
	printf("\n\nPress 0 to finish day, 1 to keep going: ");
	scanf("%d",&day);

	userorder = 0;
}
    
}