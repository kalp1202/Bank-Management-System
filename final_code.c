                   /* PROJECT ON BANKING SYSTEM */                        
/* WHERE ANY APPLICANT PERSON CAN OPEN THERE NEW ACCOUNT AND DO ANY KIND OF 
   DEPOSIT, WITHDRAW AND TRANSFER THE MONEY FROM THEIR ACCOUNT THROUGH ITS 
   BASIC AND MANDOTARY PROCESS SYSTEM */
// include the header files
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

// defination section
#define minimum_balance 1000
#define maximum_deposit 50000
#define maximum_withdraw 25000

// function declaration (function prototype)
void list();
void information();
void details();
void photoid();
void jointAccount();
void deposit();
void withdraw();
void transfer();
void checkDetails_deposit();
void checkDetails_withdraw();
void checkDetails_transfer();
int notesInformation();
void chequeDetails();
void bankPurpose(); 
void currentAccountInformation();
void communicationDetails();

// global declaration of variables which are having different tyoes of datatypes
char first_name[10],middle_name[10],last_name[10],nationality[10];
char residentail_address[50],city[10],state[10],country[10],email[30];
char specific_qualification[10],specific_occupation[10],specific_intity[10],specific_business[10],specific_industry[10];
int title_choice,gender_choice,qualification_choice,occupation_choice,mobile_number;
int account_choice,choice,fdcount,fdamount;
double account_number,adhar_number;
char name[30],accountant_name[30];
double contact_number;
char address[50],dematid[30];
char fdtime[10],joint_accountant_name[30],relationist[10];
int b_dd,b_mm,b_yyyy,dd,mm,yyyy;
long int pin_code,cheque_number,pan_number,registration_number;
int deposit_amount,total_deposit=0,current_balance=5000;
int withdraw_amount,total_withdraw=0;
char bank_name[10],incoropation_place[20],designation[30];
int transfer_amount,total_transfer=0,transfer_account,bank_choice,intity_choice,business_choice,industry_choice;

// main function 
int main()
{
	printf("***************WELCOME TO BANK OF BARODA***************\n");
	printf("\n");
	printf("*****************BRANCH : MANINAGAR********************\n");
	printf("\n");
	information();
	fflush(stdin);
	while(1)
		list();
	return 0;
}

// function list is for printing this below list 
void list()
{
	//  choice for which kind of transicition or want to open any kind of new account or want to exit that section to stop it
	printf("----------------------------------------------------------------------------------\n"); 
	printf("1. FOR OPENING NEW ACCOUNT\n");
	printf("2. FOR DEPOSIT\n");
	printf("3. FOR WITHDRAW\n");																		
	printf("4. FOR TRANSFER\n");
	printf("5. FOR EXIT\n");
	printf("ENTER YOUR CHOICE\n");
	scanf("%d", &choice);
	// user's choice is stored here in this choice variable and further actions will take plce 
	printf("-----------------------------------------------------------------------------------\n");
	switch(choice)
	{
			// for which kind of account do you want to open 	
			case 1: 
				printf("HERE, THE TYPES OF ACCOUNT\n");
				printf("1. SAVING ACCOUNT\n");
				printf("2. CURRENT ACCOUNT\n");																				 
				printf("3. FIXED DEPOSITE ACCOUNT\n");
				printf("ENTER YOUR CHOICE FOR WHICH TYPE OF ACCOUNT YOU WANT TO OPEN\n");
				scanf("%d", &account_choice);
				switch(account_choice)
				{
					// for saving account
					case 1:
							printf("----------------------------------------------------------------\n");				
							details();
							printf("SCAN YOUR PHOTO, HERE..\n");
							photoid();
							printf("                               SIGNATURE(SCAN)\n");						 
							printf("                               _________\n");	
							jointAccount();	
							bankPurpose();		
							printf("\n\n------NOW, AS PER RULES YOU HAVE TO KEEP %d RUPEES IN YOUR ACCOUNT-------\n\n", minimum_balance);
							break;		
					
					// for current account			 
					case 2: 
							printf("----------------------------------------------------------------\n");
							currentAccountInformation();
							break;							 
					
					// for fixed deposite account						
					case 3: 
							printf("----------------------------------------------------------------\n");
							fflush(stdin);
							information();	
							printf("AMOUNT FOR DEPOSIT                                                          ");
							scanf("%d", &fdamount);
							printf("FOR HOW LONG WOULD YOU DEPOSI (MONTHS/YEARS) i.e.(6 months/3 years)         ");
							scanf("%d %s", &fdcount,fdtime);
							printf("SCAN YOUR PHOTO, HERE..\n");											
							photoid();
							printf("                               SIGNATURE(SCAN)\n");						
							printf("                               _________\n");
							jointAccount();
							break;
				}
				break;
	
			// for deposite the amount in user's account and further only print withdrawed and transfered amount by getting information about accoutant
			case 2:
					printf("\n\t\t\tYOUR CURRENT BALANCE IS %d\n\n", current_balance);
					deposit();
					total_deposit = total_deposit + deposit_amount; 			
					checkDetails_deposit();
					printf("TOTAL WITHDRAW: %d\n", total_withdraw);										
					printf("TOTAL TRANSFER: %d\n", total_transfer);
					break;
			
			// 	for withdraw the amount in user's account and further only print deposited and transfered amount by getting information about accoutant
			case 3:
					printf("\n\t\t\tYOUR CURRENT BALANCE IS %d\n\n", current_balance);
					withdraw();
					checkDetails_deposit();
					checkDetails_withdraw();															
					printf("TOTAL TRANSFER: %d\n", total_transfer);
					break;
					
			// for transfer the amount from user's account or to their account and further only print deposited and withdrawed amount by getting information about accoutant	
			case 4: 
					printf("\n\t\t\tYOUR CURRENT BALANCE IS %d\n\n", current_balance);
					transfer();
					checkDetails_deposit();
					printf("TOTAL WITHDRAW: %d\n", total_withdraw);										
					checkDetails_transfer();
					break;
			
			// for exit that choices and stop here by this case				
			case 5:
					exit(0);																			
			
			// to print for specific choice by this default 		
			default: printf("ENTER SPECIFIC CHOICE\n\n");
	}
}

// for deposit the amount 
void deposit()
{
	int carry_total;
	printf("----------------HOW MANY RUPEES YOU WANT TO DEPOSIT IN YOUR ACCOUNT---------------\n");
	printf("--------IF YOUR AMOUNT IS GREATER THAN %d YOU HAVE TO PAY A CHEQUE FOR IT-------\n", maximum_deposit);
	scanf("%d", &deposit_amount);						// deposit amount is stored in deposit_amount variable which is integer type
	
	// if deposited ammount would be greater than maximum can deposit by cash which is 50000/- so deposite by cheque 
	if(deposit_amount>=maximum_deposit)
	{
		printf("---------------AS YOU KNOW YOU HAVE TO PAY THROUGH A CHEQUE--------------------\n");
		chequeDetails();								// about cheque information which would be called here by chequeDetails function
		printf("                               SIGNATURE(SCAN)\n");		
		printf("                               _________\n");
		printf("AMOUNT : %d\n", deposit_amount);
		current_balance += deposit_amount;				// add that deposit amount in current balance and further stored in current balance
		// here, print that balance and date information after deposit the amount
		printf("---------------------TOTAL BALANCE : %d ON DATE %d/%d/%d---------------------\n", current_balance,dd,mm,yyyy);
	}
	
	// if deposited amount would be smaller than maximum deposit which is 25000/- so deposit by cash
	else
	{
		carry_total=notesInformation();					// if it would be by cash so its notes information would be called by notesInformation function and return that total amount here
		if(deposit_amount==carry_total)					// if deposit amount and after notes calculations that total amount is same so further actions take place 
		{
			printf("SO, TOTAL AMOUNT IS %d\n", carry_total);
			current_balance += deposit_amount;			// add that deposite amount in current balance and further stored in current balance
				// here, print that balance and date information after deposite the amount
			printf("---------------------TOTAL BALANCE : %d ON DATE %d/%d/%d----------------------\n", current_balance,dd,mm,yyyy);
		} 
		else
		{	 
			printf("\t\t---------PLEASE, PAY VALID NOTES FOR YOUR DEPOSIT AMOUNT--------\n");					// print for valid and calcualted notes for deposit amount
			deposit_amount=0;
		}
	} 
}

// for withdraw the amount 
void withdraw()
{
	printf("------------HOW MANY RUPEES YOU WANT TO WITHDRAW FROM YOUR ACCOUNT-------------\n");
	scanf("%d", &withdraw_amount);						// withdraw amount is stored in withdraw_amount variable which is integer type
	
	// if withdrawed amount would be greater than maximum can withdraw by cash which is 25000/- so deposite by cheque
	if(withdraw_amount>=maximum_withdraw)
	{
		if(withdraw_amount<current_balance)
		{
			printf("-----AS YOU KNOW, YOUR AMOUNT IS GREATER THAN %d SO YOU HAVE TO WITHRAW BY CHEQUE-----\n", maximum_withdraw);
			chequeDetails();								// about cheque information which would be called here by chequeDetails function
			printf("                               SIGNATURE(SCAN)\n");		
			printf("                               _________\n");
			printf("AMOUNT : %d\n", withdraw_amount);
		}
		else
		{
			printf("\t\t---------THERE IS NO ENOUGH BALANCE FOR WITHDRW THE AMOUNT---------\n");				// here, print no enough current balance for withdraw amount
			withdraw_amount=0;
		}
	}
	
	// if withdraw amount would be lesser than current balance so further actions take place
	if(withdraw_amount<current_balance)
	{
		printf("DATE: (DD/MM/YYYY)\t");
		scanf("%d/%d/%d", &dd,&mm,&yyyy);
		current_balance -= withdraw_amount;				// subtract that withdraw amount from current balance and further stored in current balance 
		printf("\n");
		
			// here, print that balance and date information after deposite the amount
		printf("---------------------TOTAL BALANCE : %d ON DATE %d/%d/%d----------------------\n", current_balance,dd,mm,yyyy);
	}
	else
	{
		printf("\t\t--------THERE IS NO ENOUGH BALANCE FOR WITHDRW THE AMOUNT---------\n");				// here, print no enough current balance for withdraw amount
		withdraw_amount=0;
	}
}

// for transfer the amount
void transfer()
{
	printf("------------HOW MANY RUPEES YOU WANT TO TRANSFER FROM YOUR ACCOUNT-------------\n");
	scanf("%d", &transfer_amount);						// transfer amount is strored in transfer_amount which is integer type
	
	// if the trasnfer amount would be lesser than the current balnce so further actions take place
	if(transfer_amount<current_balance)
	{
		current_balance -= transfer_amount;			// subtract the transfer amount from current balance and further stored in current balance variable which is integer type
		printf("\n");
		printf("DATE: (DD/MM/YYYY)\t");
		scanf("%d/%d/%d", &dd,&mm,&yyyy);
		// for asking about the transfer amount is from another bank or not...
		printf("IF IT IS TO OTHER BANK...?\n1. Yes	2. No\n");
		fflush(stdin);	 
		scanf("%d", &bank_choice);
		switch(bank_choice)
		{
			case 1: 
					// name of the bank from the amount would be transfered	
					printf("PLEASE ENTER BANK NAME:                                                ");
					fflush(stdin);
					scanf("%s", bank_name);
					printf("ENTER ACCOUNT NUMBER IN WHICH ACCOUNT YOU WANT TO TRANSFER THE MONEY:  ");
					scanf("%d", &transfer_account);		// account number where the amount would be transfered
					break;
			case 2: printf("THANK YOU!\n");
		}
		chequeDetails();								// about cheque information which would be called here by chequeDetails function
  		printf("AMOUNT : %d\n", transfer_amount);
		printf("                                SIGNATURE(SCAN)\n");		
		printf("                             	_________\n");
		// here, print that balance and date information after deposite the amount
		printf("-----------------------TOTAL BALANCE : %d ON DATE %d/%d/%d------------------------\n", current_balance,dd,mm,yyyy);
		printf("------IF IT IS FROM OTHER BANK, IT WILL BE PASSED AFTER CLEARING IN A ONE DAY-----\n");
	}
	else
	{
		printf("\t\t-------THERE IS NO ENOUGH BALANCE FOR TRANSFER THE AMOUNT-------\n");			// print not enough balance for transfer the money
		transfer_amount=0;
	}	
}

// function checkDetails_deposit is for only print total deposit amount after some calculations 
void checkDetails_deposit()
{ 
	printf("----------------------------------------------------------------------------------\n");
	if(deposit_amount!=0)
		printf("TOTAL DEPOSIT: %d\n",total_deposit);
	else
		printf("TOTAL DEPOSIT: %d\n",total_deposit);
}

// function checkDetails_withdraw is for adding withdrawed amount
void checkDetails_withdraw()
{
	if(withdraw_amount==0)
		printf("TOTAL WITHDRAW: %d\n", total_withdraw);
	else
	{
		total_withdraw += withdraw_amount;					// add withdraw amount to total_withdraw variable which is integer type
		printf("TOTAL WITHDRAW: %d\n",total_withdraw);	
	}
}

// function checkDetails_transfer is for adding transfered amount
void checkDetails_transfer()
{
	if(transfer_amount==0)
		printf("TOTAL BALANCE: %d\n", total_transfer);
	else
	{
		total_transfer  += transfer_amount;					// add transfer amount to total_transfer variable which is integer type 
		printf("TOTAL TRANSFER: %d\n", total_transfer);
	}
}

// function information is for details like name and account number only about accoutant 
void information()
{
	printf("FULL NAME:         ");
	fflush(stdin);
	gets(accountant_name);
	printf("ACCOUNT NUMBER:\t   ");
	scanf("%ld", &account_number);
}

// function photoid for insert the photo for any kind of applicant
void photoid()
{
	int i,j;
	for(i=0; i<6; i++)
	{						
		for(j=0; j<6; j++)
		{
			if(i==0 || i==5 || j==0 || j==5)
				printf("- ");
			else
				printf("  ");
		}
		printf("\n");
	}
}

// function joinAccount for joint that any kind of account with first applicant
void jointAccount()
{
	int accountant_choice;
	printf("\n");
	printf("\n");
	printf("IF YOU WANT TO MAKE IT JOINT ACCOUNT...?\n");
	printf("1. YES\n2. NO\n");
	printf("ENTER YOUR CHOICE  ");
	scanf("%d", &accountant_choice);
	switch(accountant_choice)
	{
		case 1: 		
				// details about that second appicant who wants to join the account
				printf("--------------------------------------------------\n");
				information();
				printf("WHAT IS YOUR RELATION..?         ");
				fflush(stdin);
				gets(relationist);
				printf("SCAN YOUR PHOTO, HERE..\n"); 
				photoid();
				printf("                               SIGNATURE(SCAN)\n");		
				printf("                               _________\n");
				printf("--------------------------------------------------\n");	
				break;
		case 2: 
				printf("OKAY!\nTHANK YOU!\n");
				printf("--------------------------------------------------\n");
				break;
	}
}

// function bbankPurpose is only for bank which fills that account number as well as id number about accoutant
void bankPurpose()
{
	printf("\n");
	printf("\n");
	printf("---------------ONLY FOR BANK PURPOSES-------------\n");
	printf("ACCOUNT NUMBER :\n");
	printf("CUSTOMER ID NUMBER :\n");
	printf("DATE :\n");
	printf("--------------------------------------------------\n");	
}

// function details about fill up the form 
void details()
{  
	// account details about applicant
	printf("--------------DETAILS OF ACCOUNT------------------\n");
	printf("1. TITLE:\t");
	printf("1. Mr.    2. Mrs.    3. Ms\n");
	printf("ENTER CHOICE\t");
	scanf("%d", &title_choice);
	printf("--------------------------------------------------\n");
	printf("2. ACCOUNANT NAME:   ");
	printf("FIRST:\t");
	scanf("%s", first_name);
	printf("                     ");
	printf("MIDDLE:\t");
	scanf("%s", middle_name);
	printf("                     "); 
	printf("LAST:\t");
	scanf("%s", last_name);
	printf("--------------------------------------------------\n");
	printf("3. DATE 0F BIRTH: (DD/MM/YYYY)\t");
	scanf("%d/%d/%d", &dd, &mm, &yyyy);
	printf("--------------------------------------------------\n");
	printf("4. GENDER:\t");
	printf("1. Male    2. Female    3. Others\n");
	printf("ENTER CHOICE\t");
	scanf("%d", &gender_choice);
	printf("--------------------------------------------------\n");
	printf("5. NATIONALITY: \t");
	fflush(stdin);
	gets(nationality);
	printf("--------------------------------------------------\n");
	printf("6. ADHAR NUMBER: \t");
	scanf("%d", &adhar_number);
	printf("\n\n");	
	// function for details about communication 
	communicationDetails();
	printf("\n\n");
	// details about qualification for opening of saving account
	printf("----------------PERSONAL DETAILS------------------\n");
	printf("EDUCATIONAL QUALIFICATION: \t ");
	printf("1. UNDERGRDUATE    2. GRADUATE    3. POST GRADUATE    4. OTHERS\n");
	printf("ENTER CHOICE \t");
	scanf("%d", &qualification_choice);
	switch(qualification_choice)
	{
		case 4: printf("PLEASE SPECIFY \t");
				scanf("%s", specific_qualification);
				break;
	}
	printf("\n\n");	
	// details about occupation for opening of saving account
	printf("----------------OCCUPATION DETAILS----------------\n");
	printf("1. STUDENT    2. HOUSEWIFE    3. SALARIED    4. SELF-EMPLOYED    5. BUSINESS    6. RETIRED    7. OTHERS\n");
	printf("ENTER CHOICE \t");
	scanf("%d",&occupation_choice);
	switch(occupation_choice)
	{
		case 7: printf("PLEASE SPECIFY \t");
				scanf("%s", specific_occupation);
				break;
	}
}

// function currentAccountInformation for details which is only for opening new current account 
void currentAccountInformation()
{
	printf("--------------DETAILS OF ACCOUNT------------------\n");
	printf("ACCOUTANT NAME:                                ");
	fflush(stdin);
	gets(accountant_name);
	printf("--------------------------------------------------\n");
	printf("DATE OF BIRTH / INCORPORATION (DD/MM/YYYY):    ");
	scanf("%d/%d/%d", &dd, &mm, &yyyy);
	printf("--------------------------------------------------\n");
	printf("PLACE OF INCORPORATION:                        ");
	fflush(stdin);
	gets(incoropation_place);
	printf("--------------------------------------------------\n");
	printf("DATE OF COMMENCEMENT OF BUSINESS (DD/MM/YYYY): ");
	scanf("%d/%d/%d", &dd, &mm, &yyyy);
	printf("--------------------------------------------------\n");
	printf("REGISTRATION NUMBER:                           ");
	scanf("%ld", &registration_number);
	printf("--------------------------------------------------\n");
	printf("\n\n");
	// function for details about communication
	communicationDetails();
	printf("--------------------------------------------------\n");
	printf("DEGISNATION OF CONTACT PERSON: ");
	fflush(stdin);
	gets(designation);	
	printf("\n\n");
	// details about intities of business account
	printf("------------------TYPES OF INTITY-----------------\n");
	printf("1.  INDIVIDUAL\n2.  PARTNERSHIP\n3.  PRIVATE LIMITED COMPANY\n4.  LIMITED COMPANY\n5.  PUBLIC SECTOR/GOVERMENT ENTITY\n6.  ASSOCIATION/SOCIETY\n7.  TRUST\n8.  FOREIGN COMPANY\n9.  OTHERS\n");
	printf("ENTER CHOICE \t");
	scanf("%d", &intity_choice);
	switch(intity_choice)
	{
		case 9:
				printf("PLEASE SPECIFY \t");
				scanf("%s", specific_intity);
				break;
	}
	printf("\n\n");
	// details about which kind of business account do you want to open
	printf("------------------NATURE OF BUSINESS---------------\n");	
	printf("1.  MANUFACTURING\n2.  FINANCE/INVESMENT\n3.  EXPORT/IMPORT\n4.  SERVICE PROVIDER\n5.  TRADING\n6.  CHARTERED ACCOUTANT\n7.  COMMISSION AGENT/BROKER\n8.  LOTTERY\n9.  LAWYERS\n10. MONEY EXCHANGER\n11. OTHERS\n");
	printf("ENTER CHOICE \t");
	scanf("%d", &business_choice);
	switch(business_choice)
	{
		case 11: 
				printf("PLEASE SPECIFY \t");
				scanf("%s", specific_business);
				break;
	}	
	printf("\n\n");
	printf("--------------NATURE OF INDUSTRY--------------------\n");
	printf("1.  ENGINEERING/ARCHITECTUAL FIRM\n2.  IT SOFTWARE/HARDWARE\n3.  FINANICIAL SERVICES\n4.  CONSTRUCTION\n5.  FOOD PRODUCTS\n6.  POWER/ELECTRICIN\n7.  TEXTILE\n8.  TRANSPORT\n9.  HOTEL/RESTURENT\n10. GEMS/JEWELLERY\n11. LEATHER\n12. METALS\n13. OTHERS\n");        
	printf("ENTER CHOICE \t");
	scanf("%d", &industry_choice);
	switch(industry_choice)
	{
		case 13: 
				printf("PLEASE SPECIFY \t");
				scanf("%s", specific_industry);
				break;
	}
	
	int partners=0,i;
	long int passport_number;
	char name_[30];
	printf("HOW MANY PARTERS ARE THERE FOR THIS CURRENT TYPE ACCOUNT...?");
	scanf("%d", &partners);
	// for loop for how many partnes for this current account
	for(i=1; i<=partners; i++)
	{			
		printf("-----------------DETAILS OF PARTNERS----------------\n");
		printf("NAME:  ");
		fflush(stdin);
		gets(name_);
		printf("--------------------------------------------------\n");
		printf("DATE 0F BIRTH: (DD/MM/YYYY)\t");
		scanf("%d/%d/%d", &dd, &mm, &yyyy);
		printf("\n\n");
		communicationDetails();
		printf("--------------------------------------------------\n");
		printf("PAN NO.: ");
		fflush(stdin);
		scanf("%ld", &pan_number);
		printf("--------------------------------------------------\n");
		printf("PASSPORT/DRIVING NO.:  ");
		fflush(stdin);
		scanf("%ld", &passport_number);
		printf("--------------------------------------------------\n");
		printf("SCAN YOUR PHOTO,HERE..\n");
		photoid();
		printf("\n");
		printf("                               SIGNATURE(SCAN)\n");		
		printf("                               _________\n");
	}
}

// function communicationDetails for details about communication of accoutant 
void communicationDetails()
{
	printf("--------------COMMUNICATION DETAILS---------------\n");
	printf("ADDRESS: \t");
	fflush(stdin);
	gets(residentail_address);
	printf("--------------------------------------------------\n");
	printf("CITY: \t ");
	scanf("%s", city);
	printf("--------------------------------------------------\n");
	printf("STATE: \t ");
	scanf("%s", state);
	printf("--------------------------------------------------\n");
	printf("COUNTRY: \t ");
	scanf("%s", country);
	printf("--------------------------------------------------\n");
	printf("PIN CODE: \t ");
	scanf("%ld", &pin_code);
	printf("--------------------------------------------------\n");
	printf("MOBILE: \t");
	fflush(stdin);
	scanf("%ld", &mobile_number);
	printf("--------------------------------------------------\n");
	printf("EMAIL: \t ");
	fflush(stdin);
	scanf("%s", email);
}

// function chequeDetails for cheque that details for any kind of transiction
void chequeDetails()
{
	printf("CHEQUE NUMBER:                             "); 	
	scanf("%d", &cheque_number);
	printf("DATE (DD/MM/YYYY):                         ");
	scanf("%d/%d/%d", &dd,&mm,&yyyy);
	printf("CONTACT NUMBER:                            ");
	fflush(stdin);
	scanf("%d", &contact_number);
	printf("                                         \n");
}

// function notesInformation for calculating the deposite amount which is deposited by cash and further information about notes for deposite that amount 
int notesInformation()
{
	
		int tt,fh,th,h,f,tw,te,total=0;
		printf("------------------\n");
		printf("DATE (DD/MM/YYYY):          ");
		scanf("%d/%d/%d", &dd,&mm,&yyyy);
		printf("NOTES INFORMATION\n");
		printf("NOTES OF 2000  ");
		fflush(stdin);
		scanf("%d", &tt);
		printf("NOTES OF  500  ");
		scanf("%d", &fh);
		printf("NOTES OF  200  ");
		scanf("%d", &th);
		printf("NOTES OF  100  ");
		scanf("%d", &h);
		printf("NOTES OF   50  ");
		scanf("%d", &f);
		printf("NOTES OF   20  ");
		scanf("%d", &tw);
		printf("NOTES OF   10  ");
		scanf("%d", &te);
		printf("----------------------\n");		
		printf("2000 * %d    = %d\n",tt,2000*tt);
		printf(" 500 * %d    = %d\n",fh,500*fh);
		printf(" 200 * %d    = %d\n",tw,200*tw);
		printf(" 100 * %d    = %d\n",h,100*h);
		printf("  50 * %d    = %d\n",f,50*f);
		printf("  20 * %d    = %d\n",tw,20*tw);
		printf("  10 * %d    = %d\n",te,10*te);
		total=2000*tt+500*fh+200*tw+100*h+50*f+20*tw+10*te;
		printf("---------------------\n");
		printf("                               			SIGNATURE(SCAN)\n");		
		printf("                               			_________\n");
		return total;
}
