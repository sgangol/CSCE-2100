/********************************************************************
 ** NAME:  Srizan Gangol         		USERID:sg0440	           	**
 ** ASSIGNMENT:  CSCE2100		  				                  	**
 ** DESCRIPTION:  process.cpp										**
 ** Project: Naive Process Scheduler	Program: 4 		          	**
 ** 																**
 ********************************************************************/


#include"process.h"

process::process()
{

}

process::~process()
{

}

process::process(int v, int t)
{
	runtime = t;
	value = v;
}
int process::getValue()
{
	return value;
}

int process::getRuntime()
{
	return runtime;
}

void process::setRuntime(int t)
{
	runtime = t;
}

void process::setValue(int v)
{
	value = v;
}

process * newprocess(int v, int t)
{
	process * tmp = new process;
	tmp->setRuntime(t);
	tmp->setValue(v);
	return tmp;
}