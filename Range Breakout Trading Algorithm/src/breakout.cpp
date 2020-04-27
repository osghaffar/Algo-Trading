void start(){
  
   //using extern to allow variables to be edited outside the development environment
   extern double lotSize = 0.05;
   extern double stopLoss = 20;
   extern double takeProfit = 20;
  
   //setting the current time
   datetime TradingTime = TimeCurrent();
   int GetHour = TimeHour(TradingTime);
   
   //to set to your discretion
   int beginTime, endTime
   while(GetHour >= beginTime && GetHour <= endTime){
         
   //define consolidation period   
   int endOfConsolidationPeriod;
  
   //collect the highs
   int periodHigh = iHighest(Symbol(),PERIOD_H1,MODE_HIGH,11,1);
   double periodHighest = High[periodHigh];
   
   //collect the lows
   int periodLow = iLowest(Symbol(),PERIOD_H1,MODE_LOW,11,1);
   double periodLowest = Low[periodLow];
      
   //check whether the end of the consolidation period has arrived
   bool endOfPeriodFound = false;
   if(GetHour == endOfConsolidationPeriod){
      endOfPeriodFound = true;
   }
     
   bool startOfTradingPeriodFound = false;
   if(GetHour >= beginTime){
      startOfTradingPeriodFound = true;
   }

   if(endOfPeriodFound = true){
      drawShape(periodHighest, periodLowest);
   }
      
   if(startOfTradingPeriodFound == true){
      double AskCP = MarketInfo(Symbol(), MODE_ASK);
      double BidCP = MarketInfo(Symbol(), MODE_BID);
      
      drawLines(periodHighest, periodLowest);
      
      Comment("Buy threshold: ", Symbol(), periodHighest, " || Sell Threshold : ", Symbol(), periodLowest, " || Current Bid/Ask : ", BidCP, AskCP);
      
         if(AskCP > (periodHighest)){
            Print("Buy order triggered!");
            double BuyOrders = TotalOrder(1111);
            if(BuyOrders < 1){
               ticket = OrderSend(Symbol(),OP_BUY,lotSize,Ask,3,Ask-(stopLoss*pips),Ask+(takeProfit*pips),NULL,1111,0,Green);
               Print("Ticket = ", ticket);
               if(ticket < 0){
                  Print("Error in buy = ", GetLastError());
               }
            }
         }
      
         if(BidCP < (periodLowest)){
            Print("Sell orders triggered");
            double SellOrders = TotalOrder(2222);
            if(SellOrders < 1){
               ticket = OrderSend(Symbol(), OP_SELL, lotSize, Bid, 3, Bid+(stopLoss*pips), Bid-(takeProfit*pips), NULL, 2222, 0, Red);
               Print("Ticket = ", ticket);
               if(ticket < 0){
                  Print("Error in buy = ", GetLastError());
               }
            }
         }
      }
      GetHour = TimeHour(TradingTime);
   }       
}
