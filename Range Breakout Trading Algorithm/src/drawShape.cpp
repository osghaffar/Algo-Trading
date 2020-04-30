/*
Draws a rectangle around the consolidation period, serving as a visual aid to the buy/sell signal threshold.
Length and position can all be adjusted, using the following function from the documentation:

ObjectCreate(name, type, time_period, x_leftmost, y_leftmost, x_rightmost, y_rightmost)

Color can also be adjusted:

ObjectSet(name, attribute, color_name)

*/
void drawShape(double periodHighest, double periodLowest){
   
   //draw rectangle (name, object, currentchart, left edge, top edge, right edge, bottom edge)
   ObjectCreate("Rectangle", OBJ_RECTANGLE, 0, Time[0], periodHighest, Time[11], periodLowest);
   
   ObjectSet("Rectangle",OBJPROP_COLOR,clrLightGray);
   
}
