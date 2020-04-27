void drawShape(double periodHighest, double periodLowest){
   
   //draw rectangle (name, object, currentchart, left edge, top edge, right edge, bottom edge)
   ObjectCreate("Rectangle", OBJ_RECTANGLE, 0, Time[0], periodHighest, Time[11], periodLowest);
   
   ObjectSet("Rectangle",OBJPROP_COLOR,clrLightGray);
   
}
