#include "loss_read.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

void Loss_read()
{
//	vector<double*> OLRI;
	vector<double*> ALRI;
	loss_read *LR = new loss_read();

	string Str = "loss_MEM_EN10000_LN1_E5000_NN50_B100_adam_L1e-05_DR0.0.txt";

	int LINENUM = LR->read_in_lineNum(&Str);
//	cout<<"used lines num :"<<LINENUM/2<<endl;
//	OLRI = LR->one_line_read_in(&Str, LINENUM);
	ALRI = LR->all_line_read_in(&Str, LINENUM);
	cout<<"Size of Vector : "<<ALRI.size()<<endl;
	
	double *TRAIN, *TEST; 
	TRAIN = (ALRI.at(0));	
	TEST  = (ALRI.at(1));  

	int ii = 0;	
	for(int iii=0; iii<LINENUM-300; iii++)
	{
		cout<<TRAIN[iii]<<" ";
		cout<<TEST[iii]<<endl;
		ii++;
	}
//	cout<<ii<<endl;

	

}

