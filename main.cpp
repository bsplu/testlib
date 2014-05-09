#include<iostream>
#include<fstream>
#include<iomanip>
#include<dlfcn.h>

using namespace std;

int main()
{
  void mfun(string s);
  double mlib(void);
  void new_function(void);
  cout<<"Hello,I am b !\nIf U wanna exit, please input \"quit\"\n";
  
  string s;
  do
    {
      getline(cin,s);
      if(s=="quit")
	{
	  cout<<"see U !"<<endl;
	  break;
	}

      if(strstr(s.data(),"new") != NULL)
	{
	  new_function();
	  continue;
	}
      //write .cpp
      mfun(s);
      //make .so
      double status=mlib();


      //read the erro text
      fstream r_erro;
      string s_erro;
      int n_erro(0);
      
      r_erro.open("./erro.txt",ios::in);
      while(r_erro.good())
	{
	  n_erro++;
	  getline(r_erro,s_erro);
	  if(n_erro>1)
	    {
	      cout<<s_erro<<endl;
	    }

     	}
      if(n_erro != 1 )
	{
	  cout<<"please input again ! "<<endl;
	  continue;
	}


      void *pdlHandle = dlopen("./libfun.so",RTLD_LAZY);
      char *pszErr = dlerror();
      if( !pdlHandle || pszErr )
	{
	  cout<<"Load libfun failed!\n";

	  return 1;
	}

      double (*f)(void);
      f = (double(*)())(dlsym(pdlHandle, "f"));
      
      if( ! f)
	{
	  pszErr = dlerror();
	  cout<<"Find symbol failed!\n"<<pszErr<<endl;
	  return 1;
	}
      
      cout<<f()<<endl;

      dlclose(pdlHandle);
 
    }while(1);

  return 0;
}

void mfun(string s)
{
  ofstream fout("fun.cpp");
  fout<<"#include\"newfun.h\""<<endl;
  fout<<"#include\"fun.h\""<<endl;
  fout<<"#include<math.h>"<<endl;
  fout<<"double f(void)\n{"<<endl;
  fout<<"return "+s+";\n}"<<endl;
  fout.close();
}

double mlib(void)
{
  int status(0);
  status= system("g++ -fpic -shared fun.cpp -o libfun.so &>erro.txt");
   return status;
}

//need a new function to remember the new function
//it is a circle whit while{} when input "qiut" will end input
//

void new_function(void)
{
  cout<<"Please tell me the name of the new function "<<endl;
  string s_name;
  getline(cin,s_name);
  

  cout<<"if there is an input? Y/N"<<endl;
  string s_input;
  bool b_input;

  string s_inputname;
  getline(cin,s_input);
  if(s_input == "Y" || s_input == "y")
    {
      b_input = true;
      cout<<"input the verable name and its type,like double a"<<endl;

      getline(cin,s_inputname);
      cout<<s_inputname<<endl;
      
    }
  else if(s_input == "N" || s_input == "n")
    {
      b_input = false;
    }
  else
    {
      cout<<"erro\nquit make new function"<<endl;
      return ;
    }

  //as double input


  ofstream fout_newh("./newfun.h",ios::app);

  fout_newh<<"// "+s_name+"\n";
  if(b_input)
    {
      fout_newh<<"double "+s_name+"("+s_inputname+")"<<endl;
 
    }
  else
    {
      fout_newh<<"double "+s_name+"(void)"<<endl;

    }


  cout<<"ok,Let's start write the function !\nif u wanna quit ,please input quit"<<endl;

  //need two function:1.check has the author have write the return 2.is to delete the wrong one  Not Right
  fout_newh<<"{\n";

  do
    {
      string s_gn;
      getline(cin,s_gn);
      if(s_gn == "quit")
	{
	  break;
	}

      fout_newh<<s_gn<<endl;
    }while(1);

  fout_newh<<"}\n//end "+s_name+"\n";
  fout_newh.close();
 
}
