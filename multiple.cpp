#include <iostream>
#include <cstddef>
#include <stdlib.h>
#include <math.h>
static unsigned long long int profundidad=0;
static unsigned long long int mod_num=0;

unsigned long long int findp(unsigned long long int num,unsigned long long int mod){
	unsigned long long int sub_mod=num%mod;
	++profundidad;
	if (sub_mod>1){

		return findp(num,sub_mod);
	}
	if(sub_mod ==1)
		return 0;
	return mod;
}
main(){
	unsigned long long int p=2038074739;
	unsigned long long int q=1299689;
	unsigned long long int num=p*q;
	unsigned long long int pmod=sqrtl(num);

	unsigned long long int sub_mod;
	while(0==(sub_mod=findp(num,pmod))){
		pmod-=13;
		++mod_num;
	}
	std::cout<<"\np:"<<sub_mod<<" q:"<<(num/sub_mod)<<" count:"<<mod_num<<" profundidad:"<<profundidad/mod_num;
}