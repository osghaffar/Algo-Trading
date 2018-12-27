double maximum(double array[], int size)
{
   double max = 0;
   int n;
   
   for(n = 0; n < size; n++){
	if(array[n] > max){
	   max = array[n];
	}
   }
   
   return(max);
}

	