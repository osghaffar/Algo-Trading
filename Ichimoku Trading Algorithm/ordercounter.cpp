//This function keeps track of the number of orders that have been placed
//by using the orders "magic number", which is an arbitrary value that
//you assign which allows it to be identified. It's best to have a diff
//magic number for buy orders and sell orders.

int OrderCounter(int magic_number)
{    
    //we pass in the order's magic number and then use a basic for loop to
    //keep track of the number of trades.
    
    int totalOrders = 0;
    
    for(int count = 0; count < OrdersTotal(); count++){
        OrderSelect(count, SELECT_BY_POS, MODE_TRADES);
        if(OrderMagicNumber() == magic_number){
            totalOrders += 1;
        }
    }
    
    return(totalOrders);
}
