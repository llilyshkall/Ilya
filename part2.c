#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "d_stack.h"

 
double Dig(char *str, int N)
{
    int  l, c, i, j, ind=0;
    double sum2, sum;
    char str1[10], str2[10];
    int i1, i2, flag;
    i1 = 0; i2 = 0; flag = 1; //flag 1 до точки, 2 после точки
    for (ind = 0; ind < N; ind++)    
    { 
		if (str[ind] == '.')	
		{ 
			flag = 2;	
			continue;
		}
		if (flag == 1)	
		{ 
			str1[i1]=str[ind]; 
			i1=i1+1; 
		}
		else 
		{
			 str2[i2]=str[ind]; 
			 i2=i2+1; 
		}
	} 
        sum=0;
        for (ind = i1-1 , l = 1 ;  ind >= 0;  ind--, l=l*10)        
        { 		           		 			
			sum=sum + (str1[ind]-48)*l;      
		} 
  
        for (ind = 0, l = 10 ;  ind <= i2-1;  ind++, l=l*10)        
        { 
		    sum2 =  (str2[ind]-48) ;  		 			
			sum=sum + sum2/l;       
		} 				
	return sum;
}



int check (int kk, int flag)
{
    if (top < kk)
    {
        fprintf (stderr, "ERROR: Wrong input!(More mathematical operators than numbers)\n");
        exit(-1);
    }
     if (flag == 1)  
    {
        fprintf (stderr, "ERROR: Wrong input\n");
        exit(-1);
    }   
    
    return 0;
}

int main(void)
{  
    double a;
    int i, c, flag, ind;
    char str[10];
    flag = 0;   // flag = 1  режим ввода числа
    i  = 0;		
    while ( (c = getchar()) != EOF  )   
    {
    	if (c == '\n') {break;}      
        if ( (c >= '0' && c <= '9') || (c=='.' ) )     
        { 
			flag = 1;  // в режиме ввода числа
			str[i] = c;
			i = i + 1;			
        }       
        else    
        {
            switch(c) 
            {
            	case ' ': 
            	{
					      if (flag == 1)  // старый массив пишем в стек, созд новый массив
					      {
						     double aa = Dig(str,i ) ;     	
						     push(aa);        		
						     flag = 0;
						     i=0; 
					      }
					      break; 
            	}
                case '+': 
                { 
                          check(1, flag);
                          double p2 = pop(); 
                          double p1 = pop(); 	
                          push(p1+p2); 	
                          break;
                          
                }
                case '-': 
                {         
                          check(1, flag);
                          double p2 = pop();  
                          double p1 = pop();  
                          push(p1-p2);    
                          break; 
                }
                case '/':
                {         
                          check(1, flag);
                          double p2 = pop(); 
                          if (p2 != 0.0)
                          {
                             push(pop()/p2);
                          }
                          else 
                          {
                             printf ("ERROR: Divide by zero!\n"); 
                             exit(-1); 
                          }
                            break;
                }
                case '*':
                {         
                          check(1, flag);
                          double p2 = pop();  
                          double p1 = pop(); 
                          push(p1*p2); 
                          break;
               }
                case '~': 
                {         
                          check(0, flag);						  
                          double p3 = pop();
                          push(-p3);
                          break;
                }  
				default :
				{
				          fprintf (stderr, "ERROR: Wrong input!\n");
				          exit(-1);
			    }  
            } 
        } 
    } 
	if (flag == 1) // ввели просто одно число
	{ 
		double aa = Dig(str,i ) ;   
		push(aa); 					
	}       								
	
	if (top == -1) 
	{ 
	    fprintf (stderr, "ERROR: Wrong input! (Empty expression)\n");
	    exit(-1); 
	}  	
	if (top > 0) 
	{  
	    fprintf (stderr, "ERROR: Wrong input! (More numbers than mathematical operators)\n");
	    exit(-1);
	}  	
			
  	a = pop();
  	printf("\n = %f", a);
  	return 0;  
}
