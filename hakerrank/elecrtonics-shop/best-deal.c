// https://www.hackerrank.com/challenges/electronics-shop/problem
#include <stdio.h>
#define MAXARTICLES 1000 
int budget ,kb[MAXARTICLES],usb[MAXARTICLES];
int kbprice = 0;
int usbprice = 0;
int totalcost = 0;
int maxspend = -1;
int total_usb = 0;
int total_keyboards = 0;

void resetMaxSpend()
{
    maxspend = -1;
}
void populateTotalAmountForSingleKeyboard()
{
    for ( int i = 0 ; i < total_usb ; i++ ) {
        usbprice = usb[i];
        totalcost = kbprice + usbprice;
        if ( totalcost <= budget) {
            if (maxspend < totalcost) {
                maxspend = totalcost;
            }
        }
    }
}

void populateTotalAmountforEachKeyboard()
{
    for ( int i = 0 ; i < total_keyboards ; i++ ) {
        kbprice = kb[i];
        populateTotalAmountForSingleKeyboard();
    }
}


void calculateMaximumSpend()
{
}

void printMaximumSpend()
{
    printf("maxspend: %d\n", maxspend);
}

void setBudget(int budget_local)
{
    budget = budget_local;
}
void setKeyboardPrices(int kb_local[], int num_keyboards )
{
    total_keyboards = num_keyboards;
    for (int i = 0 ; i < num_keyboards ; i++)
    {
        kb[i] = kb_local[i];
    }
}
void setUSBPrices(int usb_local[], int num_usb)
{
    total_usb = num_usb;
    for (int i = 0 ; i < num_usb ; i++)
    {
        usb[i] = usb_local[i];
    }
}
int getMaximumSpend()
{
    return maxspend;
}

void GetSpendForMultipleConfigurations()
{
    int numTests = 0;
    scanf("%d", &numTests);
    while ( numTests-- ) {
        int budget_local ; 
        int kb_local[MAXARTICLES];
        int usb_local[MAXARTICLES];
        int num_keyboard; 
        int num_usb;
        scanf("%d", &budget_local);
        scanf("%d", &num_keyboard);
        scanf("%d", &num_usb);

        for(int i = 0 ; i < num_keyboard ; i++ )
        {
            scanf("%d", &kb_local[i]);
        }

        for(int i = 0 ; i < num_usb ; i++ )
        {
            scanf("%d", &usb_local[i]);
        }
        
        resetMaxSpend();
        setBudget(budget_local);
        setKeyboardPrices(kb_local, num_keyboard );
        setUSBPrices(usb_local, num_usb);

        populateTotalAmountforEachKeyboard();
        calculateMaximumSpend();

        printf("%d\n",getMaximumSpend());

    }


}


void ExecuteTest(int budget_local ,
                    int kb_local[] ,
                    int num_keyboard, 
                    int usb_local[],
                    int num_usb,
                    int expected_spent,
                    const char *testname
                     )
{
    resetMaxSpend();
    setBudget(budget_local);
    setKeyboardPrices(kb_local, num_keyboard );
    setUSBPrices(usb_local, num_usb);

    populateTotalAmountforEachKeyboard();
    calculateMaximumSpend();
    if ( expected_spent != getMaximumSpend() ) {
        printf("FAILED: %s\n",testname);
    } else {
        printf("PASS: %s\n", testname);
    }
}
void TestCaseWhenMaxSpendMatchesBudget()
{
    int budget_local = 100; 
    int kb_local[6]={60,15,28,80,36,48};
    int usb_local[4]={11,29,40,70};
    int expected_spent = 100;

    char testname[] =   "Max Spend Equals Budget";  
    ExecuteTest( budget_local ,
                         kb_local ,
                        sizeof(kb_local) / sizeof(int), 
                        usb_local,
                        sizeof(usb_local) / sizeof(int), 
                        expected_spent,
                        testname
                        );
}

void TestCaseWhenMaxSpendLessThanBudget()
{
    int budget_local = 100; 
    int kb_local[]={28,13,11,40,10,14,23,18,39,45,26,3,47,18,27,7,13,45};
    int usb_local[]={42,17,17,21,47,17,46,42,34,17};
    int expected_spent = 94;
    char testname[] =   "Max Spend Less Than Budget";  
    ExecuteTest( budget_local ,
                         kb_local ,
                        sizeof(kb_local) / sizeof(int), 
                        usb_local,
                        sizeof(usb_local) / sizeof(int), 
                        expected_spent,
                        testname
                        );
}

void RunTestSuite()
{
    TestCaseWhenMaxSpendMatchesBudget();
    TestCaseWhenMaxSpendLessThanBudget();
}

void main()
{
    //RunTestSuite();
    GetSpendForMultipleConfigurations();
}
