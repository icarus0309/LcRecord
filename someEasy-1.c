#include<math.h>
#include<stdio.h>
#include<string.h>

int max(int a,int b){
	return a>b?a:b;
}

int min(int a,int b){
	return a<b?a:b;
}

long int reverse(long int x){
    long y=0;
    while(x!=0){
        y=y*10+x%10;
        x/=10;
    }
	long tmp=2147483647;
    return y>tmp||y<-tmp-1?0:y;
}

int romanToInt(char* s){
	int res=0;   
	while(*s!='\0'){
		switch(*s){
			case 'I': res+=((*(s+1)=='V'||*(s+1)=='X')?-1:1);break;
			case 'V': res+=5;break;
			case 'X': res+=((*(s+1)=='L'||*(s+1)=='C')?-10:10);break;
			case 'L': res+=50;break;
			case 'C': res+=((*(s+1)=='D'||*(s+1)=='M')?-100:100);break;
			case 'D': res+=500;break;
			case 'M': res+=1000;break;
			default: return -1;
		}
		s++;
	}
    return res;
}


char* longestCommonPrefix(char** strs, int strsSize){
    if(strsSize==0) return "";
    int i=0,count=0;
    char* s = *strs;
    while(*s!='\0'){
    	char tmp=*(*strs+count);
    	for(i=1;i<strsSize;i++){
    		if(*(*(strs+i)+count)!=tmp){
                *s='\0';
                return s-count;
            }
		}
		s++;
        count++;
	}
	return *strs;
}


int isValid(char * s){
	int top=-1;
	char stack[10000]={};
	while(s!=NULL&&*s!='\0'){
		if(*s=='('||*s=='['||*s=='{') stack[++top]=*s;
        else if(top==-1) return 0;
		else if(*s==')' && stack[top]!='(') return 0;
		else if(*s==']' && stack[top]!='[') return 0;
		else if(*s=='}' && stack[top]!='{') return 0;
		else stack[top--]='\0';
		s++;
	}	
    return stack[0]=='\0'?1:0;
}


int massage(int* nums, int numsSize){
    if(numsSize == 0)
        return 0;
    int r1 = 0,i=0;
    int r2 = nums[0];
    for(i = 1; i <numsSize; i++) {
        int temp = r1;
        r1 = r1 > r2 ? r1 : r2;
        r2 = temp + nums[i];
    }
    return r1 > r2 ? r1 : r2;
}
/*
非常值得借鉴的思路
作者：shi-qi-91
链接：https://leetcode-cn.com/problems/the-masseuse-lcci/solution/cyu-yan-dong-tai-gui-hua-ji-di-gui-suan-fa-by-shi-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

char * convert(char * s, int numRows){
    int i=-1,j=0;
    char mat[100][100]={};
    while(*s!='\0'){
        if(j%(numRows-1)==0){
            mat[++i][j] = *s;
			printf("i:%d,j:%d\n",i,j);
            j += (i==numRows-1)?1:0;
        }
        else{
            mat[--i][j++] = *s; 
			printf("i:%d,j:%d\n",i,j-1);
			if(j%(numRows-1)==0) i=-1;           
        }
        s++;
    }
	int cont=0;
    for(i=0;i<numRows;i++){
        for(j=0;j<100;j++){
			if(mat[i][j]!='\0') {
				printf("%c",mat[i][j]);
				s[cont++]=mat[i][j];
			}
			else printf(" "); 
		}
		printf("\n");
    }
	s[cont]='\0';
    return s;
}

int main(){


	char s[100]="PAYPALISHIRING";
	char* c=convert(s,3);	
	puts(c);	
	
/*	
	int a[10]={1};
	int res=0;
	res=massage(a, 8);
	printf("res is %d\n",res);	

	long int res=0,x=1534236469;
	res=reverse(x);

	//---------------
	printf("the result is: %ld\n",res);
	char arr[100]={'V','V','I','I'};	
	char* s=arr;
	int res2 = 0;
	*s = arr[0];
	res2=romanToInt(s);
	printf("the result is: %d\n",res2);

	//---------------
	char s1[3][8]={"flower","flow","flight"};
	char* s;
	s = longestCommonPrefix(s1, 3);
	int i=0;	
	for(i=0;i<=strlen(s);i++){
		printf("%c\n",*s);
		s++;	
	}

	//---------------
	char s[10]="()]";
	int res = isValid(s);
	printf("TURE OR FALSE: %d\n",res);*/

	return 0;		
}



