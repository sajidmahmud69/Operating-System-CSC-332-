#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    int a = 10, b = 25, fq = 0, fr = 0;
    fq = fork();            // fork a child - call it Process Q
    if (fq == 0){           // child successfully forked
        a = a+b;
        printf("The value of a is %d, the value of b is %d, process Q id is %d, and process R id is %d\n",a,b,fq,fr);
        fr = fork();        // fork another child - call it Process R (Q's child)
        if (fr != 0){       // We are in Process Q scope
            b = b+20;
            printf("The value of a is %d, the value of b is %d, process Q id is %d, and process R id is %d\n",a,b,fq,fr);
        }else{              // We are in Process R
            a = (a*b)+30;
            printf("The value of a is %d, the value of b is %d, process Q id is %d, and process R id is %d\n",a,b,fq,fr);
        }
    }else{                  // We are in parent Process
        b = a+b-5;
        printf("The value of a is %d, the value of b is %d, process Q id is %d, and process R id is %d\n",a,b,fq,fr);
    }
    return 0;
}
