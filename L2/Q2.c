#include <stdio.h>
int main(){
    int n=120457051;
    int ans=0;
    int pow=1;//power of 10
    int zer=0;
    while(n!=0){
        int digit=n%10;
        if(digit!=0)ans+=digit*pow;
        else{
            ans*=10;
            zer++;
        }
        n/=10;
        pow*=10;
    }
    printf("Num: %d\nNumber of zeros: %d",ans,zer);
    return 0;
    
    

}