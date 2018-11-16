#include <iostream>

using namespace std;

int recursive_Inc(int list[],int pos,int base, bool value)
{
	if(pos==0){list[pos]++;return 0;}
	else
	{
		list[pos] = (list[pos]+1)%base;
		if(list[pos]==0){recursive_Inc(list,pos-1,base,true);}
	}
}


bool default_Checker(int list[],int len,int base)
{
	if(list[0]!=base){return false;}
	else
	{
		for(int t = 1;t<len;t++)
		{
			if(list[t]!=0){return false;}
		}
		return true;
	}
}


void iter(int list[],int len,int base,char chars[])
{
	while(default_Checker(list,len,base)==false)
	{
		recursive_Inc(list,len-1,base,true);
		for(int k = 0;k<len;k++){cout<<chars[list[k]];}
		cout<<endl;
	}
}

void standart_Rep(int min_length, int max_length,char chars[],int char_length)
{
	for(int current_length = min_length; current_length<=max_length; current_length++)
	{
		int list[current_length];
		for(int cZ = 0; cZ<current_length; cZ++){list[cZ] = 0;}
		iter(list,current_length,char_length,chars);
	}

}


int main(int argc, char *argv[0])
{

	char chars[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9'};
	int char_length = 36;
	int min_length,max_length;
	if(argc==1)
	{
		cout<<"write the min. and max numbers that you want for the lengths of the strings you want to generate. (Ex. 3 4): ";
		cin>>min_length>>max_length;
	}
	if(argc==2)
	{
		min_length = 1;
		max_length = *argv[1] -'0';
	}
	if(argc==3)
	{
		min_length =*argv[1] - '0';
		max_length = *argv[2] - '0';
	}

standart_Rep(min_length, max_length, chars, char_length);

return 0;
}


