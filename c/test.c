#include <stdio.h >
#include <stdlib.h>
#include <string.h>
        void main()
        {
          int pos,j,max,T,t,q,n,p[100];
          char s[100][20],r[9],tax[5],c[9],i[5];
          double tot;
          scanf("%d",&T);
          while(T>0)
          {
            scanf("%d",&n);
            q=0;
            pos=0;
            max=0;
            j=0;
            while( q < n)
            {
              scanf("%s %s %s",s[q],c,i);
              for(j=1; j< strlen ( c ) ;  j ++)  r[j-1]=c[j];
        
              p[q]=atoi(r);
              for( j = 0 ; j < strlen (i) - 1; j ++)  tax[j]=i[j];
              
              t=atoi( tax );

              tot = p[q] + t * p[q] / 100;
              if(tot>max)
              {
                max=tot;
                pos=q;
              }
              else if(tot == max)
              {
                 if( p[q] > p[pos])
                  pos=q;
              }
              q++;
           }
           printf("%s\n",s[pos]);
           T--;
          }
        }