//+------------------------------------------------------------------+
//|ichimoku.mq4                                                      |
//|By Omar Ghaffar                                                   |
//|www.github.com/osghaffar                                          |
//|This is free to use however you want to.                          |
//+------------------------------------------------------------------+

//include our counter function
#include "ordercounter.mq4"
#include "maximum.mq4"
#include "minimum.mq4"

//extern allows you to edit this variable in the MT4 environment itself
extern double LotSize = 0.1;

//+------------------------------------------------------------------+
//| initialization function - runs when bot initializes              |
//+------------------------------------------------------------------+
void OnInit()
{
}

//+------------------------------------------------------------------+
//| deinitialization function- runs when bot deinitializes           |
//+------------------------------------------------------------------+
void DeInit()
{
}

//+------------------------------------------------------------------+
//| start function - runs when the bot starts (after initializing)   |
//+------------------------------------------------------------------+
void start()
{
    //initialize ticket to 0
    int ticket = 0;
    
    bool buyorder = false;
    bool sellorder = false;
    
    //statically allocate the arrays since we know how many elements
    double convline[9];
    double baseline[26];
    
    //get the data for the last 9 and 26 periods respectively
    //should be stored [current period, cp-1, cp-2, cp-3, cp-4, ...]
    double conv = CopyClose(Symbol(), 0, 0, 9, convline);
    double base = CopyClose(Symbol(), 0, 0, 26, baseline);
    
    //calculate the max & min of both arrays
    double maxOfConversionLine = maximum(convline, 9);
    double minOfConversionLine = minimum(convline, 9);
    
    double maxOfBaseLine = maximum(baseline, 26);
    double minOfBaseLine = minimum(baseline, 26);
    
    /*
    Conversion Line = ((max of last 9 periods) + (min of last 9 periods))/2
    Base Line = ((max of last 26 periods) + (min of last 26 periods))/2
    */
    double conversionLine = (maxOfConversionLine + minOfConversionLine) / 2;
    double baseLine = (maxOfBaseLine + minOfBaseLine) / 2;
    
    /*
    or a much simpler built-in way:
     
    double conversionLine = iIchimoku(NULL, 0, 9, 26, 52, 1, 0);
    double baseLine = iIchimoku(NULL, 0, 9, 26, 52, 2, 0);
    */
    
    int order;
    int orderclose;
    
    //pass magic numbers of buy + sell orders to order counter to keep track
    int OrderTotal1 = OrderCounter(1111);
    int OrderTotal2 = OrderCounter(2222);
    
    if((conversionLine > baseLine) && (OrderTotal1 <= 2)){
        // C > B, Open Buy Trades, Close Sell Trades
        ticket = OrderSend(Symbol(),OP_BUY,LotSize,Ask,3,0,0,NULL,1111,0,Green);
        buyorder = true;
        //for loop checks for sell orders and closes them
        for(int c = 0; c < OrdersTotal(); c++){
            order = OrderSelect(c, SELECT_BY_POS);
            if(OrderType() == OP_SELL){
                orderclose = OrderClose(OrderTicket(), OrderLots(), Ask, 3, Red);
            }
        }
    }
    
    if((baseLine > conversionLine) && (OrderTotal2 <= 2)){
        // B > C, Open Sell Trades, Close Buy Trades
        ticket = OrderSend(Symbol(),OP_SELL,LotSize,Bid,3,0,0,NULL,2222,0,Red);
        sellorder = true;
        //for loop checks for buy orders and closes them
        for(int c = 0; c < OrdersTotal(); c++){
            order = OrderSelect(c, SELECT_BY_POS);
            if(OrderType() == OP_BUY){
                orderclose = OrderClose(OrderTicket(), OrderLots(), Bid, 3, Green);
            }
        }
    }
}
