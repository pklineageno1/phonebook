#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

#define MAX_DICT 769

int *hash_tbl[MAX_DICT];


uint32_t hash(char *str){
	// djb2
	uint32_t hash = 5381;
	int c;
	while((c= *str++)!=0){
			hash = ((hash<<5)+hash)+c; // hash*33 +c
	}
	// stringtoint
	/*uint32_t hash = 0;
	while(*str){
			hash+= *str++;
			if(*str)
				hash+=((uint32_t) *str++)<<8;
	}*/
	
	return hash%MAX_DICT;
}

int main(){
	
	uint32_t xvals[1000],yvals[1000];
	int i = 0, j = 0;
	char *str;
	for(i = 0;i<1000;i++){
		xvals[i] = i;
		str[i] = i;
		yvals[i] = hash(str);
	}
	
	FILE *pipe = popen("gnuplot -persist","w");
	fprintf(pipe,"set data style lines\n");
	for(j = 0;j<1000;j++){
			fprintf(pipe,"%u\n",yvals[i]);
	}
	fprintf(pipe,"e");
	fclose(pipe);
    return 1;
}
