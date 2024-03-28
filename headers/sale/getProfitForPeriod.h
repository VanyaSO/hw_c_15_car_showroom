#ifndef GETPROFITFORPERIOD
#define GETPROFITFORPERIOD
double getProfitForPeriod(Sale* list, int sizeList)
{
    if (sizeList == 0)
        return 0;

    double profit = 0;
    for (int i = 0; i < sizeList; ++i)
    {
        Sale sale = list[i];
        profit += sale.profit;
    }

    return profit;
}
#endif
