#include <iostream>

//k v CMDju zarunnamo argc_argv.exe mu lahko podamo dodatne argumente
int main(int argc,char const *argv[])
{
	std::cout<<"number of arguments: "<<argc<<"\n";
    for(int i = 0; i < argc; i++) {
        std::cout<<argv[i]<<"\n";
    }
	return 0;
}