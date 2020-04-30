/*
Draws lines at the top and bottom of the consolidation period, serving as a buy/sell signal threshold.
Length and position can all be adjusted, using the following function from the documentation:

ObjectCreate(name, type, time_period, x_leftmost, y_leftmost, x_rightmost, y_rightmost)

*/
void drawLines(double periodHighest, double periodLowest){
   
   //draw lines, top and bottom
   ObjectCreate("hLine",OBJ_TREND,0,Time[11],periodHighest,Time[0],periodHighest);
   ObjectCreate("lLine",OBJ_TREND,0,Time[11],periodLowest,Time[0],periodLowest);
     
   //don't make them extend all the way across the screen, i.e not rays
   ObjectSet("hLine", OBJPROP_RAY,false);
   ObjectSet("lLine", OBJPROP_RAY,false);
}
