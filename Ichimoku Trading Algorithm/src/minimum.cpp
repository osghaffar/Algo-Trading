double minimum(double array[], int size)
{
   double min = array[0];
   int n;
   
   for(n = 0; n < size; n++){
	if(array[n] < min){
	   min = array[n];
	}
   }
   
   return(min);
}
