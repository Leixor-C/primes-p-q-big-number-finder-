#include <iostream>


#include <math.h>
static unsigned long long int depth=0;
static unsigned long long int mod_num=0;

unsigned long long int mod_rec(unsigned long long int num,unsigned long long int mod){
	unsigned long long int sub_mod=num%mod;
	++depth;//looking how many iter of this fuc does
	if (sub_mod>1){

		return mod_rec(num,sub_mod);
	}
	if(sub_mod ==1)
		return 0;
	return mod;
}
unsigned long long int findp(unsigned long long int num){
	unsigned long long int pmod=sqrtl(num)+1;
	unsigned long long int p;
	while(0==(p=mod_rec(num,pmod))){
		pmod+=12;
		++mod_num;//looking how many times does this

	}
	return p;		
}
main(){
	unsigned long long int A=1299689;
	unsigned long long int B=22801763477;//55944044237;
	unsigned long long int num=A*B;

	unsigned long long int p_result =findp(num);	
	std::cout<<"\np:"<<p_result<<" q:"<<(num/p_result)<<" count:"<<mod_num<<" depth:"<<depth/mod_num;
}