int main()
{
  char arr[2][5] = {"Even", "Odd"};
  int no;
  printf( "Enter a number: ");
  scanf("%d",& no);
  printf( arr[no%2]);
  
  return 0;
}


/*The above code need to print if the given number is even or odd
Input: 2
output: Even

Make changes at appropriate positions to print the output.
Note: Do not make changes in the algorithm*/