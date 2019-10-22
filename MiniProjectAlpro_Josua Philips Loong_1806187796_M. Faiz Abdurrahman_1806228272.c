#include <stdio.h>
void return_changes( void );
void chk_status( void );
struct products
{
    char key;
    char name[20];
    int price;
    int max_stock;
    int amnt;
    char status;
} p[5] = {
    {'h', "HEAVENLYBLUSH YOGURT", 60, 20, 0, ' '},
    {'s', "SOYFRESH ", 50, 20, 0, ' '},
    {'t', "THAILAND TEA BOTTLE ", 70, 20, 0, ' '},
    {'k', "KRATINGDAENG ", 40, 20, 0, ' '},
    {'p', "MR PEPPER ", 40, 20, 0, ' '}};
struct coins
{
    char key;
    int val;
    int amnt;
} c[3] = {{'1', 10, 0}, {'2', 20, 0}, {'5', 50, 0}};
int bal;
int main( void )
{
    char i_key; /* key code entered ny a user */
    int k_type;
    int k;  /* element number in the array corresponding to the key entered */
    int total;  /* total amount (value) of coins in the machine */
    int i;
    bal = 0;
    printf("Please enter the initial amount of each product. \n");
    int temp;
    for( i = 0; i < 5; i++)
    {
        printf("%s>>", p[i].name);
        scanf("%d", &temp);

        if(temp > 20)
        {
          printf("Please insert lesser or equal to 20.\n");
          printf("%s>>", p[i].name);
          scanf("%d", &p[i].amnt);
        }
        else
          p[i].amnt = temp;
    }
    chk_status();
    printf("*Please enter the initial amount of each coin. \n");
    for( i = 0; i < 3; i++)
    {
        printf("%d sen >>", c[i].val);
        scanf("%d", &c[i].amnt);
    }
    /* Main loop (infinite) */
    do {
        /* display the availability of products and the balance of money for a customer */
        printf( "Balance = %d sen\n", bal);
        printf( "Key Product Name Price Status\n");
        for( i = 0; i < 5; i++)
        {
            printf( "(%c) %s : %d sen %c\n", p[i].key, p[i].name, p[i].price, p[i].status);
        }
        printf("Please enter coin (1=10sen, 2=20sen, 5=50sen)\n");
        printf("or select a product or enter 'x' for return money\n");
        scanf( " %c", &i_key);
        /* process according to the instruction by a user */
        switch (i_key) {
            case 'd':      /* dump status in the machine */
            printf("<Products Status>\n");
            printf("# Key Product Name Price Amount Status\n");
            for( i = 0; i < 5; i++)
            {
                printf("%d (%c) %s %d %d %d %c\n", i, p[i].key, p[i].name, p[i].price, p[i].max_stock, p[i].amnt, p[i].status);
            }
            total = 0;
            printf("\n<Coins Status>\n");
            printf("# Key Value Amount\n");
            for( i = 0; i < 3; i++)
            {
                total = total + c[i].val * c[i].amnt;
                printf("%d (%c) %d %d\n", i, c[i].key, c[i].val, c[i].amnt);
            }
        printf(" Total Amount = %d sen\n\n", total);
        k = -1;
        break;
        /* <<<PROGRAM A>>> */
        case '1':
        k=0; k_type=1;
        break;
        case '2':
        k=1; k_type=1;
        break;
        case '5':
        k=2; k_type=1;
        break;
        case 'h':
        k=0; k_type=2;
        break;
        case 's':
        k=1; k_type=2;
        break;
        case 't':
        k=2; k_type=2;
        break;
        case 'k':
        k=3; k_type=2;
        break;
        case 'p':
        k=4; k_type=2;
        break;
        case 'x':
        k=-1; return_changes();
        break;
        case'0':
        return(0);
        break;
        default :
        printf("Wrong Selection\n");
        k=-1;
        break;
        /* <<<PROGRAM A>>> */
        }
        if( k >= 0 ) {
          if( k_type == 1) {    /* A coin was inserted */
        /* <<<PROGRAM B>>> */
          bal= bal+c[k].val;
          c[k].amnt++;
          chk_status();
        /* <<<PROGRAM B>>> */
          }
        else if( k_type == 2 ) {  /* A product was selected */
        if( p[k].status == 'O') {  /* output the product and return changes, if the balance is not enough to buy another product */
        /* <<<PROGRAM C>>> */
        if(bal <= 0)
            printf("Your balance is not enough.");
        else
        {
            printf( "**** You pick %s as your drinks ****\n", p[k].name);
            printf( "**** Thanks! Enjoy Your Drink ****\n");
            p[k].amnt--;
            bal=bal-p[k].price;
            chk_status();   
        }

        }
    else {
        printf("**** Insert coin first or Choose other product ****\n");
    }
        }
        }
    } while(1);
}
void return_changes( void )
{
    printf("Your Change is %d sen\n",bal);
    while(bal >= 50){

        if(c[2].amnt <= 0)
        {
            printf("No more 50 sen.\n");
            break;
        }
        else
        {
            c[2].amnt--;
            bal-=50;
            printf("Returning %d\n",c[2].val);
        }

    }
    while(bal>=20){

        if(c[1].amnt <= 0)
        {
            printf("No more 20 sen.\n");
            break;
        }
        else
        {
            c[1].amnt--;
            bal-=20;
            printf("Returning %d\n",c[1].val);
        }

    }
    while(bal>=10){

        if(c[0].amnt <= 0)
        {
            printf("No more 10 sen.\n");
            break;
        }
        else
        {
            c[0].amnt--;
            bal-=10;
            printf("Returning %d\n",c[0].val);
        }
    }
}
/* Function to check status of each product */
void chk_status( void )
{
    int i;
    for( i = 0; i < 5; i++) {
        if( p[i].amnt <= 0 ) p[i].status = 'X';
        else if( bal >= p[i].price ) p[i].status = 'O';
        else p[i].status = ' ';
    }
}
