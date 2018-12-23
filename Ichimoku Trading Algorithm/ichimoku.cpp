//+------------------------------------------------------------------+
//|ichimoku.mq4                                                      |
//|By Omar Ghaffar                                                   |
//|www.github.com/osghaffar                                          |
//|This is free to use however you want to.                          |
//+------------------------------------------------------------------+

#include "ordercounter.mq4"

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
    int ticket = 0;
    
    bool buyorder = false;
    bool sellorder = false;
    
    double ConversionLine = iIchimoku(NULL, 0, 9, 26, 52, 1, 0);
    double Baseline = iIchimoku(NULL, 0, 9, 26, 52, 2, 0);
    
    int order;
    int orderclose;
    int OrderTotal1 = TotalOrder(1111);
    int OrderTotal2 = TotalOrder(2222);
    
    
    if((ConversionLine > Baseline) && (OrderTotal1 <= 2)){
        // C > B, Open Buy Trades, Close Sell Trades
        ticket = OrderSend(Symbol(),OP_BUY,LotSize,Ask,3,0,0,NULL,1111,0,Green);
        buyorder = true;
        for(int c = 0; c < OrdersTotal(); c++){
            order = OrderSelect(c, SELECT_BY_POS);
            if(OrderType() == OP_SELL){
                orderclose = OrderClose(OrderTicket(), OrderLots(), Ask, 3, Red);
            }
        }
    }
    
    if((Baseline > ConversionLine) && (OrderTotal2 <= 2)){
        // B > C, Open Sell Trades, Close Buy Trades
        ticket = OrderSend(Symbol(),OP_SELL,LotSize,Bid,3,0,0,NULL,2222,0,Red);
        sellorder = true;
        for(int c = 0; c < OrdersTotal(); c++){
            order = OrderSelect(c, SELECT_BY_POS);
            if(OrderType() == OP_BUY){
                orderclose = OrderClose(OrderTicket(), OrderLots(), Bid, 3, Green);
            }
        }
    }
}
