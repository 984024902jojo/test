//a.c
#include<stdio.h>
#include<stdlib.h>

int x[10];
int y[10];
int num_inputs;
int num_y=0;

void get_args(int ac, char **av)
{
	num_inputs=ac-1;
	for(int i=0; i<num_inputs;i++)
		x[i]=atoi(av[i+1]);
}

void scoot_over(int jj)
{
	for(int k=num_y-1;k>jj;k--)
		y[k]=y[k-1];
}

void insert(int new_y)//value 
{
	if(num_y==0){
		y[0]=new_y;//initial the y[0]as the fisrt input number
		return;
	}
	int j=0;
	for(j=0;j<num_y;j++){
		if(new_y < y[j]){
			scoot_over(j);
			y[j]=new_y;
			return;
		}
	}
}

void process_data(){
	for(num_y=0;num_y<num_inputs;num_y++)
		insert(x[num_y]);
}

void print_results()
{
	for(int i=0; i<num_inputs; i++)
		printf("%d\n",y[i]);
}

int main(int argc, char **argv)
{
	get_args(argc,argv);
	process_data();
	print_results();
	return 0;
}
