double TotalOrder(int magicnumber)
{
    double totalOrders = 0;
    for(int count = 0; count < OrdersTotal(); count++)
    {
        OrderSelect(count, SELECT_BY_POS, MODE_TRADES);
        if(OrderMagicNumber() == magicnumber)
        {
            totalOrders += 1;
        }
    }
    return(totalOrders);
}
