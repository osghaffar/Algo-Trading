//This allows you to stop making trades after a given time and closes any open trades
//CHANGE extension from .cpp to .mt4

extern bool UseTimeLimit = true;

void CloseTime(int x);

int start()
{
   bool AllowTrade = false;
   datetime TimeOfTrade;
   int CurrentHour;
   //set these to whatever time you want
   int StartTradeTime = 0;
   int EndTradeTime = 16;

   if (UseTimeLimit == true){
      TimeOfTrade = TimeCurrent();
      CurrentHour = TimeHour(CurrentHour);
      if (CurrentHour >= StartTradeTime && CurrentHour <= EndTradeTime){
         AllowTrade = true;
      }
   }

   if(AllowTrade == true){
      //here you can insert all necessary algorithmic functions etc. as the bool AllowTrade
      //will ensure trades only take place in the given period.
   }

   void CloseTime(EndTradeTime);
}

//Allows you to close all trades outside of given range in order to save you from paying overnight fees
void CloseTime(EndTradeTime)
{
   if(TimeCurrent() > EndTradeTime){
      if(OrderSelect(ticket, SELECT_BY_TICKET) == true){
         if((OrderType() == OP_BUY)){
            //OrderClose function is (int ticket, double LotSize, Ask/Bid, int slippage, color)
            //refer to MT4 documentation
            OrderClose(ticket,LotSize,Bid,3,Red);
         }
         else if (OrderType() == OP_SELL){
            if(OrderSelect(ticket, SELECT_BY_TICKET) == true){
               OrderClose(ticket,LotSize,Ask,3,Green);
            }
         }
      } 
   }
}
