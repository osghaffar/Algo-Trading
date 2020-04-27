void drawLines(double periodHighest, double periodLowest){
   //draw lines, top and bottom
   ObjectCreate("hLine",OBJ_TREND,0,Time[11],periodHighest,Time[0],periodHighest);
   ObjectCreate("lLine",OBJ_TREND,0,Time[11],periodLowest,Time[0],periodLowest);
     
   //dont make them extend all the way across the screen, i.e not rays
   ObjectSet("hLine", OBJPROP_RAY,false);
   ObjectSet("lLine", OBJPROP_RAY,false);
}
