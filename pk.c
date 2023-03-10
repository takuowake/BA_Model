#include <stdio.h>
#define Kmax 300
#define NID 5000

int main() {
	int i,j,N,M,k,f;
	int link[NID+1][Kmax+1];
	float pk[Kmax+1];
	int deg[Kmax+1];
	char moji;
	char filename[20];
	FILE *fp, *fq;

	for(j=1; j<=Kmax; j++) {
		deg[j]=0;
	}

	for(f=0;f<10;f++) {
		sprintf(filename, "ba%d.net", f+1);
	        fp = fopen(filename, "r");
	        fscanf(fp, "%s %d", &moji, &N);
	        fscanf(fp, "%s", &moji);

	        while(fscanf(fp, "%d %d", &i, &j) != EOF) {
		        deg[i]=deg[i]+1;
		        deg[j]=deg[j]+1;
		        link[i][deg[i]]=j;
	        }
	        fclose(fp);

	        for(k=1; k<Kmax; k++) {
	      	        pk[k] = 0.0;
	        } 

	        M=0;

	        for(j=1; j<=N; j++) {
	 	        k = deg[j];
		        M = M+k;
		        pk[k] = pk[k]+1.0/(double)N;
	        }
	        M = M/2;

	        sprintf(filename, "ba%dpk.txt", f+1);
		fq = fopen(filename,"w");
	        for(k=1; k<=Kmax; k++) {
	 	        if(pk[k]>0.0){
			        fprintf(fq, "%d %f\n", k, pk[k]);
		        }
	        }  
	        fclose(fq);
        }
}
